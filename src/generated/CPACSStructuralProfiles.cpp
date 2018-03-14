// Copyright (c) 2018 RISC Software GmbH
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

#include "CPACSStructuralProfile.h"
#include "CPACSStructuralProfile3D.h"
#include "CPACSStructuralProfiles.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStructuralProfiles::CPACSStructuralProfiles(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
    }

    CPACSStructuralProfiles::~CPACSStructuralProfiles()
    {
    }

    CTiglUIDManager& CPACSStructuralProfiles::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSStructuralProfiles::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSStructuralProfiles::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element structuralProfile2D
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralProfile2D")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/structuralProfile2D", m_structuralProfile2Ds, reinterpret_cast<CCPACSStructuralProfiles*>(this), m_uidMgr);
        }

        // read element structuralProfile3D
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/structuralProfile3D")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/structuralProfile3D", m_structuralProfile3Ds, m_uidMgr);
        }

    }

    void CPACSStructuralProfiles::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element structuralProfile2D
        tixi::TixiSaveElements(tixiHandle, xpath + "/structuralProfile2D", m_structuralProfile2Ds);

        // write element structuralProfile3D
        tixi::TixiSaveElements(tixiHandle, xpath + "/structuralProfile3D", m_structuralProfile3Ds);

    }

    const std::vector<unique_ptr<CPACSStructuralProfile> >& CPACSStructuralProfiles::GetStructuralProfile2Ds() const
    {
        return m_structuralProfile2Ds;
    }

    std::vector<unique_ptr<CPACSStructuralProfile> >& CPACSStructuralProfiles::GetStructuralProfile2Ds()
    {
        return m_structuralProfile2Ds;
    }

    const std::vector<unique_ptr<CPACSStructuralProfile3D> >& CPACSStructuralProfiles::GetStructuralProfile3Ds() const
    {
        return m_structuralProfile3Ds;
    }

    std::vector<unique_ptr<CPACSStructuralProfile3D> >& CPACSStructuralProfiles::GetStructuralProfile3Ds()
    {
        return m_structuralProfile3Ds;
    }

    CPACSStructuralProfile& CPACSStructuralProfiles::AddStructuralProfile2D()
    {
        m_structuralProfile2Ds.push_back(make_unique<CPACSStructuralProfile>(reinterpret_cast<CCPACSStructuralProfiles*>(this), m_uidMgr));
        return *m_structuralProfile2Ds.back();
    }

    void CPACSStructuralProfiles::RemoveStructuralProfile2D(CPACSStructuralProfile& ref)
    {
        for (std::size_t i = 0; i < m_structuralProfile2Ds.size(); i++) {
            if (m_structuralProfile2Ds[i].get() == &ref) {
                m_structuralProfile2Ds.erase(m_structuralProfile2Ds.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

    CPACSStructuralProfile3D& CPACSStructuralProfiles::AddStructuralProfile3D()
    {
        m_structuralProfile3Ds.push_back(make_unique<CPACSStructuralProfile3D>(m_uidMgr));
        return *m_structuralProfile3Ds.back();
    }

    void CPACSStructuralProfiles::RemoveStructuralProfile3D(CPACSStructuralProfile3D& ref)
    {
        for (std::size_t i = 0; i < m_structuralProfile3Ds.size(); i++) {
            if (m_structuralProfile3Ds[i].get() == &ref) {
                m_structuralProfile3Ds.erase(m_structuralProfile3Ds.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl