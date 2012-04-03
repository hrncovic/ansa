//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/pim/PIMPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "PIMPacket_m.h"

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
    cEnum *e = cEnum::find("PIMPacketType");
    if (!e) enums.getInstance()->add(e = new cEnum("PIMPacketType"));
    e->insert(Hello, "Hello");
    e->insert(Register, "Register");
    e->insert(RegisterStop, "RegisterStop");
    e->insert(JoinPrune, "JoinPrune");
    e->insert(Bootstrap, "Bootstrap");
    e->insert(Assert, "Assert");
    e->insert(Graft, "Graft");
    e->insert(GraftAck, "GraftAck");
    e->insert(CandidateRPAdvertisement, "CandidateRPAdvertisement");
    e->insert(StateRefresh, "StateRefresh");
);

HelloEntry::HelloEntry()
{
    Type = 0;
    Value = 0;
}

void doPacking(cCommBuffer *b, HelloEntry& a)
{
    doPacking(b,a.Type);
    doPacking(b,a.Value);
}

void doUnpacking(cCommBuffer *b, HelloEntry& a)
{
    doUnpacking(b,a.Type);
    doUnpacking(b,a.Value);
}

class HelloEntryDescriptor : public cClassDescriptor
{
  public:
    HelloEntryDescriptor();
    virtual ~HelloEntryDescriptor();

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

Register_ClassDescriptor(HelloEntryDescriptor);

HelloEntryDescriptor::HelloEntryDescriptor() : cClassDescriptor("HelloEntry", "")
{
}

HelloEntryDescriptor::~HelloEntryDescriptor()
{
}

bool HelloEntryDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<HelloEntry *>(obj)!=NULL;
}

const char *HelloEntryDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int HelloEntryDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int HelloEntryDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *HelloEntryDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "Type",
        "Value",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int HelloEntryDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "Type")==0) return base+0;
    if (fieldName[0]=='V' && strcmp(fieldName, "Value")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *HelloEntryDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *HelloEntryDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int HelloEntryDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    HelloEntry *pp = (HelloEntry *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string HelloEntryDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    HelloEntry *pp = (HelloEntry *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->Type);
        case 1: return long2string(pp->Value);
        default: return "";
    }
}

bool HelloEntryDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    HelloEntry *pp = (HelloEntry *)object; (void)pp;
    switch (field) {
        case 0: pp->Type = string2long(value); return true;
        case 1: pp->Value = string2long(value); return true;
        default: return false;
    }
}

const char *HelloEntryDescriptor::getFieldStructName(void *object, int field) const
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

