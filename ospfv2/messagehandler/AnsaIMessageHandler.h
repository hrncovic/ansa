#ifndef __INET_IMESSAGEHANDLER_H
#define __INET_IMESSAGEHANDLER_H

#include "OSPFPacket_m.h"

namespace AnsaOSPF {

class Router;
class Interface;
class Neighbor;

class IMessageHandler
{
protected:
    Router* router;

public:
    IMessageHandler(Router* containingRouter)  { router = containingRouter; }
    virtual ~IMessageHandler() {}

    virtual void    ProcessPacket(OSPFPacket*, Interface* intf, Neighbor* neighbor) = 0;
};

} // namespace AnsaOSPF

#endif // __INET_IMESSAGEHANDLER_H
