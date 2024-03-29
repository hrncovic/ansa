#include "AnsaOSPFInterface.h"
#include "AnsaOSPFInterfaceStateDown.h"
#include "InterfaceTableAccess.h"
#include "IPv4InterfaceData.h"
#include "AnsaMessageHandler.h"
#include "AnsaOSPFArea.h"
#include "AnsaOSPFRouter.h"
#include <vector>
#include <memory.h>

AnsaOSPF::Interface::Interface(AnsaOSPF::Interface::OSPFInterfaceType ifType) :
    interfaceType(ifType),
    ifIndex(0),
    mtu(0),
    interfaceAddressRange(AnsaOSPF::NullIPv4AddressRange),
    areaID(AnsaOSPF::BackboneAreaID),
    transitAreaID(AnsaOSPF::BackboneAreaID),
    helloInterval(10),
    pollInterval(120),
    routerDeadInterval(40),
    interfaceTransmissionDelay(1),
    routerPriority(1),
    designatedRouter(AnsaOSPF::NullDesignatedRouterID),
    backupDesignatedRouter(AnsaOSPF::NullDesignatedRouterID),
    interfaceOutputCost(1),
    retransmissionInterval(5),
    acknowledgementDelay(1),
    authenticationType(AnsaOSPF::NullType),
    parentArea(NULL),
    isGoingDown(false)
{
    state = new AnsaOSPF::InterfaceStateDown;
    previousState = NULL;
    helloTimer = new OSPFTimer;
    helloTimer->setTimerKind(InterfaceHelloTimer);
    helloTimer->setContextPointer(this);
    helloTimer->setName("AnsaOSPF::Interface::InterfaceHelloTimer");
    waitTimer = new OSPFTimer;
    waitTimer->setTimerKind(InterfaceWaitTimer);
    waitTimer->setContextPointer(this);
    waitTimer->setName("AnsaOSPF::Interface::InterfaceWaitTimer");
    acknowledgementTimer = new OSPFTimer;
    acknowledgementTimer->setTimerKind(InterfaceAcknowledgementTimer);
    acknowledgementTimer->setContextPointer(this);
    acknowledgementTimer->setName("AnsaOSPF::Interface::InterfaceAcknowledgementTimer");
    memset(authenticationKey.bytes, 0, 8 * sizeof(char));
}

AnsaOSPF::Interface::~Interface(void)
{
    MessageHandler* messageHandler = parentArea->GetRouter()->GetMessageHandler();
    messageHandler->ClearTimer(helloTimer);
    delete helloTimer;
    messageHandler->ClearTimer(waitTimer);
    delete waitTimer;
    messageHandler->ClearTimer(acknowledgementTimer);
    delete acknowledgementTimer;
    if (previousState != NULL) {
        delete previousState;
    }
    delete state;
    long neighborCount = neighboringRouters.size();
    for (long i = 0; i < neighborCount; i++) {
        delete neighboringRouters[i];
    }
}

void AnsaOSPF::Interface::SetIfIndex(unsigned char index)
{
    ifIndex = index;
    if (interfaceType == AnsaOSPF::Interface::UnknownType) {
        InterfaceEntry* routingInterface = InterfaceTableAccess().get()->getInterfaceById(ifIndex);
        interfaceAddressRange.address = IPv4AddressFromAddressString(routingInterface->ipv4Data()->getIPAddress().str().c_str());
        interfaceAddressRange.mask = IPv4AddressFromAddressString(routingInterface->ipv4Data()->getNetmask().str().c_str());
        mtu = routingInterface->getMTU();
    }
}

void AnsaOSPF::Interface::ChangeState(AnsaOSPF::InterfaceState* newState, AnsaOSPF::InterfaceState* currentState)
{
    if (previousState != NULL) {
        delete previousState;
    }
    state = newState;
    previousState = currentState;
}

void AnsaOSPF::Interface::ProcessEvent(AnsaOSPF::Interface::InterfaceEventType event)
{
    state->ProcessEvent(this, event);
}

