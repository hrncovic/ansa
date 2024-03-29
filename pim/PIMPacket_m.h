//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/pim/PIMPacket.msg.
//

#ifndef _PIMPACKET_M_H_
#define _PIMPACKET_M_H_

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
 * Enum generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * enum PIMPacketType 
 * {
 *    Hello = 0;
 *    Register = 1;
 *    RegisterStop = 2;
 *    JoinPrune = 3;
 *    Bootstrap = 4;
 *    Assert = 5;
 *    Graft = 6;
 *    GraftAck = 7;
 *    CandidateRPAdvertisement = 8;
 *    StateRefresh = 9;
 * }
 * </pre>
 */
enum PIMPacketType {
    Hello = 0,
    Register = 1,
    RegisterStop = 2,
    JoinPrune = 3,
    Bootstrap = 4,
    Assert = 5,
    Graft = 6,
    GraftAck = 7,
    CandidateRPAdvertisement = 8,
    StateRefresh = 9
};

/**
 * Struct generated from ansa/pim/PIMPacket.msg by opp_msgc.
 */
struct HelloEntry
{
    HelloEntry();
    short Type;
    short Value;
};

void doPacking(cCommBuffer *b, HelloEntry& a);
void doUnpacking(cCommBuffer *b, HelloEntry& a);

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * class MulticastGroup
 * {
 * 	IPAddress 	groupAddress;
 * 	IPAddress 	joinedSourceAddress[]; 
 * 	IPAddress 	prunedSourceAddress[]; 
 * }
 * </pre>
 */
class MulticastGroup : public ::cObject
{
  protected:
    IPAddress groupAddress_var;
    IPAddress *joinedSourceAddress_var; // array ptr
    unsigned int joinedSourceAddress_arraysize;
    IPAddress *prunedSourceAddress_var; // array ptr
    unsigned int prunedSourceAddress_arraysize;

  private:
    void copy(const MulticastGroup& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const MulticastGroup&);

