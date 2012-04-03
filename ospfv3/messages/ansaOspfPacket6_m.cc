//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/ospfv3/messages/ansaOspfPacket6.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ansaOspfPacket6_m.h"

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
    cEnum *e = cEnum::find("OspfPacketType6");
    if (!e) enums.getInstance()->add(e = new cEnum("OspfPacketType6"));
    e->insert(HelloPacket, "HelloPacket");
    e->insert(DatabaseDescriptionPacket, "DatabaseDescriptionPacket");
    e->insert(LinkStateRequestPacket, "LinkStateRequestPacket");
    e->insert(LinkStateUpdatePacket, "LinkStateUpdatePacket");
    e->insert(LinkStateAcknowledgementPacket, "LinkStateAcknowledgementPacket");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("LsaType6");
    if (!e) enums.getInstance()->add(e = new cEnum("LsaType6"));
    e->insert(RouterLsaType, "RouterLsaType");
    e->insert(NetworkLsaType, "NetworkLsaType");
    e->insert(InterAreaPrefixLsaType, "InterAreaPrefixLsaType");
    e->insert(InterAreaRouterLsaType, "InterAreaRouterLsaType");
    e->insert(AsExternalLsaType, "AsExternalLsaType");
    e->insert(NssaLsaType, "NssaLsaType");
    e->insert(LinkLsaType, "LinkLsaType");
    e->insert(IntraAreaPrefixLsaType, "IntraAreaPrefixLsaType");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("LinkType6");
    if (!e) enums.getInstance()->add(e = new cEnum("LinkType6"));
    e->insert(PointToPointLink, "PointToPointLink");
    e->insert(TransitLink, "TransitLink");
    e->insert(VirtualLink, "VirtualLink");
);

Register_Class(Link6);

Link6::Link6() : cObject()
{
    this->type_var = PointToPointLink;
    this->metric_var = 0;
}

Link6::Link6(const Link6& other) : cObject(other)
{
    copy(other);
}

Link6::~Link6()
{
}

Link6& Link6::operator=(const Link6& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    copy(other);
    return *this;
}

void Link6::copy(const Link6& other)
{
    this->type_var = other.type_var;
    this->metric_var = other.metric_var;
    this->interfaceID_var = other.interfaceID_var;
    this->neighborInterfaceID_var = other.neighborInterfaceID_var;
    this->neighborRouterID_var = other.neighborRouterID_var;
}

void Link6::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->type_var);
    doPacking(b,this->metric_var);
    doPacking(b,this->interfaceID_var);
    doPacking(b,this->neighborInterfaceID_var);
    doPacking(b,this->neighborRouterID_var);
}

void Link6::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->interfaceID_var);
    doUnpacking(b,this->neighborInterfaceID_var);
    doUnpacking(b,this->neighborRouterID_var);
}

uint8 Link6::getType() const
{
    return type_var;
}

void Link6::setType(uint8 type)
{
    this->type_var = type;
}

uint16 Link6::getMetric() const
{
    return metric_var;
}

void Link6::setMetric(uint16 metric)
{
    this->metric_var = metric;
}

IfaceID& Link6::getInterfaceID()
{
    return interfaceID_var;
}

void Link6::setInterfaceID(const IfaceID& interfaceID)
{
    this->interfaceID_var = interfaceID;
}

IfaceID& Link6::getNeighborInterfaceID()
{
    return neighborInterfaceID_var;
}

void Link6::setNeighborInterfaceID(const IfaceID& neighborInterfaceID)
{
    this->neighborInterfaceID_var = neighborInterfaceID;
}

RouterID& Link6::getNeighborRouterID()
{
    return neighborRouterID_var;
}

void Link6::setNeighborRouterID(const RouterID& neighborRouterID)
{
    this->neighborRouterID_var = neighborRouterID;
}

class Link6Descriptor : public cClassDescriptor
{
  public:
    Link6Descriptor();
    virtual ~Link6Descriptor();

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

Register_ClassDescriptor(Link6Descriptor);

Link6Descriptor::Link6Descriptor() : cClassDescriptor("Link6", "cObject")
{
}

Link6Descriptor::~Link6Descriptor()
{
}

bool Link6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Link6 *>(obj)!=NULL;
}

const char *Link6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int Link6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int Link6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *Link6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "metric",
        "interfaceID",
        "neighborInterfaceID",
        "neighborRouterID",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int Link6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceID")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborInterfaceID")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborRouterID")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *Link6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "uint16",
        "IfaceID",
        "IfaceID",
        "RouterID",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *Link6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "LinkType6";
            return NULL;
        default: return NULL;
    }
}

int Link6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Link6 *pp = (Link6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string Link6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Link6 *pp = (Link6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getType());
        case 1: return ulong2string(pp->getMetric());
        case 2: {std::stringstream out; out << pp->getInterfaceID(); return out.str();}
        case 3: {std::stringstream out; out << pp->getNeighborInterfaceID(); return out.str();}
        case 4: {std::stringstream out; out << pp->getNeighborRouterID(); return out.str();}
        default: return "";
    }
}

bool Link6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Link6 *pp = (Link6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2ulong(value)); return true;
        case 1: pp->setMetric(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Link6Descriptor::getFieldStructName(void *object, int field) const
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
        "IfaceID",
        "IfaceID",
        "RouterID",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *Link6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Link6 *pp = (Link6 *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getInterfaceID()); break;
        case 3: return (void *)(&pp->getNeighborInterfaceID()); break;
        case 4: return (void *)(&pp->getNeighborRouterID()); break;
        default: return NULL;
    }
}

OspfPrefixOptions6::OspfPrefixOptions6()
{
    NU_NoUnicast = false;
    LA_LocalAddress = 0;
}

void doPacking(cCommBuffer *b, OspfPrefixOptions6& a)
{
    doPacking(b,a.NU_NoUnicast);
    doPacking(b,a.LA_LocalAddress);
}

void doUnpacking(cCommBuffer *b, OspfPrefixOptions6& a)
{
    doUnpacking(b,a.NU_NoUnicast);
    doUnpacking(b,a.LA_LocalAddress);
}

class OspfPrefixOptions6Descriptor : public cClassDescriptor
{
  public:
    OspfPrefixOptions6Descriptor();
    virtual ~OspfPrefixOptions6Descriptor();

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

Register_ClassDescriptor(OspfPrefixOptions6Descriptor);

OspfPrefixOptions6Descriptor::OspfPrefixOptions6Descriptor() : cClassDescriptor("OspfPrefixOptions6", "")
{
}

OspfPrefixOptions6Descriptor::~OspfPrefixOptions6Descriptor()
{
}

bool OspfPrefixOptions6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfPrefixOptions6 *>(obj)!=NULL;
}

const char *OspfPrefixOptions6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfPrefixOptions6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int OspfPrefixOptions6Descriptor::getFieldTypeFlags(void *object, int field) const
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

const char *OspfPrefixOptions6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "NU_NoUnicast",
        "LA_LocalAddress",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int OspfPrefixOptions6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='N' && strcmp(fieldName, "NU_NoUnicast")==0) return base+0;
    if (fieldName[0]=='L' && strcmp(fieldName, "LA_LocalAddress")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfPrefixOptions6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *OspfPrefixOptions6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfPrefixOptions6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefixOptions6 *pp = (OspfPrefixOptions6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfPrefixOptions6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefixOptions6 *pp = (OspfPrefixOptions6 *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->NU_NoUnicast);
        case 1: return bool2string(pp->LA_LocalAddress);
        default: return "";
    }
}

bool OspfPrefixOptions6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefixOptions6 *pp = (OspfPrefixOptions6 *)object; (void)pp;
    switch (field) {
        case 0: pp->NU_NoUnicast = string2bool(value); return true;
        case 1: pp->LA_LocalAddress = string2bool(value); return true;
        default: return false;
    }
}

const char *OspfPrefixOptions6Descriptor::getFieldStructName(void *object, int field) const
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

void *OspfPrefixOptions6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefixOptions6 *pp = (OspfPrefixOptions6 *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(OspfPrefix6);

OspfPrefix6::OspfPrefix6() : cObject()
{
    this->prefixLenght_var = 0;
    this->metric_var = 0;
}

OspfPrefix6::OspfPrefix6(const OspfPrefix6& other) : cObject(other)
{
    copy(other);
}

OspfPrefix6::~OspfPrefix6()
{
}

OspfPrefix6& OspfPrefix6::operator=(const OspfPrefix6& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    copy(other);
    return *this;
}

void OspfPrefix6::copy(const OspfPrefix6& other)
{
    this->prefixLenght_var = other.prefixLenght_var;
    this->prefixOptions_var = other.prefixOptions_var;
    this->metric_var = other.metric_var;
    this->addressPrefix_var = other.addressPrefix_var;
}

void OspfPrefix6::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->prefixLenght_var);
    doPacking(b,this->prefixOptions_var);
    doPacking(b,this->metric_var);
    doPacking(b,this->addressPrefix_var);
}

void OspfPrefix6::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->prefixLenght_var);
    doUnpacking(b,this->prefixOptions_var);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->addressPrefix_var);
}

uint8 OspfPrefix6::getPrefixLenght() const
{
    return prefixLenght_var;
}

void OspfPrefix6::setPrefixLenght(uint8 prefixLenght)
{
    this->prefixLenght_var = prefixLenght;
}

OspfPrefixOptions6& OspfPrefix6::getPrefixOptions()
{
    return prefixOptions_var;
}

void OspfPrefix6::setPrefixOptions(const OspfPrefixOptions6& prefixOptions)
{
    this->prefixOptions_var = prefixOptions;
}

uint16 OspfPrefix6::getMetric() const
{
    return metric_var;
}

void OspfPrefix6::setMetric(uint16 metric)
{
    this->metric_var = metric;
}

IPv6Address& OspfPrefix6::getAddressPrefix()
{
    return addressPrefix_var;
}

void OspfPrefix6::setAddressPrefix(const IPv6Address& addressPrefix)
{
    this->addressPrefix_var = addressPrefix;
}

class OspfPrefix6Descriptor : public cClassDescriptor
{
  public:
    OspfPrefix6Descriptor();
    virtual ~OspfPrefix6Descriptor();

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

Register_ClassDescriptor(OspfPrefix6Descriptor);

OspfPrefix6Descriptor::OspfPrefix6Descriptor() : cClassDescriptor("OspfPrefix6", "cObject")
{
}

OspfPrefix6Descriptor::~OspfPrefix6Descriptor()
{
}

bool OspfPrefix6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfPrefix6 *>(obj)!=NULL;
}

const char *OspfPrefix6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfPrefix6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int OspfPrefix6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *OspfPrefix6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "prefixLenght",
        "prefixOptions",
        "metric",
        "addressPrefix",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int OspfPrefix6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLenght")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixOptions")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressPrefix")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfPrefix6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "OspfPrefixOptions6",
        "uint16",
        "IPv6Address",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *OspfPrefix6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfPrefix6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefix6 *pp = (OspfPrefix6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfPrefix6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefix6 *pp = (OspfPrefix6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPrefixLenght());
        case 1: {std::stringstream out; out << pp->getPrefixOptions(); return out.str();}
        case 2: return ulong2string(pp->getMetric());
        case 3: {std::stringstream out; out << pp->getAddressPrefix(); return out.str();}
        default: return "";
    }
}

bool OspfPrefix6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefix6 *pp = (OspfPrefix6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setPrefixLenght(string2ulong(value)); return true;
        case 2: pp->setMetric(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfPrefix6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "OspfPrefixOptions6",
        NULL,
        "IPv6Address",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *OspfPrefix6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfPrefix6 *pp = (OspfPrefix6 *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPrefixOptions()); break;
        case 3: return (void *)(&pp->getAddressPrefix()); break;
        default: return NULL;
    }
}

OspfOptions6::OspfOptions6()
{
    V6_IPv6Routing = true;
    E_ExternalRoutingCapability = 0;
    N_NSSA = false;
    R_Router = true;
    DC_DemandCircuits = 0;
}

void doPacking(cCommBuffer *b, OspfOptions6& a)
{
    doPacking(b,a.V6_IPv6Routing);
    doPacking(b,a.E_ExternalRoutingCapability);
    doPacking(b,a.N_NSSA);
    doPacking(b,a.R_Router);
    doPacking(b,a.DC_DemandCircuits);
}

void doUnpacking(cCommBuffer *b, OspfOptions6& a)
{
    doUnpacking(b,a.V6_IPv6Routing);
    doUnpacking(b,a.E_ExternalRoutingCapability);
    doUnpacking(b,a.N_NSSA);
    doUnpacking(b,a.R_Router);
    doUnpacking(b,a.DC_DemandCircuits);
}

class OspfOptions6Descriptor : public cClassDescriptor
{
  public:
    OspfOptions6Descriptor();
    virtual ~OspfOptions6Descriptor();

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

Register_ClassDescriptor(OspfOptions6Descriptor);

OspfOptions6Descriptor::OspfOptions6Descriptor() : cClassDescriptor("OspfOptions6", "")
{
}

OspfOptions6Descriptor::~OspfOptions6Descriptor()
{
}

bool OspfOptions6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfOptions6 *>(obj)!=NULL;
}

const char *OspfOptions6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfOptions6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int OspfOptions6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OspfOptions6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "V6_IPv6Routing",
        "E_ExternalRoutingCapability",
        "N_NSSA",
        "R_Router",
        "DC_DemandCircuits",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int OspfOptions6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='V' && strcmp(fieldName, "V6_IPv6Routing")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_ExternalRoutingCapability")==0) return base+1;
    if (fieldName[0]=='N' && strcmp(fieldName, "N_NSSA")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "R_Router")==0) return base+3;
    if (fieldName[0]=='D' && strcmp(fieldName, "DC_DemandCircuits")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfOptions6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *OspfOptions6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfOptions6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfOptions6 *pp = (OspfOptions6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfOptions6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfOptions6 *pp = (OspfOptions6 *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->V6_IPv6Routing);
        case 1: return bool2string(pp->E_ExternalRoutingCapability);
        case 2: return bool2string(pp->N_NSSA);
        case 3: return bool2string(pp->R_Router);
        case 4: return bool2string(pp->DC_DemandCircuits);
        default: return "";
    }
}

bool OspfOptions6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfOptions6 *pp = (OspfOptions6 *)object; (void)pp;
    switch (field) {
        case 0: pp->V6_IPv6Routing = string2bool(value); return true;
        case 1: pp->E_ExternalRoutingCapability = string2bool(value); return true;
        case 2: pp->N_NSSA = string2bool(value); return true;
        case 3: pp->R_Router = string2bool(value); return true;
        case 4: pp->DC_DemandCircuits = string2bool(value); return true;
        default: return false;
    }
}

