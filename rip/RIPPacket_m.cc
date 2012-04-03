//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/rip/RIPPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "RIPPacket_m.h"

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
    cEnum *e = cEnum::find("RIPCommand");
    if (!e) enums.getInstance()->add(e = new cEnum("RIPCommand"));
    e->insert(Request, "Request");
    e->insert(Response, "Response");
);

RouteEntry::RouteEntry()
{
    addressID = 0;
    mustBeZero2 = 0;
    mustBeZero3 = 0;
    mustBeZero4 = 0;
    metric = 0;
}

void doPacking(cCommBuffer *b, RouteEntry& a)
{
    doPacking(b,a.addressID);
    doPacking(b,a.mustBeZero2);
    doPacking(b,a.ipAddress);
    doPacking(b,a.mustBeZero3);
    doPacking(b,a.mustBeZero4);
    doPacking(b,a.metric);
}

void doUnpacking(cCommBuffer *b, RouteEntry& a)
{
    doUnpacking(b,a.addressID);
    doUnpacking(b,a.mustBeZero2);
    doUnpacking(b,a.ipAddress);
    doUnpacking(b,a.mustBeZero3);
    doUnpacking(b,a.mustBeZero4);
    doUnpacking(b,a.metric);
}

class RouteEntryDescriptor : public cClassDescriptor
{
  public:
    RouteEntryDescriptor();
    virtual ~RouteEntryDescriptor();

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

Register_ClassDescriptor(RouteEntryDescriptor);

RouteEntryDescriptor::RouteEntryDescriptor() : cClassDescriptor("RouteEntry", "")
{
}

RouteEntryDescriptor::~RouteEntryDescriptor()
{
}

bool RouteEntryDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RouteEntry *>(obj)!=NULL;
}

const char *RouteEntryDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RouteEntryDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int RouteEntryDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *RouteEntryDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "addressID",
        "mustBeZero2",
        "ipAddress",
        "mustBeZero3",
        "mustBeZero4",
        "metric",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int RouteEntryDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressID")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "mustBeZero2")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "ipAddress")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "mustBeZero3")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "mustBeZero4")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RouteEntryDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "short",
        "IPAddress",
        "long",
        "long",
        "long",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *RouteEntryDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RouteEntryDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RouteEntry *pp = (RouteEntry *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RouteEntryDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RouteEntry *pp = (RouteEntry *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->addressID);
        case 1: return long2string(pp->mustBeZero2);
        case 2: {std::stringstream out; out << pp->ipAddress; return out.str();}
        case 3: return long2string(pp->mustBeZero3);
        case 4: return long2string(pp->mustBeZero4);
        case 5: return long2string(pp->metric);
        default: return "";
    }
}

bool RouteEntryDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RouteEntry *pp = (RouteEntry *)object; (void)pp;
    switch (field) {
        case 0: pp->addressID = string2long(value); return true;
        case 1: pp->mustBeZero2 = string2long(value); return true;
        case 3: pp->mustBeZero3 = string2long(value); return true;
        case 4: pp->mustBeZero4 = string2long(value); return true;
        case 5: pp->metric = string2long(value); return true;
        default: return false;
    }
}

const char *RouteEntryDescriptor::getFieldStructName(void *object, int field) const
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
        "IPAddress",
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *RouteEntryDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RouteEntry *pp = (RouteEntry *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->ipAddress); break;
        default: return NULL;
    }
}

Register_Class(RIPPacket);

RIPPacket::RIPPacket(const char *name, int kind) : cMessage(name,kind)
{
    this->command_var = 0;
    this->version_var = 1;
    this->mustBeZero1_var = 0;
    routeEntry_arraysize = 0;
    this->routeEntry_var = 0;
}

RIPPacket::RIPPacket(const RIPPacket& other) : cMessage(other)
{
    routeEntry_arraysize = 0;
    this->routeEntry_var = 0;
    copy(other);
}

RIPPacket::~RIPPacket()
{
    delete [] routeEntry_var;
}

RIPPacket& RIPPacket::operator=(const RIPPacket& other)
{
    if (this==&other) return *this;
    cMessage::operator=(other);
    copy(other);
    return *this;
}

void RIPPacket::copy(const RIPPacket& other)
{
    this->command_var = other.command_var;
    this->version_var = other.version_var;
    this->mustBeZero1_var = other.mustBeZero1_var;
    delete [] this->routeEntry_var;
    this->routeEntry_var = (other.routeEntry_arraysize==0) ? NULL : new RouteEntry[other.routeEntry_arraysize];
    routeEntry_arraysize = other.routeEntry_arraysize;
    for (unsigned int i=0; i<routeEntry_arraysize; i++)
        this->routeEntry_var[i] = other.routeEntry_var[i];
}

void RIPPacket::parsimPack(cCommBuffer *b)
{
    cMessage::parsimPack(b);
    doPacking(b,this->command_var);
    doPacking(b,this->version_var);
    doPacking(b,this->mustBeZero1_var);
    b->pack(routeEntry_arraysize);
    doPacking(b,this->routeEntry_var,routeEntry_arraysize);
}

void RIPPacket::parsimUnpack(cCommBuffer *b)
{
    cMessage::parsimUnpack(b);
    doUnpacking(b,this->command_var);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->mustBeZero1_var);
    delete [] this->routeEntry_var;
    b->unpack(routeEntry_arraysize);
    if (routeEntry_arraysize==0) {
        this->routeEntry_var = 0;
    } else {
        this->routeEntry_var = new RouteEntry[routeEntry_arraysize];
        doUnpacking(b,this->routeEntry_var,routeEntry_arraysize);
    }
}

