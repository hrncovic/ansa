#ifndef __INET_OSPFNEIGHBORSTATETWOWAY_H
#define __INET_OSPFNEIGHBORSTATETWOWAY_H

#include "AnsaOSPFNeighborState.h"

namespace AnsaOSPF {

class NeighborStateTwoWay : public NeighborState
{
public:
    virtual void ProcessEvent(Neighbor* neighbor, Neighbor::NeighborEventType event);
    virtual Neighbor::NeighborStateType GetState(void) const { return Neighbor::TwoWayState; }
};

} // namespace AnsaOSPF

#endif // __INET_OSPFNEIGHBORSTATETWOWAY_H

