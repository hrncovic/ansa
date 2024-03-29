//
// Copyright (C) 2009
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

package inet.ansa;

import inet.base.NotificationBoard;
import inet.ansa.InterfaceStateManager.InterfaceStateManager;
import inet.ansa.ethernet.AnsaEthernetInterface;
import inet.ansa.ppp.PPPInterface;
//import inet.nodes.inet.NetworkLayer;
import inet.ansa.AnsaNetworkLayer;
import inet.ansa.routingTable.AnsaInterfaceTable;
import inet.ansa.routingTable.AnsaRoutingTable;
import inet.ansa.ospfv2.AnsaOSPFRouting;
import inet.ansa.rip.RIPRouting;
import inet.transport.udp.UDP;
import inet.ansa.acl.acl;
import inet.ansa.ipSplitter.IpSplitter;
import inet.ansa.deviceConfigurator.DeviceConfigurator;
import inet.ansa.isis.ISIS;

import inet.ansa.IPGen.AnsaIPTrafGen;
//
// \IP router.
//
module ANSARouter
{
    parameters:
        @node();
        string routingFile = default("");
        string hostname = default("");
        string routerId;
        @display("i=srouter;bgb=482,414");
    gates:
        inout pppg[];
        inout ethg[];
    submodules:

   //     deviceConfigurator: DeviceConfigurator {
   //         parameters:
   //			deviceId = deviceId;
   //           deviceType = "Router";
   //           configFile = configFile;
   //           @display("p=395,342");
   //     }
        notificationBoard: NotificationBoard {
            parameters:
                @display("p=45,42");
        }
        interfaceStateManager: InterfaceStateManager {
            parameters:
                @display("p=154,42");
        }
        interfaceTable: AnsaInterfaceTable {
            parameters:
                @display("p=250,42");
        }
        routingTable: AnsaRoutingTable {
            parameters:
                IPForward = true;
                routerId = routerId;
                @display("p=323,42");
        }
        ospf: AnsaOSPFRouting {
            parameters:
                @display("p=297,115,row");
        }
        rip: RIPRouting {
            parameters:
                hostname = hostname;
                @display("p=45,195,row;i=block/network2");
        }
        udp: UDP {
            parameters:
                @display("p=84,126;i=block/transport");
            gates:
                appIn[1];
                appOut[1];
        }
        ipSplitter: IpSplitter {
            parameters:
                @display("p=183,304");
            gates:
                ifIn[sizeof(pppg)+sizeof(ethg)];
                ifOut[sizeof(pppg)+sizeof(ethg)];
                ipv4In[sizeof(pppg)+sizeof(ethg)];
                ipv4Out[sizeof(pppg)+sizeof(ethg)];
        }
        //eigrp: EigrpRouting {
        //    parameters:
        //        @display("p=331,200,row");
        //}
        acl: acl {
            parameters:
                @display("p=183,216,row;i=block/network2");
            gates:
                toNetworkLayerIn[sizeof(pppg)+sizeof(ethg)];
                toNetworkLayerOut[sizeof(pppg)+sizeof(ethg)];
                ifIn[sizeof(pppg)+sizeof(ethg)];
                ifOut[sizeof(pppg)+sizeof(ethg)];
        }
        networkLayer: AnsaNetworkLayer {
            parameters:
                @display("p=183,143;q=queue");
            gates:
                ifIn[sizeof(pppg)+sizeof(ethg)];
                ifOut[sizeof(pppg)+sizeof(ethg)];
        }
        ppp[sizeof(pppg)]: PPPInterface {
            parameters:
                @display("p=92,343,row,110;q=l2queue");
        }
        eth[sizeof(ethg)]: AnsaEthernetInterface {
            parameters:
                @display("p=289,337,row,110;q=l2queue");
        }
        ipTrafGen: AnsaIPTrafGen {
            @display("p=297,195");
        }
        isis: ISIS {
            @display("p=289,265");
        }
    connections allowunconnected:
        ospf.ipOut --> networkLayer.ospfIn;
        ospf.ipIn <-- networkLayer.ospfOut;

        rip.udpOut --> udp.appIn[0];
        rip.udpIn <-- udp.appOut[0];

        udp.ipOut --> networkLayer.udpIn;
        udp.ipIn <-- networkLayer.udpOut;

        ipTrafGen.ipOut --> networkLayer.rsvpIn;
        ipTrafGen.ipIn <-- networkLayer.rsvpOut;

		ipSplitter.isisOut --> isis.ifIn;
        ipSplitter.isisIn <-- isis.ifOut;

        //eigrp.ipOut --> networkLayer.eigrpIn;
        //eigrp.ipIn <-- networkLayer.eigrpOut;

        // connections to network outside
        for i=0..sizeof(pppg)-1 {
            pppg[i] <--> ppp[i].phys;

            ppp[i].netwOut --> ipSplitter.ifIn[i];
            ppp[i].netwIn <-- ipSplitter.ifOut[i];

            acl.toNetworkLayerOut[i] --> networkLayer.ifIn[i];
            acl.toNetworkLayerIn[i] <-- networkLayer.ifOut[i];

            ipSplitter.ipv4Out[i] --> acl.ifIn[i];
            ipSplitter.ipv4In[i] <-- acl.ifOut[i];

            

        }

        for i=0..sizeof(ethg)-1 {
            ethg[i] <--> eth[i].phys;

            eth[i].netwOut --> ipSplitter.ifIn[sizeof(pppg)+i];
            eth[i].netwIn <-- ipSplitter.ifOut[sizeof(pppg)+i];

            acl.toNetworkLayerOut[sizeof(pppg)+i] --> networkLayer.ifIn[sizeof(pppg)+i];
            acl.toNetworkLayerIn[sizeof(pppg)+i] <-- networkLayer.ifOut[sizeof(pppg)+i];

            ipSplitter.ipv4Out[sizeof(pppg)+i] --> acl.ifIn[sizeof(pppg)+i];
            ipSplitter.ipv4In[sizeof(pppg)+i] <-- acl.ifOut[sizeof(pppg)+i];


        }

}


