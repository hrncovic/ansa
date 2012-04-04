//
// Generated file, do not edit! Created by opp_msgc 4.2 from ansa/isis/ISISMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ISISMessage_m.h"

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
    cEnum *e = cEnum::find("PDU_Type");
    if (!e) enums.getInstance()->add(e = new cEnum("PDU_Type"));
    e->insert(LAN_L1_HELLO, "LAN_L1_HELLO");
    e->insert(LAN_L2_HELLO, "LAN_L2_HELLO");
    e->insert(PTP_HELLO, "PTP_HELLO");
    e->insert(L1_LSP, "L1_LSP");
    e->insert(L2_LSP, "L2_LSP");
    e->insert(L1_CSNP, "L1_CSNP");
    e->insert(L2_CSNP, "L2_CSNP");
    e->insert(L1_PSNP, "L1_PSNP");
    e->insert(L2_PSNP, "L2_PSNP");
);

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("curcuitTypes");
    if (!e) enums.getInstance()->add(e = new cEnum("curcuitTypes"));
    e->insert(RESERVED, "RESERVED");
    e->insert(L1, "L1");
    e->insert(L2, "L2");
    e->insert(L1L2, "L1L2");
);

Register_Class(ISISMessage);

ISISMessage::ISISMessage(const char *name, int kind) : cPacket(name,kind)
{
    this->IRPD_var = 0x83;
    this->length_var = 0;
    this->version_var = 0x01;
    this->idLength_var = 0x00;
    this->type_var = 0;
    this->version2_var = 0x01;
    this->reserved_var = 0x00;
    this->maxAreas_var = 0x00;
}

ISISMessage::ISISMessage(const ISISMessage& other) : cPacket(other)
{
    copy(other);
}

ISISMessage::~ISISMessage()
{
}

ISISMessage& ISISMessage::operator=(const ISISMessage& other)
{
    if (this==&other) return *this;
    cPacket::operator=(other);
    copy(other);
    return *this;
}

void ISISMessage::copy(const ISISMessage& other)
{
    this->IRPD_var = other.IRPD_var;
    this->length_var = other.length_var;
    this->version_var = other.version_var;
    this->idLength_var = other.idLength_var;
    this->type_var = other.type_var;
    this->version2_var = other.version2_var;
    this->reserved_var = other.reserved_var;
    this->maxAreas_var = other.maxAreas_var;
}

void ISISMessage::parsimPack(cCommBuffer *b)
{
    cPacket::parsimPack(b);
    doPacking(b,this->IRPD_var);
    doPacking(b,this->length_var);
    doPacking(b,this->version_var);
    doPacking(b,this->idLength_var);
    doPacking(b,this->type_var);
    doPacking(b,this->version2_var);
    doPacking(b,this->reserved_var);
    doPacking(b,this->maxAreas_var);
}

void ISISMessage::parsimUnpack(cCommBuffer *b)
{
    cPacket::parsimUnpack(b);
    doUnpacking(b,this->IRPD_var);
    doUnpacking(b,this->length_var);
    doUnpacking(b,this->version_var);
    doUnpacking(b,this->idLength_var);
    doUnpacking(b,this->type_var);
    doUnpacking(b,this->version2_var);
    doUnpacking(b,this->reserved_var);
    doUnpacking(b,this->maxAreas_var);
}

unsigned char ISISMessage::getIRPD() const
{
    return IRPD_var;
}

void ISISMessage::setIRPD(unsigned char IRPD)
{
    this->IRPD_var = IRPD;
}

unsigned char ISISMessage::getLength() const
{
    return length_var;
}

void ISISMessage::setLength(unsigned char length)
{
    this->length_var = length;
}

unsigned char ISISMessage::getVersion() const
{
    return version_var;
}

void ISISMessage::setVersion(unsigned char version)
{
    this->version_var = version;
}

unsigned char ISISMessage::getIdLength() const
{
    return idLength_var;
}

void ISISMessage::setIdLength(unsigned char idLength)
{
    this->idLength_var = idLength;
}

unsigned char ISISMessage::getType() const
{
    return type_var;
}

void ISISMessage::setType(unsigned char type)
{
    this->type_var = type;
}

unsigned char ISISMessage::getVersion2() const
{
    return version2_var;
}

void ISISMessage::setVersion2(unsigned char version2)
{
    this->version2_var = version2;
}

unsigned char ISISMessage::getReserved() const
{
    return reserved_var;
}

void ISISMessage::setReserved(unsigned char reserved)
{
    this->reserved_var = reserved;
}

unsigned char ISISMessage::getMaxAreas() const
{
    return maxAreas_var;
}

void ISISMessage::setMaxAreas(unsigned char maxAreas)
{
    this->maxAreas_var = maxAreas;
}

class ISISMessageDescriptor : public cClassDescriptor
{
  public:
    ISISMessageDescriptor();
    virtual ~ISISMessageDescriptor();

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

Register_ClassDescriptor(ISISMessageDescriptor);

ISISMessageDescriptor::ISISMessageDescriptor() : cClassDescriptor("ISISMessage", "cPacket")
{
}

ISISMessageDescriptor::~ISISMessageDescriptor()
{
}

bool ISISMessageDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISMessage *>(obj)!=NULL;
}

const char *ISISMessageDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISMessageDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount(object) : 8;
}

unsigned int ISISMessageDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *ISISMessageDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "IRPD",
        "length",
        "version",
        "idLength",
        "type",
        "version2",
        "reserved",
        "maxAreas",
    };
    return (field>=0 && field<8) ? fieldNames[field] : NULL;
}

int ISISMessageDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "IRPD")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "idLength")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "version2")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxAreas")==0) return base+7;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISMessageDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
        "unsigned char",
        "unsigned char",
        "unsigned char",
        "unsigned char",
        "unsigned char",
        "unsigned char",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : NULL;
}

const char *ISISMessageDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 4:
            if (!strcmp(propertyname,"enum")) return "PDU_Type";
            return NULL;
        default: return NULL;
    }
}

int ISISMessageDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISMessage *pp = (ISISMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ISISMessageDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISMessage *pp = (ISISMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getIRPD());
        case 1: return ulong2string(pp->getLength());
        case 2: return ulong2string(pp->getVersion());
        case 3: return ulong2string(pp->getIdLength());
        case 4: return ulong2string(pp->getType());
        case 5: return ulong2string(pp->getVersion2());
        case 6: return ulong2string(pp->getReserved());
        case 7: return ulong2string(pp->getMaxAreas());
        default: return "";
    }
}

bool ISISMessageDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISMessage *pp = (ISISMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setIRPD(string2ulong(value)); return true;
        case 1: pp->setLength(string2ulong(value)); return true;
        case 2: pp->setVersion(string2ulong(value)); return true;
        case 3: pp->setIdLength(string2ulong(value)); return true;
        case 4: pp->setType(string2ulong(value)); return true;
        case 5: pp->setVersion2(string2ulong(value)); return true;
        case 6: pp->setReserved(string2ulong(value)); return true;
        case 7: pp->setMaxAreas(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ISISMessageDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        NULL,
        NULL,
    };
    return (field>=0 && field<8) ? fieldStructNames[field] : NULL;
}