char RIPPacket::getCommand() const
{
    return command_var;
}

void RIPPacket::setCommand(char command)
{
    this->command_var = command;
}

char RIPPacket::getVersion() const
{
    return version_var;
}

void RIPPacket::setVersion(char version)
{
    this->version_var = version;
}

short RIPPacket::getMustBeZero1() const
{
    return mustBeZero1_var;
}

void RIPPacket::setMustBeZero1(short mustBeZero1)
{
    this->mustBeZero1_var = mustBeZero1;
}

void RIPPacket::setRouteEntryArraySize(unsigned int size)
{
    RouteEntry *routeEntry_var2 = (size==0) ? NULL : new RouteEntry[size];
    unsigned int sz = routeEntry_arraysize < size ? routeEntry_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        routeEntry_var2[i] = this->routeEntry_var[i];
    routeEntry_arraysize = size;
    delete [] this->routeEntry_var;
    this->routeEntry_var = routeEntry_var2;
}

unsigned int RIPPacket::getRouteEntryArraySize() const
{
    return routeEntry_arraysize;
}

RouteEntry& RIPPacket::getRouteEntry(unsigned int k)
{
    if (k>=routeEntry_arraysize) throw cRuntimeError("Array of size %d indexed by %d", routeEntry_arraysize, k);
    return routeEntry_var[k];
}

void RIPPacket::setRouteEntry(unsigned int k, const RouteEntry& routeEntry)
{
    if (k>=routeEntry_arraysize) throw cRuntimeError("Array of size %d indexed by %d", routeEntry_arraysize, k);
    this->routeEntry_var[k] = routeEntry;
}

class RIPPacketDescriptor : public cClassDescriptor
{
  public:
    RIPPacketDescriptor();
    virtual ~RIPPacketDescriptor();

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

Register_ClassDescriptor(RIPPacketDescriptor);

RIPPacketDescriptor::RIPPacketDescriptor() : cClassDescriptor("RIPPacket", "cMessage")
{
}

RIPPacketDescriptor::~RIPPacketDescriptor()
{
}

bool RIPPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RIPPacket *>(obj)!=NULL;
}

const char *RIPPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RIPPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int RIPPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *RIPPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "command",
        "version",
        "mustBeZero1",
        "routeEntry",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int RIPPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mustBeZero1")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "routeEntry")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RIPPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "char",
        "short",
        "RouteEntry",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *RIPPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "RIPCommand";
            return NULL;
        default: return NULL;
    }
}

int RIPPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 3: return pp->getRouteEntryArraySize();
        default: return 0;
    }
}

std::string RIPPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCommand());
        case 1: return long2string(pp->getVersion());
        case 2: return long2string(pp->getMustBeZero1());
        case 3: {std::stringstream out; out << pp->getRouteEntry(i); return out.str();}
        default: return "";
    }
}

bool RIPPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommand(string2long(value)); return true;
        case 1: pp->setVersion(string2long(value)); return true;
        case 2: pp->setMustBeZero1(string2long(value)); return true;
        default: return false;
    }
}

const char *RIPPacketDescriptor::getFieldStructName(void *object, int field) const
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
        "RouteEntry",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *RIPPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getRouteEntry(i)); break;
        default: return NULL;
    }
}

Register_Class(Hovno);

Hovno::Hovno(const char *name, int kind) : RIPPacket(name,kind)
{
    this->kokot_var = 0;
}

Hovno::Hovno(const Hovno& other) : RIPPacket(other)
{
    copy(other);
}

Hovno::~Hovno()
{
}

Hovno& Hovno::operator=(const Hovno& other)
{
    if (this==&other) return *this;
    RIPPacket::operator=(other);
    copy(other);
    return *this;
}

void Hovno::copy(const Hovno& other)
{
    this->kokot_var = other.kokot_var;
}

void Hovno::parsimPack(cCommBuffer *b)
{
    RIPPacket::parsimPack(b);
    doPacking(b,this->kokot_var);
}

void Hovno::parsimUnpack(cCommBuffer *b)
{
    RIPPacket::parsimUnpack(b);
    doUnpacking(b,this->kokot_var);
}

char Hovno::getKokot() const
{
    return kokot_var;
}

void Hovno::setKokot(char kokot)
{
    this->kokot_var = kokot;
}

class HovnoDescriptor : public cClassDescriptor
{
  public:
    HovnoDescriptor();
    virtual ~HovnoDescriptor();

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

Register_ClassDescriptor(HovnoDescriptor);

HovnoDescriptor::HovnoDescriptor() : cClassDescriptor("Hovno", "RIPPacket")
{
}

HovnoDescriptor::~HovnoDescriptor()
{
}

bool HovnoDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Hovno *>(obj)!=NULL;
}

const char *HovnoDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HovnoDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int HovnoDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *HovnoDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "kokot",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int HovnoDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "kokot")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HovnoDescriptor::getFieldTypeString(void *object, int field) const
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

const char *HovnoDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HovnoDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Hovno *pp = (Hovno *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HovnoDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Hovno *pp = (Hovno *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getKokot());
        default: return "";
    }
}

bool HovnoDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Hovno *pp = (Hovno *)object; (void)pp;
    switch (field) {
        case 0: pp->setKokot(string2long(value)); return true;
        default: return false;
    }
}

const char *HovnoDescriptor::getFieldStructName(void *object, int field) const
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

void *HovnoDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Hovno *pp = (Hovno *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


