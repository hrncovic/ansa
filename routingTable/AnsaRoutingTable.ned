//
// Copyright (C) 2004 Andras Varga
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
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


package inet.ansa.routingTable;

//
// Stores the routing table. (Per-interface configuration is stored in 
// InterfaceTable.)
//
// For hosts, the routerId module parameter should be empty (""),
// in which case the loopback IP address will be set to 127.0.0.1/8.
// For routers which have a routerId set, the loopback address will be set to
// routerId. (See also RFC 2072 "\Router Renumbering Guide".)
//
// RouterId may also be set to the string <tt>"auto"</tt>, in which case the
// highest interface address will be chosen as routerId; the loopback address
// will remain 127.0.0.1/8.
//
// The routing table is read from a file (parameter routingFile);
// the file can also fill in or overwrite interface settings.
// The file format is documented <a href="irt.html">here</a>.
//
// Note that many protocols don't require routerId to be routable, but some
// others do -- so it is probably a good idea to set up routable routerIds.
//
// This module has no gates; all functionality can be accessed via member
// functions of the C++ module class. For detailed info, please see the C++
// documentation of the class (Doxygen).
//
// @see InterfaceTable
// @author: Jochen Reber, Andras Varga
//
simple AnsaRoutingTable
{
    parameters:
        string routerId ; // for routers, the router id using IP address dotted
                          // notation; specify "auto" to select the highest
                          // interface address; should be left empty ("") for hosts
        bool IPForward = default(true);  // turns IP forwarding on/off
        string configFile = default("");  // routing table file name
        @display("i=block/table");
}

