#include "AnsaOSPFInterfaceStateBackup.h"
#include "AnsaOSPFInterfaceStateDown.h"
#include "AnsaOSPFInterfaceStateLoopback.h"
#include "AnsaOSPFArea.h"
#include "AnsaOSPFRouter.h"
#include "AnsaMessageHandler.h"

void AnsaOSPF::InterfaceStateBackup::ProcessEvent(AnsaOSPF::Interface* intf, AnsaOSPF::Interface::InterfaceEventType event)
{
    if (event == AnsaOSPF::Interface::NeighborChange) {
        CalculateDesignatedRouter(intf);
    }
    if (event == AnsaOSPF::Interface::InterfaceDown) {
        intf->SetIsGoingDown(true);
        intf->Reset();
        ChangeState(intf, new AnsaOSPF::InterfaceStateDown, this);
        intf->SetIsGoingDown(false);
    }
    if (event == AnsaOSPF::Interface::LoopIndication) {
        intf->Reset();
        ChangeState(intf, new AnsaOSPF::InterfaceStateLoopback, this);
    }
    if (event == AnsaOSPF::Interface::HelloTimer) {
        if (intf->GetType() == AnsaOSPF::Interface::Broadcast) {
            intf->SendHelloPacket(AnsaOSPF::AllSPFRouters);
        } else {    // AnsaOSPF::Interface::NBMA
            unsigned long neighborCount = intf->GetNeighborCount();
            int           ttl           = (intf->GetType() == AnsaOSPF::Interface::Virtual) ? VIRTUAL_LINK_TTL : 1;
            for (unsigned long i = 0; i < neighborCount; i++) {
                intf->SendHelloPacket(intf->GetNeighbor(i)->GetAddress(), ttl);
            }
        }
        intf->GetArea()->GetRouter()->GetMessageHandler()->StartTimer(intf->GetHelloTimer(), intf->GetHelloInterval());
    }
    if (event == AnsaOSPF::Interface::AcknowledgementTimer) {
        intf->SendDelayedAcknowledgements();
    }
}

