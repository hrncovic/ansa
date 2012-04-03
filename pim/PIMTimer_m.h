//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/pim/PIMTimer.msg.
//

#ifndef _PIMTIMER_M_H_
#define _PIMTIMER_M_H_

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
 * Enum generated from <tt>ansa/pim/PIMTimer.msg</tt> by opp_msgc.
 * <pre>
 * enum PIMTimerType
 * {
 *     
 *    HelloTimer = 1;
 *    TriggeredHelloDelay = 2;
 *    
 *    
 *    NeighborLivnessTimer = 3;
 *    
 *    
 *    AssertTimer = 4;
 *    PruneTimer = 5;
 *    PrunePendingTimer = 6;
 *    
 *    
 *    GrafRetryTimer = 7;
 *    UpstreamOverrideTimer = 8;
 *    PruneLimitTimer = 9;
 *    SourceActiveTimer = 10;
 *    StateRefreshTimer = 11;
 * }
 * </pre>
 */
enum PIMTimerType {
    HelloTimer = 1,
    TriggeredHelloDelay = 2,
    NeighborLivnessTimer = 3,
    AssertTimer = 4,
    PruneTimer = 5,
    PrunePendingTimer = 6,
    GrafRetryTimer = 7,
    UpstreamOverrideTimer = 8,
    PruneLimitTimer = 9,
    SourceActiveTimer = 10,
    StateRefreshTimer = 11
};

/**
 * Class generated from <tt>ansa/pim/PIMTimer.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMTimer extends cMessage
 * {
 *       char 		timerKind enum(PIMTimerType);
 * }
 * </pre>
 */
class PIMTimer : public ::cMessage
{
  protected:
    char timerKind_var;

  private:
    void copy(const PIMTimer& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMTimer&);

  public:
    PIMTimer(const char *name=NULL, int kind=0);
    PIMTimer(const PIMTimer& other);
    virtual ~PIMTimer();
    PIMTimer& operator=(const PIMTimer& other);
    virtual PIMTimer *dup() const {return new PIMTimer(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual char getTimerKind() const;
    virtual void setTimerKind(char timerKind);
};

inline void doPacking(cCommBuffer *b, PIMTimer& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMTimer& obj) {obj.parsimUnpack(b);}


#endif // _PIMTIMER_M_H_
