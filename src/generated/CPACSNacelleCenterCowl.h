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

#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSEngineNacelle;

    // This class is used in:
    // CPACSEngineNacelle

    // generated from /xsd:schema/xsd:complexType[1003]
    /// @brief nacelleCenterCowlType
    /// 
    /// Describes the curve for defining rotational center of the engine.
    /// 
    class CPACSNacelleCenterCowl
    {
    public:
        TIGL_EXPORT CPACSNacelleCenterCowl(CPACSEngineNacelle* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSNacelleCenterCowl();

        TIGL_EXPORT CPACSEngineNacelle* GetParent();

        TIGL_EXPORT const CPACSEngineNacelle* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetXOffset() const;
        TIGL_EXPORT virtual void SetXOffset(const double& value);

        TIGL_EXPORT virtual const std::string& GetCurveUID() const;
        TIGL_EXPORT virtual void SetCurveUID(const std::string& value);

    protected:
        CPACSEngineNacelle* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string m_uID;
        double      m_xOffset;
        std::string m_curveUID;

    private:
        CPACSNacelleCenterCowl(const CPACSNacelleCenterCowl&) = delete;
        CPACSNacelleCenterCowl& operator=(const CPACSNacelleCenterCowl&) = delete;

        CPACSNacelleCenterCowl(CPACSNacelleCenterCowl&&) = delete;
        CPACSNacelleCenterCowl& operator=(CPACSNacelleCenterCowl&&) = delete;
    };
} // namespace generated

// CPACSNacelleCenterCowl is customized, use type CCPACSNacelleCenterCowl directly

// Aliases in tigl namespace
using CCPACSEngineNacelle = generated::CPACSEngineNacelle;
} // namespace tigl
