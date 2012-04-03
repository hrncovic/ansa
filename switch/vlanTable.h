
/*
 -- TODO --
 - VLAN ID
 - VLAN ifaces mapping


*/



#ifndef __VLANTABLE_H__
#define __VLANTABLE_H__



#include "IPAddress.h"
#include "IPAddressResolver.h"
#include "IRoutingTable.h"
#include "RoutingTableAccess.h"
#include "IInterfaceTable.h"
#include "InterfaceTableAccess.h"
#include "IPDatagram.h"
#include "TCPSegment.h"
#include "UDPPacket.h"
#include "NotificationBoard.h"
#include "MACAddress.h"
#include "Ethernet.h"
#include "EtherFrame_m.h"


#include <string>
#include <vector>


#define VLANCOUNT 32

class INET_API VLANTable : public cSimpleModule
{
public:

  VLANTable();
  ~VLANTable();


  /* VLAN -> Port mapping */
  typedef enum e_tag_action {
	  REMOVE = 0,
	  INCLUDE = 1,
	  NONE = -1,
  } tTagAction;

  typedef struct s_vid_port {
	  int port;
	  tTagAction action;
  } tVIDPort;

  typedef std::vector<tVIDPort> tVIDPortList;

  typedef struct s_vid_record {
	  int VID;
	  std::string name;
	  tVIDPortList portList;
  } tVIDRecord;

  /* Port -> VLAN mapping */
  typedef struct s_port_vid {
	  int port;
	  int VID;
  } tPortVIDRecord;


  typedef std::vector<tVIDRecord> VIDTable;
  typedef std::vector<tPortVIDRecord> PortVIDTable;

  /* MGMT */
  const VIDTable * getTaggedTable();
  const PortVIDTable * getUntaggedTable();

  /* PUBLIC ACCESS METHODS */
  tVIDPortList getPorts(int VID);
  int getVID(int Port);
  bool isAllowed(int VID, int _port);
  tTagAction getTag(int VID, int _port);

  /* MGMT */
	void add(int VID, tVIDPortList& _portList);
	void addTagged(int VID, std::vector<int>& ports);
	void addUntagged(int VID, std::vector<int>& ports);

	void setVLANName(int, std::string&);

	void addPortVID(int _port, int _VID);
	void setPortVID(int _port, int _VID);

	void delPort(int _port, int _VID);

	void regVLAN(unsigned int);
	std::vector<unsigned int> getVLANList();

	void initDefault();

	/* add empty records at the end of existing until given VLAN, inclusive*/
	void extendTable(int VLAN);

private:
	VIDTable vidTable;
	PortVIDTable portVIDTable;
	tVIDPortList empty;

	tVIDRecord emptyVID;

	std::vector<unsigned int> vlanList;

	int portCount;


protected:

  virtual void initialize(int stage);
  virtual int numInitStages() const {return 1;}
  virtual void finish();



};

inline std::ostream& operator<<(std::ostream& os, const VLANTable::tTagAction a) {
	switch (a) {
	case VLANTable::INCLUDE:
		os << "T";
		break;
	case VLANTable::REMOVE:
		os << "U";
		break;
	case VLANTable::NONE:
		os << "??";
		break;
	}
	return os;
}


inline std::ostream& operator<<(std::ostream& os, const VLANTable::tVIDPortList l) {
	os << "[";
	for (unsigned int i = 0; i < l.size(); i++) {
		if (i != 0) {
			os << ", ";
		}
		os << l.at(i).port << l.at(i).action;
	}
	os << "]";
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const VLANTable::tPortVIDRecord r) {
	os << "Port " << r.port << " accessing VLAN " << r.VID;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const VLANTable::tVIDRecord r) {
	os << "VLAN " << r.VID << " at ports " << r.portList;
	return os;
}

#endif

