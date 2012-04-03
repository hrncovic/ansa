//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/switch/AnsaEtherFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "AnsaEtherFrame_m.h"

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




Register_Class(AnsaEtherFrame);

AnsaEtherFrame::AnsaEtherFrame(const char *name, int kind) : EthernetIIFrame(name,kind)
{
    this->vlan_var = 0;
    this->displayString_var = "b=,,,kind,kind,0";
}

AnsaEtherFrame::AnsaEtherFrame(const AnsaEtherFrame& other) : EthernetIIFrame(other)
{
    copy(other);
}

AnsaEtherFrame::~AnsaEtherFrame()
{
}

AnsaEtherFrame& AnsaEtherFrame::operator=(const AnsaEtherFrame& other)
{
    if (this==&other) return *this;
    EthernetIIFrame::operator=(other);
    copy(other);
    return *this;
}

void AnsaEtherFrame::copy(const AnsaEtherFrame& other)
{
    this->vlan_var = other.vlan_var;
    this->displayString_var = other.displayString_var;
}

void AnsaEtherFrame::parsimPack(cCommBuffer *b)
{
    EthernetIIFrame::parsimPack(b);
    doPacking(b,this->vlan_var);
    doPacking(b,this->displayString_var);
}

void AnsaEtherFrame::parsimUnpack(cCommBuffer *b)
{
    EthernetIIFrame::parsimUnpack(b);
    doUnpacking(b,this->vlan_var);
    doUnpacking(b,this->displayString_var);
}

int AnsaEtherFrame::getVlan() const
{
    return vlan_var;
}

void AnsaEtherFrame::setVlan(int vlan)
{
    this->vlan_var = vlan;
}

const char * AnsaEtherFrame::getDisplayString() const
{
    return displayString_var.c_str();
}

void AnsaEtherFrame::setDisplayString(const char * displayString)
{
    this->displayString_var = displayString;
}

class AnsaEtherFrameDescriptor : public cClassDescriptor
{
  public:
    AnsaEtherFrameDescriptor();
    virtual ~AnsaEtherFrameDescriptor();

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

Register_ClassDescriptor(AnsaEtherFrameDescriptor);

AnsaEtherFrameDescriptor::AnsaEtherFrameDescriptor() : cClassDescriptor("AnsaEtherFrame", "EthernetIIFrame")
{
}

AnsaEtherFrameDescriptor::~AnsaEtherFrameDescriptor()
{
}

bool AnsaEtherFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<AnsaEtherFrame *>(obj)!=NULL;
}

const char *AnsaEtherFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int AnsaEtherFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int AnsaEtherFrameDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *AnsaEtherFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "vlan",
        "displayString",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int AnsaEtherFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "vlan")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "displayString")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *AnsaEtherFrameDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *AnsaEtherFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int AnsaEtherFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    AnsaEtherFrame *pp = (AnsaEtherFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string AnsaEtherFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    AnsaEtherFrame *pp = (AnsaEtherFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVlan());
        case 1: return oppstring2string(pp->getDisplayString());
        default: return "";
    }
}

bool AnsaEtherFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    AnsaEtherFrame *pp = (AnsaEtherFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setVlan(string2long(value)); return true;
        case 1: pp->setDisplayString((value)); return true;
        default: return false;
    }
}

const char *AnsaEtherFrameDescriptor::getFieldStructName(void *object, int field) const
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

void *AnsaEtherFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    AnsaEtherFrame *pp = (AnsaEtherFrame *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