void *ISISMessageDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISMessage *pp = (ISISMessage *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ISISL1HelloPacket);

ISISL1HelloPacket::ISISL1HelloPacket(const char *name, int kind) : ISISMessage(name,kind)
{
    this->setType(LAN_L1_HELLO);

    this->curcuitType_var = 0;
    for (unsigned int i=0; i<6; i++)
        this->sourceID_var[i] = 0;
    this->holdTime_var = 0;
    this->pduLength_var = 0;
    this->priority_var = 64;
    for (unsigned int i=0; i<7; i++)
        this->lanID_var[i] = 0;
    TLV_arraysize = 0;
    this->TLV_var = 0;
}

ISISL1HelloPacket::ISISL1HelloPacket(const ISISL1HelloPacket& other) : ISISMessage(other)
{
    TLV_arraysize = 0;
    this->TLV_var = 0;
    copy(other);
}

ISISL1HelloPacket::~ISISL1HelloPacket()
{
    delete [] TLV_var;
}

ISISL1HelloPacket& ISISL1HelloPacket::operator=(const ISISL1HelloPacket& other)
{
    if (this==&other) return *this;
    ISISMessage::operator=(other);
    copy(other);
    return *this;
}

void ISISL1HelloPacket::copy(const ISISL1HelloPacket& other)
{
    this->curcuitType_var = other.curcuitType_var;
    for (unsigned int i=0; i<6; i++)
        this->sourceID_var[i] = other.sourceID_var[i];
    this->holdTime_var = other.holdTime_var;
    this->pduLength_var = other.pduLength_var;
    this->priority_var = other.priority_var;
    for (unsigned int i=0; i<7; i++)
        this->lanID_var[i] = other.lanID_var[i];
    delete [] this->TLV_var;
    this->TLV_var = (other.TLV_arraysize==0) ? NULL : new TLV_t[other.TLV_arraysize];
    TLV_arraysize = other.TLV_arraysize;
    for (unsigned int i=0; i<TLV_arraysize; i++)
        this->TLV_var[i] = other.TLV_var[i];
}

void ISISL1HelloPacket::parsimPack(cCommBuffer *b)
{
    ISISMessage::parsimPack(b);
    doPacking(b,this->curcuitType_var);
    doPacking(b,this->sourceID_var,6);
    doPacking(b,this->holdTime_var);
    doPacking(b,this->pduLength_var);
    doPacking(b,this->priority_var);
    doPacking(b,this->lanID_var,7);
    b->pack(TLV_arraysize);
    doPacking(b,this->TLV_var,TLV_arraysize);
}

void ISISL1HelloPacket::parsimUnpack(cCommBuffer *b)
{
    ISISMessage::parsimUnpack(b);
    doUnpacking(b,this->curcuitType_var);
    doUnpacking(b,this->sourceID_var,6);
    doUnpacking(b,this->holdTime_var);
    doUnpacking(b,this->pduLength_var);
    doUnpacking(b,this->priority_var);
    doUnpacking(b,this->lanID_var,7);
    delete [] this->TLV_var;
    b->unpack(TLV_arraysize);
    if (TLV_arraysize==0) {
        this->TLV_var = 0;
    } else {
        this->TLV_var = new TLV_t[TLV_arraysize];
        doUnpacking(b,this->TLV_var,TLV_arraysize);
    }
}

unsigned char ISISL1HelloPacket::getCurcuitType() const
{
    return curcuitType_var;
}

void ISISL1HelloPacket::setCurcuitType(unsigned char curcuitType)
{
    this->curcuitType_var = curcuitType;
}

unsigned int ISISL1HelloPacket::getSourceIDArraySize() const
{
    return 6;
}

unsigned char ISISL1HelloPacket::getSourceID(unsigned int k) const
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    return sourceID_var[k];
}

void ISISL1HelloPacket::setSourceID(unsigned int k, unsigned char sourceID)
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    this->sourceID_var[k] = sourceID;
}

unsigned short ISISL1HelloPacket::getHoldTime() const
{
    return holdTime_var;
}

void ISISL1HelloPacket::setHoldTime(unsigned short holdTime)
{
    this->holdTime_var = holdTime;
}

unsigned short ISISL1HelloPacket::getPduLength() const
{
    return pduLength_var;
}

void ISISL1HelloPacket::setPduLength(unsigned short pduLength)
{
    this->pduLength_var = pduLength;
}

unsigned char ISISL1HelloPacket::getPriority() const
{
    return priority_var;
}

void ISISL1HelloPacket::setPriority(unsigned char priority)
{
    this->priority_var = priority;
}

unsigned int ISISL1HelloPacket::getLanIDArraySize() const
{
    return 7;
}

unsigned char ISISL1HelloPacket::getLanID(unsigned int k) const
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    return lanID_var[k];
}

void ISISL1HelloPacket::setLanID(unsigned int k, unsigned char lanID)
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    this->lanID_var[k] = lanID;
}

void ISISL1HelloPacket::setTLVArraySize(unsigned int size)
{
    TLV_t *TLV_var2 = (size==0) ? NULL : new TLV_t[size];
    unsigned int sz = TLV_arraysize < size ? TLV_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        TLV_var2[i] = this->TLV_var[i];
    TLV_arraysize = size;
    delete [] this->TLV_var;
    this->TLV_var = TLV_var2;
}

unsigned int ISISL1HelloPacket::getTLVArraySize() const
{
    return TLV_arraysize;
}

TLV_t& ISISL1HelloPacket::getTLV(unsigned int k)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    return TLV_var[k];
}

void ISISL1HelloPacket::setTLV(unsigned int k, const TLV_t& TLV)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    this->TLV_var[k] = TLV;
}

class ISISL1HelloPacketDescriptor : public cClassDescriptor
{
  public:
    ISISL1HelloPacketDescriptor();
    virtual ~ISISL1HelloPacketDescriptor();

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

Register_ClassDescriptor(ISISL1HelloPacketDescriptor);

ISISL1HelloPacketDescriptor::ISISL1HelloPacketDescriptor() : cClassDescriptor("ISISL1HelloPacket", "ISISMessage")
{
}

ISISL1HelloPacketDescriptor::~ISISL1HelloPacketDescriptor()
{
}

bool ISISL1HelloPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISL1HelloPacket *>(obj)!=NULL;
}

const char *ISISL1HelloPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISL1HelloPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int ISISL1HelloPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *ISISL1HelloPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "curcuitType",
        "sourceID",
        "holdTime",
        "pduLength",
        "priority",
        "lanID",
        "TLV",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int ISISL1HelloPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "curcuitType")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceID")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "pduLength")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "lanID")==0) return base+5;
    if (fieldName[0]=='T' && strcmp(fieldName, "TLV")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISL1HelloPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
        "unsigned short",
        "unsigned short",
        "unsigned char",
        "unsigned char",
        "TLV_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *ISISL1HelloPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "curcuitTypes";
            return NULL;
        default: return NULL;
    }
}

