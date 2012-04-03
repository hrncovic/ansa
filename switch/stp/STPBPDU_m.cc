//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/switch/stp/STPBPDU.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "STPBPDU_m.h"

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




Register_Class(STPBPDU);

STPBPDU::STPBPDU(const char *name, int kind) : cPacket(name,kind)
{
    this->portRole_var = 0;
    this->tc_var = 0;
    this->tca_var = 0;
    this->vlan_var = 0;
    this->bridgePriority_var = 0;
    this->rootPathCost_var = 0;
    this->rootPriority_var = 0;
    this->portID_var = 0;
    this->portPriority_var = 0;
    this->msgAge_var = 0;
    this->maxAge_var = 0;
    this->helloTime_var = 0;
    this->fwdDelay_var = 0;
}

STPBPDU::STPBPDU(const STPBPDU& other) : cPacket(other)
{
    copy(other);
}

STPBPDU::~STPBPDU()
{
}

STPBPDU& STPBPDU::operator=(const STPBPDU& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void STPBPDU::copy(const STPBPDU& other)
{
    this->portRole_var = other.portRole_var;
    this->tc_var = other.tc_var;
    this->tca_var = other.tca_var;
    this->vlan_var = other.vlan_var;
    this->bridgeID_var = other.bridgeID_var;
    this->bridgePriority_var = other.bridgePriority_var;
    this->rootPathCost_var = other.rootPathCost_var;
    this->rootID_var = other.rootID_var;
    this->rootPriority_var = other.rootPriority_var;
    this->portID_var = other.portID_var;
    this->portPriority_var = other.portPriority_var;
    this->msgAge_var = other.msgAge_var;
    this->maxAge_var = other.maxAge_var;
    this->helloTime_var = other.helloTime_var;
    this->fwdDelay_var = other.fwdDelay_var;
}

void STPBPDU::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->portRole_var);
    doPacking(b,this->tc_var);
    doPacking(b,this->tca_var);
    doPacking(b,this->vlan_var);
    doPacking(b,this->bridgeID_var);
    doPacking(b,this->bridgePriority_var);
    doPacking(b,this->rootPathCost_var);
    doPacking(b,this->rootID_var);
    doPacking(b,this->rootPriority_var);
    doPacking(b,this->portID_var);
    doPacking(b,this->portPriority_var);
    doPacking(b,this->msgAge_var);
    doPacking(b,this->maxAge_var);
    doPacking(b,this->helloTime_var);
    doPacking(b,this->fwdDelay_var);
}

void STPBPDU::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->portRole_var);
    doUnpacking(b,this->tc_var);
    doUnpacking(b,this->tca_var);
    doUnpacking(b,this->vlan_var);
    doUnpacking(b,this->bridgeID_var);
    doUnpacking(b,this->bridgePriority_var);
    doUnpacking(b,this->rootPathCost_var);
    doUnpacking(b,this->rootID_var);
    doUnpacking(b,this->rootPriority_var);
    doUnpacking(b,this->portID_var);
    doUnpacking(b,this->portPriority_var);
    doUnpacking(b,this->msgAge_var);
    doUnpacking(b,this->maxAge_var);
    doUnpacking(b,this->helloTime_var);
    doUnpacking(b,this->fwdDelay_var);
}

unsigned int STPBPDU::getPortRole() const
{
    return portRole_var;
}

void STPBPDU::setPortRole(unsigned int portRole)
{
    this->portRole_var = portRole;
}

bool STPBPDU::getTc() const
{
    return tc_var;
}

void STPBPDU::setTc(bool tc)
{
    this->tc_var = tc;
}

bool STPBPDU::getTca() const
{
    return tca_var;
}

void STPBPDU::setTca(bool tca)
{
    this->tca_var = tca;
}

unsigned int STPBPDU::getVlan() const
{
    return vlan_var;
}

void STPBPDU::setVlan(unsigned int vlan)
{
    this->vlan_var = vlan;
}

MACAddress& STPBPDU::getBridgeID()
{
    return bridgeID_var;
}

void STPBPDU::setBridgeID(const MACAddress& bridgeID)
{
    this->bridgeID_var = bridgeID;
}

unsigned int STPBPDU::getBridgePriority() const
{
    return bridgePriority_var;
}

void STPBPDU::setBridgePriority(unsigned int bridgePriority)
{
    this->bridgePriority_var = bridgePriority;
}

unsigned long STPBPDU::getRootPathCost() const
{
    return rootPathCost_var;
}

void STPBPDU::setRootPathCost(unsigned long rootPathCost)
{
    this->rootPathCost_var = rootPathCost;
}

MACAddress& STPBPDU::getRootID()
{
    return rootID_var;
}

void STPBPDU::setRootID(const MACAddress& rootID)
{
    this->rootID_var = rootID;
}

unsigned int STPBPDU::getRootPriority() const
{
    return rootPriority_var;
}

void STPBPDU::setRootPriority(unsigned int rootPriority)
{
    this->rootPriority_var = rootPriority;
}

unsigned int STPBPDU::getPortID() const
{
    return portID_var;
}

void STPBPDU::setPortID(unsigned int portID)
{
    this->portID_var = portID;
}