void AnsaOSPF::Interface::Reset(void)
{
    MessageHandler* messageHandler = parentArea->GetRouter()->GetMessageHandler();
    messageHandler->ClearTimer(helloTimer);
    messageHandler->ClearTimer(waitTimer);
    messageHandler->ClearTimer(acknowledgementTimer);
    designatedRouter = NullDesignatedRouterID;
    backupDesignatedRouter = NullDesignatedRouterID;
    long neighborCount = neighboringRouters.size();
    for (long i = 0; i < neighborCount; i++) {
        neighboringRouters[i]->ProcessEvent(AnsaOSPF::Neighbor::KillNeighbor);
    }
}

void AnsaOSPF::Interface::SendHelloPacket(AnsaOSPF::IPv4Address destination, short ttl)
{
    OSPFOptions options;
    OSPFHelloPacket* helloPacket = new OSPFHelloPacket;
    std::vector<AnsaOSPF::IPv4Address> neighbors;

    helloPacket->setRouterID(parentArea->GetRouter()->GetRouterID());
    helloPacket->setAreaID(parentArea->GetAreaID());
    helloPacket->setAuthenticationType(authenticationType);
    for (int i = 0; i < 8; i++) {
        helloPacket->setAuthentication(i, authenticationKey.bytes[i]);
    }

    if (((interfaceType == PointToPoint) &&
         (interfaceAddressRange.address == AnsaOSPF::NullIPv4Address)) ||
        (interfaceType == Virtual))
    {
        helloPacket->setNetworkMask(ULongFromIPv4Address(AnsaOSPF::NullIPv4Address));
    } else {
        helloPacket->setNetworkMask(ULongFromIPv4Address(interfaceAddressRange.mask));
    }
    memset(&options, 0, sizeof(OSPFOptions));
    options.E_ExternalRoutingCapability = parentArea->GetExternalRoutingCapability();
    helloPacket->setOptions(options);
    helloPacket->setHelloInterval(helloInterval);
    helloPacket->setRouterPriority(routerPriority);
    helloPacket->setRouterDeadInterval(routerDeadInterval);
    helloPacket->setDesignatedRouter(ULongFromIPv4Address(designatedRouter.ipInterfaceAddress));
    helloPacket->setBackupDesignatedRouter(ULongFromIPv4Address(backupDesignatedRouter.ipInterfaceAddress));
    long neighborCount = neighboringRouters.size();
    for (long j = 0; j < neighborCount; j++) {
        if (neighboringRouters[j]->GetState() >= AnsaOSPF::Neighbor::InitState) {
            neighbors.push_back(neighboringRouters[j]->GetAddress());
        }
    }
    unsigned int initedNeighborCount = neighbors.size();
    helloPacket->setNeighborArraySize(initedNeighborCount);
    for (unsigned int k = 0; k < initedNeighborCount; k++) {
        helloPacket->setNeighbor(k, ULongFromIPv4Address(neighbors[k]));
    }

    helloPacket->setPacketLength(0); // TODO: Calculate correct length
    helloPacket->setChecksum(0); // TODO: Calculate correct cheksum(16-bit one's complement of the entire packet)

    parentArea->GetRouter()->GetMessageHandler()->SendPacket(helloPacket, destination, ifIndex, ttl);
}