int ISISL1HelloPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISL1HelloPacket *pp = (ISISL1HelloPacket *)object; (void)pp;
    switch (field) {
        case 1: return 6;
        case 5: return 7;
        case 6: return pp->getTLVArraySize();
        default: return 0;
    }
}

std::string ISISL1HelloPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISL1HelloPacket *pp = (ISISL1HelloPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCurcuitType());
        case 1: return ulong2string(pp->getSourceID(i));
        case 2: return ulong2string(pp->getHoldTime());
        case 3: return ulong2string(pp->getPduLength());
        case 4: return ulong2string(pp->getPriority());
        case 5: return ulong2string(pp->getLanID(i));
        case 6: {std::stringstream out; out << pp->getTLV(i); return out.str();}
        default: return "";
    }
}

bool ISISL1HelloPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISL1HelloPacket *pp = (ISISL1HelloPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setCurcuitType(string2ulong(value)); return true;
        case 1: pp->setSourceID(i,string2ulong(value)); return true;
        case 2: pp->setHoldTime(string2ulong(value)); return true;
        case 3: pp->setPduLength(string2ulong(value)); return true;
        case 4: pp->setPriority(string2ulong(value)); return true;
        case 5: pp->setLanID(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *ISISL1HelloPacketDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        "TLV_t",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *ISISL1HelloPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISL1HelloPacket *pp = (ISISL1HelloPacket *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getTLV(i)); break;
        default: return NULL;
    }
}

Register_Class(ISISL2HelloPacket);

ISISL2HelloPacket::ISISL2HelloPacket(const char *name, int kind) : ISISL1HelloPacket(name,kind)
{
    this->setType(LAN_L2_HELLO);
}

ISISL2HelloPacket::ISISL2HelloPacket(const ISISL2HelloPacket& other) : ISISL1HelloPacket(other)
{
    copy(other);
}

ISISL2HelloPacket::~ISISL2HelloPacket()
{
}

ISISL2HelloPacket& ISISL2HelloPacket::operator=(const ISISL2HelloPacket& other)
{
    if (this==&other) return *this;
    ISISL1HelloPacket::operator=(other);
    copy(other);
    return *this;
}

void ISISL2HelloPacket::copy(const ISISL2HelloPacket& other)
{
}

void ISISL2HelloPacket::parsimPack(cCommBuffer *b)
{
    ISISL1HelloPacket::parsimPack(b);
}

void ISISL2HelloPacket::parsimUnpack(cCommBuffer *b)
{
    ISISL1HelloPacket::parsimUnpack(b);
}

class ISISL2HelloPacketDescriptor : public cClassDescriptor
{
  public:
    ISISL2HelloPacketDescriptor();
    virtual ~ISISL2HelloPacketDescriptor();

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

Register_ClassDescriptor(ISISL2HelloPacketDescriptor);

ISISL2HelloPacketDescriptor::ISISL2HelloPacketDescriptor() : cClassDescriptor("ISISL2HelloPacket", "ISISL1HelloPacket")
{
}

ISISL2HelloPacketDescriptor::~ISISL2HelloPacketDescriptor()
{
}

bool ISISL2HelloPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISL2HelloPacket *>(obj)!=NULL;
}

const char *ISISL2HelloPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISL2HelloPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int ISISL2HelloPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *ISISL2HelloPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int ISISL2HelloPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISL2HelloPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *ISISL2HelloPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISL2HelloPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISL2HelloPacket *pp = (ISISL2HelloPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ISISL2HelloPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISL2HelloPacket *pp = (ISISL2HelloPacket *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ISISL2HelloPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISL2HelloPacket *pp = (ISISL2HelloPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ISISL2HelloPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *ISISL2HelloPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISL2HelloPacket *pp = (ISISL2HelloPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ISISPTPHelloPacket);

ISISPTPHelloPacket::ISISPTPHelloPacket(const char *name, int kind) : ISISMessage(name,kind)
{
    this->setType(PTP_HELLO);

    this->curcuitType_var = 0;
    for (unsigned int i=0; i<6; i++)
        this->sourceID_var[i] = 0;
    this->holdTime_var = 0;
    this->pduLength_var = 0;
    this->localCircuitID_var = 0;
    TLV_arraysize = 0;
    this->TLV_var = 0;
}

ISISPTPHelloPacket::ISISPTPHelloPacket(const ISISPTPHelloPacket& other) : ISISMessage(other)
{
    TLV_arraysize = 0;
    this->TLV_var = 0;
    copy(other);
}

ISISPTPHelloPacket::~ISISPTPHelloPacket()
{
    delete [] TLV_var;
}

ISISPTPHelloPacket& ISISPTPHelloPacket::operator=(const ISISPTPHelloPacket& other)
{
    if (this==&other) return *this;
    ISISMessage::operator=(other);
    copy(other);
    return *this;
}

void ISISPTPHelloPacket::copy(const ISISPTPHelloPacket& other)
{
    this->curcuitType_var = other.curcuitType_var;
    for (unsigned int i=0; i<6; i++)
        this->sourceID_var[i] = other.sourceID_var[i];
    this->holdTime_var = other.holdTime_var;
    this->pduLength_var = other.pduLength_var;
    this->localCircuitID_var = other.localCircuitID_var;
    delete [] this->TLV_var;
    this->TLV_var = (other.TLV_arraysize==0) ? NULL : new TLV_t[other.TLV_arraysize];
    TLV_arraysize = other.TLV_arraysize;
    for (unsigned int i=0; i<TLV_arraysize; i++)
        this->TLV_var[i] = other.TLV_var[i];
}

void ISISPTPHelloPacket::parsimPack(cCommBuffer *b)
{
    ISISMessage::parsimPack(b);
    doPacking(b,this->curcuitType_var);
    doPacking(b,this->sourceID_var,6);
    doPacking(b,this->holdTime_var);
    doPacking(b,this->pduLength_var);
    doPacking(b,this->localCircuitID_var);
    b->pack(TLV_arraysize);
    doPacking(b,this->TLV_var,TLV_arraysize);
}

void ISISPTPHelloPacket::parsimUnpack(cCommBuffer *b)
{
    ISISMessage::parsimUnpack(b);
    doUnpacking(b,this->curcuitType_var);
    doUnpacking(b,this->sourceID_var,6);
    doUnpacking(b,this->holdTime_var);
    doUnpacking(b,this->pduLength_var);
    doUnpacking(b,this->localCircuitID_var);
    delete [] this->TLV_var;
    b->unpack(TLV_arraysize);
    if (TLV_arraysize==0) {
        this->TLV_var = 0;
    } else {
        this->TLV_var = new TLV_t[TLV_arraysize];
        doUnpacking(b,this->TLV_var,TLV_arraysize);
    }
}

unsigned char ISISPTPHelloPacket::getCurcuitType() const
{
    return curcuitType_var;
}

void ISISPTPHelloPacket::setCurcuitType(unsigned char curcuitType)
{
    this->curcuitType_var = curcuitType;
}

unsigned int ISISPTPHelloPacket::getSourceIDArraySize() const
{
    return 6;
}

unsigned char ISISPTPHelloPacket::getSourceID(unsigned int k) const
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    return sourceID_var[k];
}

void ISISPTPHelloPacket::setSourceID(unsigned int k, unsigned char sourceID)
{
    if (k>=6) throw cRuntimeError("Array of size 6 indexed by %lu", (unsigned long)k);
    this->sourceID_var[k] = sourceID;
}

unsigned short ISISPTPHelloPacket::getHoldTime() const
{
    return holdTime_var;
}

void ISISPTPHelloPacket::setHoldTime(unsigned short holdTime)
{
    this->holdTime_var = holdTime;
}

unsigned short ISISPTPHelloPacket::getPduLength() const
{
    return pduLength_var;
}

void ISISPTPHelloPacket::setPduLength(unsigned short pduLength)
{
    this->pduLength_var = pduLength;
}

unsigned char ISISPTPHelloPacket::getLocalCircuitID() const
{
    return localCircuitID_var;
}

void ISISPTPHelloPacket::setLocalCircuitID(unsigned char localCircuitID)
{
    this->localCircuitID_var = localCircuitID;
}

void ISISPTPHelloPacket::setTLVArraySize(unsigned int size)
{
    TLV_t *TLV_var2 = (size==0) ? NULL : new TLV_t[size];
    unsigned int sz = TLV_arraysize < size ? TLV_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        TLV_var2[i] = this->TLV_var[i];
    TLV_arraysize = size;
    delete [] this->TLV_var;
    this->TLV_var = TLV_var2;
}

unsigned int ISISPTPHelloPacket::getTLVArraySize() const
{
    return TLV_arraysize;
}

TLV_t& ISISPTPHelloPacket::getTLV(unsigned int k)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    return TLV_var[k];
}

void ISISPTPHelloPacket::setTLV(unsigned int k, const TLV_t& TLV)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    this->TLV_var[k] = TLV;
}