void *HelloEntryDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    HelloEntry *pp = (HelloEntry *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(MulticastGroup);

MulticastGroup::MulticastGroup() : cObject()
{
    joinedSourceAddress_arraysize = 0;
    this->joinedSourceAddress_var = 0;
    prunedSourceAddress_arraysize = 0;
    this->prunedSourceAddress_var = 0;
}

MulticastGroup::MulticastGroup(const MulticastGroup& other) : cObject(other)
{
    joinedSourceAddress_arraysize = 0;
    this->joinedSourceAddress_var = 0;
    prunedSourceAddress_arraysize = 0;
    this->prunedSourceAddress_var = 0;
    copy(other);
}

MulticastGroup::~MulticastGroup()
{
    delete [] joinedSourceAddress_var;
    delete [] prunedSourceAddress_var;
}

MulticastGroup& MulticastGroup::operator=(const MulticastGroup& other)
{
    if (this==&other) return *this;
    cObject::operator=(other);
    copy(other);
    return *this;
}

void MulticastGroup::copy(const MulticastGroup& other)
{
    this->groupAddress_var = other.groupAddress_var;
    delete [] this->joinedSourceAddress_var;
    this->joinedSourceAddress_var = (other.joinedSourceAddress_arraysize==0) ? NULL : new IPAddress[other.joinedSourceAddress_arraysize];
    joinedSourceAddress_arraysize = other.joinedSourceAddress_arraysize;
    for (unsigned int i=0; i<joinedSourceAddress_arraysize; i++)
        this->joinedSourceAddress_var[i] = other.joinedSourceAddress_var[i];
    delete [] this->prunedSourceAddress_var;
    this->prunedSourceAddress_var = (other.prunedSourceAddress_arraysize==0) ? NULL : new IPAddress[other.prunedSourceAddress_arraysize];
    prunedSourceAddress_arraysize = other.prunedSourceAddress_arraysize;
    for (unsigned int i=0; i<prunedSourceAddress_arraysize; i++)
        this->prunedSourceAddress_var[i] = other.prunedSourceAddress_var[i];
}

void MulticastGroup::parsimPack(cCommBuffer *b)
{
    doPacking(b,this->groupAddress_var);
    b->pack(joinedSourceAddress_arraysize);
    doPacking(b,this->joinedSourceAddress_var,joinedSourceAddress_arraysize);
    b->pack(prunedSourceAddress_arraysize);
    doPacking(b,this->prunedSourceAddress_var,prunedSourceAddress_arraysize);
}

void MulticastGroup::parsimUnpack(cCommBuffer *b)
{
    doUnpacking(b,this->groupAddress_var);
    delete [] this->joinedSourceAddress_var;
    b->unpack(joinedSourceAddress_arraysize);
    if (joinedSourceAddress_arraysize==0) {
        this->joinedSourceAddress_var = 0;
    } else {
        this->joinedSourceAddress_var = new IPAddress[joinedSourceAddress_arraysize];
        doUnpacking(b,this->joinedSourceAddress_var,joinedSourceAddress_arraysize);
    }
    delete [] this->prunedSourceAddress_var;
    b->unpack(prunedSourceAddress_arraysize);
    if (prunedSourceAddress_arraysize==0) {
        this->prunedSourceAddress_var = 0;
    } else {
        this->prunedSourceAddress_var = new IPAddress[prunedSourceAddress_arraysize];
        doUnpacking(b,this->prunedSourceAddress_var,prunedSourceAddress_arraysize);
    }
}

IPAddress& MulticastGroup::getGroupAddress()
{
    return groupAddress_var;
}

void MulticastGroup::setGroupAddress(const IPAddress& groupAddress)
{
    this->groupAddress_var = groupAddress;
}

void MulticastGroup::setJoinedSourceAddressArraySize(unsigned int size)
{
    IPAddress *joinedSourceAddress_var2 = (size==0) ? NULL : new IPAddress[size];
    unsigned int sz = joinedSourceAddress_arraysize < size ? joinedSourceAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        joinedSourceAddress_var2[i] = this->joinedSourceAddress_var[i];
    joinedSourceAddress_arraysize = size;
    delete [] this->joinedSourceAddress_var;
    this->joinedSourceAddress_var = joinedSourceAddress_var2;
}

unsigned int MulticastGroup::getJoinedSourceAddressArraySize() const
{
    return joinedSourceAddress_arraysize;
}

IPAddress& MulticastGroup::getJoinedSourceAddress(unsigned int k)
{
    if (k>=joinedSourceAddress_arraysize) throw cRuntimeError("Array of size %d indexed by %d", joinedSourceAddress_arraysize, k);
    return joinedSourceAddress_var[k];
}

void MulticastGroup::setJoinedSourceAddress(unsigned int k, const IPAddress& joinedSourceAddress)
{
    if (k>=joinedSourceAddress_arraysize) throw cRuntimeError("Array of size %d indexed by %d", joinedSourceAddress_arraysize, k);
    this->joinedSourceAddress_var[k] = joinedSourceAddress;
}

void MulticastGroup::setPrunedSourceAddressArraySize(unsigned int size)
{
    IPAddress *prunedSourceAddress_var2 = (size==0) ? NULL : new IPAddress[size];
    unsigned int sz = prunedSourceAddress_arraysize < size ? prunedSourceAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prunedSourceAddress_var2[i] = this->prunedSourceAddress_var[i];
    prunedSourceAddress_arraysize = size;
    delete [] this->prunedSourceAddress_var;
    this->prunedSourceAddress_var = prunedSourceAddress_var2;
}

unsigned int MulticastGroup::getPrunedSourceAddressArraySize() const
{
    return prunedSourceAddress_arraysize;
}

IPAddress& MulticastGroup::getPrunedSourceAddress(unsigned int k)
{
    if (k>=prunedSourceAddress_arraysize) throw cRuntimeError("Array of size %d indexed by %d", prunedSourceAddress_arraysize, k);
    return prunedSourceAddress_var[k];
}

void MulticastGroup::setPrunedSourceAddress(unsigned int k, const IPAddress& prunedSourceAddress)
{
    if (k>=prunedSourceAddress_arraysize) throw cRuntimeError("Array of size %d indexed by %d", prunedSourceAddress_arraysize, k);
    this->prunedSourceAddress_var[k] = prunedSourceAddress;
}

class MulticastGroupDescriptor : public cClassDescriptor
{
  public:
    MulticastGroupDescriptor();
    virtual ~MulticastGroupDescriptor();

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

Register_ClassDescriptor(MulticastGroupDescriptor);

MulticastGroupDescriptor::MulticastGroupDescriptor() : cClassDescriptor("MulticastGroup", "cObject")
{
}

MulticastGroupDescriptor::~MulticastGroupDescriptor()
{
}

bool MulticastGroupDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<MulticastGroup *>(obj)!=NULL;
}

const char *MulticastGroupDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int MulticastGroupDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int MulticastGroupDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *MulticastGroupDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "joinedSourceAddress",
        "prunedSourceAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int MulticastGroupDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinedSourceAddress")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prunedSourceAddress")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *MulticastGroupDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "IPAddress",
        "IPAddress",
        "IPAddress",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *MulticastGroupDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int MulticastGroupDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    MulticastGroup *pp = (MulticastGroup *)object; (void)pp;
    switch (field) {
        case 1: return pp->getJoinedSourceAddressArraySize();
        case 2: return pp->getPrunedSourceAddressArraySize();
        default: return 0;
    }
}

std::string MulticastGroupDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    MulticastGroup *pp = (MulticastGroup *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getJoinedSourceAddress(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getPrunedSourceAddress(i); return out.str();}
        default: return "";
    }
}

bool MulticastGroupDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    MulticastGroup *pp = (MulticastGroup *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *MulticastGroupDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        "IPAddress",
        "IPAddress",
        "IPAddress",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *MulticastGroupDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    MulticastGroup *pp = (MulticastGroup *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        case 1: return (void *)(&pp->getJoinedSourceAddress(i)); break;
        case 2: return (void *)(&pp->getPrunedSourceAddress(i)); break;
        default: return NULL;
    }
}

Register_Class(PIMPacket);

PIMPacket::PIMPacket(const char *name, int kind) : cPacket(name,kind)
{
    this->version_var = 2;
    this->type_var = 0;
}

PIMPacket::PIMPacket(const PIMPacket& other) : cPacket(other)
{
    copy(other);
}

PIMPacket::~PIMPacket()
{
}

