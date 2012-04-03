//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/igmp/IGMPTimer.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "IGMPTimer_m.h"

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
    cEnum *e = cEnum::find("IGMPTimerType");
    if (!e) enums.getInstance()->add(e = new cEnum("IGMPTimerType"));
    e->insert(TIMER_INIT_GENERAL_QUERY, "TIMER_INIT_GENERAL_QUERY");
    e->insert(TIMER_GENERAL_QUERY, "TIMER_GENERAL_QUERY");
    e->insert(TIMER_OTHER_QUERIER_PRESENT, "TIMER_OTHER_QUERIER_PRESENT");
    e->insert(TIMER_GROUP_MEMBERSHIP, "TIMER_GROUP_MEMBERSHIP");
    e->insert(TIMER_LAST_MEMBER, "TIMER_LAST_MEMBER");
);

Register_Class(IGMPTimer);

IGMPTimer::IGMPTimer(const char *name, int kind) : cMessage(name,kind)
{
    this->timerKind_var = 0;
    this->count_var = 0;
    this->intID_var = 0;
}

IGMPTimer::IGMPTimer(const IGMPTimer& other) : cMessage(other)
{
    copy(other);
}

IGMPTimer::~IGMPTimer()
{
}

IGMPTimer& IGMPTimer::operator=(const IGMPTimer& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void IGMPTimer::copy(const IGMPTimer& other)
{
    this->timerKind_var = other.timerKind_var;
    this->count_var = other.count_var;
    this->intID_var = other.intID_var;
    this->groupAddress_var = other.groupAddress_var;
}

void IGMPTimer::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->timerKind_var);
    doPacking(b,this->count_var);
    doPacking(b,this->intID_var);
    doPacking(b,this->groupAddress_var);
}

void IGMPTimer::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->timerKind_var);
    doUnpacking(b,this->count_var);
    doUnpacking(b,this->intID_var);
    doUnpacking(b,this->groupAddress_var);
}

char IGMPTimer::getTimerKind() const
{
    return timerKind_var;
}

void IGMPTimer::setTimerKind(char timerKind)
{
    this->timerKind_var = timerKind;
}

int IGMPTimer::getCount() const
{
    return count_var;
}

void IGMPTimer::setCount(int count)
{
    this->count_var = count;
}

int IGMPTimer::getIntID() const
{
    return intID_var;
}

void IGMPTimer::setIntID(int intID)
{
    this->intID_var = intID;
}

IPAddress& IGMPTimer::getGroupAddress()
{
    return groupAddress_var;
}

void IGMPTimer::setGroupAddress(const IPAddress& groupAddress)
{
    this->groupAddress_var = groupAddress;
}

class IGMPTimerDescriptor : public cClassDescriptor
{
  public:
    IGMPTimerDescriptor();
    virtual ~IGMPTimerDescriptor();

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

Register_ClassDescriptor(IGMPTimerDescriptor);

IGMPTimerDescriptor::IGMPTimerDescriptor() : cClassDescriptor("IGMPTimer", "cMessage")
{
}

IGMPTimerDescriptor::~IGMPTimerDescriptor()
{
}

bool IGMPTimerDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<IGMPTimer *>(obj)!=NULL;
}

const char *IGMPTimerDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int IGMPTimerDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int IGMPTimerDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *IGMPTimerDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "timerKind",
        "count",
        "intID",
        "groupAddress",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int IGMPTimerDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timerKind")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "count")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "intID")==0) return base+2;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *IGMPTimerDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "IPAddress",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *IGMPTimerDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "IGMPTimerType";
            return NULL;
        default: return NULL;
    }
}

int IGMPTimerDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    IGMPTimer *pp = (IGMPTimer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string IGMPTimerDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    IGMPTimer *pp = (IGMPTimer *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTimerKind());
        case 1: return long2string(pp->getCount());
        case 2: return long2string(pp->getIntID());
        case 3: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        default: return "";
    }
}

bool IGMPTimerDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    IGMPTimer *pp = (IGMPTimer *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimerKind(string2long(value)); return true;
        case 1: pp->setCount(string2long(value)); return true;
        case 2: pp->setIntID(string2long(value)); return true;
        default: return false;
    }
}

const char *IGMPTimerDescriptor::getFieldStructName(void *object, int field) const
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
        "IPAddress",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *IGMPTimerDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    IGMPTimer *pp = (IGMPTimer *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getGroupAddress()); break;
        default: return NULL;
    }
}