class ISISPTPHelloPacketDescriptor : public cClassDescriptor
{
  public:
    ISISPTPHelloPacketDescriptor();
    virtual ~ISISPTPHelloPacketDescriptor();

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

Register_ClassDescriptor(ISISPTPHelloPacketDescriptor);

ISISPTPHelloPacketDescriptor::ISISPTPHelloPacketDescriptor() : cClassDescriptor("ISISPTPHelloPacket", "ISISMessage")
{
}

ISISPTPHelloPacketDescriptor::~ISISPTPHelloPacketDescriptor()
{
}

bool ISISPTPHelloPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISPTPHelloPacket *>(obj)!=NULL;
}

const char *ISISPTPHelloPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISPTPHelloPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int ISISPTPHelloPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *ISISPTPHelloPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "curcuitType",
        "sourceID",
        "holdTime",
        "pduLength",
        "localCircuitID",
        "TLV",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int ISISPTPHelloPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "curcuitType")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceID")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "pduLength")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "localCircuitID")==0) return base+4;
    if (fieldName[0]=='T' && strcmp(fieldName, "TLV")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISPTPHelloPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
        "unsigned short",
        "unsigned short",
        "unsigned char",
        "TLV_t",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *ISISPTPHelloPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "curcuitTypes";
            return NULL;
        default: return NULL;
    }
}

int ISISPTPHelloPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISPTPHelloPacket *pp = (ISISPTPHelloPacket *)object; (void)pp;
    switch (field) {
        case 1: return 6;
        case 5: return pp->getTLVArraySize();
        default: return 0;
    }
}

std::string ISISPTPHelloPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISPTPHelloPacket *pp = (ISISPTPHelloPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCurcuitType());
        case 1: return ulong2string(pp->getSourceID(i));
        case 2: return ulong2string(pp->getHoldTime());
        case 3: return ulong2string(pp->getPduLength());
        case 4: return ulong2string(pp->getLocalCircuitID());
        case 5: {std::stringstream out; out << pp->getTLV(i); return out.str();}
        default: return "";
    }
}

bool ISISPTPHelloPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISPTPHelloPacket *pp = (ISISPTPHelloPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setCurcuitType(string2ulong(value)); return true;
        case 1: pp->setSourceID(i,string2ulong(value)); return true;
        case 2: pp->setHoldTime(string2ulong(value)); return true;
        case 3: pp->setPduLength(string2ulong(value)); return true;
        case 4: pp->setLocalCircuitID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ISISPTPHelloPacketDescriptor::getFieldStructName(void *object, int field) const
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
        "TLV_t",
    };
    return (field>=0 && field<6) ? fieldStructNames[field] : NULL;
}

void *ISISPTPHelloPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISPTPHelloPacket *pp = (ISISPTPHelloPacket *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getTLV(i)); break;
        default: return NULL;
    }
}

Register_Class(ISISLSPL1Packet);

ISISLSPL1Packet::ISISLSPL1Packet(const char *name, int kind) : ISISMessage(name,kind)
{
    this->setType(L1_LSP);

    this->pduLength_var = 0;
    this->remLifeTime_var = 1200;
    for (unsigned int i=0; i<8; i++)
        this->lspID_var[i] = 0;
    this->seqNumber_var = 0;
    this->checksum_var = 0;
    this->PATTLSPDBOLIS_var = 0x01;
    TLV_arraysize = 0;
    this->TLV_var = 0;
}

ISISLSPL1Packet::ISISLSPL1Packet(const ISISLSPL1Packet& other) : ISISMessage(other)
{
    TLV_arraysize = 0;
    this->TLV_var = 0;
    copy(other);
}

ISISLSPL1Packet::~ISISLSPL1Packet()
{
    delete [] TLV_var;
}

ISISLSPL1Packet& ISISLSPL1Packet::operator=(const ISISLSPL1Packet& other)
{
    if (this==&other) return *this;
    ISISMessage::operator=(other);
    copy(other);
    return *this;
}

void ISISLSPL1Packet::copy(const ISISLSPL1Packet& other)
{
    this->pduLength_var = other.pduLength_var;
    this->remLifeTime_var = other.remLifeTime_var;
    for (unsigned int i=0; i<8; i++)
        this->lspID_var[i] = other.lspID_var[i];
    this->seqNumber_var = other.seqNumber_var;
    this->checksum_var = other.checksum_var;
    this->PATTLSPDBOLIS_var = other.PATTLSPDBOLIS_var;
    delete [] this->TLV_var;
    this->TLV_var = (other.TLV_arraysize==0) ? NULL : new TLV_t[other.TLV_arraysize];
    TLV_arraysize = other.TLV_arraysize;
    for (unsigned int i=0; i<TLV_arraysize; i++)
        this->TLV_var[i] = other.TLV_var[i];
}