void AnsaOSPF::Interface::SendLSAcknowledgement(OSPFLSAHeader* lsaHeader, IPv4Address destination)
{
    OSPFOptions                         options;
    OSPFLinkStateAcknowledgementPacket* lsAckPacket = new OSPFLinkStateAcknowledgementPacket;

    lsAckPacket->setType(LinkStateAcknowledgementPacket);
    lsAckPacket->setRouterID(parentArea->GetRouter()->GetRouterID());
    lsAckPacket->setAreaID(parentArea->GetAreaID());
    lsAckPacket->setAuthenticationType(authenticationType);
    for (int i = 0; i < 8; i++) {
        lsAckPacket->setAuthentication(i, authenticationKey.bytes[i]);
    }

    lsAckPacket->setLsaHeadersArraySize(1);
    lsAckPacket->setLsaHeaders(0, *lsaHeader);

    lsAckPacket->setPacketLength(0); // TODO: Calculate correct length
    lsAckPacket->setChecksum(0); // TODO: Calculate correct cheksum(16-bit one's complement of the entire packet)

    int ttl = (interfaceType == AnsaOSPF::Interface::Virtual) ? VIRTUAL_LINK_TTL : 1;
    parentArea->GetRouter()->GetMessageHandler()->SendPacket(lsAckPacket, destination, ifIndex, ttl);
}


AnsaOSPF::Neighbor* AnsaOSPF::Interface::GetNeighborByID(AnsaOSPF::RouterID neighborID)
{
    std::map<AnsaOSPF::RouterID, AnsaOSPF::Neighbor*>::iterator neighborIt = neighboringRoutersByID.find(neighborID);
    if (neighborIt != neighboringRoutersByID.end()) {
        return (neighborIt->second);
    }
    else {
        return NULL;
    }
}

AnsaOSPF::Neighbor* AnsaOSPF::Interface::GetNeighborByAddress(AnsaOSPF::IPv4Address address)
{
    std::map<AnsaOSPF::IPv4Address, AnsaOSPF::Neighbor*, AnsaOSPF::IPv4Address_Less>::iterator neighborIt = neighboringRoutersByAddress.find(address);
    if (neighborIt != neighboringRoutersByAddress.end()) {
        return (neighborIt->second);
    }
    else {
        return NULL;
    }
}

void AnsaOSPF::Interface::AddNeighbor(AnsaOSPF::Neighbor* neighbor)
{
    neighboringRoutersByID[neighbor->GetNeighborID()] = neighbor;
    neighboringRoutersByAddress[neighbor->GetAddress()] = neighbor;
    neighbor->SetInterface(this);
    neighboringRouters.push_back(neighbor);
}

AnsaOSPF::Interface::InterfaceStateType AnsaOSPF::Interface::GetState(void) const
{
    return state->GetState();
}

const char* AnsaOSPF::Interface::GetStateString(AnsaOSPF::Interface::InterfaceStateType stateType)
{
    switch (stateType) {
        case DownState:                 return "Down";
        case LoopbackState:             return "Loopback";
        case WaitingState:              return "Waiting";
        case PointToPointState:         return "PointToPoint";
        case NotDesignatedRouterState:  return "NotDesignatedRouter";
        case BackupState:               return "Backup";
        case DesignatedRouterState:     return "DesignatedRouter";
        default:                        ASSERT(false);
    }
    return "";
}

bool AnsaOSPF::Interface::HasAnyNeighborInStates(int states) const
{
    long neighborCount = neighboringRouters.size();
    for (long i = 0; i < neighborCount; i++) {
        AnsaOSPF::Neighbor::NeighborStateType neighborState = neighboringRouters[i]->GetState();
        if (neighborState & states) {
            return true;
        }
    }
    return false;
}

void AnsaOSPF::Interface::RemoveFromAllRetransmissionLists(AnsaOSPF::LSAKeyType lsaKey)
{
    long neighborCount = neighboringRouters.size();
    for (long i = 0; i < neighborCount; i++) {
        neighboringRouters[i]->RemoveFromRetransmissionList(lsaKey);
    }
}

bool AnsaOSPF::Interface::IsOnAnyRetransmissionList(AnsaOSPF::LSAKeyType lsaKey) const
{
    long neighborCount = neighboringRouters.size();
    for (long i = 0; i < neighborCount; i++) {
        if (neighboringRouters[i]->IsLSAOnRetransmissionList(lsaKey)) {
            return true;
        }
    }
    return false;
}

/**
 * @see RFC2328 Section 13.3.
 */
