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

#include <cassert>
#include "CCPACSFuselage.h"
#include "CPACSFuselageStructure.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSFuselageStructure::CPACSFuselageStructure(CCPACSFuselage* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSFuselageStructure::~CPACSFuselageStructure()
    {
    }

    CCPACSFuselage* CPACSFuselageStructure::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSFuselageStructure::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSFuselageStructure::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSFuselageStructure::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element skin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/skin")) {
            m_skin = boost::in_place(m_uidMgr);
            try {
                m_skin->ReadCPACS(tixiHandle, xpath + "/skin");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read skin at xpath " << xpath << ": " << e.what();
                m_skin = boost::none;
            }
        }

        // read element stringers
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/stringers")) {
            m_stringers = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_stringers->ReadCPACS(tixiHandle, xpath + "/stringers");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read stringers at xpath " << xpath << ": " << e.what();
                m_stringers = boost::none;
            }
        }

        // read element frames
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/frames")) {
            m_frames = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_frames->ReadCPACS(tixiHandle, xpath + "/frames");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read frames at xpath " << xpath << ": " << e.what();
                m_frames = boost::none;
            }
        }

        // read element cargoCrossBeams
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoCrossBeams")) {
            m_cargoCrossBeams = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_cargoCrossBeams->ReadCPACS(tixiHandle, xpath + "/cargoCrossBeams");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cargoCrossBeams at xpath " << xpath << ": " << e.what();
                m_cargoCrossBeams = boost::none;
            }
        }

        // read element cargoCrossBeamStruts
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoCrossBeamStruts")) {
            m_cargoCrossBeamStruts = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_cargoCrossBeamStruts->ReadCPACS(tixiHandle, xpath + "/cargoCrossBeamStruts");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cargoCrossBeamStruts at xpath " << xpath << ": " << e.what();
                m_cargoCrossBeamStruts = boost::none;
            }
        }

        // read element longFloorBeams
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/longFloorBeams")) {
            m_longFloorBeams = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_longFloorBeams->ReadCPACS(tixiHandle, xpath + "/longFloorBeams");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read longFloorBeams at xpath " << xpath << ": " << e.what();
                m_longFloorBeams = boost::none;
            }
        }

        // read element pressureBulkheads
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/pressureBulkheads")) {
            m_pressureBulkheads = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_pressureBulkheads->ReadCPACS(tixiHandle, xpath + "/pressureBulkheads");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read pressureBulkheads at xpath " << xpath << ": " << e.what();
                m_pressureBulkheads = boost::none;
            }
        }

        // read element cargoDoors
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoDoors")) {
            m_cargoDoors = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
            try {
                m_cargoDoors->ReadCPACS(tixiHandle, xpath + "/cargoDoors");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cargoDoors at xpath " << xpath << ": " << e.what();
                m_cargoDoors = boost::none;
            }
        }

    }

    void CPACSFuselageStructure::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element skin
        if (m_skin) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/skin");
            m_skin->WriteCPACS(tixiHandle, xpath + "/skin");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/skin")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/skin");
            }
        }

        // write element stringers
        if (m_stringers) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/stringers");
            m_stringers->WriteCPACS(tixiHandle, xpath + "/stringers");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/stringers")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/stringers");
            }
        }

        // write element frames
        if (m_frames) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/frames");
            m_frames->WriteCPACS(tixiHandle, xpath + "/frames");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/frames")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/frames");
            }
        }

        // write element cargoCrossBeams
        if (m_cargoCrossBeams) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cargoCrossBeams");
            m_cargoCrossBeams->WriteCPACS(tixiHandle, xpath + "/cargoCrossBeams");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoCrossBeams")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cargoCrossBeams");
            }
        }

        // write element cargoCrossBeamStruts
        if (m_cargoCrossBeamStruts) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cargoCrossBeamStruts");
            m_cargoCrossBeamStruts->WriteCPACS(tixiHandle, xpath + "/cargoCrossBeamStruts");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoCrossBeamStruts")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cargoCrossBeamStruts");
            }
        }

        // write element longFloorBeams
        if (m_longFloorBeams) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/longFloorBeams");
            m_longFloorBeams->WriteCPACS(tixiHandle, xpath + "/longFloorBeams");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/longFloorBeams")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/longFloorBeams");
            }
        }

        // write element pressureBulkheads
        if (m_pressureBulkheads) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/pressureBulkheads");
            m_pressureBulkheads->WriteCPACS(tixiHandle, xpath + "/pressureBulkheads");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/pressureBulkheads")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/pressureBulkheads");
            }
        }

        // write element cargoDoors
        if (m_cargoDoors) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/cargoDoors");
            m_cargoDoors->WriteCPACS(tixiHandle, xpath + "/cargoDoors");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cargoDoors")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cargoDoors");
            }
        }

    }

    const boost::optional<CPACSSkin>& CPACSFuselageStructure::GetSkin() const
    {
        return m_skin;
    }

    boost::optional<CPACSSkin>& CPACSFuselageStructure::GetSkin()
    {
        return m_skin;
    }

    const boost::optional<CCPACSStringersAssembly>& CPACSFuselageStructure::GetStringers() const
    {
        return m_stringers;
    }

    boost::optional<CCPACSStringersAssembly>& CPACSFuselageStructure::GetStringers()
    {
        return m_stringers;
    }

    const boost::optional<CCPACSFramesAssembly>& CPACSFuselageStructure::GetFrames() const
    {
        return m_frames;
    }

    boost::optional<CCPACSFramesAssembly>& CPACSFuselageStructure::GetFrames()
    {
        return m_frames;
    }

    const boost::optional<CCPACSCargoCrossBeamsAssembly>& CPACSFuselageStructure::GetCargoCrossBeams() const
    {
        return m_cargoCrossBeams;
    }

    boost::optional<CCPACSCargoCrossBeamsAssembly>& CPACSFuselageStructure::GetCargoCrossBeams()
    {
        return m_cargoCrossBeams;
    }

    const boost::optional<CCPACSCargoCrossBeamStrutsAssembly>& CPACSFuselageStructure::GetCargoCrossBeamStruts() const
    {
        return m_cargoCrossBeamStruts;
    }

    boost::optional<CCPACSCargoCrossBeamStrutsAssembly>& CPACSFuselageStructure::GetCargoCrossBeamStruts()
    {
        return m_cargoCrossBeamStruts;
    }

    const boost::optional<CCPACSLongFloorBeamsAssembly>& CPACSFuselageStructure::GetLongFloorBeams() const
    {
        return m_longFloorBeams;
    }

    boost::optional<CCPACSLongFloorBeamsAssembly>& CPACSFuselageStructure::GetLongFloorBeams()
    {
        return m_longFloorBeams;
    }

    const boost::optional<CCPACSPressureBulkheadAssembly>& CPACSFuselageStructure::GetPressureBulkheads() const
    {
        return m_pressureBulkheads;
    }

    boost::optional<CCPACSPressureBulkheadAssembly>& CPACSFuselageStructure::GetPressureBulkheads()
    {
        return m_pressureBulkheads;
    }

    const boost::optional<CPACSCargoDoorsAssembly>& CPACSFuselageStructure::GetCargoDoors() const
    {
        return m_cargoDoors;
    }

    boost::optional<CPACSCargoDoorsAssembly>& CPACSFuselageStructure::GetCargoDoors()
    {
        return m_cargoDoors;
    }

    CPACSSkin& CPACSFuselageStructure::GetSkin(CreateIfNotExistsTag)
    {
        if (!m_skin)
            m_skin = boost::in_place(m_uidMgr);
        return *m_skin;
    }

    void CPACSFuselageStructure::RemoveSkin()
    {
        m_skin = boost::none;
    }

    CCPACSStringersAssembly& CPACSFuselageStructure::GetStringers(CreateIfNotExistsTag)
    {
        if (!m_stringers)
            m_stringers = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_stringers;
    }

    void CPACSFuselageStructure::RemoveStringers()
    {
        m_stringers = boost::none;
    }

    CCPACSFramesAssembly& CPACSFuselageStructure::GetFrames(CreateIfNotExistsTag)
    {
        if (!m_frames)
            m_frames = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_frames;
    }

    void CPACSFuselageStructure::RemoveFrames()
    {
        m_frames = boost::none;
    }

    CCPACSCargoCrossBeamsAssembly& CPACSFuselageStructure::GetCargoCrossBeams(CreateIfNotExistsTag)
    {
        if (!m_cargoCrossBeams)
            m_cargoCrossBeams = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_cargoCrossBeams;
    }

    void CPACSFuselageStructure::RemoveCargoCrossBeams()
    {
        m_cargoCrossBeams = boost::none;
    }

    CCPACSCargoCrossBeamStrutsAssembly& CPACSFuselageStructure::GetCargoCrossBeamStruts(CreateIfNotExistsTag)
    {
        if (!m_cargoCrossBeamStruts)
            m_cargoCrossBeamStruts = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_cargoCrossBeamStruts;
    }

    void CPACSFuselageStructure::RemoveCargoCrossBeamStruts()
    {
        m_cargoCrossBeamStruts = boost::none;
    }

    CCPACSLongFloorBeamsAssembly& CPACSFuselageStructure::GetLongFloorBeams(CreateIfNotExistsTag)
    {
        if (!m_longFloorBeams)
            m_longFloorBeams = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_longFloorBeams;
    }

    void CPACSFuselageStructure::RemoveLongFloorBeams()
    {
        m_longFloorBeams = boost::none;
    }

    CCPACSPressureBulkheadAssembly& CPACSFuselageStructure::GetPressureBulkheads(CreateIfNotExistsTag)
    {
        if (!m_pressureBulkheads)
            m_pressureBulkheads = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_pressureBulkheads;
    }

    void CPACSFuselageStructure::RemovePressureBulkheads()
    {
        m_pressureBulkheads = boost::none;
    }

    CPACSCargoDoorsAssembly& CPACSFuselageStructure::GetCargoDoors(CreateIfNotExistsTag)
    {
        if (!m_cargoDoors)
            m_cargoDoors = boost::in_place(reinterpret_cast<CCPACSFuselageStructure*>(this), m_uidMgr);
        return *m_cargoDoors;
    }

    void CPACSFuselageStructure::RemoveCargoDoors()
    {
        m_cargoDoors = boost::none;
    }

} // namespace generated
} // namespace tigl