void ISISLSPL1Packet::parsimPack(cCommBuffer *b)
{
    ISISMessage::parsimPack(b);
    doPacking(b,this->pduLength_var);
    doPacking(b,this->remLifeTime_var);
    doPacking(b,this->lspID_var,8);
    doPacking(b,this->seqNumber_var);
    doPacking(b,this->checksum_var);
    doPacking(b,this->PATTLSPDBOLIS_var);
    b->pack(TLV_arraysize);
    doPacking(b,this->TLV_var,TLV_arraysize);
}

void ISISLSPL1Packet::parsimUnpack(cCommBuffer *b)
{
    ISISMessage::parsimUnpack(b);
    doUnpacking(b,this->pduLength_var);
    doUnpacking(b,this->remLifeTime_var);
    doUnpacking(b,this->lspID_var,8);
    doUnpacking(b,this->seqNumber_var);
    doUnpacking(b,this->checksum_var);
    doUnpacking(b,this->PATTLSPDBOLIS_var);
    delete [] this->TLV_var;
    b->unpack(TLV_arraysize);
    if (TLV_arraysize==0) {
        this->TLV_var = 0;
    } else {
        this->TLV_var = new TLV_t[TLV_arraysize];
        doUnpacking(b,this->TLV_var,TLV_arraysize);
    }
}

unsigned short ISISLSPL1Packet::getPduLength() const
{
    return pduLength_var;
}

void ISISLSPL1Packet::setPduLength(unsigned short pduLength)
{
    this->pduLength_var = pduLength;
}

unsigned short ISISLSPL1Packet::getRemLifeTime() const
{
    return remLifeTime_var;
}

void ISISLSPL1Packet::setRemLifeTime(unsigned short remLifeTime)
{
    this->remLifeTime_var = remLifeTime;
}

unsigned int ISISLSPL1Packet::getLspIDArraySize() const
{
    return 8;
}

unsigned char ISISLSPL1Packet::getLspID(unsigned int k) const
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return lspID_var[k];
}

void ISISLSPL1Packet::setLspID(unsigned int k, unsigned char lspID)
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    this->lspID_var[k] = lspID;
}

unsigned long ISISLSPL1Packet::getSeqNumber() const
{
    return seqNumber_var;
}

void ISISLSPL1Packet::setSeqNumber(unsigned long seqNumber)
{
    this->seqNumber_var = seqNumber;
}

unsigned short ISISLSPL1Packet::getChecksum() const
{
    return checksum_var;
}

void ISISLSPL1Packet::setChecksum(unsigned short checksum)
{
    this->checksum_var = checksum;
}

unsigned char ISISLSPL1Packet::getPATTLSPDBOLIS() const
{
    return PATTLSPDBOLIS_var;
}

void ISISLSPL1Packet::setPATTLSPDBOLIS(unsigned char PATTLSPDBOLIS)
{
    this->PATTLSPDBOLIS_var = PATTLSPDBOLIS;
}

void ISISLSPL1Packet::setTLVArraySize(unsigned int size)
{
    TLV_t *TLV_var2 = (size==0) ? NULL : new TLV_t[size];
    unsigned int sz = TLV_arraysize < size ? TLV_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        TLV_var2[i] = this->TLV_var[i];
    TLV_arraysize = size;
    delete [] this->TLV_var;
    this->TLV_var = TLV_var2;
}

unsigned int ISISLSPL1Packet::getTLVArraySize() const
{
    return TLV_arraysize;
}

TLV_t& ISISLSPL1Packet::getTLV(unsigned int k)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    return TLV_var[k];
}

void ISISLSPL1Packet::setTLV(unsigned int k, const TLV_t& TLV)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    this->TLV_var[k] = TLV;
}

class ISISLSPL1PacketDescriptor : public cClassDescriptor
{
  public:
    ISISLSPL1PacketDescriptor();
    virtual ~ISISLSPL1PacketDescriptor();

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

Register_ClassDescriptor(ISISLSPL1PacketDescriptor);

ISISLSPL1PacketDescriptor::ISISLSPL1PacketDescriptor() : cClassDescriptor("ISISLSPL1Packet", "ISISMessage")
{
}

ISISLSPL1PacketDescriptor::~ISISLSPL1PacketDescriptor()
{
}

bool ISISLSPL1PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISLSPL1Packet *>(obj)!=NULL;
}

const char *ISISLSPL1PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISLSPL1PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int ISISLSPL1PacketDescriptor::getFieldTypeFlags(void *object, int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *ISISLSPL1PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pduLength",
        "remLifeTime",
        "lspID",
        "seqNumber",
        "checksum",
        "PATTLSPDBOLIS",
        "TLV",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int ISISLSPL1PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pduLength")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remLifeTime")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lspID")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNumber")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksum")==0) return base+4;
    if (fieldName[0]=='P' && strcmp(fieldName, "PATTLSPDBOLIS")==0) return base+5;
    if (fieldName[0]=='T' && strcmp(fieldName, "TLV")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISLSPL1PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
        "unsigned char",
        "unsigned long",
        "unsigned short",
        "unsigned char",
        "TLV_t",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *ISISLSPL1PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISLSPL1PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL1Packet *pp = (ISISLSPL1Packet *)object; (void)pp;
    switch (field) {
        case 2: return 8;
        case 6: return pp->getTLVArraySize();
        default: return 0;
    }
}

std::string ISISLSPL1PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL1Packet *pp = (ISISLSPL1Packet *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPduLength());
        case 1: return ulong2string(pp->getRemLifeTime());
        case 2: return ulong2string(pp->getLspID(i));
        case 3: return ulong2string(pp->getSeqNumber());
        case 4: return ulong2string(pp->getChecksum());
        case 5: return ulong2string(pp->getPATTLSPDBOLIS());
        case 6: {std::stringstream out; out << pp->getTLV(i); return out.str();}
        default: return "";
    }
}

bool ISISLSPL1PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL1Packet *pp = (ISISLSPL1Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setPduLength(string2ulong(value)); return true;
        case 1: pp->setRemLifeTime(string2ulong(value)); return true;
        case 2: pp->setLspID(i,string2ulong(value)); return true;
        case 3: pp->setSeqNumber(string2ulong(value)); return true;
        case 4: pp->setChecksum(string2ulong(value)); return true;
        case 5: pp->setPATTLSPDBOLIS(string2ulong(value)); return true;
        default: return false;
    }
}

const char *ISISLSPL1PacketDescriptor::getFieldStructName(void *object, int field) const
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
        NULL,
        "TLV_t",
    };
    return (field>=0 && field<7) ? fieldStructNames[field] : NULL;
}

void *ISISLSPL1PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL1Packet *pp = (ISISLSPL1Packet *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getTLV(i)); break;
        default: return NULL;
    }
}