PIMPacket& PIMPacket::operator=(const PIMPacket& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMPacket::copy(const PIMPacket& other)
{
    this->version_var = other.version_var;
    this->type_var = other.type_var;
}

void PIMPacket::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->version_var);
    doPacking(b,this->type_var);
}

void PIMPacket::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->type_var);
}

short PIMPacket::getVersion() const
{
    return version_var;
}

void PIMPacket::setVersion(short version)
{
    this->version_var = version;
}

short PIMPacket::getType() const
{
    return type_var;
}

void PIMPacket::setType(short type)
{
    this->type_var = type;
}

class PIMPacketDescriptor : public cClassDescriptor
{
  public:
    PIMPacketDescriptor();
    virtual ~PIMPacketDescriptor();

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

Register_ClassDescriptor(PIMPacketDescriptor);

PIMPacketDescriptor::PIMPacketDescriptor() : cClassDescriptor("PIMPacket", "cPacket")
{
}

PIMPacketDescriptor::~PIMPacketDescriptor()
{
}

bool PIMPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMPacket *>(obj)!=NULL;
}

const char *PIMPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PIMPacketDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *PIMPacketDescriptor::getFieldName(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PIMPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMPacketDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PIMPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVersion());
        case 1: return long2string(pp->getType());
        default: return "";
    }
}

bool PIMPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2long(value)); return true;
        case 1: pp->setType(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMPacketDescriptor::getFieldStructName(void *object, int field) const
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

void *PIMPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PIMHello);

PIMHello::PIMHello(const char *name, int kind) : PIMPacket(name,kind)
{
    this->type_var = Hello;
    helloContent_arraysize = 0;
    this->helloContent_var = 0;
}

PIMHello::PIMHello(const PIMHello& other) : PIMPacket(other)
{
    helloContent_arraysize = 0;
    this->helloContent_var = 0;
    copy(other);
}

PIMHello::~PIMHello()
{
    delete [] helloContent_var;
}

PIMHello& PIMHello::operator=(const PIMHello& other)
{
    if (this==&other) return *this;
    PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMHello::copy(const PIMHello& other)
{
    this->type_var = other.type_var;
    delete [] this->helloContent_var;
    this->helloContent_var = (other.helloContent_arraysize==0) ? NULL : new HelloEntry[other.helloContent_arraysize];
    helloContent_arraysize = other.helloContent_arraysize;
    for (unsigned int i=0; i<helloContent_arraysize; i++)
        this->helloContent_var[i] = other.helloContent_var[i];
}

void PIMHello::parsimPack(cCommBuffer *b)
{
    PIMPacket::parsimPack(b);
    doPacking(b,this->type_var);
    b->pack(helloContent_arraysize);
    doPacking(b,this->helloContent_var,helloContent_arraysize);
}

void PIMHello::parsimUnpack(cCommBuffer *b)
{
    PIMPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    delete [] this->helloContent_var;
    b->unpack(helloContent_arraysize);
    if (helloContent_arraysize==0) {
        this->helloContent_var = 0;
    } else {
        this->helloContent_var = new HelloEntry[helloContent_arraysize];
        doUnpacking(b,this->helloContent_var,helloContent_arraysize);
    }
}

short PIMHello::getType() const
{
    return type_var;
}

void PIMHello::setType(short type)
{
    this->type_var = type;
}

void PIMHello::setHelloContentArraySize(unsigned int size)
{
    HelloEntry *helloContent_var2 = (size==0) ? NULL : new HelloEntry[size];
    unsigned int sz = helloContent_arraysize < size ? helloContent_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        helloContent_var2[i] = this->helloContent_var[i];
    helloContent_arraysize = size;
    delete [] this->helloContent_var;
    this->helloContent_var = helloContent_var2;
}

unsigned int PIMHello::getHelloContentArraySize() const
{
    return helloContent_arraysize;
}

HelloEntry& PIMHello::getHelloContent(unsigned int k)
{
    if (k>=helloContent_arraysize) throw cRuntimeError("Array of size %d indexed by %d", helloContent_arraysize, k);
    return helloContent_var[k];
}

void PIMHello::setHelloContent(unsigned int k, const HelloEntry& helloContent)
{
    if (k>=helloContent_arraysize) throw cRuntimeError("Array of size %d indexed by %d", helloContent_arraysize, k);
    this->helloContent_var[k] = helloContent;
}

class PIMHelloDescriptor : public cClassDescriptor
{
  public:
    PIMHelloDescriptor();
    virtual ~PIMHelloDescriptor();

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

Register_ClassDescriptor(PIMHelloDescriptor);

PIMHelloDescriptor::PIMHelloDescriptor() : cClassDescriptor("PIMHello", "PIMPacket")
{
}

PIMHelloDescriptor::~PIMHelloDescriptor()
{
}

bool PIMHelloDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMHello *>(obj)!=NULL;
}

const char *PIMHelloDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMHelloDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PIMHelloDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *PIMHelloDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "helloContent",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PIMHelloDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "helloContent")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMHelloDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "HelloEntry",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PIMHelloDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMHelloDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMHello *pp = (PIMHello *)object; (void)pp;
    switch (field) {
        case 1: return pp->getHelloContentArraySize();
        default: return 0;
    }
}

std::string PIMHelloDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMHello *pp = (PIMHello *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: {std::stringstream out; out << pp->getHelloContent(i); return out.str();}
        default: return "";
    }
}

bool PIMHelloDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMHello *pp = (PIMHello *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMHelloDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "HelloEntry",
    };
    return (field>=0 && field<2) ? fieldStructNames[field] : NULL;
}

