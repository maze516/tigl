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
#include <CCPACSWingRibRotation.h>
#include <string>
#include <tixi.h>
#include "CPACSCurvePoint.h"
#include "CPACSEtaXsiPoint.h"
#include "CPACSRibCrossingBehaviour.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CCPACSWingRibsDefinition;

namespace generated
{
    // This class is used in:
    // CPACSWingRibsDefinition

    // generated from /xsd:schema/xsd:complexType[970]
    /// @brief wingRibsPositioningType
    /// 
    /// Within the ribsPositioing type the position and the
    /// orientaion of the ribs of the rib set are difend.
    /// The positions of the ribs are defined by placing the
    /// ribs on a reference line on the wing (ribReference). The inner
    /// and the outer beginning of the rib set is defined using etaStart
    /// and etaEnd. The position of the forward and rear end of the ribs
    /// is defiend by ribStart and ribEnd. The orientation of the ribs
    /// is defined in ribRotaton. The number of ribs of the current rib
    /// set is either defined by ribNumber or by spacing.
    /// Three examples how ribs can be placed on the wing can
    /// be found in the picture below. For more detailed information,
    /// pleas refer to the descripion of each parameter.
    /// @see ribs
    /// 
    class CPACSWingRibsPositioning
    {
    public:
        TIGL_EXPORT CPACSWingRibsPositioning(CCPACSWingRibsDefinition* parent);

        TIGL_EXPORT virtual ~CPACSWingRibsPositioning();

        TIGL_EXPORT CCPACSWingRibsDefinition* GetParent();

        TIGL_EXPORT const CCPACSWingRibsDefinition* GetParent() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT bool ValidateChoices() const;

        TIGL_EXPORT virtual const boost::optional<CPACSEtaXsiPoint>& GetStartEtaXsiPoint_choice1() const;
        TIGL_EXPORT virtual boost::optional<CPACSEtaXsiPoint>& GetStartEtaXsiPoint_choice1();

        TIGL_EXPORT virtual const boost::optional<CPACSCurvePoint>& GetStartCurvePoint_choice2() const;
        TIGL_EXPORT virtual boost::optional<CPACSCurvePoint>& GetStartCurvePoint_choice2();

        TIGL_EXPORT virtual const boost::optional<std::string>& GetStartSparPositionUID_choice3() const;
        TIGL_EXPORT virtual void SetStartSparPositionUID_choice3(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSEtaXsiPoint>& GetEndEtaXsiPoint_choice1() const;
        TIGL_EXPORT virtual boost::optional<CPACSEtaXsiPoint>& GetEndEtaXsiPoint_choice1();

        TIGL_EXPORT virtual const boost::optional<CPACSCurvePoint>& GetEndCurvePoint_choice2() const;
        TIGL_EXPORT virtual boost::optional<CPACSCurvePoint>& GetEndCurvePoint_choice2();

        TIGL_EXPORT virtual const boost::optional<std::string>& GetEndSparPositionUID_choice3() const;
        TIGL_EXPORT virtual void SetEndSparPositionUID_choice3(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetRibStart() const;
        TIGL_EXPORT virtual void SetRibStart(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetRibEnd() const;
        TIGL_EXPORT virtual void SetRibEnd(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetSpacing_choice1() const;
        TIGL_EXPORT virtual void SetSpacing_choice1(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetNumberOfRibs_choice2() const;
        TIGL_EXPORT virtual void SetNumberOfRibs_choice2(const boost::optional<int>& value);

        TIGL_EXPORT virtual const std::string& GetRibReference() const;
        TIGL_EXPORT virtual void SetRibReference(const std::string& value);

        TIGL_EXPORT virtual const CPACSRibCrossingBehaviour& GetRibCrossingBehaviour() const;
        TIGL_EXPORT virtual void SetRibCrossingBehaviour(const CPACSRibCrossingBehaviour& value);

        TIGL_EXPORT virtual const CCPACSWingRibRotation& GetRibRotation() const;
        TIGL_EXPORT virtual CCPACSWingRibRotation& GetRibRotation();

        TIGL_EXPORT virtual CPACSEtaXsiPoint& GetStartEtaXsiPoint_choice1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStartEtaXsiPoint_choice1();

        TIGL_EXPORT virtual CPACSCurvePoint& GetStartCurvePoint_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveStartCurvePoint_choice2();

        TIGL_EXPORT virtual CPACSEtaXsiPoint& GetEndEtaXsiPoint_choice1(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEndEtaXsiPoint_choice1();

        TIGL_EXPORT virtual CPACSCurvePoint& GetEndCurvePoint_choice2(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveEndCurvePoint_choice2();

    protected:
        CCPACSWingRibsDefinition* m_parent;

        /// startEtaXsiPoint defines the start of the rib defined in eta-xsi coordinates of a reference plane
        boost::optional<CPACSEtaXsiPoint> m_startEtaXsiPoint_choice1;

        /// startCurvePoint defines the start of the rib defined by a point on a reference curve
        /// such as a spar, but not an explicit sparPosition
        boost::optional<CPACSCurvePoint>  m_startCurvePoint_choice2;

        /// Defines the location of the beginning of the rib using a specific sparPosition.
        boost::optional<std::string>      m_startSparPositionUID_choice3;

        /// endEtaXsiPoint defines the end of the rib defined in eta-xsi coordinates of a reference plane
        boost::optional<CPACSEtaXsiPoint> m_endEtaXsiPoint_choice1;

        /// endCurvePoint defines the end of the rib defined by a point on a reference curve
        /// such as a spar, but not an explicit sparPosition
        boost::optional<CPACSCurvePoint>  m_endCurvePoint_choice2;

        /// Defines the location of the end of the rib using a specific sparPosition.
        boost::optional<std::string>      m_endSparPositionUID_choice3;

        /// RibStart defines the forward beginning of the ribs. It can either be a
        /// sparUID or
        /// "trailingEdge" or "leadingEdge".
        std::string                       m_ribStart;

        /// RibEnd defines the backward ending of the ribs. It can either be a
        /// sparUID or
        /// "trailingEdge" or "leadingEdge".
        std::string                       m_ribEnd;

        /// The spacing of the ribs defines the distance between two ribs,
        /// measured on the
        /// ribReferenceLine. First rib is placed at etaStart.
        boost::optional<double>           m_spacing_choice1;

        /// RibNumber defines the number of ribs in this ribSet. First rib is at
        /// etaStart on the
        /// referenceLine, last rib is at etaEnd. The spacing is constant on the
        /// ribReferenceLine.
        boost::optional<int>              m_numberOfRibs_choice2;

        /// The ribReference is the reference line for the computation of the rib set spacing.
        /// It can either be a sparUID or "trailingEdge" or "leadingEdge"
        std::string                       m_ribReference;

        CPACSRibCrossingBehaviour         m_ribCrossingBehaviour;

        CCPACSWingRibRotation             m_ribRotation;

    private:
        CPACSWingRibsPositioning(const CPACSWingRibsPositioning&) = delete;
        CPACSWingRibsPositioning& operator=(const CPACSWingRibsPositioning&) = delete;

        CPACSWingRibsPositioning(CPACSWingRibsPositioning&&) = delete;
        CPACSWingRibsPositioning& operator=(CPACSWingRibsPositioning&&) = delete;
    };
} // namespace generated

// CPACSWingRibsPositioning is customized, use type CCPACSWingRibsPositioning directly
} // namespace tigl