Register_Class(ISISLSPL2Packet);

ISISLSPL2Packet::ISISLSPL2Packet(const char *name, int kind) : ISISLSPL1Packet(name,kind)
{
    this->setType(L2_LSP);
}

ISISLSPL2Packet::ISISLSPL2Packet(const ISISLSPL2Packet& other) : ISISLSPL1Packet(other)
{
    copy(other);
}

ISISLSPL2Packet::~ISISLSPL2Packet()
{
}

ISISLSPL2Packet& ISISLSPL2Packet::operator=(const ISISLSPL2Packet& other)
{
    if (this==&other) return *this;
    ISISLSPL1Packet::operator=(other);
    copy(other);
    return *this;
}

void ISISLSPL2Packet::copy(const ISISLSPL2Packet& other)
{
}

void ISISLSPL2Packet::parsimPack(cCommBuffer *b)
{
    ISISLSPL1Packet::parsimPack(b);
}

void ISISLSPL2Packet::parsimUnpack(cCommBuffer *b)
{
    ISISLSPL1Packet::parsimUnpack(b);
}

class ISISLSPL2PacketDescriptor : public cClassDescriptor
{
  public:
    ISISLSPL2PacketDescriptor();
    virtual ~ISISLSPL2PacketDescriptor();

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

Register_ClassDescriptor(ISISLSPL2PacketDescriptor);

ISISLSPL2PacketDescriptor::ISISLSPL2PacketDescriptor() : cClassDescriptor("ISISLSPL2Packet", "ISISLSPL1Packet")
{
}

ISISLSPL2PacketDescriptor::~ISISLSPL2PacketDescriptor()
{
}

bool ISISLSPL2PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISLSPL2Packet *>(obj)!=NULL;
}

const char *ISISLSPL2PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISLSPL2PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int ISISLSPL2PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *ISISLSPL2PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int ISISLSPL2PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISLSPL2PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *ISISLSPL2PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISLSPL2PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL2Packet *pp = (ISISLSPL2Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ISISLSPL2PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL2Packet *pp = (ISISLSPL2Packet *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ISISLSPL2PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL2Packet *pp = (ISISLSPL2Packet *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ISISLSPL2PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *ISISLSPL2PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISLSPL2Packet *pp = (ISISLSPL2Packet *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ISISCSNPL1Packet);

ISISCSNPL1Packet::ISISCSNPL1Packet(const char *name, int kind) : ISISMessage(name,kind)
{
    this->setType(L1_CSNP);

    this->pduLength_var = 0;
    for (unsigned int i=0; i<7; i++)
        this->sourceID_var[i] = 0;
    for (unsigned int i=0; i<8; i++)
        this->startLspID_var[i] = 0;
    for (unsigned int i=0; i<8; i++)
        this->endLspID_var[i] = 0;
    TLV_arraysize = 0;
    this->TLV_var = 0;
}

ISISCSNPL1Packet::ISISCSNPL1Packet(const ISISCSNPL1Packet& other) : ISISMessage(other)
{
    TLV_arraysize = 0;
    this->TLV_var = 0;
    copy(other);
}

ISISCSNPL1Packet::~ISISCSNPL1Packet()
{
    delete [] TLV_var;
}

ISISCSNPL1Packet& ISISCSNPL1Packet::operator=(const ISISCSNPL1Packet& other)
{
    if (this==&other) return *this;
    ISISMessage::operator=(other);
    copy(other);
    return *this;
}

void ISISCSNPL1Packet::copy(const ISISCSNPL1Packet& other)
{
    this->pduLength_var = other.pduLength_var;
    for (unsigned int i=0; i<7; i++)
        this->sourceID_var[i] = other.sourceID_var[i];
    for (unsigned int i=0; i<8; i++)
        this->startLspID_var[i] = other.startLspID_var[i];
    for (unsigned int i=0; i<8; i++)
        this->endLspID_var[i] = other.endLspID_var[i];
    delete [] this->TLV_var;
    this->TLV_var = (other.TLV_arraysize==0) ? NULL : new TLV_t[other.TLV_arraysize];
    TLV_arraysize = other.TLV_arraysize;
    for (unsigned int i=0; i<TLV_arraysize; i++)
        this->TLV_var[i] = other.TLV_var[i];
}

void ISISCSNPL1Packet::parsimPack(cCommBuffer *b)
{
    ISISMessage::parsimPack(b);
    doPacking(b,this->pduLength_var);
    doPacking(b,this->sourceID_var,7);
    doPacking(b,this->startLspID_var,8);
    doPacking(b,this->endLspID_var,8);
    b->pack(TLV_arraysize);
    doPacking(b,this->TLV_var,TLV_arraysize);
}

void ISISCSNPL1Packet::parsimUnpack(cCommBuffer *b)
{
    ISISMessage::parsimUnpack(b);
    doUnpacking(b,this->pduLength_var);
    doUnpacking(b,this->sourceID_var,7);
    doUnpacking(b,this->startLspID_var,8);
    doUnpacking(b,this->endLspID_var,8);
    delete [] this->TLV_var;
    b->unpack(TLV_arraysize);
    if (TLV_arraysize==0) {
        this->TLV_var = 0;
    } else {
        this->TLV_var = new TLV_t[TLV_arraysize];
        doUnpacking(b,this->TLV_var,TLV_arraysize);
    }
}

unsigned short ISISCSNPL1Packet::getPduLength() const
{
    return pduLength_var;
}

void ISISCSNPL1Packet::setPduLength(unsigned short pduLength)
{
    this->pduLength_var = pduLength;
}

unsigned int ISISCSNPL1Packet::getSourceIDArraySize() const
{
    return 7;
}

unsigned char ISISCSNPL1Packet::getSourceID(unsigned int k) const
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    return sourceID_var[k];
}

void ISISCSNPL1Packet::setSourceID(unsigned int k, unsigned char sourceID)
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    this->sourceID_var[k] = sourceID;
}

unsigned int ISISCSNPL1Packet::getStartLspIDArraySize() const
{
    return 8;
}

unsigned char ISISCSNPL1Packet::getStartLspID(unsigned int k) const
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return startLspID_var[k];
}

void ISISCSNPL1Packet::setStartLspID(unsigned int k, unsigned char startLspID)
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    this->startLspID_var[k] = startLspID;
}

unsigned int ISISCSNPL1Packet::getEndLspIDArraySize() const
{
    return 8;
}

unsigned char ISISCSNPL1Packet::getEndLspID(unsigned int k) const
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return endLspID_var[k];
}

void ISISCSNPL1Packet::setEndLspID(unsigned int k, unsigned char endLspID)
{
    if (k>=8) throw cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    this->endLspID_var[k] = endLspID;
}