bool AnsaOSPF::Interface::FloodLSA(OSPFLSA* lsa, AnsaOSPF::Interface* intf, AnsaOSPF::Neighbor* neighbor)
{
    bool floodedBackOut = false;

    if (
        (
         (lsa->getHeader().getLsType() == ASExternalLSAType) &&
         (interfaceType != AnsaOSPF::Interface::Virtual) &&
         (parentArea->GetExternalRoutingCapability())
        ) ||
        (
         (lsa->getHeader().getLsType() != ASExternalLSAType) &&
         (
          (
           (areaID != AnsaOSPF::BackboneAreaID) &&
           (interfaceType != AnsaOSPF::Interface::Virtual)
          ) ||
          (areaID == AnsaOSPF::BackboneAreaID)
         )
        )
       )
    {
        long              neighborCount                = neighboringRouters.size();
        bool              lsaAddedToRetransmissionList = false;
        AnsaOSPF::LinkStateID linkStateID                  = lsa->getHeader().getLinkStateID();
        AnsaOSPF::LSAKeyType  lsaKey;

        lsaKey.linkStateID = linkStateID;
        lsaKey.advertisingRouter = lsa->getHeader().getAdvertisingRouter().getInt();

        for (long i = 0; i < neighborCount; i++) {  // (1)
            if (neighboringRouters[i]->GetState() < AnsaOSPF::Neighbor::ExchangeState) {   // (1) (a)
                continue;
            }
            if (neighboringRouters[i]->GetState() < AnsaOSPF::Neighbor::FullState) {   // (1) (b)
                OSPFLSAHeader* requestLSAHeader = neighboringRouters[i]->FindOnRequestList(lsaKey);
                if (requestLSAHeader != NULL) {
                    // operator< and operator== on OSPFLSAHeaders determines which one is newer(less means older)
                    if (lsa->getHeader() < (*requestLSAHeader)) {
                        continue;
                    }
                    if (operator== (lsa->getHeader(), (*requestLSAHeader))) {
                        neighboringRouters[i]->RemoveFromRequestList(lsaKey);
                        continue;
                    }
                    neighboringRouters[i]->RemoveFromRequestList(lsaKey);
                }
            }
            if (neighbor == neighboringRouters[i]) {     // (1) (c)
                continue;
            }
            neighboringRouters[i]->AddToRetransmissionList(lsa);   // (1) (d)
            lsaAddedToRetransmissionList = true;
        }
        if (lsaAddedToRetransmissionList) {     // (2)
            if ((intf != this) ||
                ((neighbor != NULL) &&
                 (neighbor->GetNeighborID() != designatedRouter.routerID) &&
                 (neighbor->GetNeighborID() != backupDesignatedRouter.routerID)))  // (3)
            {
                if ((intf != this) || (GetState() != AnsaOSPF::Interface::BackupState)) {  // (4)
                    OSPFLinkStateUpdatePacket* updatePacket = CreateUpdatePacket(lsa);    // (5)

                    if (updatePacket != NULL) {
                        int                   ttl            = (interfaceType == AnsaOSPF::Interface::Virtual) ? VIRTUAL_LINK_TTL : 1;
                        AnsaOSPF::MessageHandler* messageHandler = parentArea->GetRouter()->GetMessageHandler();

                        if (interfaceType == AnsaOSPF::Interface::Broadcast) {
                            if ((GetState() == AnsaOSPF::Interface::DesignatedRouterState) ||
                                (GetState() == AnsaOSPF::Interface::BackupState) ||
                                (designatedRouter == AnsaOSPF::NullDesignatedRouterID))
                            {
                                messageHandler->SendPacket(updatePacket, AnsaOSPF::AllSPFRouters, ifIndex, ttl);
                                for (long k = 0; k < neighborCount; k++) {
                                    neighboringRouters[k]->AddToTransmittedLSAList(lsaKey);
                                    if (!neighboringRouters[k]->IsUpdateRetransmissionTimerActive()) {
                                        neighboringRouters[k]->StartUpdateRetransmissionTimer();
                                    }
                                }
                            } else {
                                messageHandler->SendPacket(updatePacket, AnsaOSPF::AllDRouters, ifIndex, ttl);
                                AnsaOSPF::Neighbor* dRouter = GetNeighborByID(designatedRouter.routerID);
                                AnsaOSPF::Neighbor* backupDRouter = GetNeighborByID(backupDesignatedRouter.routerID);
                                if (dRouter != NULL) {
                                    dRouter->AddToTransmittedLSAList(lsaKey);
                                    if (!dRouter->IsUpdateRetransmissionTimerActive()) {
                                        dRouter->StartUpdateRetransmissionTimer();
                                    }
                                }
                                if (backupDRouter != NULL) {
                                    backupDRouter->AddToTransmittedLSAList(lsaKey);
                                    if (!backupDRouter->IsUpdateRetransmissionTimerActive()) {
                                        backupDRouter->StartUpdateRetransmissionTimer();
                                    }
                                }
                            }
                        } else {
                            if (interfaceType == AnsaOSPF::Interface::PointToPoint) {
                                messageHandler->SendPacket(updatePacket, AnsaOSPF::AllSPFRouters, ifIndex, ttl);
                                if (neighborCount > 0) {
                                    neighboringRouters[0]->AddToTransmittedLSAList(lsaKey);
                                    if (!neighboringRouters[0]->IsUpdateRetransmissionTimerActive()) {
                                        neighboringRouters[0]->StartUpdateRetransmissionTimer();
                                    }
                                }
                            } else {
                                for (long m = 0; m < neighborCount; m++) {
                                    if (neighboringRouters[m]->GetState() >= AnsaOSPF::Neighbor::ExchangeState) {
                                        messageHandler->SendPacket(updatePacket, neighboringRouters[m]->GetAddress(), ifIndex, ttl);
                                        neighboringRouters[m]->AddToTransmittedLSAList(lsaKey);
                                        if (!neighboringRouters[m]->IsUpdateRetransmissionTimerActive()) {
                                            neighboringRouters[m]->StartUpdateRetransmissionTimer();
                                        }
                                    }
                                }
                            }
                        }

                        if (intf == this) {
                            floodedBackOut = true;
                        }
                    }
                }
            }
        }
    }

    return floodedBackOut;
}

