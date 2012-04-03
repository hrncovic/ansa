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

#include "ansaLsa6.h"

bool AnsaOspf6::AsExternalLsa::Update(const OspfAsExternalLsa6* lsa) {
   bool different = DiffersFrom(lsa);
   (*this) = (*lsa);
   ResetInstallTime();
   if (different){
      ClearNextHops();
      return true;
   }else{
      return false;
   }
}

bool AnsaOspf6::AsExternalLsa::DiffersFrom(const OspfAsExternalLsa6* asExternalLsa) const {

   const OspfLsaHeader6& lsaHeader = asExternalLsa->getHeader();

   if (((header_var.getLsAge() == MAX_AGE) && (lsaHeader.getLsAge() != MAX_AGE))
         || ((header_var.getLsAge() != MAX_AGE) && (lsaHeader.getLsAge() == MAX_AGE))
         || (header_var.getAdvertisingRouter() != lsaHeader.getAdvertisingRouter())
         || (header_var.getLsSequenceNumber() != lsaHeader.getLsSequenceNumber())){
      return true;


   }else if (E_ExternalMetricType_var != asExternalLsa->getE_ExternalMetricType()){
      return true;
   }else if (F_ForwardingAddress_var != asExternalLsa->getF_ForwardingAddress()){
      return true;
   }else if (T_ExternalRouteTag_var != asExternalLsa->getT_ExternalRouteTag()){
      return true;
   }else if (metric_var != asExternalLsa->getMetric()){
      return true;
   }else if (prefixLenght_var != asExternalLsa->getPrefixLenght()){
      return true;
   }else if (prefixOptions_var != asExternalLsa->getPrefixOptions()){
      return true;
   }else if (referencedLsType_var != asExternalLsa->getReferencedLsType()){
      return true;
   }else if (addressPrefix_var != asExternalLsa->getAddressPrefix()){
      return true;
   }else if (forwardingAddress_var != asExternalLsa->getForwardingAddress()){
      return true;
   }else if (externalRouteTag_var != asExternalLsa->getExternalRouteTag()){
      return true;
   }else if (referencedLinkStateID_var != asExternalLsa->getReferencedLinkStateID()){
      return true;
   }

   return false;
}