void ISISCSNPL1Packet::setTLVArraySize(unsigned int size)
{
    TLV_t *TLV_var2 = (size==0) ? NULL : new TLV_t[size];
    unsigned int sz = TLV_arraysize < size ? TLV_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        TLV_var2[i] = this->TLV_var[i];
    TLV_arraysize = size;
    delete [] this->TLV_var;
    this->TLV_var = TLV_var2;
}

unsigned int ISISCSNPL1Packet::getTLVArraySize() const
{
    return TLV_arraysize;
}

TLV_t& ISISCSNPL1Packet::getTLV(unsigned int k)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    return TLV_var[k];
}

void ISISCSNPL1Packet::setTLV(unsigned int k, const TLV_t& TLV)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    this->TLV_var[k] = TLV;
}

class ISISCSNPL1PacketDescriptor : public cClassDescriptor
{
  public:
    ISISCSNPL1PacketDescriptor();
    virtual ~ISISCSNPL1PacketDescriptor();

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

Register_ClassDescriptor(ISISCSNPL1PacketDescriptor);

ISISCSNPL1PacketDescriptor::ISISCSNPL1PacketDescriptor() : cClassDescriptor("ISISCSNPL1Packet", "ISISMessage")
{
}

ISISCSNPL1PacketDescriptor::~ISISCSNPL1PacketDescriptor()
{
}

bool ISISCSNPL1PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISCSNPL1Packet *>(obj)!=NULL;
}

const char *ISISCSNPL1PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISCSNPL1PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int ISISCSNPL1PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *ISISCSNPL1PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pduLength",
        "sourceID",
        "startLspID",
        "endLspID",
        "TLV",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int ISISCSNPL1PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pduLength")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceID")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "startLspID")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "endLspID")==0) return base+3;
    if (fieldName[0]=='T' && strcmp(fieldName, "TLV")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISCSNPL1PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned char",
        "unsigned char",
        "unsigned char",
        "TLV_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *ISISCSNPL1PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISCSNPL1PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL1Packet *pp = (ISISCSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 1: return 7;
        case 2: return 8;
        case 3: return 8;
        case 4: return pp->getTLVArraySize();
        default: return 0;
    }
}

std::string ISISCSNPL1PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL1Packet *pp = (ISISCSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPduLength());
        case 1: return ulong2string(pp->getSourceID(i));
        case 2: return ulong2string(pp->getStartLspID(i));
        case 3: return ulong2string(pp->getEndLspID(i));
        case 4: {std::stringstream out; out << pp->getTLV(i); return out.str();}
        default: return "";
    }
}

bool ISISCSNPL1PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL1Packet *pp = (ISISCSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setPduLength(string2ulong(value)); return true;
        case 1: pp->setSourceID(i,string2ulong(value)); return true;
        case 2: pp->setStartLspID(i,string2ulong(value)); return true;
        case 3: pp->setEndLspID(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *ISISCSNPL1PacketDescriptor::getFieldStructName(void *object, int field) const
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
        "TLV_t",
    };
    return (field>=0 && field<5) ? fieldStructNames[field] : NULL;
}

void *ISISCSNPL1PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL1Packet *pp = (ISISCSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getTLV(i)); break;
        default: return NULL;
    }
}

Register_Class(ISISCSNPL2Packet);

ISISCSNPL2Packet::ISISCSNPL2Packet(const char *name, int kind) : ISISCSNPL1Packet(name,kind)
{
    this->setType(L2_CSNP);
}

ISISCSNPL2Packet::ISISCSNPL2Packet(const ISISCSNPL2Packet& other) : ISISCSNPL1Packet(other)
{
    copy(other);
}

ISISCSNPL2Packet::~ISISCSNPL2Packet()
{
}

ISISCSNPL2Packet& ISISCSNPL2Packet::operator=(const ISISCSNPL2Packet& other)
{
    if (this==&other) return *this;
    ISISCSNPL1Packet::operator=(other);
    copy(other);
    return *this;
}

void ISISCSNPL2Packet::copy(const ISISCSNPL2Packet& other)
{
}

void ISISCSNPL2Packet::parsimPack(cCommBuffer *b)
{
    ISISCSNPL1Packet::parsimPack(b);
}

void ISISCSNPL2Packet::parsimUnpack(cCommBuffer *b)
{
    ISISCSNPL1Packet::parsimUnpack(b);
}

class ISISCSNPL2PacketDescriptor : public cClassDescriptor
{
  public:
    ISISCSNPL2PacketDescriptor();
    virtual ~ISISCSNPL2PacketDescriptor();

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

Register_ClassDescriptor(ISISCSNPL2PacketDescriptor);

ISISCSNPL2PacketDescriptor::ISISCSNPL2PacketDescriptor() : cClassDescriptor("ISISCSNPL2Packet", "ISISCSNPL1Packet")
{
}

ISISCSNPL2PacketDescriptor::~ISISCSNPL2PacketDescriptor()
{
}

bool ISISCSNPL2PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISCSNPL2Packet *>(obj)!=NULL;
}

