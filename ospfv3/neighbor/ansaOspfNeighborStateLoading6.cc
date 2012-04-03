//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "ansaOspfArea6.h"
#include "ansaOspfInterface6.h"
#include "ansaOspfRouter6.h"
#include "ansaMessageHandler6.h"

#include "ansaOspfNeighborStateDown6.h"
#include "ansaOspfNeighborStateExchangeStart6.h"
#include "ansaOspfNeighborStateFull6.h"
#include "ansaOspfNeighborStateInit6.h"
#include "ansaOspfNeighborStateLoading6.h"
#include "ansaOspfNeighborStateTwoWay6.h"

void AnsaOspf6::NeighborStateLoading::ProcessEvent(AnsaOspf6::Neighbor* neighbor,
      AnsaOspf6::Neighbor::NeighborEventType event) {
   if ((event == AnsaOspf6::Neighbor::KillNeighbor) || (event == AnsaOspf6::Neighbor::LinkDown)){
      MessageHandler* messageHandler =
            neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
      neighbor->Reset();
      messageHandler->ClearTimer(neighbor->GetInactivityTimer());
      ChangeState(neighbor, new AnsaOspf6::NeighborStateDown, this);
   }
   if (event == AnsaOspf6::Neighbor::InactivityTimer){
      neighbor->Reset();
      if (neighbor->GetInterface()->GetType() == AnsaOspf6::Interface::NBMA){
         MessageHandler* messageHandler =
               neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
         messageHandler->StartTimer(neighbor->GetPollTimer(),
               neighbor->GetInterface()->GetPollInterval());
      }
      ChangeState(neighbor, new AnsaOspf6::NeighborStateDown, this);
   }
   if (event == AnsaOspf6::Neighbor::OneWayReceived){
      neighbor->Reset();
      ChangeState(neighbor, new AnsaOspf6::NeighborStateInit, this);
   }
   if (event == AnsaOspf6::Neighbor::HelloReceived){
      MessageHandler* messageHandler =
            neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
      messageHandler->ClearTimer(neighbor->GetInactivityTimer());
      messageHandler->StartTimer(neighbor->GetInactivityTimer(), neighbor->GetRouterDeadInterval());
   }
   if (event == AnsaOspf6::Neighbor::LoadingDone){
      neighbor->ClearRequestRetransmissionTimer();
      ChangeState(neighbor, new AnsaOspf6::NeighborStateFull, this);
   }
   if (event == AnsaOspf6::Neighbor::IsAdjacencyOK){
      if (!neighbor->NeedAdjacency()){
         neighbor->Reset();
         ChangeState(neighbor, new AnsaOspf6::NeighborStateTwoWay, this);
      }
   }
   if ((event == AnsaOspf6::Neighbor::SequenceNumberMismatch) || (event
         == AnsaOspf6::Neighbor::BadLinkStateRequest)){
      MessageHandler* messageHandler =
            neighbor->GetInterface()->GetArea()->GetRouter()->GetMessageHandler();
      neighbor->Reset();
      neighbor->IncrementDDSequenceNumber();
      neighbor->SendDatabaseDescriptionPacket(true);
      messageHandler->StartTimer(neighbor->GetDDRetransmissionTimer(),
            neighbor->GetInterface()->GetRetransmissionInterval());
      ChangeState(neighbor, new AnsaOspf6::NeighborStateExchangeStart, this);
   }
   if (event == AnsaOspf6::Neighbor::RequestRetransmissionTimer){
      neighbor->SendLinkStateRequestPacket();
      neighbor->StartRequestRetransmissionTimer();
   }
   if (event == AnsaOspf6::Neighbor::UpdateRetransmissionTimer){
      neighbor->RetransmitUpdatePacket();
      neighbor->StartUpdateRetransmissionTimer();
   }
   if (event == AnsaOspf6::Neighbor::DDRetransmissionTimer){
      neighbor->DeleteLastSentDDPacket();
   }
}
