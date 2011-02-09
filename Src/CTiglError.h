/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: CTiglError.h 4416 2011-02-08 21:03:40Z litz_ma $ 
*
* Version: $Revision: 4416 $
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file 
* @brief  Exception class used to throw tigl exceptions.
*/

#ifndef CTIGLERROR_H
#define CTIGLERROR_H

#include "tigl.h"
#include <string>

namespace tigl {

	class CTiglError
	{

	public:
		// Constructor
		CTiglError(std::string error = "", TiglReturnCode errorCode = TIGL_ERROR) throw();

		// Destructor
		virtual ~CTiglError(void) throw();

		// Default copy constructor and assignment operator are correct since
		// memberwise copy is enough for this class.

		// Returns the error string as C string (char*)
		virtual const char* getError(void) const throw();

		// Returns the error code
		virtual TiglReturnCode getCode(void) const throw();

	private:
		std::string	   err;
		TiglReturnCode code;
		
	};

} // end namespace tigl

#endif // CTIGLERROR_H