const char *OspfOptions6Descriptor::getFieldStructName(void *object, int field) const
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
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *OspfOptions6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfOptions6 *pp = (OspfOptions6 *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

OspfDdOptions6::OspfDdOptions6()
{
    I_Init = 0;
    M_More = 0;
    MS_MasterSlave = 0;
}

void doPacking(cCommBuffer *b, OspfDdOptions6& a)
{
    doPacking(b,a.I_Init);
    doPacking(b,a.M_More);
    doPacking(b,a.MS_MasterSlave);
}

void doUnpacking(cCommBuffer *b, OspfDdOptions6& a)
{
    doUnpacking(b,a.I_Init);
    doUnpacking(b,a.M_More);
    doUnpacking(b,a.MS_MasterSlave);
}

class OspfDdOptions6Descriptor : public cClassDescriptor
{
  public:
    OspfDdOptions6Descriptor();
    virtual ~OspfDdOptions6Descriptor();

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

Register_ClassDescriptor(OspfDdOptions6Descriptor);

OspfDdOptions6Descriptor::OspfDdOptions6Descriptor() : cClassDescriptor("OspfDdOptions6", "")
{
}

OspfDdOptions6Descriptor::~OspfDdOptions6Descriptor()
{
}

bool OspfDdOptions6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfDdOptions6 *>(obj)!=NULL;
}

const char *OspfDdOptions6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfDdOptions6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int OspfDdOptions6Descriptor::getFieldTypeFlags(void *object, int field) const
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

const char *OspfDdOptions6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "I_Init",
        "M_More",
        "MS_MasterSlave",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int OspfDdOptions6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "I_Init")==0) return base+0;
    if (fieldName[0]=='M' && strcmp(fieldName, "M_More")==0) return base+1;
    if (fieldName[0]=='M' && strcmp(fieldName, "MS_MasterSlave")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfDdOptions6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *OspfDdOptions6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfDdOptions6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfDdOptions6 *pp = (OspfDdOptions6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfDdOptions6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfDdOptions6 *pp = (OspfDdOptions6 *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->I_Init);
        case 1: return bool2string(pp->M_More);
        case 2: return bool2string(pp->MS_MasterSlave);
        default: return "";
    }
}

bool OspfDdOptions6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfDdOptions6 *pp = (OspfDdOptions6 *)object; (void)pp;
    switch (field) {
        case 0: pp->I_Init = string2bool(value); return true;
        case 1: pp->M_More = string2bool(value); return true;
        case 2: pp->MS_MasterSlave = string2bool(value); return true;
        default: return false;
    }
}

const char *OspfDdOptions6Descriptor::getFieldStructName(void *object, int field) const
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

void *OspfDdOptions6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfDdOptions6 *pp = (OspfDdOptions6 *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

OspfLsaRequest6::OspfLsaRequest6()
{
    lsType = 0;
    linkStateID = 0;
}

void doPacking(cCommBuffer *b, OspfLsaRequest6& a)
{
    doPacking(b,a.lsType);
    doPacking(b,a.linkStateID);
    doPacking(b,a.advertisingRouter);
}

void doUnpacking(cCommBuffer *b, OspfLsaRequest6& a)
{
    doUnpacking(b,a.lsType);
    doUnpacking(b,a.linkStateID);
    doUnpacking(b,a.advertisingRouter);
}

class OspfLsaRequest6Descriptor : public cClassDescriptor
{
  public:
    OspfLsaRequest6Descriptor();
    virtual ~OspfLsaRequest6Descriptor();

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

Register_ClassDescriptor(OspfLsaRequest6Descriptor);

OspfLsaRequest6Descriptor::OspfLsaRequest6Descriptor() : cClassDescriptor("OspfLsaRequest6", "")
{
}

OspfLsaRequest6Descriptor::~OspfLsaRequest6Descriptor()
{
}

bool OspfLsaRequest6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLsaRequest6 *>(obj)!=NULL;
}

const char *OspfLsaRequest6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLsaRequest6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int OspfLsaRequest6Descriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *OspfLsaRequest6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "lsType",
        "linkStateID",
        "advertisingRouter",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int OspfLsaRequest6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkStateID")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisingRouter")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLsaRequest6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint32",
        "RouterID",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLsaRequest6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfLsaRequest6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaRequest6 *pp = (OspfLsaRequest6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfLsaRequest6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaRequest6 *pp = (OspfLsaRequest6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->lsType);
        case 1: return ulong2string(pp->linkStateID);
        case 2: {std::stringstream out; out << pp->advertisingRouter; return out.str();}
        default: return "";
    }
}

bool OspfLsaRequest6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaRequest6 *pp = (OspfLsaRequest6 *)object; (void)pp;
    switch (field) {
        case 0: pp->lsType = string2ulong(value); return true;
        case 1: pp->linkStateID = string2ulong(value); return true;
        default: return false;
    }
}

const char *OspfLsaRequest6Descriptor::getFieldStructName(void *object, int field) const
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
        "RouterID",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *OspfLsaRequest6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaRequest6 *pp = (OspfLsaRequest6 *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->advertisingRouter); break;
        default: return NULL;
    }
}

Register_Class(OspfLsaHeader6);

OspfLsaHeader6::OspfLsaHeader6() : cObject()
{
    this->lsAge_var = 0;
    this->lsType_var = RouterLsaType;
    this->linkStateID_var = 0;
    this->lsSequenceNumber_var = 0;
}

OspfLsaHeader6::OspfLsaHeader6(const OspfLsaHeader6& other) : cObject(other)
{
    copy(other);
}

OspfLsaHeader6::~OspfLsaHeader6()
{
}

OspfLsaHeader6& OspfLsaHeader6::operator=(const OspfLsaHeader6& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    copy(other);
    return *this;
}

void OspfLsaHeader6::copy(const OspfLsaHeader6& other)
{
    this->lsAge_var = other.lsAge_var;
    this->lsType_var = other.lsType_var;
    this->linkStateID_var = other.linkStateID_var;
    this->advertisingRouter_var = other.advertisingRouter_var;
    this->lsSequenceNumber_var = other.lsSequenceNumber_var;
}

void OspfLsaHeader6::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->lsAge_var);
    doPacking(b,this->lsType_var);
    doPacking(b,this->linkStateID_var);
    doPacking(b,this->advertisingRouter_var);
    doPacking(b,this->lsSequenceNumber_var);
}

void OspfLsaHeader6::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->lsAge_var);
    doUnpacking(b,this->lsType_var);
    doUnpacking(b,this->linkStateID_var);
    doUnpacking(b,this->advertisingRouter_var);
    doUnpacking(b,this->lsSequenceNumber_var);
}

uint16 OspfLsaHeader6::getLsAge() const
{
    return lsAge_var;
}

void OspfLsaHeader6::setLsAge(uint16 lsAge)
{
    this->lsAge_var = lsAge;
}

uint16 OspfLsaHeader6::getLsType() const
{
    return lsType_var;
}

void OspfLsaHeader6::setLsType(uint16 lsType)
{
    this->lsType_var = lsType;
}

uint32 OspfLsaHeader6::getLinkStateID() const
{
    return linkStateID_var;
}

void OspfLsaHeader6::setLinkStateID(uint32 linkStateID)
{
    this->linkStateID_var = linkStateID;
}

RouterID& OspfLsaHeader6::getAdvertisingRouter()
{
    return advertisingRouter_var;
}

void OspfLsaHeader6::setAdvertisingRouter(const RouterID& advertisingRouter)
{
    this->advertisingRouter_var = advertisingRouter;
}

uint32 OspfLsaHeader6::getLsSequenceNumber() const
{
    return lsSequenceNumber_var;
}

void OspfLsaHeader6::setLsSequenceNumber(uint32 lsSequenceNumber)
{
    this->lsSequenceNumber_var = lsSequenceNumber;
}

class OspfLsaHeader6Descriptor : public cClassDescriptor
{
  public:
    OspfLsaHeader6Descriptor();
    virtual ~OspfLsaHeader6Descriptor();

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

Register_ClassDescriptor(OspfLsaHeader6Descriptor);

OspfLsaHeader6Descriptor::OspfLsaHeader6Descriptor() : cClassDescriptor("OspfLsaHeader6", "cObject")
{
}

OspfLsaHeader6Descriptor::~OspfLsaHeader6Descriptor()
{
}

bool OspfLsaHeader6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLsaHeader6 *>(obj)!=NULL;
}

const char *OspfLsaHeader6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLsaHeader6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int OspfLsaHeader6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OspfLsaHeader6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "lsAge",
        "lsType",
        "linkStateID",
        "advertisingRouter",
        "lsSequenceNumber",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int OspfLsaHeader6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsAge")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsType")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkStateID")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisingRouter")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsSequenceNumber")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLsaHeader6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint16",
        "uint32",
        "RouterID",
        "uint32",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLsaHeader6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "LsaType6";
            return NULL;
        default: return NULL;
    }
}

int OspfLsaHeader6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaHeader6 *pp = (OspfLsaHeader6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfLsaHeader6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaHeader6 *pp = (OspfLsaHeader6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getLsAge());
        case 1: return ulong2string(pp->getLsType());
        case 2: return ulong2string(pp->getLinkStateID());
        case 3: {std::stringstream out; out << pp->getAdvertisingRouter(); return out.str();}
        case 4: return ulong2string(pp->getLsSequenceNumber());
        default: return "";
    }
}

bool OspfLsaHeader6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaHeader6 *pp = (OspfLsaHeader6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setLsAge(string2ulong(value)); return true;
        case 1: pp->setLsType(string2ulong(value)); return true;
        case 2: pp->setLinkStateID(string2ulong(value)); return true;
        case 4: pp->setLsSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfLsaHeader6Descriptor::getFieldStructName(void *object, int field) const
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
        "RouterID",
        NULL,
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *OspfLsaHeader6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsaHeader6 *pp = (OspfLsaHeader6 *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getAdvertisingRouter()); break;
        default: return NULL;
    }
}

Register_Class(OspfLsa6);

OspfLsa6::OspfLsa6() : cObject()
{
}

OspfLsa6::OspfLsa6(const OspfLsa6& other) : cObject(other)
{
    copy(other);
}

OspfLsa6::~OspfLsa6()
{
}

OspfLsa6& OspfLsa6::operator=(const OspfLsa6& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    copy(other);
    return *this;
}

void OspfLsa6::copy(const OspfLsa6& other)
{
    this->header_var = other.header_var;
}

void OspfLsa6::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->header_var);
}

void OspfLsa6::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->header_var);
}

OspfLsaHeader6& OspfLsa6::getHeader()
{
    return header_var;
}

void OspfLsa6::setHeader(const OspfLsaHeader6& header)
{
    this->header_var = header;
}

class OspfLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfLsa6Descriptor();
    virtual ~OspfLsa6Descriptor();

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

Register_ClassDescriptor(OspfLsa6Descriptor);

OspfLsa6Descriptor::OspfLsa6Descriptor() : cClassDescriptor("OspfLsa6", "cObject")
{
}

OspfLsa6Descriptor::~OspfLsa6Descriptor()
{
}

bool OspfLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLsa6 *>(obj)!=NULL;
}

const char *OspfLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int OspfLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OspfLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "header",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int OspfLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "header")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "OspfLsaHeader6",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsa6 *pp = (OspfLsa6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsa6 *pp = (OspfLsa6 *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHeader(); return out.str();}
        default: return "";
    }
}

bool OspfLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsa6 *pp = (OspfLsa6 *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfLsa6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "OspfLsaHeader6",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *OspfLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLsa6 *pp = (OspfLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(&pp->getHeader()); break;
        default: return NULL;
    }
}

Register_Class(OspfRouterLsa6);

OspfRouterLsa6::OspfRouterLsa6() : OspfLsa6()
{
    this->V_VirtualLinkEndpoint_var = false;
    this->E_AsBoundaryRouter_var = false;
    this->B_AreaBorderRouter_var = false;
    links_arraysize = 0;
    this->links_var = 0;
}

OspfRouterLsa6::OspfRouterLsa6(const OspfRouterLsa6& other) : OspfLsa6(other)
{
    links_arraysize = 0;
    this->links_var = 0;
    copy(other);
}

OspfRouterLsa6::~OspfRouterLsa6()
{
    delete [] links_var;
}

OspfRouterLsa6& OspfRouterLsa6::operator=(const OspfRouterLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfRouterLsa6::copy(const OspfRouterLsa6& other)
{
    this->V_VirtualLinkEndpoint_var = other.V_VirtualLinkEndpoint_var;
    this->E_AsBoundaryRouter_var = other.E_AsBoundaryRouter_var;
    this->B_AreaBorderRouter_var = other.B_AreaBorderRouter_var;
    this->options_var = other.options_var;
    delete [] this->links_var;
    this->links_var = (other.links_arraysize==0) ? NULL : new Link6[other.links_arraysize];
    links_arraysize = other.links_arraysize;
    for (unsigned int i=0; i<links_arraysize; i++)
        this->links_var[i] = other.links_var[i];
}

void OspfRouterLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->V_VirtualLinkEndpoint_var);
    doPacking(b,this->E_AsBoundaryRouter_var);
    doPacking(b,this->B_AreaBorderRouter_var);
    doPacking(b,this->options_var);
    b->pack(links_arraysize);
    doPacking(b,this->links_var,links_arraysize);
}

void OspfRouterLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->V_VirtualLinkEndpoint_var);
    doUnpacking(b,this->E_AsBoundaryRouter_var);
    doUnpacking(b,this->B_AreaBorderRouter_var);
    doUnpacking(b,this->options_var);
    delete [] this->links_var;
    b->unpack(links_arraysize);
    if (links_arraysize==0) {
        this->links_var = 0;
    } else {
        this->links_var = new Link6[links_arraysize];
        doUnpacking(b,this->links_var,links_arraysize);
    }
}

bool OspfRouterLsa6::getV_VirtualLinkEndpoint() const
{
    return V_VirtualLinkEndpoint_var;
}

void OspfRouterLsa6::setV_VirtualLinkEndpoint(bool V_VirtualLinkEndpoint)
{
    this->V_VirtualLinkEndpoint_var = V_VirtualLinkEndpoint;
}

bool OspfRouterLsa6::getE_AsBoundaryRouter() const
{
    return E_AsBoundaryRouter_var;
}

void OspfRouterLsa6::setE_AsBoundaryRouter(bool E_AsBoundaryRouter)
{
    this->E_AsBoundaryRouter_var = E_AsBoundaryRouter;
}

bool OspfRouterLsa6::getB_AreaBorderRouter() const
{
    return B_AreaBorderRouter_var;
}

void OspfRouterLsa6::setB_AreaBorderRouter(bool B_AreaBorderRouter)
{
    this->B_AreaBorderRouter_var = B_AreaBorderRouter;
}

OspfOptions6& OspfRouterLsa6::getOptions()
{
    return options_var;
}

void OspfRouterLsa6::setOptions(const OspfOptions6& options)
{
    this->options_var = options;
}

void OspfRouterLsa6::setLinksArraySize(unsigned int size)
{
    Link6 *links_var2 = (size==0) ? NULL : new Link6[size];
    unsigned int sz = links_arraysize < size ? links_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        links_var2[i] = this->links_var[i];
    links_arraysize = size;
    delete [] this->links_var;
    this->links_var = links_var2;
}

unsigned int OspfRouterLsa6::getLinksArraySize() const
{
    return links_arraysize;
}

Link6& OspfRouterLsa6::getLinks(unsigned int k)
{
    if (k>=links_arraysize) throw cRuntimeError("Array of size %d indexed by %d", links_arraysize, k);
    return links_var[k];
}

void OspfRouterLsa6::setLinks(unsigned int k, const Link6& links)
{
    if (k>=links_arraysize) throw cRuntimeError("Array of size %d indexed by %d", links_arraysize, k);
    this->links_var[k] = links;
}

class OspfRouterLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfRouterLsa6Descriptor();
    virtual ~OspfRouterLsa6Descriptor();

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

Register_ClassDescriptor(OspfRouterLsa6Descriptor);

OspfRouterLsa6Descriptor::OspfRouterLsa6Descriptor() : cClassDescriptor("OspfRouterLsa6", "OspfLsa6")
{
}

OspfRouterLsa6Descriptor::~OspfRouterLsa6Descriptor()
{
}

bool OspfRouterLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfRouterLsa6 *>(obj)!=NULL;
}

const char *OspfRouterLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfRouterLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int OspfRouterLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OspfRouterLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "V_VirtualLinkEndpoint",
        "E_AsBoundaryRouter",
        "B_AreaBorderRouter",
        "options",
        "links",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int OspfRouterLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='V' && strcmp(fieldName, "V_VirtualLinkEndpoint")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_AsBoundaryRouter")==0) return base+1;
    if (fieldName[0]=='B' && strcmp(fieldName, "B_AreaBorderRouter")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "links")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfRouterLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "OspfOptions6",
        "Link6",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *OspfRouterLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfRouterLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfRouterLsa6 *pp = (OspfRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 4: return pp->getLinksArraySize();
        default: return 0;
    }
}

std::string OspfRouterLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfRouterLsa6 *pp = (OspfRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getV_VirtualLinkEndpoint());
        case 1: return bool2string(pp->getE_AsBoundaryRouter());
        case 2: return bool2string(pp->getB_AreaBorderRouter());
        case 3: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 4: {std::stringstream out; out << pp->getLinks(i); return out.str();}
        default: return "";
    }
}

bool OspfRouterLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfRouterLsa6 *pp = (OspfRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setV_VirtualLinkEndpoint(string2bool(value)); return true;
        case 1: pp->setE_AsBoundaryRouter(string2bool(value)); return true;
        case 2: pp->setB_AreaBorderRouter(string2bool(value)); return true;
        default: return false;
    }
}

const char *OspfRouterLsa6Descriptor::getFieldStructName(void *object, int field) const
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
        "OspfOptions6",
        "Link6",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *OspfRouterLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfRouterLsa6 *pp = (OspfRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getOptions()); break;
        case 4: return (void *)static_cast<cObject *>(&pp->getLinks(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfNetworkLsa6);

OspfNetworkLsa6::OspfNetworkLsa6() : OspfLsa6()
{
    attachedRouters_arraysize = 0;
    this->attachedRouters_var = 0;
}

OspfNetworkLsa6::OspfNetworkLsa6(const OspfNetworkLsa6& other) : OspfLsa6(other)
{
    attachedRouters_arraysize = 0;
    this->attachedRouters_var = 0;
    copy(other);
}

OspfNetworkLsa6::~OspfNetworkLsa6()
{
    delete [] attachedRouters_var;
}

OspfNetworkLsa6& OspfNetworkLsa6::operator=(const OspfNetworkLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfNetworkLsa6::copy(const OspfNetworkLsa6& other)
{
    this->options_var = other.options_var;
    delete [] this->attachedRouters_var;
    this->attachedRouters_var = (other.attachedRouters_arraysize==0) ? NULL : new RouterID[other.attachedRouters_arraysize];
    attachedRouters_arraysize = other.attachedRouters_arraysize;
    for (unsigned int i=0; i<attachedRouters_arraysize; i++)
        this->attachedRouters_var[i] = other.attachedRouters_var[i];
}

void OspfNetworkLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->options_var);
    b->pack(attachedRouters_arraysize);
    doPacking(b,this->attachedRouters_var,attachedRouters_arraysize);
}

void OspfNetworkLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->options_var);
    delete [] this->attachedRouters_var;
    b->unpack(attachedRouters_arraysize);
    if (attachedRouters_arraysize==0) {
        this->attachedRouters_var = 0;
    } else {
        this->attachedRouters_var = new RouterID[attachedRouters_arraysize];
        doUnpacking(b,this->attachedRouters_var,attachedRouters_arraysize);
    }
}

OspfOptions6& OspfNetworkLsa6::getOptions()
{
    return options_var;
}

void OspfNetworkLsa6::setOptions(const OspfOptions6& options)
{
    this->options_var = options;
}

void OspfNetworkLsa6::setAttachedRoutersArraySize(unsigned int size)
{
    RouterID *attachedRouters_var2 = (size==0) ? NULL : new RouterID[size];
    unsigned int sz = attachedRouters_arraysize < size ? attachedRouters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        attachedRouters_var2[i] = this->attachedRouters_var[i];
    attachedRouters_arraysize = size;
    delete [] this->attachedRouters_var;
    this->attachedRouters_var = attachedRouters_var2;
}

unsigned int OspfNetworkLsa6::getAttachedRoutersArraySize() const
{
    return attachedRouters_arraysize;
}

RouterID& OspfNetworkLsa6::getAttachedRouters(unsigned int k)
{
    if (k>=attachedRouters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", attachedRouters_arraysize, k);
    return attachedRouters_var[k];
}

void OspfNetworkLsa6::setAttachedRouters(unsigned int k, const RouterID& attachedRouters)
{
    if (k>=attachedRouters_arraysize) throw cRuntimeError("Array of size %d indexed by %d", attachedRouters_arraysize, k);
    this->attachedRouters_var[k] = attachedRouters;
}

class OspfNetworkLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfNetworkLsa6Descriptor();
    virtual ~OspfNetworkLsa6Descriptor();

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

Register_ClassDescriptor(OspfNetworkLsa6Descriptor);

OspfNetworkLsa6Descriptor::OspfNetworkLsa6Descriptor() : cClassDescriptor("OspfNetworkLsa6", "OspfLsa6")
{
}

OspfNetworkLsa6Descriptor::~OspfNetworkLsa6Descriptor()
{
}

bool OspfNetworkLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfNetworkLsa6 *>(obj)!=NULL;
}

const char *OspfNetworkLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfNetworkLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int OspfNetworkLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *OspfNetworkLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "options",
        "attachedRouters",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int OspfNetworkLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "attachedRouters")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfNetworkLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "OspfOptions6",
        "RouterID",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *OspfNetworkLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfNetworkLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfNetworkLsa6 *pp = (OspfNetworkLsa6 *)object; (void)pp;
    switch (field) {
        case 1: return pp->getAttachedRoutersArraySize();
        default: return 0;
    }
}

std::string OspfNetworkLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfNetworkLsa6 *pp = (OspfNetworkLsa6 *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 1: {std::stringstream out; out << pp->getAttachedRouters(i); return out.str();}
        default: return "";
    }
}

bool OspfNetworkLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfNetworkLsa6 *pp = (OspfNetworkLsa6 *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfNetworkLsa6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "OspfOptions6",
        "RouterID",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *OspfNetworkLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfNetworkLsa6 *pp = (OspfNetworkLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOptions()); break;
        case 1: return (void *)(&pp->getAttachedRouters(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfInterAreaPrefixLsa6);

OspfInterAreaPrefixLsa6::OspfInterAreaPrefixLsa6() : OspfLsa6()
{
    this->metric_var = 0;
    this->prefixLenght_var = 0;
}

OspfInterAreaPrefixLsa6::OspfInterAreaPrefixLsa6(const OspfInterAreaPrefixLsa6& other) : OspfLsa6(other)
{
    copy(other);
}

OspfInterAreaPrefixLsa6::~OspfInterAreaPrefixLsa6()
{
}

OspfInterAreaPrefixLsa6& OspfInterAreaPrefixLsa6::operator=(const OspfInterAreaPrefixLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfInterAreaPrefixLsa6::copy(const OspfInterAreaPrefixLsa6& other)
{
    this->metric_var = other.metric_var;
    this->prefixLenght_var = other.prefixLenght_var;
    this->prefixOptions_var = other.prefixOptions_var;
    this->addressPrefix_var = other.addressPrefix_var;
}

void OspfInterAreaPrefixLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->metric_var);
    doPacking(b,this->prefixLenght_var);
    doPacking(b,this->prefixOptions_var);
    doPacking(b,this->addressPrefix_var);
}

void OspfInterAreaPrefixLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->prefixLenght_var);
    doUnpacking(b,this->prefixOptions_var);
    doUnpacking(b,this->addressPrefix_var);
}

uint16 OspfInterAreaPrefixLsa6::getMetric() const
{
    return metric_var;
}

void OspfInterAreaPrefixLsa6::setMetric(uint16 metric)
{
    this->metric_var = metric;
}

uint8 OspfInterAreaPrefixLsa6::getPrefixLenght() const
{
    return prefixLenght_var;
}

void OspfInterAreaPrefixLsa6::setPrefixLenght(uint8 prefixLenght)
{
    this->prefixLenght_var = prefixLenght;
}

OspfPrefixOptions6& OspfInterAreaPrefixLsa6::getPrefixOptions()
{
    return prefixOptions_var;
}

void OspfInterAreaPrefixLsa6::setPrefixOptions(const OspfPrefixOptions6& prefixOptions)
{
    this->prefixOptions_var = prefixOptions;
}

IPv6Address& OspfInterAreaPrefixLsa6::getAddressPrefix()
{
    return addressPrefix_var;
}

void OspfInterAreaPrefixLsa6::setAddressPrefix(const IPv6Address& addressPrefix)
{
    this->addressPrefix_var = addressPrefix;
}

class OspfInterAreaPrefixLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfInterAreaPrefixLsa6Descriptor();
    virtual ~OspfInterAreaPrefixLsa6Descriptor();

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

Register_ClassDescriptor(OspfInterAreaPrefixLsa6Descriptor);

OspfInterAreaPrefixLsa6Descriptor::OspfInterAreaPrefixLsa6Descriptor() : cClassDescriptor("OspfInterAreaPrefixLsa6", "OspfLsa6")
{
}

OspfInterAreaPrefixLsa6Descriptor::~OspfInterAreaPrefixLsa6Descriptor()
{
}

bool OspfInterAreaPrefixLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfInterAreaPrefixLsa6 *>(obj)!=NULL;
}

const char *OspfInterAreaPrefixLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfInterAreaPrefixLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int OspfInterAreaPrefixLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *OspfInterAreaPrefixLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "metric",
        "prefixLenght",
        "prefixOptions",
        "addressPrefix",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int OspfInterAreaPrefixLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLenght")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixOptions")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressPrefix")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfInterAreaPrefixLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint8",
        "OspfPrefixOptions6",
        "IPv6Address",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *OspfInterAreaPrefixLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfInterAreaPrefixLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaPrefixLsa6 *pp = (OspfInterAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfInterAreaPrefixLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaPrefixLsa6 *pp = (OspfInterAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getMetric());
        case 1: return ulong2string(pp->getPrefixLenght());
        case 2: {std::stringstream out; out << pp->getPrefixOptions(); return out.str();}
        case 3: {std::stringstream out; out << pp->getAddressPrefix(); return out.str();}
        default: return "";
    }
}

bool OspfInterAreaPrefixLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaPrefixLsa6 *pp = (OspfInterAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setMetric(string2ulong(value)); return true;
        case 1: pp->setPrefixLenght(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfInterAreaPrefixLsa6Descriptor::getFieldStructName(void *object, int field) const
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
        "OspfPrefixOptions6",
        "IPv6Address",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *OspfInterAreaPrefixLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaPrefixLsa6 *pp = (OspfInterAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getPrefixOptions()); break;
        case 3: return (void *)(&pp->getAddressPrefix()); break;
        default: return NULL;
    }
}

Register_Class(OspfInterAreaRouterLsa6);

OspfInterAreaRouterLsa6::OspfInterAreaRouterLsa6() : OspfLsa6()
{
    this->metric_var = 0;
}

OspfInterAreaRouterLsa6::OspfInterAreaRouterLsa6(const OspfInterAreaRouterLsa6& other) : OspfLsa6(other)
{
    copy(other);
}

OspfInterAreaRouterLsa6::~OspfInterAreaRouterLsa6()
{
}

OspfInterAreaRouterLsa6& OspfInterAreaRouterLsa6::operator=(const OspfInterAreaRouterLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfInterAreaRouterLsa6::copy(const OspfInterAreaRouterLsa6& other)
{
    this->options_var = other.options_var;
    this->metric_var = other.metric_var;
    this->destinationRouterID_var = other.destinationRouterID_var;
}

void OspfInterAreaRouterLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->options_var);
    doPacking(b,this->metric_var);
    doPacking(b,this->destinationRouterID_var);
}

void OspfInterAreaRouterLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->options_var);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->destinationRouterID_var);
}

OspfOptions6& OspfInterAreaRouterLsa6::getOptions()
{
    return options_var;
}

void OspfInterAreaRouterLsa6::setOptions(const OspfOptions6& options)
{
    this->options_var = options;
}

uint16 OspfInterAreaRouterLsa6::getMetric() const
{
    return metric_var;
}

void OspfInterAreaRouterLsa6::setMetric(uint16 metric)
{
    this->metric_var = metric;
}

RouterID& OspfInterAreaRouterLsa6::getDestinationRouterID()
{
    return destinationRouterID_var;
}

void OspfInterAreaRouterLsa6::setDestinationRouterID(const RouterID& destinationRouterID)
{
    this->destinationRouterID_var = destinationRouterID;
}

class OspfInterAreaRouterLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfInterAreaRouterLsa6Descriptor();
    virtual ~OspfInterAreaRouterLsa6Descriptor();

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

Register_ClassDescriptor(OspfInterAreaRouterLsa6Descriptor);

OspfInterAreaRouterLsa6Descriptor::OspfInterAreaRouterLsa6Descriptor() : cClassDescriptor("OspfInterAreaRouterLsa6", "OspfLsa6")
{
}

OspfInterAreaRouterLsa6Descriptor::~OspfInterAreaRouterLsa6Descriptor()
{
}

bool OspfInterAreaRouterLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfInterAreaRouterLsa6 *>(obj)!=NULL;
}

const char *OspfInterAreaRouterLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfInterAreaRouterLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int OspfInterAreaRouterLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *OspfInterAreaRouterLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "options",
        "metric",
        "destinationRouterID",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int OspfInterAreaRouterLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationRouterID")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfInterAreaRouterLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "OspfOptions6",
        "uint16",
        "RouterID",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *OspfInterAreaRouterLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfInterAreaRouterLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaRouterLsa6 *pp = (OspfInterAreaRouterLsa6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfInterAreaRouterLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaRouterLsa6 *pp = (OspfInterAreaRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 1: return ulong2string(pp->getMetric());
        case 2: {std::stringstream out; out << pp->getDestinationRouterID(); return out.str();}
        default: return "";
    }
}

bool OspfInterAreaRouterLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaRouterLsa6 *pp = (OspfInterAreaRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 1: pp->setMetric(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfInterAreaRouterLsa6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "OspfOptions6",
        NULL,
        "RouterID",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *OspfInterAreaRouterLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfInterAreaRouterLsa6 *pp = (OspfInterAreaRouterLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOptions()); break;
        case 2: return (void *)(&pp->getDestinationRouterID()); break;
        default: return NULL;
    }
}

Register_Class(OspfAsExternalLsa6);