  public:
    MulticastGroup();
    MulticastGroup(const MulticastGroup& other);
    virtual ~MulticastGroup();
    MulticastGroup& operator=(const MulticastGroup& other);
    virtual MulticastGroup *dup() const {return new MulticastGroup(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual IPAddress& getGroupAddress();
    virtual const IPAddress& getGroupAddress() const {return const_cast<MulticastGroup*>(this)->getGroupAddress();}
    virtual void setGroupAddress(const IPAddress& groupAddress);
    virtual void setJoinedSourceAddressArraySize(unsigned int size);
    virtual unsigned int getJoinedSourceAddressArraySize() const;
    virtual IPAddress& getJoinedSourceAddress(unsigned int k);
    virtual const IPAddress& getJoinedSourceAddress(unsigned int k) const {return const_cast<MulticastGroup*>(this)->getJoinedSourceAddress(k);}
    virtual void setJoinedSourceAddress(unsigned int k, const IPAddress& joinedSourceAddress);
    virtual void setPrunedSourceAddressArraySize(unsigned int size);
    virtual unsigned int getPrunedSourceAddressArraySize() const;
    virtual IPAddress& getPrunedSourceAddress(unsigned int k);
    virtual const IPAddress& getPrunedSourceAddress(unsigned int k) const {return const_cast<MulticastGroup*>(this)->getPrunedSourceAddress(k);}
    virtual void setPrunedSourceAddress(unsigned int k, const IPAddress& prunedSourceAddress);
};

inline void doPacking(cCommBuffer *b, MulticastGroup& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, MulticastGroup& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMPacket 
 * {
 *    short 		version = 2;
 *    short 		type enum(PIMPacketType);							
 * }
 * </pre>
 */
class PIMPacket : public ::cPacket
{
  protected:
    short version_var;
    short type_var;

  private:
    void copy(const PIMPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMPacket&);

  public:
    PIMPacket(const char *name=NULL, int kind=0);
    PIMPacket(const PIMPacket& other);
    virtual ~PIMPacket();
    PIMPacket& operator=(const PIMPacket& other);
    virtual PIMPacket *dup() const {return new PIMPacket(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getVersion() const;
    virtual void setVersion(short version);
    virtual short getType() const;
    virtual void setType(short type);
};

inline void doPacking(cCommBuffer *b, PIMPacket& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMPacket& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMHello extends PIMPacket
 * {
 * 	short 			type enum(PIMPacketType) = Hello;
 * 	HelloEntry		helloContent[];	   
 * }
 * </pre>
 */
class PIMHello : public ::PIMPacket
{
  protected:
    short type_var;
    HelloEntry *helloContent_var; // array ptr
    unsigned int helloContent_arraysize;

  private:
    void copy(const PIMHello& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMHello&);

  public:
    PIMHello(const char *name=NULL, int kind=0);
    PIMHello(const PIMHello& other);
    virtual ~PIMHello();
    PIMHello& operator=(const PIMHello& other);
    virtual PIMHello *dup() const {return new PIMHello(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual void setHelloContentArraySize(unsigned int size);
    virtual unsigned int getHelloContentArraySize() const;
    virtual HelloEntry& getHelloContent(unsigned int k);
    virtual const HelloEntry& getHelloContent(unsigned int k) const {return const_cast<PIMHello*>(this)->getHelloContent(k);}
    virtual void setHelloContent(unsigned int k, const HelloEntry& helloContent);
};

inline void doPacking(cCommBuffer *b, PIMHello& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMHello& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMJoinPrune extends PIMPacket
 * {
 * 	short 			type enum(PIMPacketType) = JoinPrune;
 * 	IPAddress		upstreamNeighborAddress;	
 * 	int				holdTime;
 * 	
 * 	MulticastGroup	multicastGroups[];   
 * }
 * </pre>
 */
class PIMJoinPrune : public ::PIMPacket
{
  protected:
    short type_var;
    IPAddress upstreamNeighborAddress_var;
    int holdTime_var;
    MulticastGroup *multicastGroups_var; // array ptr
    unsigned int multicastGroups_arraysize;

  private:
    void copy(const PIMJoinPrune& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMJoinPrune&);

  public:
    PIMJoinPrune(const char *name=NULL, int kind=0);
    PIMJoinPrune(const PIMJoinPrune& other);
    virtual ~PIMJoinPrune();
    PIMJoinPrune& operator=(const PIMJoinPrune& other);
    virtual PIMJoinPrune *dup() const {return new PIMJoinPrune(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual IPAddress& getUpstreamNeighborAddress();
    virtual const IPAddress& getUpstreamNeighborAddress() const {return const_cast<PIMJoinPrune*>(this)->getUpstreamNeighborAddress();}
    virtual void setUpstreamNeighborAddress(const IPAddress& upstreamNeighborAddress);
    virtual int getHoldTime() const;
    virtual void setHoldTime(int holdTime);
    virtual void setMulticastGroupsArraySize(unsigned int size);
    virtual unsigned int getMulticastGroupsArraySize() const;
    virtual MulticastGroup& getMulticastGroups(unsigned int k);
    virtual const MulticastGroup& getMulticastGroups(unsigned int k) const {return const_cast<PIMJoinPrune*>(this)->getMulticastGroups(k);}
    virtual void setMulticastGroups(unsigned int k, const MulticastGroup& multicastGroups);
};

inline void doPacking(cCommBuffer *b, PIMJoinPrune& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMJoinPrune& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMAssert extends PIMPacket
 * {
 * 	short 			type enum(PIMPacketType) = Assert;
 * 	IPAddress		groupAddress;
 * 	IPAddress		sourceAddress;	
 * 	bool			R;
 * 	int				metric;   
 * 	int				metricPreference;   
 * }
 * </pre>
 */
class PIMAssert : public ::PIMPacket
{
  protected:
    short type_var;
    IPAddress groupAddress_var;
    IPAddress sourceAddress_var;
    bool R_var;
    int metric_var;
    int metricPreference_var;

  private:
    void copy(const PIMAssert& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMAssert&);

  public:
    PIMAssert(const char *name=NULL, int kind=0);
    PIMAssert(const PIMAssert& other);
    virtual ~PIMAssert();
    PIMAssert& operator=(const PIMAssert& other);
    virtual PIMAssert *dup() const {return new PIMAssert(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual IPAddress& getGroupAddress();
    virtual const IPAddress& getGroupAddress() const {return const_cast<PIMAssert*>(this)->getGroupAddress();}
    virtual void setGroupAddress(const IPAddress& groupAddress);
    virtual IPAddress& getSourceAddress();
    virtual const IPAddress& getSourceAddress() const {return const_cast<PIMAssert*>(this)->getSourceAddress();}
    virtual void setSourceAddress(const IPAddress& sourceAddress);
    virtual bool getR() const;
    virtual void setR(bool R);
    virtual int getMetric() const;
    virtual void setMetric(int metric);
    virtual int getMetricPreference() const;
    virtual void setMetricPreference(int metricPreference);
};

inline void doPacking(cCommBuffer *b, PIMAssert& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMAssert& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMGraft extends PIMJoinPrune
 * {
 * 	short 			type enum(PIMPacketType) = Graft;	
 * 	int				holdTime = 0; 
 * }
 * </pre>
 */
class PIMGraft : public ::PIMJoinPrune
{
  protected:
    short type_var;
    int holdTime_var;

  private:
    void copy(const PIMGraft& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMGraft&);

  public:
    PIMGraft(const char *name=NULL, int kind=0);
    PIMGraft(const PIMGraft& other);
    virtual ~PIMGraft();
    PIMGraft& operator=(const PIMGraft& other);
    virtual PIMGraft *dup() const {return new PIMGraft(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual int getHoldTime() const;
    virtual void setHoldTime(int holdTime);
};

inline void doPacking(cCommBuffer *b, PIMGraft& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMGraft& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMGraftAck extends PIMJoinPrune
 * {
 * 	short 			type enum(PIMPacketType) = GraftAck;	
 * 	int				holdTime = 0; 
 * }
 * </pre>
 */
class PIMGraftAck : public ::PIMJoinPrune
{
  protected:
    short type_var;
    int holdTime_var;

  private:
    void copy(const PIMGraftAck& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMGraftAck&);

  public:
    PIMGraftAck(const char *name=NULL, int kind=0);
    PIMGraftAck(const PIMGraftAck& other);
    virtual ~PIMGraftAck();
    PIMGraftAck& operator=(const PIMGraftAck& other);
    virtual PIMGraftAck *dup() const {return new PIMGraftAck(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual int getHoldTime() const;
    virtual void setHoldTime(int holdTime);
};

inline void doPacking(cCommBuffer *b, PIMGraftAck& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMGraftAck& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMStateRefresh extends PIMPacket
 * {
 * 	short 			type enum(PIMPacketType) = StateRefresh;	
 * 	IPAddress		groupAddress;
 * 	IPAddress		sourceAddress;	
 * 	IPAddress		originatorAddress;	
 * 	int				metric;   
 * 	int				metricPreference;  
 * 	short			maskLen;
 * 	short			ttl;
 * 	bool			P;
 * 	int				interval; 
 * }
 * </pre>
 */
class PIMStateRefresh : public ::PIMPacket
{
  protected:
    short type_var;
    IPAddress groupAddress_var;
    IPAddress sourceAddress_var;
    IPAddress originatorAddress_var;
    int metric_var;
    int metricPreference_var;
    short maskLen_var;
    short ttl_var;
    bool P_var;
    int interval_var;

  private:
    void copy(const PIMStateRefresh& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMStateRefresh&);

  public:
    PIMStateRefresh(const char *name=NULL, int kind=0);
    PIMStateRefresh(const PIMStateRefresh& other);
    virtual ~PIMStateRefresh();
    PIMStateRefresh& operator=(const PIMStateRefresh& other);
    virtual PIMStateRefresh *dup() const {return new PIMStateRefresh(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual IPAddress& getGroupAddress();
    virtual const IPAddress& getGroupAddress() const {return const_cast<PIMStateRefresh*>(this)->getGroupAddress();}
    virtual void setGroupAddress(const IPAddress& groupAddress);
    virtual IPAddress& getSourceAddress();
    virtual const IPAddress& getSourceAddress() const {return const_cast<PIMStateRefresh*>(this)->getSourceAddress();}
    virtual void setSourceAddress(const IPAddress& sourceAddress);
    virtual IPAddress& getOriginatorAddress();
    virtual const IPAddress& getOriginatorAddress() const {return const_cast<PIMStateRefresh*>(this)->getOriginatorAddress();}
    virtual void setOriginatorAddress(const IPAddress& originatorAddress);
    virtual int getMetric() const;
    virtual void setMetric(int metric);
    virtual int getMetricPreference() const;
    virtual void setMetricPreference(int metricPreference);
    virtual short getMaskLen() const;
    virtual void setMaskLen(short maskLen);
    virtual short getTtl() const;
    virtual void setTtl(short ttl);
    virtual bool getP() const;
    virtual void setP(bool P);
    virtual int getInterval() const;
    virtual void setInterval(int interval);
};

inline void doPacking(cCommBuffer *b, PIMStateRefresh& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMStateRefresh& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMRegister extends PIMPacket
 * {
 * 	short 			type enum(PIMPacketType) = Register;	
 * 	bool			B;
 * 	bool			N;
 * 	
 * }
 * </pre>
 */
class PIMRegister : public ::PIMPacket
{
  protected:
    short type_var;
    bool B_var;
    bool N_var;

  private:
    void copy(const PIMRegister& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMRegister&);

  public:
    PIMRegister(const char *name=NULL, int kind=0);
    PIMRegister(const PIMRegister& other);
    virtual ~PIMRegister();
    PIMRegister& operator=(const PIMRegister& other);
    virtual PIMRegister *dup() const {return new PIMRegister(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual bool getB() const;
    virtual void setB(bool B);
    virtual bool getN() const;
    virtual void setN(bool N);
};

inline void doPacking(cCommBuffer *b, PIMRegister& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMRegister& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>ansa/pim/PIMPacket.msg</tt> by opp_msgc.
 * <pre>
 * packet PIMRegisterStop extends PIMPacket
 * {
 * 	short 			type enum(PIMPacketType) = RegisterStop;	
 * 	IPAddress		groupAddress;
 * 	IPAddress		sourceAddress;
 * }
 * </pre>
 */
class PIMRegisterStop : public ::PIMPacket
{
  protected:
    short type_var;
    IPAddress groupAddress_var;
    IPAddress sourceAddress_var;

  private:
    void copy(const PIMRegisterStop& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PIMRegisterStop&);

  public:
    PIMRegisterStop(const char *name=NULL, int kind=0);
    PIMRegisterStop(const PIMRegisterStop& other);
    virtual ~PIMRegisterStop();
    PIMRegisterStop& operator=(const PIMRegisterStop& other);
    virtual PIMRegisterStop *dup() const {return new PIMRegisterStop(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual IPAddress& getGroupAddress();
    virtual const IPAddress& getGroupAddress() const {return const_cast<PIMRegisterStop*>(this)->getGroupAddress();}
    virtual void setGroupAddress(const IPAddress& groupAddress);
    virtual IPAddress& getSourceAddress();
    virtual const IPAddress& getSourceAddress() const {return const_cast<PIMRegisterStop*>(this)->getSourceAddress();}
    virtual void setSourceAddress(const IPAddress& sourceAddress);
};

inline void doPacking(cCommBuffer *b, PIMRegisterStop& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, PIMRegisterStop& obj) {obj.parsimUnpack(b);}


#endif // _PIMPACKET_M_H_
