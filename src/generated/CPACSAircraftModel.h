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

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSEnginePylons.h>
#include <CCPACSExternalObjects.h>
#include <CCPACSFuselages.h>
#include <CCPACSWings.h>
#include <string>
#include <tixi.h>
#include "CPACSEnginePositions.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSAircraft

    // generated from /xsd:schema/xsd:complexType[55]
    class CPACSAircraftModel
    {
    public:
        TIGL_EXPORT CPACSAircraftModel(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSAircraftModel();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CCPACSFuselages>& GetFuselages() const;
        TIGL_EXPORT virtual boost::optional<CCPACSFuselages>& GetFuselages();

        TIGL_EXPORT virtual const boost::optional<CCPACSWings>& GetWings() const;
        TIGL_EXPORT virtual boost::optional<CCPACSWings>& GetWings();

        TIGL_EXPORT virtual const boost::optional<CPACSEnginePositions>& GetEngines() const;
        TIGL_EXPORT virtual boost::optional<CPACSEnginePositions>& GetEngines();

        TIGL_EXPORT virtual const boost::optional<CCPACSEnginePylons>& GetEnginePylons() const;
        TIGL_EXPORT virtual boost::optional<CCPACSEnginePylons>& GetEnginePylons();

        TIGL_EXPORT virtual const boost::optional<CCPACSExternalObjects>& GetGenericGeometryComponents() const;
        TIGL_EXPORT virtual boost::optional<CCPACSExternalObjects>& GetGenericGeometryComponents();

        TIGL_EXPORT virtual CCPACSFuselages& GetFuselages(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveFuselages();

        TIGL_EXPORT virtual CCPACSWings& GetWings(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveWings();

        TIGL_EXPORT virtual CPACSEnginePositions& GetEngines(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEngines();

        TIGL_EXPORT virtual CCPACSEnginePylons& GetEnginePylons(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEnginePylons();

        TIGL_EXPORT virtual CCPACSExternalObjects& GetGenericGeometryComponents(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveGenericGeometryComponents();

    protected:
        CTiglUIDManager* m_uidMgr;

        std::string                            m_uID;
        std::string                            m_name;
        boost::optional<std::string>           m_description;
        boost::optional<CCPACSFuselages>       m_fuselages;
        boost::optional<CCPACSWings>           m_wings;
        boost::optional<CPACSEnginePositions>  m_engines;
        boost::optional<CCPACSEnginePylons>    m_enginePylons;
        boost::optional<CCPACSExternalObjects> m_genericGeometryComponents;

    private:
#ifdef HAVE_CPP11
        CPACSAircraftModel(const CPACSAircraftModel&) = delete;
        CPACSAircraftModel& operator=(const CPACSAircraftModel&) = delete;

        CPACSAircraftModel(CPACSAircraftModel&&) = delete;
        CPACSAircraftModel& operator=(CPACSAircraftModel&&) = delete;
#else
        CPACSAircraftModel(const CPACSAircraftModel&);
        CPACSAircraftModel& operator=(const CPACSAircraftModel&);
#endif
    };
} // namespace generated

// CPACSAircraftModel is customized, use type CCPACSAircraftModel directly
} // namespace tigl
