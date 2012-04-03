#ifndef __INET_OSPFROUTINGTABLEENTRY_H
#define __INET_OSPFROUTINGTABLEENTRY_H

#include "IRoutingTable.h"
#include "InterfaceTableAccess.h"
#include "AnsaOSPFcommon.h"
#include <memory.h>

namespace AnsaOSPF {

class RoutingTableEntry : public IPRoute
{
public:
    enum RoutingPathType {
        IntraArea     = 0,
        InterArea     = 1,
        Type1External = 2,
        Type2External = 3
    };

    typedef unsigned char RoutingDestinationType;

    // destinationType bitfield values
    static const unsigned char NetworkDestination = 0;
    static const unsigned char AreaBorderRouterDestination = 1;
    static const unsigned char ASBoundaryRouterDestination = 2;

private:
    RoutingDestinationType  destinationType;
    // destinationID is IPRoute::host
    // addressMask is IPRoute::netmask
    OSPFOptions             optionalCapabilities;
    AreaID                  area;
    RoutingPathType         pathType;
    Metric                  cost;
    Metric                  type2Cost;
    const OSPFLSA*          linkStateOrigin;
    std::vector<NextHop>    nextHops;
    // IPRoute::interfacePtr comes from nextHops[0].ifIndex
    // IPRoute::gateway is nextHops[0].hopAddress

public:
            RoutingTableEntry  (void);
            RoutingTableEntry  (const RoutingTableEntry& entry);
    virtual ~RoutingTableEntry(void) {}

    bool    operator== (const RoutingTableEntry& entry) const;
    bool    operator!= (const RoutingTableEntry& entry) const { return (!((*this) == entry)); }

    void                    SetDestinationType      (RoutingDestinationType type)   { destinationType = type; }
    RoutingDestinationType  GetDestinationType      (void) const                    { return destinationType; }
    void                    SetDestinationID        (IPAddress destID)              { host = destID; }
    IPAddress               GetDestinationID        (void) const                    { return host; }
    void                    SetAddressMask          (IPAddress destMask)            { netmask = destMask; }
    IPAddress               GetAddressMask          (void) const                    { return netmask; }
    void                    SetOptionalCapabilities(OSPFOptions options)           { optionalCapabilities = options; }
    OSPFOptions             GetOptionalCapabilities(void) const                    { return optionalCapabilities; }
    void                    SetArea                 (AreaID source)                 { area = source; }
    AreaID                  GetArea                 (void) const                    { return area; }
    void                    SetPathType             (RoutingPathType type);
    RoutingPathType         GetPathType             (void) const                    { return pathType; }
    void                    SetCost                 (Metric pathCost);
    Metric                  GetCost                 (void) const                    { return cost; }
    void                    SetType2Cost            (Metric pathCost);
    Metric                  GetType2Cost            (void) const                    { return type2Cost; }
    void                    SetLinkStateOrigin      (const OSPFLSA* lsa)            { linkStateOrigin = lsa; }
    const OSPFLSA*          GetLinkStateOrigin      (void) const                    { return linkStateOrigin; }
    void                    AddNextHop              (NextHop hop);
    void                    ClearNextHops           (void)                          { nextHops.clear(); }
    unsigned int            GetNextHopCount         (void) const                    { return nextHops.size(); }
    NextHop                 GetNextHop              (unsigned int index) const      { return nextHops[index]; }
};

} // namespace AnsaOSPF

inline AnsaOSPF::RoutingTableEntry::RoutingTableEntry(void) :
    IPRoute(),
    destinationType(AnsaOSPF::RoutingTableEntry::NetworkDestination),
    area(AnsaOSPF::BackboneAreaID),
    pathType(AnsaOSPF::RoutingTableEntry::IntraArea),
    type2Cost(0),
    linkStateOrigin(NULL)
{
    netmask = 0xFFFFFFFF;
    source  = IPRoute::OSPF;
    memset(&optionalCapabilities, 0, sizeof(OSPFOptions));
}

inline AnsaOSPF::RoutingTableEntry::RoutingTableEntry(const RoutingTableEntry& entry) :
    destinationType(entry.destinationType),
    optionalCapabilities(entry.optionalCapabilities),
    area(entry.area),
    pathType(entry.pathType),
    cost(entry.cost),
    type2Cost(entry.type2Cost),
    linkStateOrigin(entry.linkStateOrigin),
    nextHops(entry.nextHops)
{
    host          = entry.host;
    netmask       = entry.netmask;
    gateway       = entry.gateway;
    interfacePtr  = entry.interfacePtr;
    type          = entry.type;
    source        = entry.source;
    metric        = entry.metric;
}