void *PIMHelloDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMHello *pp = (PIMHello *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getHelloContent(i)); break;
        default: return NULL;
    }
}

Register_Class(PIMJoinPrune);

PIMJoinPrune::PIMJoinPrune(const char *name, int kind) : PIMPacket(name,kind)
{
    this->type_var = JoinPrune;
    this->holdTime_var = 0;
    multicastGroups_arraysize = 0;
    this->multicastGroups_var = 0;
}

PIMJoinPrune::PIMJoinPrune(const PIMJoinPrune& other) : PIMPacket(other)
{
    multicastGroups_arraysize = 0;
    this->multicastGroups_var = 0;
    copy(other);
}

PIMJoinPrune::~PIMJoinPrune()
{
    delete [] multicastGroups_var;
}

PIMJoinPrune& PIMJoinPrune::operator=(const PIMJoinPrune& other)
{
    if (this==&other) return *this;
    PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMJoinPrune::copy(const PIMJoinPrune& other)
{
    this->type_var = other.type_var;
    this->upstreamNeighborAddress_var = other.upstreamNeighborAddress_var;
    this->holdTime_var = other.holdTime_var;
    delete [] this->multicastGroups_var;
    this->multicastGroups_var = (other.multicastGroups_arraysize==0) ? NULL : new MulticastGroup[other.multicastGroups_arraysize];
    multicastGroups_arraysize = other.multicastGroups_arraysize;
    for (unsigned int i=0; i<multicastGroups_arraysize; i++)
        this->multicastGroups_var[i] = other.multicastGroups_var[i];
}

void PIMJoinPrune::parsimPack(cCommBuffer *b)
{
    PIMPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->upstreamNeighborAddress_var);
    doPacking(b,this->holdTime_var);
    b->pack(multicastGroups_arraysize);
    doPacking(b,this->multicastGroups_var,multicastGroups_arraysize);
}

void PIMJoinPrune::parsimUnpack(cCommBuffer *b)
{
    PIMPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->upstreamNeighborAddress_var);
    doUnpacking(b,this->holdTime_var);
    delete [] this->multicastGroups_var;
    b->unpack(multicastGroups_arraysize);
    if (multicastGroups_arraysize==0) {
        this->multicastGroups_var = 0;
    } else {
        this->multicastGroups_var = new MulticastGroup[multicastGroups_arraysize];
        doUnpacking(b,this->multicastGroups_var,multicastGroups_arraysize);
    }
}

short PIMJoinPrune::getType() const
{
    return type_var;
}

void PIMJoinPrune::setType(short type)
{
    this->type_var = type;
}

IPAddress& PIMJoinPrune::getUpstreamNeighborAddress()
{
    return upstreamNeighborAddress_var;
}

void PIMJoinPrune::setUpstreamNeighborAddress(const IPAddress& upstreamNeighborAddress)
{
    this->upstreamNeighborAddress_var = upstreamNeighborAddress;
}

int PIMJoinPrune::getHoldTime() const
{
    return holdTime_var;
}

void PIMJoinPrune::setHoldTime(int holdTime)
{
    this->holdTime_var = holdTime;
}

void PIMJoinPrune::setMulticastGroupsArraySize(unsigned int size)
{
    MulticastGroup *multicastGroups_var2 = (size==0) ? NULL : new MulticastGroup[size];
    unsigned int sz = multicastGroups_arraysize < size ? multicastGroups_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        multicastGroups_var2[i] = this->multicastGroups_var[i];
    multicastGroups_arraysize = size;
    delete [] this->multicastGroups_var;
    this->multicastGroups_var = multicastGroups_var2;
}

unsigned int PIMJoinPrune::getMulticastGroupsArraySize() const
{
    return multicastGroups_arraysize;
}

MulticastGroup& PIMJoinPrune::getMulticastGroups(unsigned int k)
{
    if (k>=multicastGroups_arraysize) throw cRuntimeError("Array of size %d indexed by %d", multicastGroups_arraysize, k);
    return multicastGroups_var[k];
}

void PIMJoinPrune::setMulticastGroups(unsigned int k, const MulticastGroup& multicastGroups)
{
    if (k>=multicastGroups_arraysize) throw cRuntimeError("Array of size %d indexed by %d", multicastGroups_arraysize, k);
    this->multicastGroups_var[k] = multicastGroups;
}

class PIMJoinPruneDescriptor : public cClassDescriptor
{
  public:
    PIMJoinPruneDescriptor();
    virtual ~PIMJoinPruneDescriptor();

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

Register_ClassDescriptor(PIMJoinPruneDescriptor);

PIMJoinPruneDescriptor::PIMJoinPruneDescriptor() : cClassDescriptor("PIMJoinPrune", "PIMPacket")
{
}

PIMJoinPruneDescriptor::~PIMJoinPruneDescriptor()
{
}

bool PIMJoinPruneDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMJoinPrune *>(obj)!=NULL;
}

const char *PIMJoinPruneDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMJoinPruneDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int PIMJoinPruneDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *PIMJoinPruneDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "upstreamNeighborAddress",
        "holdTime",
        "multicastGroups",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int PIMJoinPruneDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "upstreamNeighborAddress")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastGroups")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMJoinPruneDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IPAddress",
        "int",
        "MulticastGroup",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *PIMJoinPruneDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMJoinPruneDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 3: return pp->getMulticastGroupsArraySize();
        default: return 0;
    }
}

