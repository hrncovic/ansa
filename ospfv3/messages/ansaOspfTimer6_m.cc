//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/ospfv3/messages/ansaOspfTimer6.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ansaOspfTimer6_m.h"

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
    cEnum *e = cEnum::find("OspfTimerType6");
    if (!e) enums.getInstance()->add(e = new cEnum("OspfTimerType6"));
    e->insert(InterfaceHelloTimer, "InterfaceHelloTimer");
    e->insert(InterfaceWaitTimer, "InterfaceWaitTimer");
    e->insert(InterfaceAcknowledgementTimer, "InterfaceAcknowledgementTimer");
    e->insert(NeighborInactivityTimer, "NeighborInactivityTimer");
    e->insert(NeighborPollTimer, "NeighborPollTimer");
    e->insert(NeighborDDRetransmissionTimer, "NeighborDDRetransmissionTimer");
    e->insert(NeighborUpdateRetransmissionTimer, "NeighborUpdateRetransmissionTimer");
    e->insert(NeighborRequestRetransmissionTimer, "NeighborRequestRetransmissionTimer");
    e->insert(DatabaseAgeTimer, "DatabaseAgeTimer");
);

Register_Class(OspfTimer6);

OspfTimer6::OspfTimer6(const char *name, int kind) : cMessage(name,kind)
{
    this->timerKind_var = InterfaceHelloTimer;
}

OspfTimer6::OspfTimer6(const OspfTimer6& other) : cMessage(other)
{
    copy(other);
}

OspfTimer6::~OspfTimer6()
{
}

OspfTimer6& OspfTimer6::operator=(const OspfTimer6& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void OspfTimer6::copy(const OspfTimer6& other)
{
    this->timerKind_var = other.timerKind_var;
}

void OspfTimer6::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->timerKind_var);
}

void OspfTimer6::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->timerKind_var);
}

char OspfTimer6::getTimerKind() const
{
    return timerKind_var;
}

void OspfTimer6::setTimerKind(char timerKind)
{
    this->timerKind_var = timerKind;
}

class OspfTimer6Descriptor : public cClassDescriptor
{
  public:
    OspfTimer6Descriptor();
    virtual ~OspfTimer6Descriptor();

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

Register_ClassDescriptor(OspfTimer6Descriptor);

OspfTimer6Descriptor::OspfTimer6Descriptor() : cClassDescriptor("OspfTimer6", "cMessage")
{
}

OspfTimer6Descriptor::~OspfTimer6Descriptor()
{
}

bool OspfTimer6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfTimer6 *>(obj)!=NULL;
}

const char *OspfTimer6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfTimer6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int OspfTimer6Descriptor::getFieldTypeFlags(void *object, int field) const
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

const char *OspfTimer6Descriptor::getFieldName(void *object, int field) const
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

int OspfTimer6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timerKind")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfTimer6Descriptor::getFieldTypeString(void *object, int field) const
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

const char *OspfTimer6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "OspfTimerType6";
            return NULL;
        default: return NULL;
    }
}

int OspfTimer6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfTimer6 *pp = (OspfTimer6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfTimer6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfTimer6 *pp = (OspfTimer6 *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTimerKind());
        default: return "";
    }
}

bool OspfTimer6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfTimer6 *pp = (OspfTimer6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimerKind(string2long(value)); return true;
        default: return false;
    }
}

const char *OspfTimer6Descriptor::getFieldStructName(void *object, int field) const
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

void *OspfTimer6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfTimer6 *pp = (OspfTimer6 *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


