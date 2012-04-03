//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/rip/RIPTimer.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RIPTimer_m.h"

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




EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("RIPTimerType");
    if (!e) enums.getInstance()->add(e = new cEnum("RIPTimerType"));
    e->insert(hello, "hello");
    e->insert(timeout, "timeout");
    e->insert(garbage, "garbage");
    e->insert(trigger, "trigger");
);

Register_Class(RIPTimer);

RIPTimer::RIPTimer(const char *name, int kind) : cMessage(name,kind)
{
    this->timerKind_var = hello;
    this->intID_var = 0;
}

RIPTimer::RIPTimer(const RIPTimer& other) : cMessage(other)
{
    copy(other);
}

RIPTimer::~RIPTimer()
{
}

RIPTimer& RIPTimer::operator=(const RIPTimer& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void RIPTimer::copy(const RIPTimer& other)
{
    this->timerKind_var = other.timerKind_var;
    this->intID_var = other.intID_var;
}

void RIPTimer::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->timerKind_var);
    doPacking(b,this->intID_var);
}

void RIPTimer::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->timerKind_var);
    doUnpacking(b,this->intID_var);
}

char RIPTimer::getTimerKind() const
{
    return timerKind_var;
}

void RIPTimer::setTimerKind(char timerKind)
{
    this->timerKind_var = timerKind;
}

int RIPTimer::getIntID() const
{
    return intID_var;
}

void RIPTimer::setIntID(int intID)
{
    this->intID_var = intID;
}

class RIPTimerDescriptor : public cClassDescriptor
{
  public:
    RIPTimerDescriptor();
    virtual ~RIPTimerDescriptor();

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

Register_ClassDescriptor(RIPTimerDescriptor);

RIPTimerDescriptor::RIPTimerDescriptor() : cClassDescriptor("RIPTimer", "cMessage")
{
}

RIPTimerDescriptor::~RIPTimerDescriptor()
{
}

bool RIPTimerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RIPTimer *>(obj)!=NULL;
}

const char *RIPTimerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RIPTimerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int RIPTimerDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RIPTimerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "timerKind",
        "intID",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int RIPTimerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timerKind")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "intID")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RIPTimerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *RIPTimerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "RIPTimerType";
            return NULL;
        default: return NULL;
    }
}

int RIPTimerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RIPTimer *pp = (RIPTimer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RIPTimerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RIPTimer *pp = (RIPTimer *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTimerKind());
        case 1: return long2string(pp->getIntID());
        default: return "";
    }
}

bool RIPTimerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RIPTimer *pp = (RIPTimer *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimerKind(string2long(value)); return true;
        case 1: pp->setIntID(string2long(value)); return true;
        default: return false;
    }
}

const char *RIPTimerDescriptor::getFieldStructName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *RIPTimerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RIPTimer *pp = (RIPTimer *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