const char *ISISCSNPL2PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISCSNPL2PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int ISISCSNPL2PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *ISISCSNPL2PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int ISISCSNPL2PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISCSNPL2PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *ISISCSNPL2PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISCSNPL2PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL2Packet *pp = (ISISCSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ISISCSNPL2PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL2Packet *pp = (ISISCSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ISISCSNPL2PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL2Packet *pp = (ISISCSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ISISCSNPL2PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *ISISCSNPL2PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISCSNPL2Packet *pp = (ISISCSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ISISPSNPL1Packet);

ISISPSNPL1Packet::ISISPSNPL1Packet(const char *name, int kind) : ISISMessage(name,kind)
{
    this->setType(L1_PSNP);

    this->pduLength_var = 0;
    for (unsigned int i=0; i<7; i++)
        this->sourceID_var[i] = 0;
    TLV_arraysize = 0;
    this->TLV_var = 0;
}

ISISPSNPL1Packet::ISISPSNPL1Packet(const ISISPSNPL1Packet& other) : ISISMessage(other)
{
    TLV_arraysize = 0;
    this->TLV_var = 0;
    copy(other);
}

ISISPSNPL1Packet::~ISISPSNPL1Packet()
{
    delete [] TLV_var;
}

ISISPSNPL1Packet& ISISPSNPL1Packet::operator=(const ISISPSNPL1Packet& other)
{
    if (this==&other) return *this;
    ISISMessage::operator=(other);
    copy(other);
    return *this;
}

void ISISPSNPL1Packet::copy(const ISISPSNPL1Packet& other)
{
    this->pduLength_var = other.pduLength_var;
    for (unsigned int i=0; i<7; i++)
        this->sourceID_var[i] = other.sourceID_var[i];
    delete [] this->TLV_var;
    this->TLV_var = (other.TLV_arraysize==0) ? NULL : new TLV_t[other.TLV_arraysize];
    TLV_arraysize = other.TLV_arraysize;
    for (unsigned int i=0; i<TLV_arraysize; i++)
        this->TLV_var[i] = other.TLV_var[i];
}

void ISISPSNPL1Packet::parsimPack(cCommBuffer *b)
{
    ISISMessage::parsimPack(b);
    doPacking(b,this->pduLength_var);
    doPacking(b,this->sourceID_var,7);
    b->pack(TLV_arraysize);
    doPacking(b,this->TLV_var,TLV_arraysize);
}

void ISISPSNPL1Packet::parsimUnpack(cCommBuffer *b)
{
    ISISMessage::parsimUnpack(b);
    doUnpacking(b,this->pduLength_var);
    doUnpacking(b,this->sourceID_var,7);
    delete [] this->TLV_var;
    b->unpack(TLV_arraysize);
    if (TLV_arraysize==0) {
        this->TLV_var = 0;
    } else {
        this->TLV_var = new TLV_t[TLV_arraysize];
        doUnpacking(b,this->TLV_var,TLV_arraysize);
    }
}

unsigned short ISISPSNPL1Packet::getPduLength() const
{
    return pduLength_var;
}

void ISISPSNPL1Packet::setPduLength(unsigned short pduLength)
{
    this->pduLength_var = pduLength;
}

unsigned int ISISPSNPL1Packet::getSourceIDArraySize() const
{
    return 7;
}

unsigned char ISISPSNPL1Packet::getSourceID(unsigned int k) const
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    return sourceID_var[k];
}

void ISISPSNPL1Packet::setSourceID(unsigned int k, unsigned char sourceID)
{
    if (k>=7) throw cRuntimeError("Array of size 7 indexed by %lu", (unsigned long)k);
    this->sourceID_var[k] = sourceID;
}

void ISISPSNPL1Packet::setTLVArraySize(unsigned int size)
{
    TLV_t *TLV_var2 = (size==0) ? NULL : new TLV_t[size];
    unsigned int sz = TLV_arraysize < size ? TLV_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        TLV_var2[i] = this->TLV_var[i];
    TLV_arraysize = size;
    delete [] this->TLV_var;
    this->TLV_var = TLV_var2;
}

unsigned int ISISPSNPL1Packet::getTLVArraySize() const
{
    return TLV_arraysize;
}

TLV_t& ISISPSNPL1Packet::getTLV(unsigned int k)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    return TLV_var[k];
}

void ISISPSNPL1Packet::setTLV(unsigned int k, const TLV_t& TLV)
{
    if (k>=TLV_arraysize) throw cRuntimeError("Array of size %d indexed by %d", TLV_arraysize, k);
    this->TLV_var[k] = TLV;
}

class ISISPSNPL1PacketDescriptor : public cClassDescriptor
{
  public:
    ISISPSNPL1PacketDescriptor();
    virtual ~ISISPSNPL1PacketDescriptor();

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

Register_ClassDescriptor(ISISPSNPL1PacketDescriptor);

ISISPSNPL1PacketDescriptor::ISISPSNPL1PacketDescriptor() : cClassDescriptor("ISISPSNPL1Packet", "ISISMessage")
{
}

ISISPSNPL1PacketDescriptor::~ISISPSNPL1PacketDescriptor()
{
}

bool ISISPSNPL1PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISPSNPL1Packet *>(obj)!=NULL;
}

const char *ISISPSNPL1PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISPSNPL1PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int ISISPSNPL1PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *ISISPSNPL1PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pduLength",
        "sourceID",
        "TLV",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int ISISPSNPL1PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pduLength")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceID")==0) return base+1;
    if (fieldName[0]=='T' && strcmp(fieldName, "TLV")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISPSNPL1PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned char",
        "TLV_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *ISISPSNPL1PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISPSNPL1PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL1Packet *pp = (ISISPSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 1: return 7;
        case 2: return pp->getTLVArraySize();
        default: return 0;
    }
}

std::string ISISPSNPL1PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL1Packet *pp = (ISISPSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPduLength());
        case 1: return ulong2string(pp->getSourceID(i));
        case 2: {std::stringstream out; out << pp->getTLV(i); return out.str();}
        default: return "";
    }
}

bool ISISPSNPL1PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL1Packet *pp = (ISISPSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 0: pp->setPduLength(string2ulong(value)); return true;
        case 1: pp->setSourceID(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *ISISPSNPL1PacketDescriptor::getFieldStructName(void *object, int field) const
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
        "TLV_t",
    };
    return (field>=0 && field<3) ? fieldStructNames[field] : NULL;
}

void *ISISPSNPL1PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL1Packet *pp = (ISISPSNPL1Packet *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getTLV(i)); break;
        default: return NULL;
    }
}

Register_Class(ISISPSNPL2Packet);

ISISPSNPL2Packet::ISISPSNPL2Packet(const char *name, int kind) : ISISPSNPL1Packet(name,kind)
{
    this->setType(L2_PSNP);
}

ISISPSNPL2Packet::ISISPSNPL2Packet(const ISISPSNPL2Packet& other) : ISISPSNPL1Packet(other)
{
    copy(other);
}

ISISPSNPL2Packet::~ISISPSNPL2Packet()
{
}

ISISPSNPL2Packet& ISISPSNPL2Packet::operator=(const ISISPSNPL2Packet& other)
{
    if (this==&other) return *this;
    ISISPSNPL1Packet::operator=(other);
    copy(other);
    return *this;
}

void ISISPSNPL2Packet::copy(const ISISPSNPL2Packet& other)
{
}

void ISISPSNPL2Packet::parsimPack(cCommBuffer *b)
{
    ISISPSNPL1Packet::parsimPack(b);
}

void ISISPSNPL2Packet::parsimUnpack(cCommBuffer *b)
{
    ISISPSNPL1Packet::parsimUnpack(b);
}

class ISISPSNPL2PacketDescriptor : public cClassDescriptor
{
  public:
    ISISPSNPL2PacketDescriptor();
    virtual ~ISISPSNPL2PacketDescriptor();

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

Register_ClassDescriptor(ISISPSNPL2PacketDescriptor);

ISISPSNPL2PacketDescriptor::ISISPSNPL2PacketDescriptor() : cClassDescriptor("ISISPSNPL2Packet", "ISISPSNPL1Packet")
{
}

ISISPSNPL2PacketDescriptor::~ISISPSNPL2PacketDescriptor()
{
}

bool ISISPSNPL2PacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ISISPSNPL2Packet *>(obj)!=NULL;
}

const char *ISISPSNPL2PacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ISISPSNPL2PacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int ISISPSNPL2PacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *ISISPSNPL2PacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int ISISPSNPL2PacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ISISPSNPL2PacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *ISISPSNPL2PacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ISISPSNPL2PacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL2Packet *pp = (ISISPSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ISISPSNPL2PacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL2Packet *pp = (ISISPSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool ISISPSNPL2PacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL2Packet *pp = (ISISPSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *ISISPSNPL2PacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *ISISPSNPL2PacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ISISPSNPL2Packet *pp = (ISISPSNPL2Packet *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


