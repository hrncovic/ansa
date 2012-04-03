//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/TrafficGenerator/TrafGenPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "TrafGenPacket_m.h"

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




Register_Class(TrafGenPacket);

TrafGenPacket::TrafGenPacket(const char *name, int kind) : cPacket(name,kind)
{
    this->flowId_var = 0;
    this->sentTime_var = 0;
    this->application_var = 0;
}

TrafGenPacket::TrafGenPacket(const TrafGenPacket& other) : cPacket(other)
{
    copy(other);
}

TrafGenPacket::~TrafGenPacket()
{
}

TrafGenPacket& TrafGenPacket::operator=(const TrafGenPacket& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void TrafGenPacket::copy(const TrafGenPacket& other)
{
    this->flowId_var = other.flowId_var;
    this->sentTime_var = other.sentTime_var;
    this->application_var = other.application_var;
}

void TrafGenPacket::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->flowId_var);
    doPacking(b,this->sentTime_var);
    doPacking(b,this->application_var);
}

void TrafGenPacket::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->flowId_var);
    doUnpacking(b,this->sentTime_var);
    doUnpacking(b,this->application_var);
}

const char * TrafGenPacket::getFlowId() const
{
    return flowId_var.c_str();
}

void TrafGenPacket::setFlowId(const char * flowId)
{
    this->flowId_var = flowId;
}

double TrafGenPacket::getSentTime() const
{
    return sentTime_var;
}

void TrafGenPacket::setSentTime(double sentTime)
{
    this->sentTime_var = sentTime;
}

const char * TrafGenPacket::getApplication() const
{
    return application_var.c_str();
}

void TrafGenPacket::setApplication(const char * application)
{
    this->application_var = application;
}

class TrafGenPacketDescriptor : public cClassDescriptor
{
  public:
    TrafGenPacketDescriptor();
    virtual ~TrafGenPacketDescriptor();

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

Register_ClassDescriptor(TrafGenPacketDescriptor);

TrafGenPacketDescriptor::TrafGenPacketDescriptor() : cClassDescriptor("TrafGenPacket", "cPacket")
{
}

TrafGenPacketDescriptor::~TrafGenPacketDescriptor()
{
}

bool TrafGenPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<TrafGenPacket *>(obj)!=NULL;
}

const char *TrafGenPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int TrafGenPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int TrafGenPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *TrafGenPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "flowId",
        "sentTime",
        "application",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int TrafGenPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flowId")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sentTime")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "application")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *TrafGenPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "double",
        "string",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *TrafGenPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int TrafGenPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    TrafGenPacket *pp = (TrafGenPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string TrafGenPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    TrafGenPacket *pp = (TrafGenPacket *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getFlowId());
        case 1: return double2string(pp->getSentTime());
        case 2: return oppstring2string(pp->getApplication());
        default: return "";
    }
}

bool TrafGenPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    TrafGenPacket *pp = (TrafGenPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlowId((value)); return true;
        case 1: pp->setSentTime(string2double(value)); return true;
        case 2: pp->setApplication((value)); return true;
        default: return false;
    }
}

const char *TrafGenPacketDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *TrafGenPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    TrafGenPacket *pp = (TrafGenPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


