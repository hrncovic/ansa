//
// Copyright (C) 2004 Andras Varga
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//

#ifndef __INET_PPP_H
#define __INET_PPP_H


#include <omnetpp.h>
#include "INETDefs.h"
#include "PPPFrame_m.h"
#include "TxNotifDetails.h"
#include "INotifiable.h"

class InterfaceEntry;
class IPassiveQueue;
class NotificationBoard;

/**
 * PPP implementation.
 */
class INET_API AnsaPPP : public cSimpleModule, public INotifiable
{
  protected:
    long txQueueLimit;
    cGate *physOutGate;
    cChannel *datarateChannel; // NULL if we're not connected
    
    bool disabled;             // true if the interface is disabled, defined by the user

    cQueue txQueue;
    cMessage *endTransmissionEvent;
    IPassiveQueue *queueModule;

    InterfaceEntry *interfaceEntry;  // points into IInterfaceTable

    NotificationBoard *nb;
    TxNotifDetails notifDetails;
    bool hasSubscribers; // only notify if somebody is listening

    std::string oldConnColor;

    // statistics
    long numSent;
    long numRcvdOK;
    long numBitErr;
    long numDroppedIfaceDown;

  protected:
    virtual InterfaceEntry *registerInterface(double datarate);
    virtual void startTransmitting(cPacket *msg);
    virtual PPPFrame *encapsulate(cPacket *msg);
    virtual cPacket *decapsulate(PPPFrame *pppFrame);
    virtual void displayBusy();
    virtual void displayIdle();
    virtual void updateDisplayString();
    virtual void updateHasSubcribers();
    virtual void receiveChangeNotification(int category, const cPolymorphic *details);

  public:
    AnsaPPP();
    virtual ~AnsaPPP();
    
    virtual InterfaceEntry * getInterfaceEntry(void) { return interfaceEntry; }
    virtual void setDisabled(bool b)  { disabled = b; }
    virtual bool isDisabled(void) { return disabled; }

  protected:
    virtual int numInitStages() const {return 4;}
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
};

#endif


