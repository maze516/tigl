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
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CCPACSWingRibsPositioning;

namespace generated
{
    // This class is used in:
    // CPACSWingRibsPositioning

    // generated from /xsd:schema/xsd:complexType[772]
    /// @brief Definition of the rotation of the ribs.
    /// 
    /// The rotation around z describes the rotation around the
    /// wings midplane normal axis. The defaults to 90°. The reference
    /// for the 'zero-angle' of the z-rotation is defined in
    /// ribRotationReference.
    /// 
    class CPACSRibRotation
    {
    public:
        TIGL_EXPORT CPACSRibRotation(CCPACSWingRibsPositioning* parent);

        TIGL_EXPORT virtual ~CPACSRibRotation();

        TIGL_EXPORT CCPACSWingRibsPositioning* GetParent();

        TIGL_EXPORT const CCPACSWingRibsPositioning* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<std::string>& GetRibRotationReference() const;
        TIGL_EXPORT virtual void SetRibRotationReference(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const double& GetZ() const;
        TIGL_EXPORT virtual void SetZ(const double& value);

    protected:
        CCPACSWingRibsPositioning* m_parent;

        /// RotationReference defines the reference for
        /// the z-rotation it is either sparUID, „LeadingEdge“, 
        /// „TrailingEdge“, "globalX", "globalY" or "globalZ".
        /// If it is not defined the rotation reference is
        /// the eta-axis (=leading edge, that is projected on the wings
        /// y-z-plane). A z-rotation angle of 90 degrees means, that the rib
        /// is perpendicular on the ribRotationReference (e.g. spar, leading
        /// edge...). The rib itself is always straight, and the rotation
        /// is defined with respect of the intersection point of the rib
        /// with the ribRotationReference.
        boost::optional<std::string> m_ribRotationReference;

        /// The rotation around z describes the rotation
        /// around the wings midplane normal axis. The defaults to 90°. The
        /// reference for the 'zero-angle' of the z-rotation is defined in
        /// ribRotationReference.
        double                       m_z;

    private:
        CPACSRibRotation(const CPACSRibRotation&) = delete;
        CPACSRibRotation& operator=(const CPACSRibRotation&) = delete;

        CPACSRibRotation(CPACSRibRotation&&) = delete;
        CPACSRibRotation& operator=(CPACSRibRotation&&) = delete;
    };
} // namespace generated

// CPACSRibRotation is customized, use type CCPACSWingRibRotation directly
} // namespace tigl