unsigned int STPBPDU::getPortPriority() const
{
    return portPriority_var;
}

void STPBPDU::setPortPriority(unsigned int portPriority)
{
    this->portPriority_var = portPriority;
}

unsigned int STPBPDU::getMsgAge() const
{
    return msgAge_var;
}

void STPBPDU::setMsgAge(unsigned int msgAge)
{
    this->msgAge_var = msgAge;
}

unsigned int STPBPDU::getMaxAge() const
{
    return maxAge_var;
}

void STPBPDU::setMaxAge(unsigned int maxAge)
{
    this->maxAge_var = maxAge;
}

unsigned int STPBPDU::getHelloTime() const
{
    return helloTime_var;
}

void STPBPDU::setHelloTime(unsigned int helloTime)
{
    this->helloTime_var = helloTime;
}

unsigned int STPBPDU::getFwdDelay() const
{
    return fwdDelay_var;
}

void STPBPDU::setFwdDelay(unsigned int fwdDelay)
{
    this->fwdDelay_var = fwdDelay;
}

class STPBPDUDescriptor : public cClassDescriptor
{
  public:
    STPBPDUDescriptor();
    virtual ~STPBPDUDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(STPBPDUDescriptor);

STPBPDUDescriptor::STPBPDUDescriptor() : cClassDescriptor("STPBPDU", "cPacket")
{
}

STPBPDUDescriptor::~STPBPDUDescriptor()
{
}

bool STPBPDUDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<STPBPDU *>(obj)!=NULL;
}

const char *STPBPDUDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int STPBPDUDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount(object) : 15;
}

unsigned int STPBPDUDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *STPBPDUDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "portRole",
        "tc",
        "tca",
        "vlan",
        "bridgeID",
        "bridgePriority",
        "rootPathCost",
        "rootID",
        "rootPriority",
        "portID",
        "portPriority",
        "msgAge",
        "maxAge",
        "helloTime",
        "fwdDelay",
    };
    return (field>=0 && field<15) ? fieldNames[field] : NULL;
}

int STPBPDUDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "portRole")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tc")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tca")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlan")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "bridgeID")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "bridgePriority")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootPathCost")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootID")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootPriority")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "portID")==0) return base+9;
    if (fieldName[0]=='p' && strcmp(fieldName, "portPriority")==0) return base+10;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgAge")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxAge")==0) return base+12;
    if (fieldName[0]=='h' && strcmp(fieldName, "helloTime")==0) return base+13;
    if (fieldName[0]=='f' && strcmp(fieldName, "fwdDelay")==0) return base+14;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *STPBPDUDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "bool",
        "bool",
        "unsigned int",
        "MACAddress",
        "unsigned int",
        "unsigned long",
        "MACAddress",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : NULL;
}

const char *STPBPDUDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int STPBPDUDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    STPBPDU *pp = (STPBPDU *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string STPBPDUDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    STPBPDU *pp = (STPBPDU *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPortRole());
        case 1: return bool2string(pp->getTc());
        case 2: return bool2string(pp->getTca());
        case 3: return ulong2string(pp->getVlan());
        case 4: {std::stringstream out; out << pp->getBridgeID(); return out.str();}
        case 5: return ulong2string(pp->getBridgePriority());
        case 6: return ulong2string(pp->getRootPathCost());
        case 7: {std::stringstream out; out << pp->getRootID(); return out.str();}
        case 8: return ulong2string(pp->getRootPriority());
        case 9: return ulong2string(pp->getPortID());
        case 10: return ulong2string(pp->getPortPriority());
        case 11: return ulong2string(pp->getMsgAge());
        case 12: return ulong2string(pp->getMaxAge());
        case 13: return ulong2string(pp->getHelloTime());
        case 14: return ulong2string(pp->getFwdDelay());
        default: return "";
    }
}

bool STPBPDUDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    STPBPDU *pp = (STPBPDU *)object; (void)pp;
    switch (field) {
        case 0: pp->setPortRole(string2ulong(value)); return true;
        case 1: pp->setTc(string2bool(value)); return true;
        case 2: pp->setTca(string2bool(value)); return true;
        case 3: pp->setVlan(string2ulong(value)); return true;
        case 5: pp->setBridgePriority(string2ulong(value)); return true;
        case 6: pp->setRootPathCost(string2ulong(value)); return true;
        case 8: pp->setRootPriority(string2ulong(value)); return true;
        case 9: pp->setPortID(string2ulong(value)); return true;
        case 10: pp->setPortPriority(string2ulong(value)); return true;
        case 11: pp->setMsgAge(string2ulong(value)); return true;
        case 12: pp->setMaxAge(string2ulong(value)); return true;
        case 13: pp->setHelloTime(string2ulong(value)); return true;
        case 14: pp->setFwdDelay(string2ulong(value)); return true;
        default: return false;
    }
}

const char *STPBPDUDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        NULL,
        NULL,
        NULL,
        "MACAddress",
        NULL,
        NULL,
        "MACAddress",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<15) ? fieldStructNames[field] : NULL;
}

void *STPBPDUDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    STPBPDU *pp = (STPBPDU *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getBridgeID()); break;
        case 7: return (void *)(&pp->getRootID()); break;
        default: return NULL;
    }
}


