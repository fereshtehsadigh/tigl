// Copyright (c) 2016 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <tixi.h>
#include <string>
#include <boost/optional.hpp>
#include "tigl_internal.h"

namespace tigl
{
    namespace generated
    {
        // This class is used in:
        // CPACSPositionings
        
        // generated from /xsd:schema/xsd:complexType[697]
        class CPACSPositioning
        {
        public:
            TIGL_EXPORT CPACSPositioning();
            TIGL_EXPORT virtual ~CPACSPositioning();
            
            TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
            TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;
            
            TIGL_EXPORT bool HasUID() const;
            TIGL_EXPORT const std::string& GetUID() const;
            TIGL_EXPORT void SetUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetName() const;
            TIGL_EXPORT void SetName(const std::string& value);
            
            TIGL_EXPORT bool HasDescription() const;
            TIGL_EXPORT const std::string& GetDescription() const;
            TIGL_EXPORT void SetDescription(const std::string& value);
            
            TIGL_EXPORT const double& GetLength() const;
            TIGL_EXPORT void SetLength(const double& value);
            
            TIGL_EXPORT const double& GetSweepAngle() const;
            TIGL_EXPORT void SetSweepAngle(const double& value);
            
            TIGL_EXPORT const double& GetDihedralAngle() const;
            TIGL_EXPORT void SetDihedralAngle(const double& value);
            
            TIGL_EXPORT bool HasFromSectionUID() const;
            TIGL_EXPORT const std::string& GetFromSectionUID() const;
            TIGL_EXPORT void SetFromSectionUID(const std::string& value);
            
            TIGL_EXPORT const std::string& GetToSectionUID() const;
            TIGL_EXPORT void SetToSectionUID(const std::string& value);
            
        protected:
            boost::optional<std::string> m_uID;
            std::string                  m_name;
            boost::optional<std::string> m_description;
            double                       m_length;
            double                       m_sweepAngle;
            double                       m_dihedralAngle;
            boost::optional<std::string> m_fromSectionUID;
            std::string                  m_toSectionUID;
            
        private:
            #ifdef HAVE_CPP11
            CPACSPositioning(const CPACSPositioning&) = delete;
            CPACSPositioning& operator=(const CPACSPositioning&) = delete;
            
            CPACSPositioning(CPACSPositioning&&) = delete;
            CPACSPositioning& operator=(CPACSPositioning&&) = delete;
            #else
            CPACSPositioning(const CPACSPositioning&);
            CPACSPositioning& operator=(const CPACSPositioning&);
            #endif
        };
    }
    
    // This type is customized, use type CCPACSPositioning
}