OspfAsExternalLsa6::OspfAsExternalLsa6() : OspfLsa6()
{
    this->E_ExternalMetricType_var = false;
    this->F_ForwardingAddress_var = false;
    this->T_ExternalRouteTag_var = false;
    this->metric_var = 0;
    this->prefixLenght_var = 0;
    this->referencedLsType_var = 0;
    this->externalRouteTag_var = 0;
    this->referencedLinkStateID_var = 0;
}

OspfAsExternalLsa6::OspfAsExternalLsa6(const OspfAsExternalLsa6& other) : OspfLsa6(other)
{
    copy(other);
}

OspfAsExternalLsa6::~OspfAsExternalLsa6()
{
}

OspfAsExternalLsa6& OspfAsExternalLsa6::operator=(const OspfAsExternalLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfAsExternalLsa6::copy(const OspfAsExternalLsa6& other)
{
    this->E_ExternalMetricType_var = other.E_ExternalMetricType_var;
    this->F_ForwardingAddress_var = other.F_ForwardingAddress_var;
    this->T_ExternalRouteTag_var = other.T_ExternalRouteTag_var;
    this->metric_var = other.metric_var;
    this->prefixLenght_var = other.prefixLenght_var;
    this->prefixOptions_var = other.prefixOptions_var;
    this->referencedLsType_var = other.referencedLsType_var;
    this->addressPrefix_var = other.addressPrefix_var;
    this->forwardingAddress_var = other.forwardingAddress_var;
    this->externalRouteTag_var = other.externalRouteTag_var;
    this->referencedLinkStateID_var = other.referencedLinkStateID_var;
}

void OspfAsExternalLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->E_ExternalMetricType_var);
    doPacking(b,this->F_ForwardingAddress_var);
    doPacking(b,this->T_ExternalRouteTag_var);
    doPacking(b,this->metric_var);
    doPacking(b,this->prefixLenght_var);
    doPacking(b,this->prefixOptions_var);
    doPacking(b,this->referencedLsType_var);
    doPacking(b,this->addressPrefix_var);
    doPacking(b,this->forwardingAddress_var);
    doPacking(b,this->externalRouteTag_var);
    doPacking(b,this->referencedLinkStateID_var);
}

void OspfAsExternalLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->E_ExternalMetricType_var);
    doUnpacking(b,this->F_ForwardingAddress_var);
    doUnpacking(b,this->T_ExternalRouteTag_var);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->prefixLenght_var);
    doUnpacking(b,this->prefixOptions_var);
    doUnpacking(b,this->referencedLsType_var);
    doUnpacking(b,this->addressPrefix_var);
    doUnpacking(b,this->forwardingAddress_var);
    doUnpacking(b,this->externalRouteTag_var);
    doUnpacking(b,this->referencedLinkStateID_var);
}

bool OspfAsExternalLsa6::getE_ExternalMetricType() const
{
    return E_ExternalMetricType_var;
}

void OspfAsExternalLsa6::setE_ExternalMetricType(bool E_ExternalMetricType)
{
    this->E_ExternalMetricType_var = E_ExternalMetricType;
}

bool OspfAsExternalLsa6::getF_ForwardingAddress() const
{
    return F_ForwardingAddress_var;
}

void OspfAsExternalLsa6::setF_ForwardingAddress(bool F_ForwardingAddress)
{
    this->F_ForwardingAddress_var = F_ForwardingAddress;
}

bool OspfAsExternalLsa6::getT_ExternalRouteTag() const
{
    return T_ExternalRouteTag_var;
}

void OspfAsExternalLsa6::setT_ExternalRouteTag(bool T_ExternalRouteTag)
{
    this->T_ExternalRouteTag_var = T_ExternalRouteTag;
}

uint16 OspfAsExternalLsa6::getMetric() const
{
    return metric_var;
}

void OspfAsExternalLsa6::setMetric(uint16 metric)
{
    this->metric_var = metric;
}

uint8 OspfAsExternalLsa6::getPrefixLenght() const
{
    return prefixLenght_var;
}

void OspfAsExternalLsa6::setPrefixLenght(uint8 prefixLenght)
{
    this->prefixLenght_var = prefixLenght;
}

OspfPrefixOptions6& OspfAsExternalLsa6::getPrefixOptions()
{
    return prefixOptions_var;
}

void OspfAsExternalLsa6::setPrefixOptions(const OspfPrefixOptions6& prefixOptions)
{
    this->prefixOptions_var = prefixOptions;
}

uint16 OspfAsExternalLsa6::getReferencedLsType() const
{
    return referencedLsType_var;
}

void OspfAsExternalLsa6::setReferencedLsType(uint16 referencedLsType)
{
    this->referencedLsType_var = referencedLsType;
}

IPv6Address& OspfAsExternalLsa6::getAddressPrefix()
{
    return addressPrefix_var;
}

void OspfAsExternalLsa6::setAddressPrefix(const IPv6Address& addressPrefix)
{
    this->addressPrefix_var = addressPrefix;
}

IPv6Address& OspfAsExternalLsa6::getForwardingAddress()
{
    return forwardingAddress_var;
}

void OspfAsExternalLsa6::setForwardingAddress(const IPv6Address& forwardingAddress)
{
    this->forwardingAddress_var = forwardingAddress;
}

uint32 OspfAsExternalLsa6::getExternalRouteTag() const
{
    return externalRouteTag_var;
}

void OspfAsExternalLsa6::setExternalRouteTag(uint32 externalRouteTag)
{
    this->externalRouteTag_var = externalRouteTag;
}

uint32 OspfAsExternalLsa6::getReferencedLinkStateID() const
{
    return referencedLinkStateID_var;
}

void OspfAsExternalLsa6::setReferencedLinkStateID(uint32 referencedLinkStateID)
{
    this->referencedLinkStateID_var = referencedLinkStateID;
}

class OspfAsExternalLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfAsExternalLsa6Descriptor();
    virtual ~OspfAsExternalLsa6Descriptor();

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

Register_ClassDescriptor(OspfAsExternalLsa6Descriptor);

OspfAsExternalLsa6Descriptor::OspfAsExternalLsa6Descriptor() : cClassDescriptor("OspfAsExternalLsa6", "OspfLsa6")
{
}

OspfAsExternalLsa6Descriptor::~OspfAsExternalLsa6Descriptor()
{
}

bool OspfAsExternalLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfAsExternalLsa6 *>(obj)!=NULL;
}

const char *OspfAsExternalLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfAsExternalLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int OspfAsExternalLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *OspfAsExternalLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "E_ExternalMetricType",
        "F_ForwardingAddress",
        "T_ExternalRouteTag",
        "metric",
        "prefixLenght",
        "prefixOptions",
        "referencedLsType",
        "addressPrefix",
        "forwardingAddress",
        "externalRouteTag",
        "referencedLinkStateID",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int OspfAsExternalLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_ExternalMetricType")==0) return base+0;
    if (fieldName[0]=='F' && strcmp(fieldName, "F_ForwardingAddress")==0) return base+1;
    if (fieldName[0]=='T' && strcmp(fieldName, "T_ExternalRouteTag")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLenght")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixOptions")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLsType")==0) return base+6;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressPrefix")==0) return base+7;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardingAddress")==0) return base+8;
    if (fieldName[0]=='e' && strcmp(fieldName, "externalRouteTag")==0) return base+9;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLinkStateID")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfAsExternalLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "uint16",
        "uint8",
        "OspfPrefixOptions6",
        "uint16",
        "IPv6Address",
        "IPv6Address",
        "uint32",
        "uint32",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *OspfAsExternalLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 6:
            if (!strcmp(propertyname,"enum")) return "LsaType6";
            return NULL;
        default: return NULL;
    }
}

int OspfAsExternalLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfAsExternalLsa6 *pp = (OspfAsExternalLsa6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfAsExternalLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfAsExternalLsa6 *pp = (OspfAsExternalLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getE_ExternalMetricType());
        case 1: return bool2string(pp->getF_ForwardingAddress());
        case 2: return bool2string(pp->getT_ExternalRouteTag());
        case 3: return ulong2string(pp->getMetric());
        case 4: return ulong2string(pp->getPrefixLenght());
        case 5: {std::stringstream out; out << pp->getPrefixOptions(); return out.str();}
        case 6: return ulong2string(pp->getReferencedLsType());
        case 7: {std::stringstream out; out << pp->getAddressPrefix(); return out.str();}
        case 8: {std::stringstream out; out << pp->getForwardingAddress(); return out.str();}
        case 9: return ulong2string(pp->getExternalRouteTag());
        case 10: return ulong2string(pp->getReferencedLinkStateID());
        default: return "";
    }
}

bool OspfAsExternalLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfAsExternalLsa6 *pp = (OspfAsExternalLsa6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setE_ExternalMetricType(string2bool(value)); return true;
        case 1: pp->setF_ForwardingAddress(string2bool(value)); return true;
        case 2: pp->setT_ExternalRouteTag(string2bool(value)); return true;
        case 3: pp->setMetric(string2ulong(value)); return true;
        case 4: pp->setPrefixLenght(string2ulong(value)); return true;
        case 6: pp->setReferencedLsType(string2ulong(value)); return true;
        case 9: pp->setExternalRouteTag(string2ulong(value)); return true;
        case 10: pp->setReferencedLinkStateID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfAsExternalLsa6Descriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        "OspfPrefixOptions6",
        NULL,
        "IPv6Address",
        "IPv6Address",
        NULL,
        NULL,
    };
    return (field>=0 && field<11) ? fieldStructNames[field] : NULL;
}

void *OspfAsExternalLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfAsExternalLsa6 *pp = (OspfAsExternalLsa6 *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getPrefixOptions()); break;
        case 7: return (void *)(&pp->getAddressPrefix()); break;
        case 8: return (void *)(&pp->getForwardingAddress()); break;
        default: return NULL;
    }
}

Register_Class(OspfLinkLsa6);

OspfLinkLsa6::OspfLinkLsa6() : OspfLsa6()
{
    this->rtrPriority_var = 0;
    prefixes_arraysize = 0;
    this->prefixes_var = 0;
}

OspfLinkLsa6::OspfLinkLsa6(const OspfLinkLsa6& other) : OspfLsa6(other)
{
    prefixes_arraysize = 0;
    this->prefixes_var = 0;
    copy(other);
}

OspfLinkLsa6::~OspfLinkLsa6()
{
    delete [] prefixes_var;
}

OspfLinkLsa6& OspfLinkLsa6::operator=(const OspfLinkLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkLsa6::copy(const OspfLinkLsa6& other)
{
    this->rtrPriority_var = other.rtrPriority_var;
    this->options_var = other.options_var;
    this->linkLocalAddress_var = other.linkLocalAddress_var;
    delete [] this->prefixes_var;
    this->prefixes_var = (other.prefixes_arraysize==0) ? NULL : new OspfPrefix6[other.prefixes_arraysize];
    prefixes_arraysize = other.prefixes_arraysize;
    for (unsigned int i=0; i<prefixes_arraysize; i++)
        this->prefixes_var[i] = other.prefixes_var[i];
}

void OspfLinkLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->rtrPriority_var);
    doPacking(b,this->options_var);
    doPacking(b,this->linkLocalAddress_var);
    b->pack(prefixes_arraysize);
    doPacking(b,this->prefixes_var,prefixes_arraysize);
}

void OspfLinkLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->rtrPriority_var);
    doUnpacking(b,this->options_var);
    doUnpacking(b,this->linkLocalAddress_var);
    delete [] this->prefixes_var;
    b->unpack(prefixes_arraysize);
    if (prefixes_arraysize==0) {
        this->prefixes_var = 0;
    } else {
        this->prefixes_var = new OspfPrefix6[prefixes_arraysize];
        doUnpacking(b,this->prefixes_var,prefixes_arraysize);
    }
}

uint8 OspfLinkLsa6::getRtrPriority() const
{
    return rtrPriority_var;
}

void OspfLinkLsa6::setRtrPriority(uint8 rtrPriority)
{
    this->rtrPriority_var = rtrPriority;
}

OspfOptions6& OspfLinkLsa6::getOptions()
{
    return options_var;
}

void OspfLinkLsa6::setOptions(const OspfOptions6& options)
{
    this->options_var = options;
}

IPv6Address& OspfLinkLsa6::getLinkLocalAddress()
{
    return linkLocalAddress_var;
}

void OspfLinkLsa6::setLinkLocalAddress(const IPv6Address& linkLocalAddress)
{
    this->linkLocalAddress_var = linkLocalAddress;
}

void OspfLinkLsa6::setPrefixesArraySize(unsigned int size)
{
    OspfPrefix6 *prefixes_var2 = (size==0) ? NULL : new OspfPrefix6[size];
    unsigned int sz = prefixes_arraysize < size ? prefixes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prefixes_var2[i] = this->prefixes_var[i];
    prefixes_arraysize = size;
    delete [] this->prefixes_var;
    this->prefixes_var = prefixes_var2;
}

unsigned int OspfLinkLsa6::getPrefixesArraySize() const
{
    return prefixes_arraysize;
}

OspfPrefix6& OspfLinkLsa6::getPrefixes(unsigned int k)
{
    if (k>=prefixes_arraysize) throw cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    return prefixes_var[k];
}

void OspfLinkLsa6::setPrefixes(unsigned int k, const OspfPrefix6& prefixes)
{
    if (k>=prefixes_arraysize) throw cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    this->prefixes_var[k] = prefixes;
}

class OspfLinkLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfLinkLsa6Descriptor();
    virtual ~OspfLinkLsa6Descriptor();

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

Register_ClassDescriptor(OspfLinkLsa6Descriptor);

OspfLinkLsa6Descriptor::OspfLinkLsa6Descriptor() : cClassDescriptor("OspfLinkLsa6", "OspfLsa6")
{
}

OspfLinkLsa6Descriptor::~OspfLinkLsa6Descriptor()
{
}

bool OspfLinkLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLinkLsa6 *>(obj)!=NULL;
}

const char *OspfLinkLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLinkLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int OspfLinkLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "rtrPriority",
        "options",
        "linkLocalAddress",
        "prefixes",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int OspfLinkLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtrPriority")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkLocalAddress")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixes")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLinkLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "OspfOptions6",
        "IPv6Address",
        "OspfPrefix6",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLinkLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfLinkLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkLsa6 *pp = (OspfLinkLsa6 *)object; (void)pp;
    switch (field) {
        case 3: return pp->getPrefixesArraySize();
        default: return 0;
    }
}