OSPFLinkStateUpdatePacket* AnsaOSPF::Interface::CreateUpdatePacket(OSPFLSA* lsa)
{
    LSAType lsaType                  = static_cast<LSAType> (lsa->getHeader().getLsType());
    OSPFRouterLSA* routerLSA         = (lsaType == RouterLSAType) ? dynamic_cast<OSPFRouterLSA*> (lsa) : NULL;
    OSPFNetworkLSA* networkLSA       = (lsaType == NetworkLSAType) ? dynamic_cast<OSPFNetworkLSA*> (lsa) : NULL;
    OSPFSummaryLSA* summaryLSA       = ((lsaType == SummaryLSA_NetworksType) ||
                                        (lsaType == SummaryLSA_ASBoundaryRoutersType)) ? dynamic_cast<OSPFSummaryLSA*> (lsa) : NULL;
    OSPFASExternalLSA* asExternalLSA = (lsaType == ASExternalLSAType) ? dynamic_cast<OSPFASExternalLSA*> (lsa) : NULL;

    if (((lsaType == RouterLSAType) && (routerLSA != NULL)) ||
        ((lsaType == NetworkLSAType) && (networkLSA != NULL)) ||
        (((lsaType == SummaryLSA_NetworksType) || (lsaType == SummaryLSA_ASBoundaryRoutersType)) && (summaryLSA != NULL)) ||
        ((lsaType == ASExternalLSAType) && (asExternalLSA != NULL)))
    {
        OSPFLinkStateUpdatePacket* updatePacket = new OSPFLinkStateUpdatePacket;

        updatePacket->setType(LinkStateUpdatePacket);
        updatePacket->setRouterID(parentArea->GetRouter()->GetRouterID());
        updatePacket->setAreaID(areaID);
        updatePacket->setAuthenticationType(authenticationType);
        for (int j = 0; j < 8; j++) {
            updatePacket->setAuthentication(j, authenticationKey.bytes[j]);
        }

        updatePacket->setNumberOfLSAs(1);

        switch (lsaType) {
            case RouterLSAType:
                {
                    updatePacket->setRouterLSAsArraySize(1);
                    updatePacket->setRouterLSAs(0, *routerLSA);
                    unsigned short lsAge = updatePacket->getRouterLSAs(0).getHeader().getLsAge();
                    if (lsAge < MAX_AGE - interfaceTransmissionDelay) {
                        updatePacket->getRouterLSAs(0).getHeader().setLsAge(lsAge + interfaceTransmissionDelay);
                    } else {
                        updatePacket->getRouterLSAs(0).getHeader().setLsAge(MAX_AGE);
                    }
                }
                break;
            case NetworkLSAType:
                {
                    updatePacket->setNetworkLSAsArraySize(1);
                    updatePacket->setNetworkLSAs(0, *networkLSA);
                    unsigned short lsAge = updatePacket->getNetworkLSAs(0).getHeader().getLsAge();
                    if (lsAge < MAX_AGE - interfaceTransmissionDelay) {
                        updatePacket->getNetworkLSAs(0).getHeader().setLsAge(lsAge + interfaceTransmissionDelay);
                    } else {
                        updatePacket->getNetworkLSAs(0).getHeader().setLsAge(MAX_AGE);
                    }
                }
                break;
            case SummaryLSA_NetworksType:
            case SummaryLSA_ASBoundaryRoutersType:
                {
                    updatePacket->setSummaryLSAsArraySize(1);
                    updatePacket->setSummaryLSAs(0, *summaryLSA);
                    unsigned short lsAge = updatePacket->getSummaryLSAs(0).getHeader().getLsAge();
                    if (lsAge < MAX_AGE - interfaceTransmissionDelay) {
                        updatePacket->getSummaryLSAs(0).getHeader().setLsAge(lsAge + interfaceTransmissionDelay);
                    } else {
                        updatePacket->getSummaryLSAs(0).getHeader().setLsAge(MAX_AGE);
                    }
                }
                break;
            case ASExternalLSAType:
                {
                    updatePacket->setAsExternalLSAsArraySize(1);
                    updatePacket->setAsExternalLSAs(0, *asExternalLSA);
                    unsigned short lsAge = updatePacket->getAsExternalLSAs(0).getHeader().getLsAge();
                    if (lsAge < MAX_AGE - interfaceTransmissionDelay) {
                        updatePacket->getAsExternalLSAs(0).getHeader().setLsAge(lsAge + interfaceTransmissionDelay);
                    } else {
                        updatePacket->getAsExternalLSAs(0).getHeader().setLsAge(MAX_AGE);
                    }
                }
                break;
            default: break;
        }

        updatePacket->setPacketLength(0); // TODO: Calculate correct length
        updatePacket->setChecksum(0); // TODO: Calculate correct cheksum(16-bit one's complement of the entire packet)

        return updatePacket;
    }
    return NULL;
}

