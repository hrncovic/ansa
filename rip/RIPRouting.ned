//
// Author: Veronika Rybov�
// Contact: xrybov00@stud.fit.vutbr.cz
// Date: 11.5.2009
// Institutuion: Brno University of Technology
// 
// Tento modul vznikl v r�mci m� bakal��sk� pr�ce.
// This module was created within the scope of my bachelor's thesis.
// 
// Modul RIPRouting v sob� implementuje protokol RIP a redistribuci
// z protokolu OSPF do protokolu RIP.
// Module RIPRouting implements protocol RIP and redistribution from
// protocol OSPF to protocol RIP.
// 
// Zde uveden� parametry je, pro spr�vnou funk�nost modulu RIPRouting,
// zadat do omnetpp.ini souboru ke ka�d� simulaci.
// 


package inet.ansa.rip;

simple RIPRouting
{
    parameters:
       int localPort = default(520);
       int destPort = default(520);
       string configFile;
       string hostname;
       @display("i=block/network2");  
    gates:
        input udpIn;
        output udpOut;
}