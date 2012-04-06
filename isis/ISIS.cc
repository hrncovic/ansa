/*
 * IS-IS.cc
 *
 *  Created on: 2.4.2012
 *  Author: Matej Hrncirik | xhrnci00
 */

#include "ISIS.h"

Define_Module(ISIS);

void ISIS::initialize()
{
    ISISL1HelloPacket *msg = new ISISL1HelloPacket("hello");

    send(msg, "ifOut");

}



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

