//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/rip/RIPPacket.msg.
//

#ifndef _RIPPACKET_M_H_
#define _RIPPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "IPAddress.h"
// }}



/**
 * Enum generated from <tt>ansa/rip/RIPPacket.msg</tt> by opp_msgc.
 * <pre>
 * enum RIPCommand
 * {
 *     Request = 1;
 *     Response = 2;
 * }
 * </pre>
 */
enum RIPCommand {
    Request = 1,
    Response = 2
};

/**
 * Struct generated from ansa/rip/RIPPacket.msg by opp_msgc.
 */
struct RouteEntry
{
    RouteEntry();
    short addressID;
    short mustBeZero2;
    IPAddress ipAddress;
    long mustBeZero3;
    long mustBeZero4;
    long metric;
};

void doPacking(cCommBuffer *b, RouteEntry& a);
void doUnpacking(cCommBuffer *b, RouteEntry& a);

/**
 * Class generated from <tt>ansa/rip/RIPPacket.msg</tt> by opp_msgc.
 * <pre>
 * message RIPPacket
 * {
 *     char 		command enum(RIPCommand);
 *     char 		version = 1;
 *     short 		mustBeZero1 = 0;
 *     RouteEntry 	routeEntry[];
 * }
 * </pre>
 */
class RIPPacket : public ::cMessage
{
  protected:
    char command_var;
    char version_var;
    short mustBeZero1_var;
    RouteEntry *routeEntry_var; // array ptr
    unsigned int routeEntry_arraysize;

  private:
    void copy(const RIPPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RIPPacket&);

  public:
    RIPPacket(const char *name=NULL, int kind=0);
    RIPPacket(const RIPPacket& other);
    virtual ~RIPPacket();
    RIPPacket& operator=(const RIPPacket& other);
    virtual RIPPacket *dup() const {return new RIPPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual char getCommand() const;
    virtual void setCommand(char command);
    virtual char getVersion() const;
    virtual void setVersion(char version);
    virtual short getMustBeZero1() const;
    virtual void setMustBeZero1(short mustBeZero1);
    virtual void setRouteEntryArraySize(unsigned int size);
    virtual unsigned int getRouteEntryArraySize() const;
    virtual RouteEntry& getRouteEntry(unsigned int k);
    virtual const RouteEntry& getRouteEntry(unsigned int k) const {return const_cast<RIPPacket*>(this)->getRouteEntry(k);}
    virtual void setRouteEntry(unsigned int k, const RouteEntry& routeEntry);
};

inline void doPacking(cCommBuffer *b, RIPPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RIPPacket& obj) {obj.parsimUnpack(b);}


#endif // _RIPPACKET_M_H_
