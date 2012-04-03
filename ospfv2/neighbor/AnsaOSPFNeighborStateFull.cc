#include "AnsaOSPFNeighborStateFull.h"
#include "AnsaOSPFNeighborStateDown.h"
#include "AnsaOSPFNeighborStateInit.h"
#include "AnsaOSPFNeighborStateTwoWay.h"
#include "AnsaOSPFNeighborStateExchangeStart.h"
#include "AnsaMessageHandler.h"
#include "AnsaOSPFInterface.h"
#include "AnsaOSPFArea.h"
#include "AnsaOSPFRouter.h"
#include <fstream>

void AnsaOSPF::NeighborStateFull::ProcessEvent(AnsaOSPF::Neighbor* neighbor, AnsaOSPF::Neighbor::NeighborEventType event)
{
    if ((event == AnsaOSPF::Neighbor::KillNeighbor) || (event == AnsaOSPF::Neighbor::LinkDown)) {
        MessageHandler* messageHandler = neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
        neighbor->Reset();
        messageHandler->ClearTimer(neighbor->GetInactivityTimer());
        ChangeState(neighbor, new AnsaOSPF::NeighborStateDown, this);
    }
    if (event == AnsaOSPF::Neighbor::InactivityTimer) {
        neighbor->Reset();
        if (neighbor->GetInterface()->GetType() == AnsaOSPF::Interface::NBMA) {
            MessageHandler* messageHandler = neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
            messageHandler->StartTimer(neighbor->GetPollTimer(), neighbor->GetInterface()->GetPollInterval());
        }
        ChangeState(neighbor, new AnsaOSPF::NeighborStateDown, this);
    }
    if (event == AnsaOSPF::Neighbor::OneWayReceived) {
        neighbor->Reset();
        ChangeState(neighbor, new AnsaOSPF::NeighborStateInit, this);
    }
    if (event == AnsaOSPF::Neighbor::HelloReceived) {
        MessageHandler* messageHandler = neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
        messageHandler->ClearTimer(neighbor->GetInactivityTimer());
        messageHandler->StartTimer(neighbor->GetInactivityTimer(), neighbor->GetRouterDeadInterval());
    }
    if (event == AnsaOSPF::Neighbor::IsAdjacencyOK) {
        if (!neighbor->NeedAdjacency()) {
            neighbor->Reset();
            ChangeState(neighbor, new AnsaOSPF::NeighborStateTwoWay, this);
        }
    }
    if ((event == AnsaOSPF::Neighbor::SequenceNumberMismatch) || (event == AnsaOSPF::Neighbor::BadLinkStateRequest)) {
        MessageHandler* messageHandler = neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
        neighbor->Reset();
        neighbor->IncrementDDSequenceNumber();
        neighbor->SendDatabaseDescriptionPacket(true);
        messageHandler->StartTimer(neighbor->GetDDRetransmissionTimer(), neighbor->GetInterface()->GetRetransmissionInterval());
        ChangeState(neighbor, new AnsaOSPF::NeighborStateExchangeStart, this);
    }
    if (event == AnsaOSPF::Neighbor::UpdateRetransmissionTimer) {
        neighbor->RetransmitUpdatePacket();
        neighbor->StartUpdateRetransmissionTimer();
    }
    if (event == AnsaOSPF::Neighbor::DDRetransmissionTimer) {
        neighbor->DeleteLastSentDDPacket();
    }
}
