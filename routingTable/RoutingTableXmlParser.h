//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
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


#ifndef __INET_ROUTINGTABLEXMLPARSER_H
#define __INET_ROUTINGTABLEXMLPARSER_H

#include <omnetpp.h>
#include "AnsaRoutingTable.h"

/**
 * Parses a routing table file into a routing table.
 */
class INET_API RoutingTableXmlParser
{
  protected:
    IInterfaceTable *ift;
    IRoutingTable *rt;

  public:
    /**
     * Constructor
     */
    RoutingTableXmlParser(IInterfaceTable *ift, IRoutingTable *rt);

    /**
     * Read Routing Table file; return 0 on success, -1 on error
     */
    virtual bool readRoutingTableFromXml (const char *filename, const char *RouterId);
    
    
    void readInterfaceFromXml(cXMLElement* Node);
    void readStaticRouteFromXml(cXMLElement* Node); 
};


#endif