inline void AnsaOSPF::RoutingTableEntry::SetPathType(RoutingPathType type)
{
    pathType = type;
    // FIXME: this is a hack. But the correct way to do it is to implement a separate IRoutingTable module for OSPF...
    if (pathType == AnsaOSPF::RoutingTableEntry::Type2External) {
        metric = cost + type2Cost * 1000;
    } else {
        metric = cost;
    }
}

inline void AnsaOSPF::RoutingTableEntry::SetCost(Metric pathCost)
{
    cost = pathCost;
    // FIXME: this is a hack. But the correct way to do it is to implement a separate IRoutingTable module for OSPF...
    if (pathType == AnsaOSPF::RoutingTableEntry::Type2External) {
        metric = cost + type2Cost * 1000;
    } else {
        metric = cost;
    }
}

inline void AnsaOSPF::RoutingTableEntry::SetType2Cost(Metric pathCost)
{
    type2Cost = pathCost;
    // FIXME: this is a hack. But the correct way to do it is to implement a separate IRoutingTable module for OSPF...
    if (pathType == AnsaOSPF::RoutingTableEntry::Type2External) {
        metric = cost + type2Cost * 1000;
    } else {
        metric = cost;
    }
}

inline void AnsaOSPF::RoutingTableEntry::AddNextHop(AnsaOSPF::NextHop hop)
{
    if (nextHops.size() == 0) {
        InterfaceEntry*    routingInterface = InterfaceTableAccess().get()->getInterfaceById(hop.ifIndex);

        interfacePtr = routingInterface;
        gateway = ULongFromIPv4Address(hop.hopAddress); // TODO: verify this isn't necessary
    }
    nextHops.push_back(hop);
}

inline bool AnsaOSPF::RoutingTableEntry::operator== (const RoutingTableEntry& entry) const
{
    unsigned int hopCount = nextHops.size();
    unsigned int i        = 0;

    if (hopCount != entry.nextHops.size()) {
        return false;
    }
    for (i = 0; i < hopCount; i++) {
        if ((nextHops[i] != entry.nextHops[i]))
        {
            return false;
        }
    }

    return ((destinationType      == entry.destinationType)      &&
            (host                 == entry.host)                 &&
            (netmask              == entry.netmask)              &&
            (optionalCapabilities == entry.optionalCapabilities) &&
            (area                 == entry.area)                 &&
            (pathType             == entry.pathType)             &&
            (cost                 == entry.cost)                 &&
            (type2Cost            == entry.type2Cost)            &&
            (linkStateOrigin      == entry.linkStateOrigin));
}

inline std::ostream& operator<< (std::ostream& out, const AnsaOSPF::RoutingTableEntry& entry)
{
    out << "Destination: "
        << entry.GetDestinationID().str()
        << "/"
        << entry.GetAddressMask().str()
        << " (";
    if (entry.GetDestinationType() == AnsaOSPF::RoutingTableEntry::NetworkDestination) {
        out << "Network";
    } else {
        if ((entry.GetDestinationType() & AnsaOSPF::RoutingTableEntry::AreaBorderRouterDestination) != 0) {
            out << "AreaBorderRouter";
        }
        if ((entry.GetDestinationType() & (AnsaOSPF::RoutingTableEntry::ASBoundaryRouterDestination | AnsaOSPF::RoutingTableEntry::AreaBorderRouterDestination)) != 0) {
            out << "+";
        }
        if ((entry.GetDestinationType() & AnsaOSPF::RoutingTableEntry::ASBoundaryRouterDestination) != 0) {
            out << "ASBoundaryRouter";
        }
    }
    out << "), Area: "
        << entry.GetArea()
        << ", PathType: ";
    switch (entry.GetPathType()) {
        case AnsaOSPF::RoutingTableEntry::IntraArea:     out << "IntraArea";     break;
        case AnsaOSPF::RoutingTableEntry::InterArea:     out << "InterArea";     break;
        case AnsaOSPF::RoutingTableEntry::Type1External: out << "Type1External"; break;
        case AnsaOSPF::RoutingTableEntry::Type2External: out << "Type2External"; break;
        default:            out << "Unknown";       break;
    }
    out << ", Cost: "
        << entry.GetCost()
        << ", Type2Cost: "
        << entry.GetType2Cost()
        << ", Origin: [";
    PrintLSAHeader(entry.GetLinkStateOrigin()->getHeader(), out);
    out << "], NextHops: ";

    unsigned int hopCount = entry.GetNextHopCount();
    for (unsigned int i = 0; i < hopCount; i++) {
        char addressString[16];
        out << AddressStringFromIPv4Address(addressString, sizeof(addressString), entry.GetNextHop(i).hopAddress)
            << " ";
    }

    return out;
}

#endif // __INET_OSPFROUTINGTABLEENTRY_H
