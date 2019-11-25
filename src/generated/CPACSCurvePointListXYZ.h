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
#include <CCPACSCurveParamPointMap.h>
#include <CCPACSPointListXYZVector.h>
#include <CCPACSStringVector.h>
#include <string>
#include <tixi.h>
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSProfileGeometry

    // generated from /xsd:schema/xsd:complexType[723]
    class CPACSCurvePointListXYZ : public CCPACSPointListXYZVector
    {
    public:
        TIGL_EXPORT CPACSCurvePointListXYZ();
        TIGL_EXPORT virtual ~CPACSCurvePointListXYZ();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const boost::optional<CCPACSStringVector>& GetKinks() const;
        TIGL_EXPORT virtual boost::optional<CCPACSStringVector>& GetKinks();

        TIGL_EXPORT virtual const boost::optional<CCPACSCurveParamPointMap>& GetParameterMap() const;
        TIGL_EXPORT virtual boost::optional<CCPACSCurveParamPointMap>& GetParameterMap();

        TIGL_EXPORT virtual CCPACSStringVector& GetKinks(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveKinks();

        TIGL_EXPORT virtual CCPACSCurveParamPointMap& GetParameterMap(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveParameterMap();

    protected:
        /// Curve parameters at which the curve has a kink. To define a kink at a specific point,
        /// the parameterMap has to be used that associates a point with a parameter.
        boost::optional<CCPACSStringVector>       m_kinks;

        /// Map between point index and curve parameter.
        boost::optional<CCPACSCurveParamPointMap> m_parameterMap;

    private:
        CPACSCurvePointListXYZ(const CPACSCurvePointListXYZ&) = delete;
        CPACSCurvePointListXYZ& operator=(const CPACSCurvePointListXYZ&) = delete;

        CPACSCurvePointListXYZ(CPACSCurvePointListXYZ&&) = delete;
        CPACSCurvePointListXYZ& operator=(CPACSCurvePointListXYZ&&) = delete;
    };
} // namespace generated

// CPACSCurvePointListXYZ is customized, use type CCPACSCurvePointListXYZ directly
} // namespace tigl