std::string PIMJoinPruneDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: {std::stringstream out; out << pp->getUpstreamNeighborAddress(); return out.str();}
        case 2: return long2string(pp->getHoldTime());
        case 3: {std::stringstream out; out << pp->getMulticastGroups(i); return out.str();}
        default: return "";
    }
}

bool PIMJoinPruneDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 2: pp->setHoldTime(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMJoinPruneDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "IPAddress",
        NULL,
        "MulticastGroup",
    };
    return (field>=0 && field<4) ? fieldStructNames[field] : NULL;
}

void *PIMJoinPruneDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getUpstreamNeighborAddress()); break;
        case 3: return (void *)static_cast<cObject *>(&pp->getMulticastGroups(i)); break;
        default: return NULL;
    }
}

Register_Class(PIMAssert);

PIMAssert::PIMAssert(const char *name, int kind) : PIMPacket(name,kind)
{
    this->type_var = Assert;
    this->R_var = 0;
    this->metric_var = 0;
    this->metricPreference_var = 0;
}

PIMAssert::PIMAssert(const PIMAssert& other) : PIMPacket(other)
{
    copy(other);
}

PIMAssert::~PIMAssert()
{
}

PIMAssert& PIMAssert::operator=(const PIMAssert& other)
{
    if (this==&other) return *this;
    PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMAssert::copy(const PIMAssert& other)
{
    this->type_var = other.type_var;
    this->groupAddress_var = other.groupAddress_var;
    this->sourceAddress_var = other.sourceAddress_var;
    this->R_var = other.R_var;
    this->metric_var = other.metric_var;
    this->metricPreference_var = other.metricPreference_var;
}

void PIMAssert::parsimPack(cCommBuffer *b)
{
    PIMPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->groupAddress_var);
    doPacking(b,this->sourceAddress_var);
    doPacking(b,this->R_var);
    doPacking(b,this->metric_var);
    doPacking(b,this->metricPreference_var);
}

void PIMAssert::parsimUnpack(cCommBuffer *b)
{
    PIMPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->groupAddress_var);
    doUnpacking(b,this->sourceAddress_var);
    doUnpacking(b,this->R_var);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->metricPreference_var);
}

short PIMAssert::getType() const
{
    return type_var;
}

void PIMAssert::setType(short type)
{
    this->type_var = type;
}

IPAddress& PIMAssert::getGroupAddress()
{
    return groupAddress_var;
}

void PIMAssert::setGroupAddress(const IPAddress& groupAddress)
{
    this->groupAddress_var = groupAddress;
}

IPAddress& PIMAssert::getSourceAddress()
{
    return sourceAddress_var;
}

void PIMAssert::setSourceAddress(const IPAddress& sourceAddress)
{
    this->sourceAddress_var = sourceAddress;
}

bool PIMAssert::getR() const
{
    return R_var;
}

void PIMAssert::setR(bool R)
{
    this->R_var = R;
}

int PIMAssert::getMetric() const
{
    return metric_var;
}

void PIMAssert::setMetric(int metric)
{
    this->metric_var = metric;
}

int PIMAssert::getMetricPreference() const
{
    return metricPreference_var;
}

void PIMAssert::setMetricPreference(int metricPreference)
{
    this->metricPreference_var = metricPreference;
}

class PIMAssertDescriptor : public cClassDescriptor
{
  public:
    PIMAssertDescriptor();
    virtual ~PIMAssertDescriptor();

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

Register_ClassDescriptor(PIMAssertDescriptor);

PIMAssertDescriptor::PIMAssertDescriptor() : cClassDescriptor("PIMAssert", "PIMPacket")
{
}

PIMAssertDescriptor::~PIMAssertDescriptor()
{
}

bool PIMAssertDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMAssert *>(obj)!=NULL;
}

const char *PIMAssertDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMAssertDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int PIMAssertDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *PIMAssertDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "groupAddress",
        "sourceAddress",
        "R",
        "metric",
        "metricPreference",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int PIMAssertDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "R")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "metricPreference")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMAssertDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IPAddress",
        "IPAddress",
        "bool",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *PIMAssertDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMAssertDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMAssertDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceAddress(); return out.str();}
        case 3: return bool2string(pp->getR());
        case 4: return long2string(pp->getMetric());
        case 5: return long2string(pp->getMetricPreference());
        default: return "";
    }
}

bool PIMAssertDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 3: pp->setR(string2bool(value)); return true;
        case 4: pp->setMetric(string2long(value)); return true;
        case 5: pp->setMetricPreference(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMAssertDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "IPAddress",
        "IPAddress",
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *PIMAssertDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getGroupAddress()); break;
        case 2: return (void *)(&pp->getSourceAddress()); break;
        default: return NULL;
    }
}

Register_Class(PIMGraft);

PIMGraft::PIMGraft(const char *name, int kind) : PIMJoinPrune(name,kind)
{
    this->type_var = Graft;
    this->holdTime_var = 0;
}

PIMGraft::PIMGraft(const PIMGraft& other) : PIMJoinPrune(other)
{
    copy(other);
}

PIMGraft::~PIMGraft()
{
}

PIMGraft& PIMGraft::operator=(const PIMGraft& other)
{
    if (this==&other) return *this;
    PIMJoinPrune::operator=(other);
    copy(other);
    return *this;
}

void PIMGraft::copy(const PIMGraft& other)
{
    this->type_var = other.type_var;
    this->holdTime_var = other.holdTime_var;
}

void PIMGraft::parsimPack(cCommBuffer *b)
{
    PIMJoinPrune::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->holdTime_var);
}

