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
#include <cctype>

#include "CTiglError.h"
#include "to_string.h"

namespace tigl
{
namespace generated
{
    // This enum is used in:
    // CPACSProfileGeometry2D

    // generated from /xsd:schema/xsd:complexType[749]/xsd:complexContent/xsd:extension/xsd:attribute[1]/xsd:simpleType
    enum CPACSProfileGeometry2DType_symmetry
    {
        x_axis,
        y_axis
    };

    inline std::string CPACSProfileGeometry2DType_symmetryToString(const CPACSProfileGeometry2DType_symmetry& value)
    {
        switch(value) {
        case x_axis: return "x-axis";
        case y_axis: return "y-axis";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSProfileGeometry2DType_symmetry");
        }
    }
    inline CPACSProfileGeometry2DType_symmetry stringToCPACSProfileGeometry2DType_symmetry(const std::string& value)
    {
        auto toLower = [](std::string str) { for (char& c : str) { c = std::tolower(c); } return str; };
        if (toLower(value) == "x-axis") { return x_axis; }
        if (toLower(value) == "y-axis") { return y_axis; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSProfileGeometry2DType_symmetry");
    }
} // namespace generated

// Aliases in tigl namespace
using ECPACSProfileGeometry2DType_symmetry = generated::CPACSProfileGeometry2DType_symmetry;
} // namespace tigl
