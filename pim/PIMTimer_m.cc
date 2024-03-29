//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/pim/PIMTimer.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PIMTimer_m.h"

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
    cEnum *e = cEnum::find("PIMTimerType");
    if (!e) enums.getInstance()->add(e = new cEnum("PIMTimerType"));
    e->insert(HelloTimer, "HelloTimer");
    e->insert(TriggeredHelloDelay, "TriggeredHelloDelay");
    e->insert(NeighborLivnessTimer, "NeighborLivnessTimer");
    e->insert(AssertTimer, "AssertTimer");
    e->insert(PruneTimer, "PruneTimer");
    e->insert(PrunePendingTimer, "PrunePendingTimer");
    e->insert(GrafRetryTimer, "GrafRetryTimer");
    e->insert(UpstreamOverrideTimer, "UpstreamOverrideTimer");
    e->insert(PruneLimitTimer, "PruneLimitTimer");
    e->insert(SourceActiveTimer, "SourceActiveTimer");
    e->insert(StateRefreshTimer, "StateRefreshTimer");
);

Register_Class(PIMTimer);

PIMTimer::PIMTimer(const char *name, int kind) : cMessage(name,kind)
{
    this->timerKind_var = 0;
}

PIMTimer::PIMTimer(const PIMTimer& other) : cMessage(other)
{
    copy(other);
}

PIMTimer::~PIMTimer()
{
}

PIMTimer& PIMTimer::operator=(const PIMTimer& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void PIMTimer::copy(const PIMTimer& other)
{
    this->timerKind_var = other.timerKind_var;
}

void PIMTimer::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->timerKind_var);
}

void PIMTimer::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->timerKind_var);
}

char PIMTimer::getTimerKind() const
{
    return timerKind_var;
}

void PIMTimer::setTimerKind(char timerKind)
{
    this->timerKind_var = timerKind;
}

class PIMTimerDescriptor : public cClassDescriptor
{
  public:
    PIMTimerDescriptor();
    virtual ~PIMTimerDescriptor();

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

Register_ClassDescriptor(PIMTimerDescriptor);

PIMTimerDescriptor::PIMTimerDescriptor() : cClassDescriptor("PIMTimer", "cMessage")
{
}

PIMTimerDescriptor::~PIMTimerDescriptor()
{
}

bool PIMTimerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMTimer *>(obj)!=NULL;
}

const char *PIMTimerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMTimerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int PIMTimerDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *PIMTimerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "timerKind",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int PIMTimerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timerKind")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMTimerDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *PIMTimerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMTimerType";
            return NULL;
        default: return NULL;
    }
}

int PIMTimerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMTimer *pp = (PIMTimer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMTimerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMTimer *pp = (PIMTimer *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTimerKind());
        default: return "";
    }
}

bool PIMTimerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMTimer *pp = (PIMTimer *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimerKind(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMTimerDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *PIMTimerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMTimer *pp = (PIMTimer *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