void PIMGraft::parsimUnpack(cCommBuffer *b)
{
    PIMJoinPrune::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->holdTime_var);
}

short PIMGraft::getType() const
{
    return type_var;
}

void PIMGraft::setType(short type)
{
    this->type_var = type;
}

int PIMGraft::getHoldTime() const
{
    return holdTime_var;
}

void PIMGraft::setHoldTime(int holdTime)
{
    this->holdTime_var = holdTime;
}

class PIMGraftDescriptor : public cClassDescriptor
{
  public:
    PIMGraftDescriptor();
    virtual ~PIMGraftDescriptor();

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

Register_ClassDescriptor(PIMGraftDescriptor);

PIMGraftDescriptor::PIMGraftDescriptor() : cClassDescriptor("PIMGraft", "PIMJoinPrune")
{
}

PIMGraftDescriptor::~PIMGraftDescriptor()
{
}

bool PIMGraftDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMGraft *>(obj)!=NULL;
}

const char *PIMGraftDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMGraftDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PIMGraftDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *PIMGraftDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "holdTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PIMGraftDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMGraftDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PIMGraftDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMGraftDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMGraftDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return long2string(pp->getHoldTime());
        default: return "";
    }
}

bool PIMGraftDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setHoldTime(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMGraftDescriptor::getFieldStructName(void *object, int field) const
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

void *PIMGraftDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PIMGraftAck);

PIMGraftAck::PIMGraftAck(const char *name, int kind) : PIMJoinPrune(name,kind)
{
    this->type_var = GraftAck;
    this->holdTime_var = 0;
}

PIMGraftAck::PIMGraftAck(const PIMGraftAck& other) : PIMJoinPrune(other)
{
    copy(other);
}

PIMGraftAck::~PIMGraftAck()
{
}

PIMGraftAck& PIMGraftAck::operator=(const PIMGraftAck& other)
{
    if (this==&other) return *this;
    PIMJoinPrune::operator=(other);
    copy(other);
    return *this;
}

void PIMGraftAck::copy(const PIMGraftAck& other)
{
    this->type_var = other.type_var;
    this->holdTime_var = other.holdTime_var;
}

void PIMGraftAck::parsimPack(cCommBuffer *b)
{
    PIMJoinPrune::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->holdTime_var);
}

void PIMGraftAck::parsimUnpack(cCommBuffer *b)
{
    PIMJoinPrune::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->holdTime_var);
}

short PIMGraftAck::getType() const
{
    return type_var;
}

void PIMGraftAck::setType(short type)
{
    this->type_var = type;
}

int PIMGraftAck::getHoldTime() const
{
    return holdTime_var;
}

void PIMGraftAck::setHoldTime(int holdTime)
{
    this->holdTime_var = holdTime;
}

class PIMGraftAckDescriptor : public cClassDescriptor
{
  public:
    PIMGraftAckDescriptor();
    virtual ~PIMGraftAckDescriptor();

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

Register_ClassDescriptor(PIMGraftAckDescriptor);

PIMGraftAckDescriptor::PIMGraftAckDescriptor() : cClassDescriptor("PIMGraftAck", "PIMJoinPrune")
{
}

PIMGraftAckDescriptor::~PIMGraftAckDescriptor()
{
}

bool PIMGraftAckDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMGraftAck *>(obj)!=NULL;
}

const char *PIMGraftAckDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMGraftAckDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int PIMGraftAckDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *PIMGraftAckDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "holdTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int PIMGraftAckDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMGraftAckDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *PIMGraftAckDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMGraftAckDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMGraftAckDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return long2string(pp->getHoldTime());
        default: return "";
    }
}

bool PIMGraftAckDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setHoldTime(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMGraftAckDescriptor::getFieldStructName(void *object, int field) const
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

void *PIMGraftAckDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PIMStateRefresh);

PIMStateRefresh::PIMStateRefresh(const char *name, int kind) : PIMPacket(name,kind)
{
    this->type_var = StateRefresh;
    this->metric_var = 0;
    this->metricPreference_var = 0;
    this->maskLen_var = 0;
    this->ttl_var = 0;
    this->P_var = 0;
    this->interval_var = 0;
}

PIMStateRefresh::PIMStateRefresh(const PIMStateRefresh& other) : PIMPacket(other)
{
    copy(other);
}

PIMStateRefresh::~PIMStateRefresh()
{
}

PIMStateRefresh& PIMStateRefresh::operator=(const PIMStateRefresh& other)
{
    if (this==&other) return *this;
    PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMStateRefresh::copy(const PIMStateRefresh& other)
{
    this->type_var = other.type_var;
    this->groupAddress_var = other.groupAddress_var;
    this->sourceAddress_var = other.sourceAddress_var;
    this->originatorAddress_var = other.originatorAddress_var;
    this->metric_var = other.metric_var;
    this->metricPreference_var = other.metricPreference_var;
    this->maskLen_var = other.maskLen_var;
    this->ttl_var = other.ttl_var;
    this->P_var = other.P_var;
    this->interval_var = other.interval_var;
}

void PIMStateRefresh::parsimPack(cCommBuffer *b)
{
    PIMPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->groupAddress_var);
    doPacking(b,this->sourceAddress_var);
    doPacking(b,this->originatorAddress_var);
    doPacking(b,this->metric_var);
    doPacking(b,this->metricPreference_var);
    doPacking(b,this->maskLen_var);
    doPacking(b,this->ttl_var);
    doPacking(b,this->P_var);
    doPacking(b,this->interval_var);
}