std::string OspfLinkLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkLsa6 *pp = (OspfLinkLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRtrPriority());
        case 1: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 2: {std::stringstream out; out << pp->getLinkLocalAddress(); return out.str();}
        case 3: {std::stringstream out; out << pp->getPrefixes(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkLsa6 *pp = (OspfLinkLsa6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setRtrPriority(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfLinkLsa6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "OspfOptions6",
        "IPv6Address",
        "OspfPrefix6",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *OspfLinkLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkLsa6 *pp = (OspfLinkLsa6 *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getOptions()); break;
        case 2: return (void *)(&pp->getLinkLocalAddress()); break;
        case 3: return (void *)static_cast<cObject *>(&pp->getPrefixes(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfIntraAreaPrefixLsa6);

OspfIntraAreaPrefixLsa6::OspfIntraAreaPrefixLsa6() : OspfLsa6()
{
    this->referencedLsType_var = 0;
    this->referencedLinkStateID_var = 0;
    prefixes_arraysize = 0;
    this->prefixes_var = 0;
}

OspfIntraAreaPrefixLsa6::OspfIntraAreaPrefixLsa6(const OspfIntraAreaPrefixLsa6& other) : OspfLsa6(other)
{
    prefixes_arraysize = 0;
    this->prefixes_var = 0;
    copy(other);
}

OspfIntraAreaPrefixLsa6::~OspfIntraAreaPrefixLsa6()
{
    delete [] prefixes_var;
}

OspfIntraAreaPrefixLsa6& OspfIntraAreaPrefixLsa6::operator=(const OspfIntraAreaPrefixLsa6& other)
{
    if (this==&other) return *this;
    OspfLsa6::operator=(other);
    copy(other);
    return *this;
}

void OspfIntraAreaPrefixLsa6::copy(const OspfIntraAreaPrefixLsa6& other)
{
    this->referencedLsType_var = other.referencedLsType_var;
    this->referencedLinkStateID_var = other.referencedLinkStateID_var;
    this->referencedAdvertisingRouter_var = other.referencedAdvertisingRouter_var;
    delete [] this->prefixes_var;
    this->prefixes_var = (other.prefixes_arraysize==0) ? NULL : new OspfPrefix6[other.prefixes_arraysize];
    prefixes_arraysize = other.prefixes_arraysize;
    for (unsigned int i=0; i<prefixes_arraysize; i++)
        this->prefixes_var[i] = other.prefixes_var[i];
}

void OspfIntraAreaPrefixLsa6::parsimPack(cCommBuffer *b)
{
    OspfLsa6::parsimPack(b);
    doPacking(b,this->referencedLsType_var);
    doPacking(b,this->referencedLinkStateID_var);
    doPacking(b,this->referencedAdvertisingRouter_var);
    b->pack(prefixes_arraysize);
    doPacking(b,this->prefixes_var,prefixes_arraysize);
}

void OspfIntraAreaPrefixLsa6::parsimUnpack(cCommBuffer *b)
{
    OspfLsa6::parsimUnpack(b);
    doUnpacking(b,this->referencedLsType_var);
    doUnpacking(b,this->referencedLinkStateID_var);
    doUnpacking(b,this->referencedAdvertisingRouter_var);
    delete [] this->prefixes_var;
    b->unpack(prefixes_arraysize);
    if (prefixes_arraysize==0) {
        this->prefixes_var = 0;
    } else {
        this->prefixes_var = new OspfPrefix6[prefixes_arraysize];
        doUnpacking(b,this->prefixes_var,prefixes_arraysize);
    }
}

uint16 OspfIntraAreaPrefixLsa6::getReferencedLsType() const
{
    return referencedLsType_var;
}

void OspfIntraAreaPrefixLsa6::setReferencedLsType(uint16 referencedLsType)
{
    this->referencedLsType_var = referencedLsType;
}

uint32 OspfIntraAreaPrefixLsa6::getReferencedLinkStateID() const
{
    return referencedLinkStateID_var;
}

void OspfIntraAreaPrefixLsa6::setReferencedLinkStateID(uint32 referencedLinkStateID)
{
    this->referencedLinkStateID_var = referencedLinkStateID;
}

RouterID& OspfIntraAreaPrefixLsa6::getReferencedAdvertisingRouter()
{
    return referencedAdvertisingRouter_var;
}

void OspfIntraAreaPrefixLsa6::setReferencedAdvertisingRouter(const RouterID& referencedAdvertisingRouter)
{
    this->referencedAdvertisingRouter_var = referencedAdvertisingRouter;
}

void OspfIntraAreaPrefixLsa6::setPrefixesArraySize(unsigned int size)
{
    OspfPrefix6 *prefixes_var2 = (size==0) ? NULL : new OspfPrefix6[size];
    unsigned int sz = prefixes_arraysize < size ? prefixes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prefixes_var2[i] = this->prefixes_var[i];
    prefixes_arraysize = size;
    delete [] this->prefixes_var;
    this->prefixes_var = prefixes_var2;
}

unsigned int OspfIntraAreaPrefixLsa6::getPrefixesArraySize() const
{
    return prefixes_arraysize;
}

OspfPrefix6& OspfIntraAreaPrefixLsa6::getPrefixes(unsigned int k)
{
    if (k>=prefixes_arraysize) throw cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    return prefixes_var[k];
}

void OspfIntraAreaPrefixLsa6::setPrefixes(unsigned int k, const OspfPrefix6& prefixes)
{
    if (k>=prefixes_arraysize) throw cRuntimeError("Array of size %d indexed by %d", prefixes_arraysize, k);
    this->prefixes_var[k] = prefixes;
}

class OspfIntraAreaPrefixLsa6Descriptor : public cClassDescriptor
{
  public:
    OspfIntraAreaPrefixLsa6Descriptor();
    virtual ~OspfIntraAreaPrefixLsa6Descriptor();

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

Register_ClassDescriptor(OspfIntraAreaPrefixLsa6Descriptor);

OspfIntraAreaPrefixLsa6Descriptor::OspfIntraAreaPrefixLsa6Descriptor() : cClassDescriptor("OspfIntraAreaPrefixLsa6", "OspfLsa6")
{
}

OspfIntraAreaPrefixLsa6Descriptor::~OspfIntraAreaPrefixLsa6Descriptor()
{
}

bool OspfIntraAreaPrefixLsa6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfIntraAreaPrefixLsa6 *>(obj)!=NULL;
}

const char *OspfIntraAreaPrefixLsa6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfIntraAreaPrefixLsa6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int OspfIntraAreaPrefixLsa6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *OspfIntraAreaPrefixLsa6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "referencedLsType",
        "referencedLinkStateID",
        "referencedAdvertisingRouter",
        "prefixes",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int OspfIntraAreaPrefixLsa6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLsType")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedLinkStateID")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "referencedAdvertisingRouter")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixes")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfIntraAreaPrefixLsa6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint32",
        "RouterID",
        "OspfPrefix6",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *OspfIntraAreaPrefixLsa6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "LsaType6";
            return NULL;
        default: return NULL;
    }
}

int OspfIntraAreaPrefixLsa6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfIntraAreaPrefixLsa6 *pp = (OspfIntraAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 3: return pp->getPrefixesArraySize();
        default: return 0;
    }
}

std::string OspfIntraAreaPrefixLsa6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfIntraAreaPrefixLsa6 *pp = (OspfIntraAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getReferencedLsType());
        case 1: return ulong2string(pp->getReferencedLinkStateID());
        case 2: {std::stringstream out; out << pp->getReferencedAdvertisingRouter(); return out.str();}
        case 3: {std::stringstream out; out << pp->getPrefixes(i); return out.str();}
        default: return "";
    }
}

bool OspfIntraAreaPrefixLsa6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfIntraAreaPrefixLsa6 *pp = (OspfIntraAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setReferencedLsType(string2ulong(value)); return true;
        case 1: pp->setReferencedLinkStateID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfIntraAreaPrefixLsa6Descriptor::getFieldStructName(void *object, int field) const
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
        "RouterID",
        "OspfPrefix6",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *OspfIntraAreaPrefixLsa6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfIntraAreaPrefixLsa6 *pp = (OspfIntraAreaPrefixLsa6 *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getReferencedAdvertisingRouter()); break;
        case 3: return (void *)static_cast<cObject *>(&pp->getPrefixes(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfPacket6);

OspfPacket6::OspfPacket6(const char *name, int kind) : cPacket(name,kind)
{
    this->version_var = 3;
    this->type_var = HelloPacket;
    this->instanceID_var = 0;
}

OspfPacket6::OspfPacket6(const OspfPacket6& other) : cPacket(other)
{
    copy(other);
}

OspfPacket6::~OspfPacket6()
{
}

OspfPacket6& OspfPacket6::operator=(const OspfPacket6& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void OspfPacket6::copy(const OspfPacket6& other)
{
    this->version_var = other.version_var;
    this->type_var = other.type_var;
    this->routerID_var = other.routerID_var;
    this->areaID_var = other.areaID_var;
    this->instanceID_var = other.instanceID_var;
}

void OspfPacket6::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->version_var);
    doPacking(b,this->type_var);
    doPacking(b,this->routerID_var);
    doPacking(b,this->areaID_var);
    doPacking(b,this->instanceID_var);
}

void OspfPacket6::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->routerID_var);
    doUnpacking(b,this->areaID_var);
    doUnpacking(b,this->instanceID_var);
}

uint8 OspfPacket6::getVersion() const
{
    return version_var;
}

void OspfPacket6::setVersion(uint8 version)
{
    this->version_var = version;
}

uint8 OspfPacket6::getType() const
{
    return type_var;
}

void OspfPacket6::setType(uint8 type)
{
    this->type_var = type;
}

RouterID& OspfPacket6::getRouterID()
{
    return routerID_var;
}

void OspfPacket6::setRouterID(const RouterID& routerID)
{
    this->routerID_var = routerID;
}

AreaID& OspfPacket6::getAreaID()
{
    return areaID_var;
}

void OspfPacket6::setAreaID(const AreaID& areaID)
{
    this->areaID_var = areaID;
}

InstanceID& OspfPacket6::getInstanceID()
{
    return instanceID_var;
}

void OspfPacket6::setInstanceID(const InstanceID& instanceID)
{
    this->instanceID_var = instanceID;
}

class OspfPacket6Descriptor : public cClassDescriptor
{
  public:
    OspfPacket6Descriptor();
    virtual ~OspfPacket6Descriptor();

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

Register_ClassDescriptor(OspfPacket6Descriptor);

OspfPacket6Descriptor::OspfPacket6Descriptor() : cClassDescriptor("OspfPacket6", "cPacket")
{
}

OspfPacket6Descriptor::~OspfPacket6Descriptor()
{
}

bool OspfPacket6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfPacket6 *>(obj)!=NULL;
}

const char *OspfPacket6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfPacket6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int OspfPacket6Descriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OspfPacket6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "version",
        "type",
        "routerID",
        "areaID",
        "instanceID",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int OspfPacket6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerID")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "areaID")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "instanceID")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfPacket6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "uint8",
        "RouterID",
        "AreaID",
        "InstanceID",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *OspfPacket6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "OspfPacketType6";
            return NULL;
        default: return NULL;
    }
}

int OspfPacket6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfPacket6 *pp = (OspfPacket6 *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OspfPacket6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfPacket6 *pp = (OspfPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getVersion());
        case 1: return ulong2string(pp->getType());
        case 2: {std::stringstream out; out << pp->getRouterID(); return out.str();}
        case 3: {std::stringstream out; out << pp->getAreaID(); return out.str();}
        case 4: {std::stringstream out; out << pp->getInstanceID(); return out.str();}
        default: return "";
    }
}

bool OspfPacket6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfPacket6 *pp = (OspfPacket6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2ulong(value)); return true;
        case 1: pp->setType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfPacket6Descriptor::getFieldStructName(void *object, int field) const
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
        "RouterID",
        "AreaID",
        "InstanceID",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *OspfPacket6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfPacket6 *pp = (OspfPacket6 *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getRouterID()); break;
        case 3: return (void *)(&pp->getAreaID()); break;
        case 4: return (void *)(&pp->getInstanceID()); break;
        default: return NULL;
    }
}

Register_Class(OspfHelloPacket6);

OspfHelloPacket6::OspfHelloPacket6(const char *name, int kind) : OspfPacket6(name,kind)
{
    this->rtrPriority_var = 0;
    this->helloInterval_var = 0;
    this->routerDeadInterval_var = 0;
    neighborID_arraysize = 0;
    this->neighborID_var = 0;
}

OspfHelloPacket6::OspfHelloPacket6(const OspfHelloPacket6& other) : OspfPacket6(other)
{
    neighborID_arraysize = 0;
    this->neighborID_var = 0;
    copy(other);
}

OspfHelloPacket6::~OspfHelloPacket6()
{
    delete [] neighborID_var;
}

OspfHelloPacket6& OspfHelloPacket6::operator=(const OspfHelloPacket6& other)
{
    if (this==&other) return *this;
    OspfPacket6::operator=(other);
    copy(other);
    return *this;
}

void OspfHelloPacket6::copy(const OspfHelloPacket6& other)
{
    this->interfaceID_var = other.interfaceID_var;
    this->rtrPriority_var = other.rtrPriority_var;
    this->options_var = other.options_var;
    this->helloInterval_var = other.helloInterval_var;
    this->routerDeadInterval_var = other.routerDeadInterval_var;
    this->designatedRouterID_var = other.designatedRouterID_var;
    this->backupDesignatedRouterID_var = other.backupDesignatedRouterID_var;
    delete [] this->neighborID_var;
    this->neighborID_var = (other.neighborID_arraysize==0) ? NULL : new RouterID[other.neighborID_arraysize];
    neighborID_arraysize = other.neighborID_arraysize;
    for (unsigned int i=0; i<neighborID_arraysize; i++)
        this->neighborID_var[i] = other.neighborID_var[i];
}

void OspfHelloPacket6::parsimPack(cCommBuffer *b)
{
    OspfPacket6::parsimPack(b);
    doPacking(b,this->interfaceID_var);
    doPacking(b,this->rtrPriority_var);
    doPacking(b,this->options_var);
    doPacking(b,this->helloInterval_var);
    doPacking(b,this->routerDeadInterval_var);
    doPacking(b,this->designatedRouterID_var);
    doPacking(b,this->backupDesignatedRouterID_var);
    b->pack(neighborID_arraysize);
    doPacking(b,this->neighborID_var,neighborID_arraysize);
}

void OspfHelloPacket6::parsimUnpack(cCommBuffer *b)
{
    OspfPacket6::parsimUnpack(b);
    doUnpacking(b,this->interfaceID_var);
    doUnpacking(b,this->rtrPriority_var);
    doUnpacking(b,this->options_var);
    doUnpacking(b,this->helloInterval_var);
    doUnpacking(b,this->routerDeadInterval_var);
    doUnpacking(b,this->designatedRouterID_var);
    doUnpacking(b,this->backupDesignatedRouterID_var);
    delete [] this->neighborID_var;
    b->unpack(neighborID_arraysize);
    if (neighborID_arraysize==0) {
        this->neighborID_var = 0;
    } else {
        this->neighborID_var = new RouterID[neighborID_arraysize];
        doUnpacking(b,this->neighborID_var,neighborID_arraysize);
    }
}

IfaceID& OspfHelloPacket6::getInterfaceID()
{
    return interfaceID_var;
}

void OspfHelloPacket6::setInterfaceID(const IfaceID& interfaceID)
{
    this->interfaceID_var = interfaceID;
}

uint8 OspfHelloPacket6::getRtrPriority() const
{
    return rtrPriority_var;
}

void OspfHelloPacket6::setRtrPriority(uint8 rtrPriority)
{
    this->rtrPriority_var = rtrPriority;
}

OspfOptions6& OspfHelloPacket6::getOptions()
{
    return options_var;
}

void OspfHelloPacket6::setOptions(const OspfOptions6& options)
{
    this->options_var = options;
}

