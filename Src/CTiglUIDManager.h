/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id: CTiglUIDManager.h 4416 2011-02-08 21:03:40Z litz_ma $ 
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
* @brief  Implementation of the TIGL UID manager.
*/

#ifndef CTIGLUIDMANAGER_H
#define CTIGLUIDMANAGER_H

#include "ITiglGeometricComponent.h"
#include <map>
#include <string>

namespace tigl {

	class CTiglUIDManager
	{

    private:
        typedef std::map<const std::string, ITiglGeometricComponent*> UIDStoreContainerType;        

	public:
		// Constructor
        CTiglUIDManager(void);

        // Function to add a UID and a geometric component to the uid store.
        void AddUID(const std::string& uid, ITiglGeometricComponent* componentPtr);

        // Checks if a UID already exists. 
        bool HasUID(const std::string& uid) const;

        // Returns a pointer to the geometric component for the given unique id.
        ITiglGeometricComponent* GetComponent(const std::string& uid);

        // Returns the parent component for a component or a null pointer
        // if there is no parent.
        ITiglGeometricComponent* GetParentComponent(const std::string& uid);

        // Returns the root component of the geometric topology.
        ITiglGeometricComponent* GetRootComponent(void);

        // Clears the uid store
        void Clear(void);

		// Virtual Destructor
		virtual ~CTiglUIDManager(void);

    protected:
   		// Update internal UID manager data.
		void Update(void);

        // Returns the root component of the geometric topology.
        void FindRootComponent(void);

        // Builds the parent child relationships.
        void BuildParentChildTree(void);

    private:
		// Copy constructor
		CTiglUIDManager(const CTiglUIDManager& ) { /* Do nothing */ }

		// Assignment operator
		void operator=(const CTiglUIDManager& ) { /* Do nothing */ }

    private:
        UIDStoreContainerType    uidStore;
		bool                     invalidated;          /**< Internal state flag */
        ITiglGeometricComponent* rootComponent;        /**< Ptr to the root component of the component tree */

	};

} // end namespace tigl

#endif // CTIGLUIDMANAGER_H