void PIMStateRefresh::parsimUnpack(cCommBuffer *b)
{
    PIMPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->groupAddress_var);
    doUnpacking(b,this->sourceAddress_var);
    doUnpacking(b,this->originatorAddress_var);
    doUnpacking(b,this->metric_var);
    doUnpacking(b,this->metricPreference_var);
    doUnpacking(b,this->maskLen_var);
    doUnpacking(b,this->ttl_var);
    doUnpacking(b,this->P_var);
    doUnpacking(b,this->interval_var);
}

short PIMStateRefresh::getType() const
{
    return type_var;
}

void PIMStateRefresh::setType(short type)
{
    this->type_var = type;
}

IPAddress& PIMStateRefresh::getGroupAddress()
{
    return groupAddress_var;
}

void PIMStateRefresh::setGroupAddress(const IPAddress& groupAddress)
{
    this->groupAddress_var = groupAddress;
}

IPAddress& PIMStateRefresh::getSourceAddress()
{
    return sourceAddress_var;
}

void PIMStateRefresh::setSourceAddress(const IPAddress& sourceAddress)
{
    this->sourceAddress_var = sourceAddress;
}

IPAddress& PIMStateRefresh::getOriginatorAddress()
{
    return originatorAddress_var;
}

void PIMStateRefresh::setOriginatorAddress(const IPAddress& originatorAddress)
{
    this->originatorAddress_var = originatorAddress;
}

int PIMStateRefresh::getMetric() const
{
    return metric_var;
}

void PIMStateRefresh::setMetric(int metric)
{
    this->metric_var = metric;
}

int PIMStateRefresh::getMetricPreference() const
{
    return metricPreference_var;
}

void PIMStateRefresh::setMetricPreference(int metricPreference)
{
    this->metricPreference_var = metricPreference;
}

short PIMStateRefresh::getMaskLen() const
{
    return maskLen_var;
}

void PIMStateRefresh::setMaskLen(short maskLen)
{
    this->maskLen_var = maskLen;
}

short PIMStateRefresh::getTtl() const
{
    return ttl_var;
}

void PIMStateRefresh::setTtl(short ttl)
{
    this->ttl_var = ttl;
}

bool PIMStateRefresh::getP() const
{
    return P_var;
}

void PIMStateRefresh::setP(bool P)
{
    this->P_var = P;
}

int PIMStateRefresh::getInterval() const
{
    return interval_var;
}

void PIMStateRefresh::setInterval(int interval)
{
    this->interval_var = interval;
}

class PIMStateRefreshDescriptor : public cClassDescriptor
{
  public:
    PIMStateRefreshDescriptor();
    virtual ~PIMStateRefreshDescriptor();

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

Register_ClassDescriptor(PIMStateRefreshDescriptor);

PIMStateRefreshDescriptor::PIMStateRefreshDescriptor() : cClassDescriptor("PIMStateRefresh", "PIMPacket")
{
}

PIMStateRefreshDescriptor::~PIMStateRefreshDescriptor()
{
}

bool PIMStateRefreshDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMStateRefresh *>(obj)!=NULL;
}

const char *PIMStateRefreshDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMStateRefreshDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 10;
}

unsigned int PIMStateRefreshDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *PIMStateRefreshDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "groupAddress",
        "sourceAddress",
        "originatorAddress",
        "metric",
        "metricPreference",
        "maskLen",
        "ttl",
        "P",
        "interval",
    };
    return (field>=0 && field<10) ? fieldNames[field] : NULL;
}

int PIMStateRefreshDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddress")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "metricPreference")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "maskLen")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+7;
    if (fieldName[0]=='P' && strcmp(fieldName, "P")==0) return base+8;
    if (fieldName[0]=='i' && strcmp(fieldName, "interval")==0) return base+9;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMStateRefreshDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IPAddress",
        "IPAddress",
        "IPAddress",
        "int",
        "int",
        "short",
        "short",
        "bool",
        "int",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : NULL;
}

const char *PIMStateRefreshDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMStateRefreshDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMStateRefreshDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceAddress(); return out.str();}
        case 3: {std::stringstream out; out << pp->getOriginatorAddress(); return out.str();}
        case 4: return long2string(pp->getMetric());
        case 5: return long2string(pp->getMetricPreference());
        case 6: return long2string(pp->getMaskLen());
        case 7: return long2string(pp->getTtl());
        case 8: return bool2string(pp->getP());
        case 9: return long2string(pp->getInterval());
        default: return "";
    }
}

bool PIMStateRefreshDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 4: pp->setMetric(string2long(value)); return true;
        case 5: pp->setMetricPreference(string2long(value)); return true;
        case 6: pp->setMaskLen(string2long(value)); return true;
        case 7: pp->setTtl(string2long(value)); return true;
        case 8: pp->setP(string2bool(value)); return true;
        case 9: pp->setInterval(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMStateRefreshDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "IPAddress",
        "IPAddress",
        "IPAddress",
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<10) ? fieldStructNames[field] : NULL;
}

void *PIMStateRefreshDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getGroupAddress()); break;
        case 2: return (void *)(&pp->getSourceAddress()); break;
        case 3: return (void *)(&pp->getOriginatorAddress()); break;
        default: return NULL;
    }
}

Register_Class(PIMRegister);

PIMRegister::PIMRegister(const char *name, int kind) : PIMPacket(name,kind)
{
    this->type_var = Register;
    this->B_var = 0;
    this->N_var = 0;
}

PIMRegister::PIMRegister(const PIMRegister& other) : PIMPacket(other)
{
    copy(other);
}

PIMRegister::~PIMRegister()
{
}