uint16 OspfHelloPacket6::getHelloInterval() const
{
    return helloInterval_var;
}

void OspfHelloPacket6::setHelloInterval(uint16 helloInterval)
{
    this->helloInterval_var = helloInterval;
}

uint16 OspfHelloPacket6::getRouterDeadInterval() const
{
    return routerDeadInterval_var;
}

void OspfHelloPacket6::setRouterDeadInterval(uint16 routerDeadInterval)
{
    this->routerDeadInterval_var = routerDeadInterval;
}

DesignatedRouterID& OspfHelloPacket6::getDesignatedRouterID()
{
    return designatedRouterID_var;
}

void OspfHelloPacket6::setDesignatedRouterID(const DesignatedRouterID& designatedRouterID)
{
    this->designatedRouterID_var = designatedRouterID;
}

DesignatedRouterID& OspfHelloPacket6::getBackupDesignatedRouterID()
{
    return backupDesignatedRouterID_var;
}

void OspfHelloPacket6::setBackupDesignatedRouterID(const DesignatedRouterID& backupDesignatedRouterID)
{
    this->backupDesignatedRouterID_var = backupDesignatedRouterID;
}

void OspfHelloPacket6::setNeighborIDArraySize(unsigned int size)
{
    RouterID *neighborID_var2 = (size==0) ? NULL : new RouterID[size];
    unsigned int sz = neighborID_arraysize < size ? neighborID_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        neighborID_var2[i] = this->neighborID_var[i];
    neighborID_arraysize = size;
    delete [] this->neighborID_var;
    this->neighborID_var = neighborID_var2;
}

unsigned int OspfHelloPacket6::getNeighborIDArraySize() const
{
    return neighborID_arraysize;
}

RouterID& OspfHelloPacket6::getNeighborID(unsigned int k)
{
    if (k>=neighborID_arraysize) throw cRuntimeError("Array of size %d indexed by %d", neighborID_arraysize, k);
    return neighborID_var[k];
}

void OspfHelloPacket6::setNeighborID(unsigned int k, const RouterID& neighborID)
{
    if (k>=neighborID_arraysize) throw cRuntimeError("Array of size %d indexed by %d", neighborID_arraysize, k);
    this->neighborID_var[k] = neighborID;
}

class OspfHelloPacket6Descriptor : public cClassDescriptor
{
  public:
    OspfHelloPacket6Descriptor();
    virtual ~OspfHelloPacket6Descriptor();

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

Register_ClassDescriptor(OspfHelloPacket6Descriptor);

OspfHelloPacket6Descriptor::OspfHelloPacket6Descriptor() : cClassDescriptor("OspfHelloPacket6", "OspfPacket6")
{
}

OspfHelloPacket6Descriptor::~OspfHelloPacket6Descriptor()
{
}

bool OspfHelloPacket6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfHelloPacket6 *>(obj)!=NULL;
}

const char *OspfHelloPacket6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfHelloPacket6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int OspfHelloPacket6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OspfHelloPacket6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "interfaceID",
        "rtrPriority",
        "options",
        "helloInterval",
        "routerDeadInterval",
        "designatedRouterID",
        "backupDesignatedRouterID",
        "neighborID",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int OspfHelloPacket6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceID")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtrPriority")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "helloInterval")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerDeadInterval")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "designatedRouterID")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "backupDesignatedRouterID")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighborID")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfHelloPacket6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IfaceID",
        "uint8",
        "OspfOptions6",
        "uint16",
        "uint16",
        "DesignatedRouterID",
        "DesignatedRouterID",
        "RouterID",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *OspfHelloPacket6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfHelloPacket6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfHelloPacket6 *pp = (OspfHelloPacket6 *)object; (void)pp;
    switch (field) {
        case 7: return pp->getNeighborIDArraySize();
        default: return 0;
    }
}

std::string OspfHelloPacket6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfHelloPacket6 *pp = (OspfHelloPacket6 *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getInterfaceID(); return out.str();}
        case 1: return ulong2string(pp->getRtrPriority());
        case 2: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 3: return ulong2string(pp->getHelloInterval());
        case 4: return ulong2string(pp->getRouterDeadInterval());
        case 5: {std::stringstream out; out << pp->getDesignatedRouterID(); return out.str();}
        case 6: {std::stringstream out; out << pp->getBackupDesignatedRouterID(); return out.str();}
        case 7: {std::stringstream out; out << pp->getNeighborID(i); return out.str();}
        default: return "";
    }
}

