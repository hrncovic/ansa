//
// Author: Veronika Rybov�
// Contact: xrybov00@stud.fit.vutbr.cz
// Date: 29.10.2011
// Institutuion: Brno University of Technology
//
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package inet.ansa.pim;


simple pimSplitter
{
    parameters:
    	@display("i=block/dispatch");
    gates:
        input pimDMIn;
        input pimSMIn;
        output pimDMOut;
        output pimSMOut;
        input transportIn;
        output transportOut;
}