PIMRegister& PIMRegister::operator=(const PIMRegister& other)
{
    if (this==&other) return *this;
    PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMRegister::copy(const PIMRegister& other)
{
    this->type_var = other.type_var;
    this->B_var = other.B_var;
    this->N_var = other.N_var;
}

void PIMRegister::parsimPack(cCommBuffer *b)
{
    PIMPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->B_var);
    doPacking(b,this->N_var);
}

void PIMRegister::parsimUnpack(cCommBuffer *b)
{
    PIMPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->B_var);
    doUnpacking(b,this->N_var);
}

short PIMRegister::getType() const
{
    return type_var;
}

void PIMRegister::setType(short type)
{
    this->type_var = type;
}

bool PIMRegister::getB() const
{
    return B_var;
}

void PIMRegister::setB(bool B)
{
    this->B_var = B;
}

bool PIMRegister::getN() const
{
    return N_var;
}

void PIMRegister::setN(bool N)
{
    this->N_var = N;
}

class PIMRegisterDescriptor : public cClassDescriptor
{
  public:
    PIMRegisterDescriptor();
    virtual ~PIMRegisterDescriptor();

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

Register_ClassDescriptor(PIMRegisterDescriptor);

PIMRegisterDescriptor::PIMRegisterDescriptor() : cClassDescriptor("PIMRegister", "PIMPacket")
{
}

PIMRegisterDescriptor::~PIMRegisterDescriptor()
{
}

bool PIMRegisterDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMRegister *>(obj)!=NULL;
}

const char *PIMRegisterDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMRegisterDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PIMRegisterDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *PIMRegisterDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "B",
        "N",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PIMRegisterDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='B' && strcmp(fieldName, "B")==0) return base+1;
    if (fieldName[0]=='N' && strcmp(fieldName, "N")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMRegisterDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "bool",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PIMRegisterDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMRegisterDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMRegisterDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: return bool2string(pp->getB());
        case 2: return bool2string(pp->getN());
        default: return "";
    }
}

bool PIMRegisterDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        case 1: pp->setB(string2bool(value)); return true;
        case 2: pp->setN(string2bool(value)); return true;
        default: return false;
    }
}

const char *PIMRegisterDescriptor::getFieldStructName(void *object, int field) const
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

void *PIMRegisterDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(PIMRegisterStop);

PIMRegisterStop::PIMRegisterStop(const char *name, int kind) : PIMPacket(name,kind)
{
    this->type_var = RegisterStop;
}

PIMRegisterStop::PIMRegisterStop(const PIMRegisterStop& other) : PIMPacket(other)
{
    copy(other);
}

PIMRegisterStop::~PIMRegisterStop()
{
}

PIMRegisterStop& PIMRegisterStop::operator=(const PIMRegisterStop& other)
{
    if (this==&other) return *this;
    PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMRegisterStop::copy(const PIMRegisterStop& other)
{
    this->type_var = other.type_var;
    this->groupAddress_var = other.groupAddress_var;
    this->sourceAddress_var = other.sourceAddress_var;
}

void PIMRegisterStop::parsimPack(cCommBuffer *b)
{
    PIMPacket::parsimPack(b);
    doPacking(b,this->type_var);
    doPacking(b,this->groupAddress_var);
    doPacking(b,this->sourceAddress_var);
}

void PIMRegisterStop::parsimUnpack(cCommBuffer *b)
{
    PIMPacket::parsimUnpack(b);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->groupAddress_var);
    doUnpacking(b,this->sourceAddress_var);
}

short PIMRegisterStop::getType() const
{
    return type_var;
}

void PIMRegisterStop::setType(short type)
{
    this->type_var = type;
}

IPAddress& PIMRegisterStop::getGroupAddress()
{
    return groupAddress_var;
}

void PIMRegisterStop::setGroupAddress(const IPAddress& groupAddress)
{
    this->groupAddress_var = groupAddress;
}

IPAddress& PIMRegisterStop::getSourceAddress()
{
    return sourceAddress_var;
}

void PIMRegisterStop::setSourceAddress(const IPAddress& sourceAddress)
{
    this->sourceAddress_var = sourceAddress;
}

class PIMRegisterStopDescriptor : public cClassDescriptor
{
  public:
    PIMRegisterStopDescriptor();
    virtual ~PIMRegisterStopDescriptor();

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

Register_ClassDescriptor(PIMRegisterStopDescriptor);

PIMRegisterStopDescriptor::PIMRegisterStopDescriptor() : cClassDescriptor("PIMRegisterStop", "PIMPacket")
{
}

PIMRegisterStopDescriptor::~PIMRegisterStopDescriptor()
{
}

bool PIMRegisterStopDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<PIMRegisterStop *>(obj)!=NULL;
}

const char *PIMRegisterStopDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int PIMRegisterStopDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int PIMRegisterStopDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PIMRegisterStopDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "groupAddress",
        "sourceAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int PIMRegisterStopDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *PIMRegisterStopDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IPAddress",
        "IPAddress",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *PIMRegisterStopDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "PIMPacketType";
            return NULL;
        default: return NULL;
    }
}

int PIMRegisterStopDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string PIMRegisterStopDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceAddress(); return out.str();}
        default: return "";
    }
}

bool PIMRegisterStopDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMRegisterStopDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldStructNames[] = {
        NULL,
        "IPAddress",
        "IPAddress",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *PIMRegisterStopDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getGroupAddress()); break;
        case 2: return (void *)(&pp->getSourceAddress()); break;
        default: return NULL;
    }
}