bool OspfHelloPacket6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfHelloPacket6 *pp = (OspfHelloPacket6 *)object; (void)pp;
    switch (field) {
        case 1: pp->setRtrPriority(string2ulong(value)); return true;
        case 3: pp->setHelloInterval(string2ulong(value)); return true;
        case 4: pp->setRouterDeadInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfHelloPacket6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IfaceID",
        NULL,
        "OspfOptions6",
        NULL,
        NULL,
        "DesignatedRouterID",
        "DesignatedRouterID",
        "RouterID",
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *OspfHelloPacket6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfHelloPacket6 *pp = (OspfHelloPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getInterfaceID()); break;
        case 2: return (void *)(&pp->getOptions()); break;
        case 5: return (void *)(&pp->getDesignatedRouterID()); break;
        case 6: return (void *)(&pp->getBackupDesignatedRouterID()); break;
        case 7: return (void *)(&pp->getNeighborID(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfDatabaseDescriptionPacket6);

OspfDatabaseDescriptionPacket6::OspfDatabaseDescriptionPacket6(const char *name, int kind) : OspfPacket6(name,kind)
{
    this->interfaceMtu_var = 0;
    this->ddSequenceNumber_var = 0;
    lsaHeaders_arraysize = 0;
    this->lsaHeaders_var = 0;
}

OspfDatabaseDescriptionPacket6::OspfDatabaseDescriptionPacket6(const OspfDatabaseDescriptionPacket6& other) : OspfPacket6(other)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders_var = 0;
    copy(other);
}

OspfDatabaseDescriptionPacket6::~OspfDatabaseDescriptionPacket6()
{
    delete [] lsaHeaders_var;
}

OspfDatabaseDescriptionPacket6& OspfDatabaseDescriptionPacket6::operator=(const OspfDatabaseDescriptionPacket6& other)
{
    if (this==&other) return *this;
    OspfPacket6::operator=(other);
    copy(other);
    return *this;
}

void OspfDatabaseDescriptionPacket6::copy(const OspfDatabaseDescriptionPacket6& other)
{
    this->interfaceMtu_var = other.interfaceMtu_var;
    this->options_var = other.options_var;
    this->ddOptions_var = other.ddOptions_var;
    this->ddSequenceNumber_var = other.ddSequenceNumber_var;
    delete [] this->lsaHeaders_var;
    this->lsaHeaders_var = (other.lsaHeaders_arraysize==0) ? NULL : new OspfLsaHeader6[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (unsigned int i=0; i<lsaHeaders_arraysize; i++)
        this->lsaHeaders_var[i] = other.lsaHeaders_var[i];
}

void OspfDatabaseDescriptionPacket6::parsimPack(cCommBuffer *b)
{
    OspfPacket6::parsimPack(b);
    doPacking(b,this->interfaceMtu_var);
    doPacking(b,this->options_var);
    doPacking(b,this->ddOptions_var);
    doPacking(b,this->ddSequenceNumber_var);
    b->pack(lsaHeaders_arraysize);
    doPacking(b,this->lsaHeaders_var,lsaHeaders_arraysize);
}

void OspfDatabaseDescriptionPacket6::parsimUnpack(cCommBuffer *b)
{
    OspfPacket6::parsimUnpack(b);
    doUnpacking(b,this->interfaceMtu_var);
    doUnpacking(b,this->options_var);
    doUnpacking(b,this->ddOptions_var);
    doUnpacking(b,this->ddSequenceNumber_var);
    delete [] this->lsaHeaders_var;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize==0) {
        this->lsaHeaders_var = 0;
    } else {
        this->lsaHeaders_var = new OspfLsaHeader6[lsaHeaders_arraysize];
        doUnpacking(b,this->lsaHeaders_var,lsaHeaders_arraysize);
    }
}

uint16 OspfDatabaseDescriptionPacket6::getInterfaceMtu() const
{
    return interfaceMtu_var;
}

void OspfDatabaseDescriptionPacket6::setInterfaceMtu(uint16 interfaceMtu)
{
    this->interfaceMtu_var = interfaceMtu;
}

OspfOptions6& OspfDatabaseDescriptionPacket6::getOptions()
{
    return options_var;
}

void OspfDatabaseDescriptionPacket6::setOptions(const OspfOptions6& options)
{
    this->options_var = options;
}

OspfDdOptions6& OspfDatabaseDescriptionPacket6::getDdOptions()
{
    return ddOptions_var;
}

void OspfDatabaseDescriptionPacket6::setDdOptions(const OspfDdOptions6& ddOptions)
{
    this->ddOptions_var = ddOptions;
}

uint32 OspfDatabaseDescriptionPacket6::getDdSequenceNumber() const
{
    return ddSequenceNumber_var;
}

void OspfDatabaseDescriptionPacket6::setDdSequenceNumber(uint32 ddSequenceNumber)
{
    this->ddSequenceNumber_var = ddSequenceNumber;
}

void OspfDatabaseDescriptionPacket6::setLsaHeadersArraySize(unsigned int size)
{
    OspfLsaHeader6 *lsaHeaders_var2 = (size==0) ? NULL : new OspfLsaHeader6[size];
    unsigned int sz = lsaHeaders_arraysize < size ? lsaHeaders_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        lsaHeaders_var2[i] = this->lsaHeaders_var[i];
    lsaHeaders_arraysize = size;
    delete [] this->lsaHeaders_var;
    this->lsaHeaders_var = lsaHeaders_var2;
}

unsigned int OspfDatabaseDescriptionPacket6::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

OspfLsaHeader6& OspfDatabaseDescriptionPacket6::getLsaHeaders(unsigned int k)
{
    if (k>=lsaHeaders_arraysize) throw cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    return lsaHeaders_var[k];
}

void OspfDatabaseDescriptionPacket6::setLsaHeaders(unsigned int k, const OspfLsaHeader6& lsaHeaders)
{
    if (k>=lsaHeaders_arraysize) throw cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    this->lsaHeaders_var[k] = lsaHeaders;
}

class OspfDatabaseDescriptionPacket6Descriptor : public cClassDescriptor
{
  public:
    OspfDatabaseDescriptionPacket6Descriptor();
    virtual ~OspfDatabaseDescriptionPacket6Descriptor();

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

Register_ClassDescriptor(OspfDatabaseDescriptionPacket6Descriptor);

OspfDatabaseDescriptionPacket6Descriptor::OspfDatabaseDescriptionPacket6Descriptor() : cClassDescriptor("OspfDatabaseDescriptionPacket6", "OspfPacket6")
{
}

OspfDatabaseDescriptionPacket6Descriptor::~OspfDatabaseDescriptionPacket6Descriptor()
{
}

bool OspfDatabaseDescriptionPacket6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfDatabaseDescriptionPacket6 *>(obj)!=NULL;
}

const char *OspfDatabaseDescriptionPacket6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfDatabaseDescriptionPacket6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int OspfDatabaseDescriptionPacket6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OspfDatabaseDescriptionPacket6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "interfaceMtu",
        "options",
        "ddOptions",
        "ddSequenceNumber",
        "lsaHeaders",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int OspfDatabaseDescriptionPacket6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceMtu")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "ddOptions")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "ddSequenceNumber")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaHeaders")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfDatabaseDescriptionPacket6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "OspfOptions6",
        "OspfDdOptions6",
        "uint32",
        "OspfLsaHeader6",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *OspfDatabaseDescriptionPacket6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfDatabaseDescriptionPacket6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfDatabaseDescriptionPacket6 *pp = (OspfDatabaseDescriptionPacket6 *)object; (void)pp;
    switch (field) {
        case 4: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

std::string OspfDatabaseDescriptionPacket6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfDatabaseDescriptionPacket6 *pp = (OspfDatabaseDescriptionPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInterfaceMtu());
        case 1: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 2: {std::stringstream out; out << pp->getDdOptions(); return out.str();}
        case 3: return ulong2string(pp->getDdSequenceNumber());
        case 4: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OspfDatabaseDescriptionPacket6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfDatabaseDescriptionPacket6 *pp = (OspfDatabaseDescriptionPacket6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceMtu(string2ulong(value)); return true;
        case 3: pp->setDdSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfDatabaseDescriptionPacket6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "OspfOptions6",
        "OspfDdOptions6",
        NULL,
        "OspfLsaHeader6",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *OspfDatabaseDescriptionPacket6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfDatabaseDescriptionPacket6 *pp = (OspfDatabaseDescriptionPacket6 *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getOptions()); break;
        case 2: return (void *)(&pp->getDdOptions()); break;
        case 4: return (void *)static_cast<cObject *>(&pp->getLsaHeaders(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfLinkStateRequestPacket6);

OspfLinkStateRequestPacket6::OspfLinkStateRequestPacket6(const char *name, int kind) : OspfPacket6(name,kind)
{
    requests_arraysize = 0;
    this->requests_var = 0;
}

OspfLinkStateRequestPacket6::OspfLinkStateRequestPacket6(const OspfLinkStateRequestPacket6& other) : OspfPacket6(other)
{
    requests_arraysize = 0;
    this->requests_var = 0;
    copy(other);
}

OspfLinkStateRequestPacket6::~OspfLinkStateRequestPacket6()
{
    delete [] requests_var;
}

OspfLinkStateRequestPacket6& OspfLinkStateRequestPacket6::operator=(const OspfLinkStateRequestPacket6& other)
{
    if (this==&other) return *this;
    OspfPacket6::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkStateRequestPacket6::copy(const OspfLinkStateRequestPacket6& other)
{
    delete [] this->requests_var;
    this->requests_var = (other.requests_arraysize==0) ? NULL : new OspfLsaRequest6[other.requests_arraysize];
    requests_arraysize = other.requests_arraysize;
    for (unsigned int i=0; i<requests_arraysize; i++)
        this->requests_var[i] = other.requests_var[i];
}

void OspfLinkStateRequestPacket6::parsimPack(cCommBuffer *b)
{
    OspfPacket6::parsimPack(b);
    b->pack(requests_arraysize);
    doPacking(b,this->requests_var,requests_arraysize);
}

void OspfLinkStateRequestPacket6::parsimUnpack(cCommBuffer *b)
{
    OspfPacket6::parsimUnpack(b);
    delete [] this->requests_var;
    b->unpack(requests_arraysize);
    if (requests_arraysize==0) {
        this->requests_var = 0;
    } else {
        this->requests_var = new OspfLsaRequest6[requests_arraysize];
        doUnpacking(b,this->requests_var,requests_arraysize);
    }
}

void OspfLinkStateRequestPacket6::setRequestsArraySize(unsigned int size)
{
    OspfLsaRequest6 *requests_var2 = (size==0) ? NULL : new OspfLsaRequest6[size];
    unsigned int sz = requests_arraysize < size ? requests_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        requests_var2[i] = this->requests_var[i];
    requests_arraysize = size;
    delete [] this->requests_var;
    this->requests_var = requests_var2;
}

unsigned int OspfLinkStateRequestPacket6::getRequestsArraySize() const
{
    return requests_arraysize;
}

OspfLsaRequest6& OspfLinkStateRequestPacket6::getRequests(unsigned int k)
{
    if (k>=requests_arraysize) throw cRuntimeError("Array of size %d indexed by %d", requests_arraysize, k);
    return requests_var[k];
}

void OspfLinkStateRequestPacket6::setRequests(unsigned int k, const OspfLsaRequest6& requests)
{
    if (k>=requests_arraysize) throw cRuntimeError("Array of size %d indexed by %d", requests_arraysize, k);
    this->requests_var[k] = requests;
}

class OspfLinkStateRequestPacket6Descriptor : public cClassDescriptor
{
  public:
    OspfLinkStateRequestPacket6Descriptor();
    virtual ~OspfLinkStateRequestPacket6Descriptor();

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

Register_ClassDescriptor(OspfLinkStateRequestPacket6Descriptor);

OspfLinkStateRequestPacket6Descriptor::OspfLinkStateRequestPacket6Descriptor() : cClassDescriptor("OspfLinkStateRequestPacket6", "OspfPacket6")
{
}

OspfLinkStateRequestPacket6Descriptor::~OspfLinkStateRequestPacket6Descriptor()
{
}

bool OspfLinkStateRequestPacket6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLinkStateRequestPacket6 *>(obj)!=NULL;
}

const char *OspfLinkStateRequestPacket6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLinkStateRequestPacket6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int OspfLinkStateRequestPacket6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkStateRequestPacket6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "requests",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int OspfLinkStateRequestPacket6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requests")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLinkStateRequestPacket6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "OspfLsaRequest6",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLinkStateRequestPacket6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfLinkStateRequestPacket6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateRequestPacket6 *pp = (OspfLinkStateRequestPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return pp->getRequestsArraySize();
        default: return 0;
    }
}

std::string OspfLinkStateRequestPacket6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateRequestPacket6 *pp = (OspfLinkStateRequestPacket6 *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRequests(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkStateRequestPacket6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateRequestPacket6 *pp = (OspfLinkStateRequestPacket6 *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfLinkStateRequestPacket6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "OspfLsaRequest6",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *OspfLinkStateRequestPacket6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateRequestPacket6 *pp = (OspfLinkStateRequestPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRequests(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfLinkStateUpdatePacket6);

OspfLinkStateUpdatePacket6::OspfLinkStateUpdatePacket6(const char *name, int kind) : OspfPacket6(name,kind)
{
    this->numberOfLsas_var = 0;
    routerLsas_arraysize = 0;
    this->routerLsas_var = 0;
    networkLsas_arraysize = 0;
    this->networkLsas_var = 0;
    interAreaPrefixLsas_arraysize = 0;
    this->interAreaPrefixLsas_var = 0;
    interAreaRouterLsas_arraysize = 0;
    this->interAreaRouterLsas_var = 0;
    asExternalLsas_arraysize = 0;
    this->asExternalLsas_var = 0;
    linkLsas_arraysize = 0;
    this->linkLsas_var = 0;
    intraAreaPrefixLsas_arraysize = 0;
    this->intraAreaPrefixLsas_var = 0;
}

OspfLinkStateUpdatePacket6::OspfLinkStateUpdatePacket6(const OspfLinkStateUpdatePacket6& other) : OspfPacket6(other)
{
    routerLsas_arraysize = 0;
    this->routerLsas_var = 0;
    networkLsas_arraysize = 0;
    this->networkLsas_var = 0;
    interAreaPrefixLsas_arraysize = 0;
    this->interAreaPrefixLsas_var = 0;
    interAreaRouterLsas_arraysize = 0;
    this->interAreaRouterLsas_var = 0;
    asExternalLsas_arraysize = 0;
    this->asExternalLsas_var = 0;
    linkLsas_arraysize = 0;
    this->linkLsas_var = 0;
    intraAreaPrefixLsas_arraysize = 0;
    this->intraAreaPrefixLsas_var = 0;
    copy(other);
}

OspfLinkStateUpdatePacket6::~OspfLinkStateUpdatePacket6()
{
    delete [] routerLsas_var;
    delete [] networkLsas_var;
    delete [] interAreaPrefixLsas_var;
    delete [] interAreaRouterLsas_var;
    delete [] asExternalLsas_var;
    delete [] linkLsas_var;
    delete [] intraAreaPrefixLsas_var;
}

OspfLinkStateUpdatePacket6& OspfLinkStateUpdatePacket6::operator=(const OspfLinkStateUpdatePacket6& other)
{
    if (this==&other) return *this;
    OspfPacket6::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkStateUpdatePacket6::copy(const OspfLinkStateUpdatePacket6& other)
{
    this->numberOfLsas_var = other.numberOfLsas_var;
    delete [] this->routerLsas_var;
    this->routerLsas_var = (other.routerLsas_arraysize==0) ? NULL : new OspfRouterLsa6[other.routerLsas_arraysize];
    routerLsas_arraysize = other.routerLsas_arraysize;
    for (unsigned int i=0; i<routerLsas_arraysize; i++)
        this->routerLsas_var[i] = other.routerLsas_var[i];
    delete [] this->networkLsas_var;
    this->networkLsas_var = (other.networkLsas_arraysize==0) ? NULL : new OspfNetworkLsa6[other.networkLsas_arraysize];
    networkLsas_arraysize = other.networkLsas_arraysize;
    for (unsigned int i=0; i<networkLsas_arraysize; i++)
        this->networkLsas_var[i] = other.networkLsas_var[i];
    delete [] this->interAreaPrefixLsas_var;
    this->interAreaPrefixLsas_var = (other.interAreaPrefixLsas_arraysize==0) ? NULL : new OspfInterAreaPrefixLsa6[other.interAreaPrefixLsas_arraysize];
    interAreaPrefixLsas_arraysize = other.interAreaPrefixLsas_arraysize;
    for (unsigned int i=0; i<interAreaPrefixLsas_arraysize; i++)
        this->interAreaPrefixLsas_var[i] = other.interAreaPrefixLsas_var[i];
    delete [] this->interAreaRouterLsas_var;
    this->interAreaRouterLsas_var = (other.interAreaRouterLsas_arraysize==0) ? NULL : new OspfInterAreaRouterLsa6[other.interAreaRouterLsas_arraysize];
    interAreaRouterLsas_arraysize = other.interAreaRouterLsas_arraysize;
    for (unsigned int i=0; i<interAreaRouterLsas_arraysize; i++)
        this->interAreaRouterLsas_var[i] = other.interAreaRouterLsas_var[i];
    delete [] this->asExternalLsas_var;
    this->asExternalLsas_var = (other.asExternalLsas_arraysize==0) ? NULL : new OspfAsExternalLsa6[other.asExternalLsas_arraysize];
    asExternalLsas_arraysize = other.asExternalLsas_arraysize;
    for (unsigned int i=0; i<asExternalLsas_arraysize; i++)
        this->asExternalLsas_var[i] = other.asExternalLsas_var[i];
    delete [] this->linkLsas_var;
    this->linkLsas_var = (other.linkLsas_arraysize==0) ? NULL : new OspfLinkLsa6[other.linkLsas_arraysize];
    linkLsas_arraysize = other.linkLsas_arraysize;
    for (unsigned int i=0; i<linkLsas_arraysize; i++)
        this->linkLsas_var[i] = other.linkLsas_var[i];
    delete [] this->intraAreaPrefixLsas_var;
    this->intraAreaPrefixLsas_var = (other.intraAreaPrefixLsas_arraysize==0) ? NULL : new OspfIntraAreaPrefixLsa6[other.intraAreaPrefixLsas_arraysize];
    intraAreaPrefixLsas_arraysize = other.intraAreaPrefixLsas_arraysize;
    for (unsigned int i=0; i<intraAreaPrefixLsas_arraysize; i++)
        this->intraAreaPrefixLsas_var[i] = other.intraAreaPrefixLsas_var[i];
}

void OspfLinkStateUpdatePacket6::parsimPack(cCommBuffer *b)
{
    OspfPacket6::parsimPack(b);
    doPacking(b,this->numberOfLsas_var);
    b->pack(routerLsas_arraysize);
    doPacking(b,this->routerLsas_var,routerLsas_arraysize);
    b->pack(networkLsas_arraysize);
    doPacking(b,this->networkLsas_var,networkLsas_arraysize);
    b->pack(interAreaPrefixLsas_arraysize);
    doPacking(b,this->interAreaPrefixLsas_var,interAreaPrefixLsas_arraysize);
    b->pack(interAreaRouterLsas_arraysize);
    doPacking(b,this->interAreaRouterLsas_var,interAreaRouterLsas_arraysize);
    b->pack(asExternalLsas_arraysize);
    doPacking(b,this->asExternalLsas_var,asExternalLsas_arraysize);
    b->pack(linkLsas_arraysize);
    doPacking(b,this->linkLsas_var,linkLsas_arraysize);
    b->pack(intraAreaPrefixLsas_arraysize);
    doPacking(b,this->intraAreaPrefixLsas_var,intraAreaPrefixLsas_arraysize);
}

void OspfLinkStateUpdatePacket6::parsimUnpack(cCommBuffer *b)
{
    OspfPacket6::parsimUnpack(b);
    doUnpacking(b,this->numberOfLsas_var);
    delete [] this->routerLsas_var;
    b->unpack(routerLsas_arraysize);
    if (routerLsas_arraysize==0) {
        this->routerLsas_var = 0;
    } else {
        this->routerLsas_var = new OspfRouterLsa6[routerLsas_arraysize];
        doUnpacking(b,this->routerLsas_var,routerLsas_arraysize);
    }
    delete [] this->networkLsas_var;
    b->unpack(networkLsas_arraysize);
    if (networkLsas_arraysize==0) {
        this->networkLsas_var = 0;
    } else {
        this->networkLsas_var = new OspfNetworkLsa6[networkLsas_arraysize];
        doUnpacking(b,this->networkLsas_var,networkLsas_arraysize);
    }
    delete [] this->interAreaPrefixLsas_var;
    b->unpack(interAreaPrefixLsas_arraysize);
    if (interAreaPrefixLsas_arraysize==0) {
        this->interAreaPrefixLsas_var = 0;
    } else {
        this->interAreaPrefixLsas_var = new OspfInterAreaPrefixLsa6[interAreaPrefixLsas_arraysize];
        doUnpacking(b,this->interAreaPrefixLsas_var,interAreaPrefixLsas_arraysize);
    }
    delete [] this->interAreaRouterLsas_var;
    b->unpack(interAreaRouterLsas_arraysize);
    if (interAreaRouterLsas_arraysize==0) {
        this->interAreaRouterLsas_var = 0;
    } else {
        this->interAreaRouterLsas_var = new OspfInterAreaRouterLsa6[interAreaRouterLsas_arraysize];
        doUnpacking(b,this->interAreaRouterLsas_var,interAreaRouterLsas_arraysize);
    }
    delete [] this->asExternalLsas_var;
    b->unpack(asExternalLsas_arraysize);
    if (asExternalLsas_arraysize==0) {
        this->asExternalLsas_var = 0;
    } else {
        this->asExternalLsas_var = new OspfAsExternalLsa6[asExternalLsas_arraysize];
        doUnpacking(b,this->asExternalLsas_var,asExternalLsas_arraysize);
    }
    delete [] this->linkLsas_var;
    b->unpack(linkLsas_arraysize);
    if (linkLsas_arraysize==0) {
        this->linkLsas_var = 0;
    } else {
        this->linkLsas_var = new OspfLinkLsa6[linkLsas_arraysize];
        doUnpacking(b,this->linkLsas_var,linkLsas_arraysize);
    }
    delete [] this->intraAreaPrefixLsas_var;
    b->unpack(intraAreaPrefixLsas_arraysize);
    if (intraAreaPrefixLsas_arraysize==0) {
        this->intraAreaPrefixLsas_var = 0;
    } else {
        this->intraAreaPrefixLsas_var = new OspfIntraAreaPrefixLsa6[intraAreaPrefixLsas_arraysize];
        doUnpacking(b,this->intraAreaPrefixLsas_var,intraAreaPrefixLsas_arraysize);
    }
}

uint32 OspfLinkStateUpdatePacket6::getNumberOfLsas() const
{
    return numberOfLsas_var;
}

void OspfLinkStateUpdatePacket6::setNumberOfLsas(uint32 numberOfLsas)
{
    this->numberOfLsas_var = numberOfLsas;
}

void OspfLinkStateUpdatePacket6::setRouterLsasArraySize(unsigned int size)
{
    OspfRouterLsa6 *routerLsas_var2 = (size==0) ? NULL : new OspfRouterLsa6[size];
    unsigned int sz = routerLsas_arraysize < size ? routerLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        routerLsas_var2[i] = this->routerLsas_var[i];
    routerLsas_arraysize = size;
    delete [] this->routerLsas_var;
    this->routerLsas_var = routerLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getRouterLsasArraySize() const
{
    return routerLsas_arraysize;
}

OspfRouterLsa6& OspfLinkStateUpdatePacket6::getRouterLsas(unsigned int k)
{
    if (k>=routerLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", routerLsas_arraysize, k);
    return routerLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setRouterLsas(unsigned int k, const OspfRouterLsa6& routerLsas)
{
    if (k>=routerLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", routerLsas_arraysize, k);
    this->routerLsas_var[k] = routerLsas;
}

void OspfLinkStateUpdatePacket6::setNetworkLsasArraySize(unsigned int size)
{
    OspfNetworkLsa6 *networkLsas_var2 = (size==0) ? NULL : new OspfNetworkLsa6[size];
    unsigned int sz = networkLsas_arraysize < size ? networkLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        networkLsas_var2[i] = this->networkLsas_var[i];
    networkLsas_arraysize = size;
    delete [] this->networkLsas_var;
    this->networkLsas_var = networkLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getNetworkLsasArraySize() const
{
    return networkLsas_arraysize;
}

OspfNetworkLsa6& OspfLinkStateUpdatePacket6::getNetworkLsas(unsigned int k)
{
    if (k>=networkLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", networkLsas_arraysize, k);
    return networkLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setNetworkLsas(unsigned int k, const OspfNetworkLsa6& networkLsas)
{
    if (k>=networkLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", networkLsas_arraysize, k);
    this->networkLsas_var[k] = networkLsas;
}

void OspfLinkStateUpdatePacket6::setInterAreaPrefixLsasArraySize(unsigned int size)
{
    OspfInterAreaPrefixLsa6 *interAreaPrefixLsas_var2 = (size==0) ? NULL : new OspfInterAreaPrefixLsa6[size];
    unsigned int sz = interAreaPrefixLsas_arraysize < size ? interAreaPrefixLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        interAreaPrefixLsas_var2[i] = this->interAreaPrefixLsas_var[i];
    interAreaPrefixLsas_arraysize = size;
    delete [] this->interAreaPrefixLsas_var;
    this->interAreaPrefixLsas_var = interAreaPrefixLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getInterAreaPrefixLsasArraySize() const
{
    return interAreaPrefixLsas_arraysize;
}

OspfInterAreaPrefixLsa6& OspfLinkStateUpdatePacket6::getInterAreaPrefixLsas(unsigned int k)
{
    if (k>=interAreaPrefixLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", interAreaPrefixLsas_arraysize, k);
    return interAreaPrefixLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setInterAreaPrefixLsas(unsigned int k, const OspfInterAreaPrefixLsa6& interAreaPrefixLsas)
{
    if (k>=interAreaPrefixLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", interAreaPrefixLsas_arraysize, k);
    this->interAreaPrefixLsas_var[k] = interAreaPrefixLsas;
}

void OspfLinkStateUpdatePacket6::setInterAreaRouterLsasArraySize(unsigned int size)
{
    OspfInterAreaRouterLsa6 *interAreaRouterLsas_var2 = (size==0) ? NULL : new OspfInterAreaRouterLsa6[size];
    unsigned int sz = interAreaRouterLsas_arraysize < size ? interAreaRouterLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        interAreaRouterLsas_var2[i] = this->interAreaRouterLsas_var[i];
    interAreaRouterLsas_arraysize = size;
    delete [] this->interAreaRouterLsas_var;
    this->interAreaRouterLsas_var = interAreaRouterLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getInterAreaRouterLsasArraySize() const
{
    return interAreaRouterLsas_arraysize;
}

OspfInterAreaRouterLsa6& OspfLinkStateUpdatePacket6::getInterAreaRouterLsas(unsigned int k)
{
    if (k>=interAreaRouterLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", interAreaRouterLsas_arraysize, k);
    return interAreaRouterLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setInterAreaRouterLsas(unsigned int k, const OspfInterAreaRouterLsa6& interAreaRouterLsas)
{
    if (k>=interAreaRouterLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", interAreaRouterLsas_arraysize, k);
    this->interAreaRouterLsas_var[k] = interAreaRouterLsas;
}

void OspfLinkStateUpdatePacket6::setAsExternalLsasArraySize(unsigned int size)
{
    OspfAsExternalLsa6 *asExternalLsas_var2 = (size==0) ? NULL : new OspfAsExternalLsa6[size];
    unsigned int sz = asExternalLsas_arraysize < size ? asExternalLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        asExternalLsas_var2[i] = this->asExternalLsas_var[i];
    asExternalLsas_arraysize = size;
    delete [] this->asExternalLsas_var;
    this->asExternalLsas_var = asExternalLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getAsExternalLsasArraySize() const
{
    return asExternalLsas_arraysize;
}

OspfAsExternalLsa6& OspfLinkStateUpdatePacket6::getAsExternalLsas(unsigned int k)
{
    if (k>=asExternalLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", asExternalLsas_arraysize, k);
    return asExternalLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setAsExternalLsas(unsigned int k, const OspfAsExternalLsa6& asExternalLsas)
{
    if (k>=asExternalLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", asExternalLsas_arraysize, k);
    this->asExternalLsas_var[k] = asExternalLsas;
}

void OspfLinkStateUpdatePacket6::setLinkLsasArraySize(unsigned int size)
{
    OspfLinkLsa6 *linkLsas_var2 = (size==0) ? NULL : new OspfLinkLsa6[size];
    unsigned int sz = linkLsas_arraysize < size ? linkLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        linkLsas_var2[i] = this->linkLsas_var[i];
    linkLsas_arraysize = size;
    delete [] this->linkLsas_var;
    this->linkLsas_var = linkLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getLinkLsasArraySize() const
{
    return linkLsas_arraysize;
}

OspfLinkLsa6& OspfLinkStateUpdatePacket6::getLinkLsas(unsigned int k)
{
    if (k>=linkLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", linkLsas_arraysize, k);
    return linkLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setLinkLsas(unsigned int k, const OspfLinkLsa6& linkLsas)
{
    if (k>=linkLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", linkLsas_arraysize, k);
    this->linkLsas_var[k] = linkLsas;
}

void OspfLinkStateUpdatePacket6::setIntraAreaPrefixLsasArraySize(unsigned int size)
{
    OspfIntraAreaPrefixLsa6 *intraAreaPrefixLsas_var2 = (size==0) ? NULL : new OspfIntraAreaPrefixLsa6[size];
    unsigned int sz = intraAreaPrefixLsas_arraysize < size ? intraAreaPrefixLsas_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        intraAreaPrefixLsas_var2[i] = this->intraAreaPrefixLsas_var[i];
    intraAreaPrefixLsas_arraysize = size;
    delete [] this->intraAreaPrefixLsas_var;
    this->intraAreaPrefixLsas_var = intraAreaPrefixLsas_var2;
}

unsigned int OspfLinkStateUpdatePacket6::getIntraAreaPrefixLsasArraySize() const
{
    return intraAreaPrefixLsas_arraysize;
}

OspfIntraAreaPrefixLsa6& OspfLinkStateUpdatePacket6::getIntraAreaPrefixLsas(unsigned int k)
{
    if (k>=intraAreaPrefixLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", intraAreaPrefixLsas_arraysize, k);
    return intraAreaPrefixLsas_var[k];
}

void OspfLinkStateUpdatePacket6::setIntraAreaPrefixLsas(unsigned int k, const OspfIntraAreaPrefixLsa6& intraAreaPrefixLsas)
{
    if (k>=intraAreaPrefixLsas_arraysize) throw cRuntimeError("Array of size %d indexed by %d", intraAreaPrefixLsas_arraysize, k);
    this->intraAreaPrefixLsas_var[k] = intraAreaPrefixLsas;
}

class OspfLinkStateUpdatePacket6Descriptor : public cClassDescriptor
{
  public:
    OspfLinkStateUpdatePacket6Descriptor();
    virtual ~OspfLinkStateUpdatePacket6Descriptor();

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

Register_ClassDescriptor(OspfLinkStateUpdatePacket6Descriptor);

OspfLinkStateUpdatePacket6Descriptor::OspfLinkStateUpdatePacket6Descriptor() : cClassDescriptor("OspfLinkStateUpdatePacket6", "OspfPacket6")
{
}

OspfLinkStateUpdatePacket6Descriptor::~OspfLinkStateUpdatePacket6Descriptor()
{
}

bool OspfLinkStateUpdatePacket6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLinkStateUpdatePacket6 *>(obj)!=NULL;
}

const char *OspfLinkStateUpdatePacket6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLinkStateUpdatePacket6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int OspfLinkStateUpdatePacket6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkStateUpdatePacket6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numberOfLsas",
        "routerLsas",
        "networkLsas",
        "interAreaPrefixLsas",
        "interAreaRouterLsas",
        "asExternalLsas",
        "linkLsas",
        "intraAreaPrefixLsas",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int OspfLinkStateUpdatePacket6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfLsas")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerLsas")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkLsas")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "interAreaPrefixLsas")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "interAreaRouterLsas")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "asExternalLsas")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkLsas")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "intraAreaPrefixLsas")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLinkStateUpdatePacket6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "OspfRouterLsa6",
        "OspfNetworkLsa6",
        "OspfInterAreaPrefixLsa6",
        "OspfInterAreaRouterLsa6",
        "OspfAsExternalLsa6",
        "OspfLinkLsa6",
        "OspfIntraAreaPrefixLsa6",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLinkStateUpdatePacket6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfLinkStateUpdatePacket6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateUpdatePacket6 *pp = (OspfLinkStateUpdatePacket6 *)object; (void)pp;
    switch (field) {
        case 1: return pp->getRouterLsasArraySize();
        case 2: return pp->getNetworkLsasArraySize();
        case 3: return pp->getInterAreaPrefixLsasArraySize();
        case 4: return pp->getInterAreaRouterLsasArraySize();
        case 5: return pp->getAsExternalLsasArraySize();
        case 6: return pp->getLinkLsasArraySize();
        case 7: return pp->getIntraAreaPrefixLsasArraySize();
        default: return 0;
    }
}

std::string OspfLinkStateUpdatePacket6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateUpdatePacket6 *pp = (OspfLinkStateUpdatePacket6 *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNumberOfLsas());
        case 1: {std::stringstream out; out << pp->getRouterLsas(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getNetworkLsas(i); return out.str();}
        case 3: {std::stringstream out; out << pp->getInterAreaPrefixLsas(i); return out.str();}
        case 4: {std::stringstream out; out << pp->getInterAreaRouterLsas(i); return out.str();}
        case 5: {std::stringstream out; out << pp->getAsExternalLsas(i); return out.str();}
        case 6: {std::stringstream out; out << pp->getLinkLsas(i); return out.str();}
        case 7: {std::stringstream out; out << pp->getIntraAreaPrefixLsas(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkStateUpdatePacket6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateUpdatePacket6 *pp = (OspfLinkStateUpdatePacket6 *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumberOfLsas(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OspfLinkStateUpdatePacket6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "OspfRouterLsa6",
        "OspfNetworkLsa6",
        "OspfInterAreaPrefixLsa6",
        "OspfInterAreaRouterLsa6",
        "OspfAsExternalLsa6",
        "OspfLinkLsa6",
        "OspfIntraAreaPrefixLsa6",
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *OspfLinkStateUpdatePacket6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateUpdatePacket6 *pp = (OspfLinkStateUpdatePacket6 *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<cObject *>(&pp->getRouterLsas(i)); break;
        case 2: return (void *)static_cast<cObject *>(&pp->getNetworkLsas(i)); break;
        case 3: return (void *)static_cast<cObject *>(&pp->getInterAreaPrefixLsas(i)); break;
        case 4: return (void *)static_cast<cObject *>(&pp->getInterAreaRouterLsas(i)); break;
        case 5: return (void *)static_cast<cObject *>(&pp->getAsExternalLsas(i)); break;
        case 6: return (void *)static_cast<cObject *>(&pp->getLinkLsas(i)); break;
        case 7: return (void *)static_cast<cObject *>(&pp->getIntraAreaPrefixLsas(i)); break;
        default: return NULL;
    }
}

Register_Class(OspfLinkStateAcknowledgementPacket6);

OspfLinkStateAcknowledgementPacket6::OspfLinkStateAcknowledgementPacket6(const char *name, int kind) : OspfPacket6(name,kind)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders_var = 0;
}

OspfLinkStateAcknowledgementPacket6::OspfLinkStateAcknowledgementPacket6(const OspfLinkStateAcknowledgementPacket6& other) : OspfPacket6(other)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders_var = 0;
    copy(other);
}

OspfLinkStateAcknowledgementPacket6::~OspfLinkStateAcknowledgementPacket6()
{
    delete [] lsaHeaders_var;
}

OspfLinkStateAcknowledgementPacket6& OspfLinkStateAcknowledgementPacket6::operator=(const OspfLinkStateAcknowledgementPacket6& other)
{
    if (this==&other) return *this;
    OspfPacket6::operator=(other);
    copy(other);
    return *this;
}

void OspfLinkStateAcknowledgementPacket6::copy(const OspfLinkStateAcknowledgementPacket6& other)
{
    delete [] this->lsaHeaders_var;
    this->lsaHeaders_var = (other.lsaHeaders_arraysize==0) ? NULL : new OspfLsaHeader6[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (unsigned int i=0; i<lsaHeaders_arraysize; i++)
        this->lsaHeaders_var[i] = other.lsaHeaders_var[i];
}

void OspfLinkStateAcknowledgementPacket6::parsimPack(cCommBuffer *b)
{
    OspfPacket6::parsimPack(b);
    b->pack(lsaHeaders_arraysize);
    doPacking(b,this->lsaHeaders_var,lsaHeaders_arraysize);
}

void OspfLinkStateAcknowledgementPacket6::parsimUnpack(cCommBuffer *b)
{
    OspfPacket6::parsimUnpack(b);
    delete [] this->lsaHeaders_var;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize==0) {
        this->lsaHeaders_var = 0;
    } else {
        this->lsaHeaders_var = new OspfLsaHeader6[lsaHeaders_arraysize];
        doUnpacking(b,this->lsaHeaders_var,lsaHeaders_arraysize);
    }
}

void OspfLinkStateAcknowledgementPacket6::setLsaHeadersArraySize(unsigned int size)
{
    OspfLsaHeader6 *lsaHeaders_var2 = (size==0) ? NULL : new OspfLsaHeader6[size];
    unsigned int sz = lsaHeaders_arraysize < size ? lsaHeaders_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        lsaHeaders_var2[i] = this->lsaHeaders_var[i];
    lsaHeaders_arraysize = size;
    delete [] this->lsaHeaders_var;
    this->lsaHeaders_var = lsaHeaders_var2;
}

unsigned int OspfLinkStateAcknowledgementPacket6::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

OspfLsaHeader6& OspfLinkStateAcknowledgementPacket6::getLsaHeaders(unsigned int k)
{
    if (k>=lsaHeaders_arraysize) throw cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    return lsaHeaders_var[k];
}

void OspfLinkStateAcknowledgementPacket6::setLsaHeaders(unsigned int k, const OspfLsaHeader6& lsaHeaders)
{
    if (k>=lsaHeaders_arraysize) throw cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    this->lsaHeaders_var[k] = lsaHeaders;
}

class OspfLinkStateAcknowledgementPacket6Descriptor : public cClassDescriptor
{
  public:
    OspfLinkStateAcknowledgementPacket6Descriptor();
    virtual ~OspfLinkStateAcknowledgementPacket6Descriptor();

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

Register_ClassDescriptor(OspfLinkStateAcknowledgementPacket6Descriptor);

OspfLinkStateAcknowledgementPacket6Descriptor::OspfLinkStateAcknowledgementPacket6Descriptor() : cClassDescriptor("OspfLinkStateAcknowledgementPacket6", "OspfPacket6")
{
}

OspfLinkStateAcknowledgementPacket6Descriptor::~OspfLinkStateAcknowledgementPacket6Descriptor()
{
}

bool OspfLinkStateAcknowledgementPacket6Descriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<OspfLinkStateAcknowledgementPacket6 *>(obj)!=NULL;
}

const char *OspfLinkStateAcknowledgementPacket6Descriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OspfLinkStateAcknowledgementPacket6Descriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int OspfLinkStateAcknowledgementPacket6Descriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OspfLinkStateAcknowledgementPacket6Descriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "lsaHeaders",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int OspfLinkStateAcknowledgementPacket6Descriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaHeaders")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OspfLinkStateAcknowledgementPacket6Descriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "OspfLsaHeader6",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *OspfLinkStateAcknowledgementPacket6Descriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OspfLinkStateAcknowledgementPacket6Descriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateAcknowledgementPacket6 *pp = (OspfLinkStateAcknowledgementPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

std::string OspfLinkStateAcknowledgementPacket6Descriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateAcknowledgementPacket6 *pp = (OspfLinkStateAcknowledgementPacket6 *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OspfLinkStateAcknowledgementPacket6Descriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateAcknowledgementPacket6 *pp = (OspfLinkStateAcknowledgementPacket6 *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OspfLinkStateAcknowledgementPacket6Descriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "OspfLsaHeader6",
    };
    return (field>=0 && field<1) ? fieldStructNames[field] : NULL;
}

void *OspfLinkStateAcknowledgementPacket6Descriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    OspfLinkStateAcknowledgementPacket6 *pp = (OspfLinkStateAcknowledgementPacket6 *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<cObject *>(&pp->getLsaHeaders(i)); break;
        default: return NULL;
    }
}


