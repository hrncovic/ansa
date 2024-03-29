//
// Copyright (C) 2003 CTIE, Monash University
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


package inet.ansa.ethernet;

//
// Ethernet MAC layer. MAC performs transmission and reception of frames.
// Doesn't do encapsulation/decapsulation; see EtherLLC and EtherEncap for
// that.
//
// Supported variations:
// - 10Mb Ethernet bus or twisted pair
// - 100Mb Ethernet duplex or half-duplex
// - 1Gb Ethernet
//
// Supports all three Ethernet frame types. (It handles EtherFrame message class;
// specific frame classes (Ethernet-II, IEEE 802.3) are subclassed from that one.)
// RAW mode (only used by the IPX protocol) is not supported.
//
// Expected environment:
// - phys$i and phys$o should be connected to the "network"
// - upperLayerIn and upperLayerOut are usually connected to EtherLLC (in hosts)
//   or MACRelayUnitPP (in a switch)
//
// <b>Operation</b>
//
// Processing of frames received from higher layers:
// - if src address in the frame is empty, fill it out
// - frames get queued up until transmission
// - transmit according to the CSMA/CD protocol
// - can send PAUSE message if requested by higher layers (PAUSE protocol,
//   used in switches).
//
// Processing of frames incoming from the network:
// - receive according to the CSMA/CD protocol
// - CRC checking (frames with the error bit set are discarded).
// - respond to PAUSE frames
// - in promiscuous mode, pass up all received frames;
//   otherwise, only frames with matching MAC addresses and
//   broadcast frames are passed up.
//
// The module does not perform encapsulation or decapsulation of frames --
// this is done by higher layers (EtherLLC or EtherEncap).
//
// When a frame is received from the higher layers, it must be an EtherFrame,
// and with all protocol fields filled out
// (including the destination MAC address). The source address, if left empty,
// will be filled in. Then frame is queued and transmitted according
// to the CSMA/CD protocol.
//
// Data frames received from the network are EtherFrames. They are passed to
// the higher layers without modification.
// Also, the module properly responds to PAUSE frames, but never sends them
// by itself -- however, it transmits PAUSE frames received from upper layers.
// See <a href="ether-pause.html">PAUSE handling</a> for more info.
//
// <b>Autoconfiguration</b>
//
// A very short period at the beginning of the simulation is spent on
// all EtherMAC's exchanging autoconfiguration messages, during which
// the selection of transmission rate and full duplex/half duplex mode
// takes place.
//
// For more info see <a href="ether-overview.html">Ethernet Model Overview</a>.
//
// <b>Disabling and disconnecting</b>
//
// If the MAC is not connected to the network ("cable unplugged"), it will
// start up in "disabled" mode. A disabled MAC simply discards any messages
// it receives. It is currently not supported to dynamically connect/disconnect
// a MAC.
//
//
// <b>Queueing</b>
//
// In routers, MAC relies on an external queue module (see OutputQueue)
// to model finite buffer, implement QoS and/or RED, and requests packets
// from this external queue one-by-one.
//
// In hosts, no such queue is used, so MAC contains an internal
// queue named txQueue to queue up packets waiting for transmission.
// Conceptually, txQueue is of infinite size, but for better diagnostics
// one can specify a hard limit in the txQueueLimit parameter -- if this is
// exceeded, the simulation stops with an error.
//
//
// <b>Physical layer messaging</b>
//
// Please see <a href="physical.html">Messaging on the physical layer</a>.
//
// <b>Statistics</b>
//
// Output vectors and WATCHes:
// - framesSent: number of frames sent
// - framesReceivedOK: number of frames received without collision or CRC error
// - bytesSent: bytes sent, including Ethernet frame fields (but excluding preamble and SFD)
// - bytesReceivedOK: total bytes received, including Ethernet frame fields
//   (but excluding preamble and SFD), including discarded frames (see also
//   framesPassedToHL)
// - droppedIfaceDown: number of frames from higher layer dropped
// - droppedBitError: number of frames dropped because of bit errors
// - droppedNotForUs: number of frames dropped because destination address didn't match
// - framesPassedToHL: number of frames actually passed up to higher layer
// - pauseFramesRcvd: number of PAUSE frames received from network
// - pauseFramesSent: number of PAUSE frames sent out
// - collisions: number of collisions (NOT number of collided frames!) sensed
// - backoffs: number of retransmissions
//
// Output scalars (written in the finish() function) include the final values of
// the above variables and throughput.
//
// @see EtherMAC2, EthernetInterface, EthernetInterface2, OutputQueue, EtherEncap, EtherLLC
// @see EtherFrame, EthernetIIFrame, EtherFrameWithLLC, Ieee802Ctrl
//
simple AnsaEtherMAC
{
    parameters:
        bool promiscuous = default(false); // if true, all packets are received, otherwise only the
                                // ones with matching destination MAC address
        string address = default("auto");  // MAC address as hex string (12 hex digits), or
                                // "auto". "auto" values will be replaced by
                                // a generated MAC address in init stage 0.
        double txrate @unit("bps") = default(100Mbps); // maximum data rate supported by this station (bit/s);
                                // actually chosen speed may be lower due to auto-
                                // configuration. 0 means fully auto-configured.
        bool duplexEnabled = default(true);   // whether duplex mode can be enabled or not; whether
                                // MAC will actually use duplex mode depends on the result
                                // of the auto-configuration process (duplex is only
                                // possible with DTE-to-DTE connection).
        int txQueueLimit = default(1000); // maximum number of frames queued up for transmission;
                                // additional frames are dropped. Only used if queueModule==""
        string queueModule = default("");    // name of optional external queue module
        @display("i=block/rxtx");
    gates:
        input upperLayerIn;    // to EtherLLC or MACRelayUnitPP
        output upperLayerOut;  // to EtherLLC or MACRelayUnitPP
        inout phys;            // to physical layer or the network
}

