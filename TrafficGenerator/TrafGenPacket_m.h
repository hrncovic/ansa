//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/TrafficGenerator/TrafGenPacket.msg.
//

#ifndef _TRAFGENPACKET_M_H_
#define _TRAFGENPACKET_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0402
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// cplusplus {{
#include "INETDefs.h"
// }}



/**
 * Class generated from <tt>ansa/TrafficGenerator/TrafGenPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet TrafGenPacket
 * {
 *     string flowId;
 *     double sentTime;
 *     string application;
 * }
 * </pre>
 */
class TrafGenPacket : public ::cPacket
{
  protected:
    opp_string flowId_var;
    double sentTime_var;
    opp_string application_var;

  private:
    void copy(const TrafGenPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TrafGenPacket&);

  public:
    TrafGenPacket(const char *name=NULL, int kind=0);
    TrafGenPacket(const TrafGenPacket& other);
    virtual ~TrafGenPacket();
    TrafGenPacket& operator=(const TrafGenPacket& other);
    virtual TrafGenPacket *dup() const {return new TrafGenPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual const char * getFlowId() const;
    virtual void setFlowId(const char * flowId);
    virtual double getSentTime() const;
    virtual void setSentTime(double sentTime);
    virtual const char * getApplication() const;
    virtual void setApplication(const char * application);
};

inline void doPacking(cCommBuffer *b, TrafGenPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TrafGenPacket& obj) {obj.parsimUnpack(b);}


#endif // _TRAFGENPACKET_M_H_
