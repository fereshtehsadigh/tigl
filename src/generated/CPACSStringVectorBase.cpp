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

#include "TixiHelper.h"
#include "CTiglLogging.h"
#include "CTiglError.h"
#include "CPACSStringVectorBase.h"

namespace tigl
{
    namespace generated
    {
        CPACSStringVectorBase::CPACSStringVectorBase(){}
        CPACSStringVectorBase::~CPACSStringVectorBase() {}
        
        void CPACSStringVectorBase::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
        {
            // read attribute mapType
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "mapType")) {
                m_mapType = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "mapType");
            }
            else {
                LOG(ERROR) << "Required attribute mapType is missing";
            }
            
            // read attribute uncertaintyFunctionName
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "uncertaintyFunctionName")) {
                m_uncertaintyFunctionName = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "uncertaintyFunctionName");
            }
            
            // read attribute mu
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "mu")) {
                m_mu = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "mu");
            }
            
            // read attribute delta
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "delta")) {
                m_delta = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "delta");
            }
            
            // read attribute a
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "a")) {
                m_a = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "a");
            }
            
            // read attribute b
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "b")) {
                m_b = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "b");
            }
            
            // read attribute c
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "c")) {
                m_c = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "c");
            }
            
            // read attribute v
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "v")) {
                m_v = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "v");
            }
            
            // read attribute w
            if (tixihelper::TixiCheckAttribute(tixiHandle, xpath, "w")) {
                m_w = tixihelper::TixiGetAttribute<std::string>(tixiHandle, xpath, "w");
            }
            
            // read simpleContent 
            if (tixihelper::TixiCheckElement(tixiHandle, xpath)) {
                m_simpleContent = tixihelper::TixiGetElement<std::string>(tixiHandle, xpath);
            }
            else {
                LOG(ERROR) << "Required simpleContent  is missing";
            }
            
        }
        
        void CPACSStringVectorBase::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
        {
            // write attribute mapType
            tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mapType");
            tixihelper::TixiSaveAttribute(tixiHandle, xpath, "mapType", m_mapType);
            
            // write attribute uncertaintyFunctionName
            if (m_uncertaintyFunctionName) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/uncertaintyFunctionName");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "uncertaintyFunctionName", *m_uncertaintyFunctionName);
            }
            
            // write attribute mu
            if (m_mu) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/mu");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "mu", *m_mu);
            }
            
            // write attribute delta
            if (m_delta) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/delta");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "delta", *m_delta);
            }
            
            // write attribute a
            if (m_a) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/a");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "a", *m_a);
            }
            
            // write attribute b
            if (m_b) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/b");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "b", *m_b);
            }
            
            // write attribute c
            if (m_c) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/c");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "c", *m_c);
            }
            
            // write attribute v
            if (m_v) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/v");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "v", *m_v);
            }
            
            // write attribute w
            if (m_w) {
                tixihelper::TixiCreateElementIfNotExists(tixiHandle, xpath + "/w");
                tixihelper::TixiSaveAttribute(tixiHandle, xpath, "w", *m_w);
            }
            
            // write simpleContent 
            tixihelper::TixiSaveElement(tixiHandle, xpath, m_simpleContent);
            
        }
        
        const std::string& CPACSStringVectorBase::GetMapType() const
        {
            return m_mapType;
        }
        
        void CPACSStringVectorBase::SetMapType(const std::string& value)
        {
            m_mapType = value;
        }
        
        bool CPACSStringVectorBase::HasUncertaintyFunctionName() const
        {
            return static_cast<bool>(m_uncertaintyFunctionName);
        }
        
        const std::string& CPACSStringVectorBase::GetUncertaintyFunctionName() const
        {
            return *m_uncertaintyFunctionName;
        }
        
        void CPACSStringVectorBase::SetUncertaintyFunctionName(const std::string& value)
        {
            m_uncertaintyFunctionName = value;
        }
        
        bool CPACSStringVectorBase::HasMu() const
        {
            return static_cast<bool>(m_mu);
        }
        
        const std::string& CPACSStringVectorBase::GetMu() const
        {
            return *m_mu;
        }
        
        void CPACSStringVectorBase::SetMu(const std::string& value)
        {
            m_mu = value;
        }
        
        bool CPACSStringVectorBase::HasDelta() const
        {
            return static_cast<bool>(m_delta);
        }
        
        const std::string& CPACSStringVectorBase::GetDelta() const
        {
            return *m_delta;
        }
        
        void CPACSStringVectorBase::SetDelta(const std::string& value)
        {
            m_delta = value;
        }
        
        bool CPACSStringVectorBase::HasA() const
        {
            return static_cast<bool>(m_a);
        }
        
        const std::string& CPACSStringVectorBase::GetA() const
        {
            return *m_a;
        }
        
        void CPACSStringVectorBase::SetA(const std::string& value)
        {
            m_a = value;
        }
        
        bool CPACSStringVectorBase::HasB() const
        {
            return static_cast<bool>(m_b);
        }
        
        const std::string& CPACSStringVectorBase::GetB() const
        {
            return *m_b;
        }
        
        void CPACSStringVectorBase::SetB(const std::string& value)
        {
            m_b = value;
        }
        
        bool CPACSStringVectorBase::HasC() const
        {
            return static_cast<bool>(m_c);
        }
        
        const std::string& CPACSStringVectorBase::GetC() const
        {
            return *m_c;
        }
        
        void CPACSStringVectorBase::SetC(const std::string& value)
        {
            m_c = value;
        }
        
        bool CPACSStringVectorBase::HasV() const
        {
            return static_cast<bool>(m_v);
        }
        
        const std::string& CPACSStringVectorBase::GetV() const
        {
            return *m_v;
        }
        
        void CPACSStringVectorBase::SetV(const std::string& value)
        {
            m_v = value;
        }
        
        bool CPACSStringVectorBase::HasW() const
        {
            return static_cast<bool>(m_w);
        }
        
        const std::string& CPACSStringVectorBase::GetW() const
        {
            return *m_w;
        }
        
        void CPACSStringVectorBase::SetW(const std::string& value)
        {
            m_w = value;
        }
        
        const std::string& CPACSStringVectorBase::GetSimpleContent() const
        {
            return m_simpleContent;
        }
        
        void CPACSStringVectorBase::SetSimpleContent(const std::string& value)
        {
            m_simpleContent = value;
        }
        
    }
}