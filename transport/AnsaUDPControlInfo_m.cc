//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/transport/AnsaUDPControlInfo.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AnsaUDPControlInfo_m.h"

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




Register_Class(AnsaUDPControlInfo);

AnsaUDPControlInfo::AnsaUDPControlInfo() : cObject()
{
    this->sockId_var = -1;
    this->userId_var = -1;
    this->diffServCodePoint_var = 0;
    this->timeToLive_var = 0;
    this->srcPort_var = 0;
    this->destPort_var = 0;
    this->interfaceId_var = -1;
}

AnsaUDPControlInfo::AnsaUDPControlInfo(const AnsaUDPControlInfo& other) : cObject(other)
{
    copy(other);
}

AnsaUDPControlInfo::~AnsaUDPControlInfo()
{
}

AnsaUDPControlInfo& AnsaUDPControlInfo::operator=(const AnsaUDPControlInfo& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    copy(other);
    return *this;
}

void AnsaUDPControlInfo::copy(const AnsaUDPControlInfo& other)
{
    this->sockId_var = other.sockId_var;
    this->userId_var = other.userId_var;
    this->srcAddr_var = other.srcAddr_var;
    this->destAddr_var = other.destAddr_var;
    this->diffServCodePoint_var = other.diffServCodePoint_var;
    this->timeToLive_var = other.timeToLive_var;
    this->srcPort_var = other.srcPort_var;
    this->destPort_var = other.destPort_var;
    this->interfaceId_var = other.interfaceId_var;
}

void AnsaUDPControlInfo::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->sockId_var);
    doPacking(b,this->userId_var);
    doPacking(b,this->srcAddr_var);
    doPacking(b,this->destAddr_var);
    doPacking(b,this->diffServCodePoint_var);
    doPacking(b,this->timeToLive_var);
    doPacking(b,this->srcPort_var);
    doPacking(b,this->destPort_var);
    doPacking(b,this->interfaceId_var);
}

void AnsaUDPControlInfo::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->sockId_var);
    doUnpacking(b,this->userId_var);
    doUnpacking(b,this->srcAddr_var);
    doUnpacking(b,this->destAddr_var);
    doUnpacking(b,this->diffServCodePoint_var);
    doUnpacking(b,this->timeToLive_var);
    doUnpacking(b,this->srcPort_var);
    doUnpacking(b,this->destPort_var);
    doUnpacking(b,this->interfaceId_var);
}

int AnsaUDPControlInfo::getSockId() const
{
    return sockId_var;
}

void AnsaUDPControlInfo::setSockId(int sockId)
{
    this->sockId_var = sockId;
}

int AnsaUDPControlInfo::getUserId() const
{
    return userId_var;
}

void AnsaUDPControlInfo::setUserId(int userId)
{
    this->userId_var = userId;
}

IPvXAddress& AnsaUDPControlInfo::getSrcAddr()
{
    return srcAddr_var;
}

void AnsaUDPControlInfo::setSrcAddr(const IPvXAddress& srcAddr)
{
    this->srcAddr_var = srcAddr;
}

IPvXAddress& AnsaUDPControlInfo::getDestAddr()
{
    return destAddr_var;
}

void AnsaUDPControlInfo::setDestAddr(const IPvXAddress& destAddr)
{
    this->destAddr_var = destAddr;
}

unsigned char AnsaUDPControlInfo::getDiffServCodePoint() const
{
    return diffServCodePoint_var;
}

void AnsaUDPControlInfo::setDiffServCodePoint(unsigned char diffServCodePoint)
{
    this->diffServCodePoint_var = diffServCodePoint;
}

short AnsaUDPControlInfo::getTimeToLive() const
{
    return timeToLive_var;
}

void AnsaUDPControlInfo::setTimeToLive(short timeToLive)
{
    this->timeToLive_var = timeToLive;
}

int AnsaUDPControlInfo::getSrcPort() const
{
    return srcPort_var;
}

void AnsaUDPControlInfo::setSrcPort(int srcPort)
{
    this->srcPort_var = srcPort;
}

int AnsaUDPControlInfo::getDestPort() const
{
    return destPort_var;
}

void AnsaUDPControlInfo::setDestPort(int destPort)
{
    this->destPort_var = destPort;
}

int AnsaUDPControlInfo::getInterfaceId() const
{
    return interfaceId_var;
}

void AnsaUDPControlInfo::setInterfaceId(int interfaceId)
{
    this->interfaceId_var = interfaceId;
}

class AnsaUDPControlInfoDescriptor : public cClassDescriptor
{
  public:
    AnsaUDPControlInfoDescriptor();
    virtual ~AnsaUDPControlInfoDescriptor();

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

Register_ClassDescriptor(AnsaUDPControlInfoDescriptor);

AnsaUDPControlInfoDescriptor::AnsaUDPControlInfoDescriptor() : cClassDescriptor("AnsaUDPControlInfo", "cObject")
{
}

AnsaUDPControlInfoDescriptor::~AnsaUDPControlInfoDescriptor()
{
}

bool AnsaUDPControlInfoDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AnsaUDPControlInfo *>(obj)!=NULL;
}

const char *AnsaUDPControlInfoDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AnsaUDPControlInfoDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount(object) : 9;
}

unsigned int AnsaUDPControlInfoDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *AnsaUDPControlInfoDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "sockId",
        "userId",
        "srcAddr",
        "destAddr",
        "diffServCodePoint",
        "timeToLive",
        "srcPort",
        "destPort",
        "interfaceId",
    };
    return (field>=0 && field<9) ? fieldNames[field] : NULL;
}

int AnsaUDPControlInfoDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sockId")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "userId")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "diffServCodePoint")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeToLive")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+7;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+8;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AnsaUDPControlInfoDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "IPvXAddress",
        "IPvXAddress",
        "unsigned char",
        "short",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : NULL;
}

const char *AnsaUDPControlInfoDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AnsaUDPControlInfoDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AnsaUDPControlInfo *pp = (AnsaUDPControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AnsaUDPControlInfoDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AnsaUDPControlInfo *pp = (AnsaUDPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSockId());
        case 1: return long2string(pp->getUserId());
        case 2: {std::stringstream out; out << pp->getSrcAddr(); return out.str();}
        case 3: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 4: return ulong2string(pp->getDiffServCodePoint());
        case 5: return long2string(pp->getTimeToLive());
        case 6: return long2string(pp->getSrcPort());
        case 7: return long2string(pp->getDestPort());
        case 8: return long2string(pp->getInterfaceId());
        default: return "";
    }
}

bool AnsaUDPControlInfoDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AnsaUDPControlInfo *pp = (AnsaUDPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setSockId(string2long(value)); return true;
        case 1: pp->setUserId(string2long(value)); return true;
        case 4: pp->setDiffServCodePoint(string2ulong(value)); return true;
        case 5: pp->setTimeToLive(string2long(value)); return true;
        case 6: pp->setSrcPort(string2long(value)); return true;
        case 7: pp->setDestPort(string2long(value)); return true;
        case 8: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *AnsaUDPControlInfoDescriptor::getFieldStructName(void *object, int field) const
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
        "IPvXAddress",
        "IPvXAddress",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<9) ? fieldStructNames[field] : NULL;
}

void *AnsaUDPControlInfoDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AnsaUDPControlInfo *pp = (AnsaUDPControlInfo *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getSrcAddr()); break;
        case 3: return (void *)(&pp->getDestAddr()); break;
        default: return NULL;
    }
}


