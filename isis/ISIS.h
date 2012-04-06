/*
 * ISIS.h
 *
 *  Created on: 2.4.2012
 *  Author: Matej Hrncirik | xhrnci00
 */

#ifndef ISIS_H_
#define ISIS_H_

#include <omnetpp.h>
#include <string>
#include "ISISMessage_m.h"


using namespace std;

class ISIS : public cSimpleModule
{
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage* msg);

};


#endif /* ISIS_H_ */
