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

#include "CPACSProfileGeometry.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSProfileGeometry::CPACSProfileGeometry(CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
    }

    CPACSProfileGeometry::~CPACSProfileGeometry()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    CTiglUIDManager& CPACSProfileGeometry::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSProfileGeometry::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSProfileGeometry::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute symmetry
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
            m_symmetry = stringToTiglSymmetryAxis(tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "symmetry"));
        }

        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element name
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/name")) {
            m_name = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/name");
            if (m_name.empty()) {
                LOG(WARNING) << "Required element name is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element name is missing at xpath " << xpath;
        }

        // read element description
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
            m_description = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/description");
            if (m_description->empty()) {
                LOG(WARNING) << "Optional element description is present but empty at xpath " << xpath;
            }
        }

        // read element pointList
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pointList")) {
            m_pointList_choice1 = boost::in_place();
            try {
                m_pointList_choice1->ReadCPACS(tixiHandle, xpath + "/pointList");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read pointList at xpath " << xpath << ": " << e.what();
                m_pointList_choice1 = boost::none;
            }
        }

        // read element cst2D
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cst2D")) {
            m_cst2D_choice2 = boost::in_place();
            try {
                m_cst2D_choice2->ReadCPACS(tixiHandle, xpath + "/cst2D");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cst2D at xpath " << xpath << ": " << e.what();
                m_cst2D_choice2 = boost::none;
            }
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSProfileGeometry::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute symmetry
        if (m_symmetry) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "symmetry", TiglSymmetryAxisToString(*m_symmetry));
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "symmetry")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "symmetry");
            }
        }

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element name
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/name");
        tixi::TixiSaveElement(tixiHandle, xpath + "/name", m_name);

        // write element description
        if (m_description) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/description");
            tixi::TixiSaveElement(tixiHandle, xpath + "/description", *m_description);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/description")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/description");
            }
        }

        // write element pointList
        if (m_pointList_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/pointList");
            m_pointList_choice1->WriteCPACS(tixiHandle, xpath + "/pointList");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/pointList")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/pointList");
            }
        }

        // write element cst2D
        if (m_cst2D_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cst2D");
            m_cst2D_choice2->WriteCPACS(tixiHandle, xpath + "/cst2D");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cst2D")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cst2D");
            }
        }

    }

    bool CPACSProfileGeometry::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_pointList_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_cst2D_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_cst2D_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_pointList_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<TiglSymmetryAxis>& CPACSProfileGeometry::GetSymmetry() const
    {
        return m_symmetry;
    }

    void CPACSProfileGeometry::SetSymmetry(const boost::optional<TiglSymmetryAxis>& value)
    {
        m_symmetry = value;
    }

    const std::string& CPACSProfileGeometry::GetUID() const
    {
        return m_uID;
    }

    void CPACSProfileGeometry::SetUID(const std::string& value)
    {
        if (m_uidMgr) {
            m_uidMgr->TryUnregisterObject(m_uID);
            m_uidMgr->RegisterObject(value, *this);
        }
        m_uID = value;
    }

    const std::string& CPACSProfileGeometry::GetName() const
    {
        return m_name;
    }

    void CPACSProfileGeometry::SetName(const std::string& value)
    {
        m_name = value;
    }

    const boost::optional<std::string>& CPACSProfileGeometry::GetDescription() const
    {
        return m_description;
    }

    void CPACSProfileGeometry::SetDescription(const boost::optional<std::string>& value)
    {
        m_description = value;
    }

    const boost::optional<CPACSCurvePointListXYZ>& CPACSProfileGeometry::GetPointList_choice1() const
    {
        return m_pointList_choice1;
    }

    boost::optional<CPACSCurvePointListXYZ>& CPACSProfileGeometry::GetPointList_choice1()
    {
        return m_pointList_choice1;
    }

    const boost::optional<CCPACSWingProfileCST>& CPACSProfileGeometry::GetCst2D_choice2() const
    {
        return m_cst2D_choice2;
    }

    boost::optional<CCPACSWingProfileCST>& CPACSProfileGeometry::GetCst2D_choice2()
    {
        return m_cst2D_choice2;
    }

    CPACSCurvePointListXYZ& CPACSProfileGeometry::GetPointList_choice1(CreateIfNotExistsTag)
    {
        if (!m_pointList_choice1)
            m_pointList_choice1 = boost::in_place();
        return *m_pointList_choice1;
    }

    void CPACSProfileGeometry::RemovePointList_choice1()
    {
        m_pointList_choice1 = boost::none;
    }

    CCPACSWingProfileCST& CPACSProfileGeometry::GetCst2D_choice2(CreateIfNotExistsTag)
    {
        if (!m_cst2D_choice2)
            m_cst2D_choice2 = boost::in_place();
        return *m_cst2D_choice2;
    }

    void CPACSProfileGeometry::RemoveCst2D_choice2()
    {
        m_cst2D_choice2 = boost::none;
    }

} // namespace generated
} // namespace tigl
