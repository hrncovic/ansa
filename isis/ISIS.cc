/*
 * IS-IS.cc
 *
 *  Created on: 2.4.2012
 *  Author: Matej Hrncirik
 */

#include "ISIS.h"

void ISIS::handleMessage(cMessage* msg)
{

    cGate* gate = msg->getArrivalGate();
    string name = gate->getBaseName();
    int index = gate->getIndex();

    if (name == "ifIn")
    {
        //cMessage *MsgCopy = msg->dup();
        ev << "received packet\n";
    }


}