void AnsaOSPF::Interface::AddDelayedAcknowledgement(OSPFLSAHeader& lsaHeader)
{
    if (interfaceType == AnsaOSPF::Interface::Broadcast) {
        if ((GetState() == AnsaOSPF::Interface::DesignatedRouterState) ||
            (GetState() == AnsaOSPF::Interface::BackupState) ||
            (designatedRouter == AnsaOSPF::NullDesignatedRouterID))
        {
            delayedAcknowledgements[AnsaOSPF::AllSPFRouters].push_back(lsaHeader);
        } else {
            delayedAcknowledgements[AnsaOSPF::AllDRouters].push_back(lsaHeader);
        }
    } else {
        long neighborCount = neighboringRouters.size();
        for (long i = 0; i < neighborCount; i++) {
            if (neighboringRouters[i]->GetState() >= AnsaOSPF::Neighbor::ExchangeState) {
                delayedAcknowledgements[neighboringRouters[i]->GetAddress()].push_back(lsaHeader);
            }
        }
    }
}

void AnsaOSPF::Interface::SendDelayedAcknowledgements(void)
{
    AnsaOSPF::MessageHandler* messageHandler = parentArea->GetRouter()->GetMessageHandler();
    long                  maxPacketSize  = ((IPV4_HEADER_LENGTH + OSPF_HEADER_LENGTH + OSPF_LSA_HEADER_LENGTH) > mtu) ? IPV4_DATAGRAM_LENGTH : mtu;

    for (std::map<IPv4Address, std::list<OSPFLSAHeader>, AnsaOSPF::IPv4Address_Less>::iterator delayIt = delayedAcknowledgements.begin();
         delayIt != delayedAcknowledgements.end();
         delayIt++)
    {
        int ackCount = delayIt->second.size();
        if (ackCount > 0) {
            while (!(delayIt->second.empty())) {
                OSPFLinkStateAcknowledgementPacket* ackPacket  = new OSPFLinkStateAcknowledgementPacket;
                long                                packetSize = IPV4_HEADER_LENGTH + OSPF_HEADER_LENGTH;

                ackPacket->setType(LinkStateAcknowledgementPacket);
                ackPacket->setRouterID(parentArea->GetRouter()->GetRouterID());
                ackPacket->setAreaID(areaID);
                ackPacket->setAuthenticationType(authenticationType);
                for (int i = 0; i < 8; i++) {
                    ackPacket->setAuthentication(i, authenticationKey.bytes[i]);
                }

                while ((!(delayIt->second.empty())) && (packetSize <= (maxPacketSize - OSPF_LSA_HEADER_LENGTH))) {
                    unsigned long   headerCount = ackPacket->getLsaHeadersArraySize();
                    ackPacket->setLsaHeadersArraySize(headerCount + 1);
                    ackPacket->setLsaHeaders(headerCount, *(delayIt->second.begin()));
                    delayIt->second.pop_front();
                    packetSize += OSPF_LSA_HEADER_LENGTH;
                }

                ackPacket->setPacketLength(0); // TODO: Calculate correct length
                ackPacket->setChecksum(0); // TODO: Calculate correct cheksum(16-bit one's complement of the entire packet)

                int ttl = (interfaceType == AnsaOSPF::Interface::Virtual) ? VIRTUAL_LINK_TTL : 1;

                if (interfaceType == AnsaOSPF::Interface::Broadcast) {
                    if ((GetState() == AnsaOSPF::Interface::DesignatedRouterState) ||
                        (GetState() == AnsaOSPF::Interface::BackupState) ||
                        (designatedRouter == AnsaOSPF::NullDesignatedRouterID))
                    {
                        messageHandler->SendPacket(ackPacket, AnsaOSPF::AllSPFRouters, ifIndex, ttl);
                    } else {
                        messageHandler->SendPacket(ackPacket, AnsaOSPF::AllDRouters, ifIndex, ttl);
                    }
                } else {
                    if (interfaceType == AnsaOSPF::Interface::PointToPoint) {
                        messageHandler->SendPacket(ackPacket, AnsaOSPF::AllSPFRouters, ifIndex, ttl);
                    } else {
                        messageHandler->SendPacket(ackPacket, delayIt->first, ifIndex, ttl);
                    }
                }
            }
        }
    }
    messageHandler->StartTimer(acknowledgementTimer, acknowledgementDelay);
}

void AnsaOSPF::Interface::AgeTransmittedLSALists(void)
{
    long neighborCount = neighboringRouters.size();
    for (long i = 0; i < neighborCount; i++) {
        neighboringRouters[i]->AgeTransmittedLSAList();
    }
}
