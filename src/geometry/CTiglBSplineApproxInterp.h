/*
* Copyright (C) 2018 German Aerospace Center (DLR/SC)
*
* Created: 2019-04-24 Martin Siggel <Martin.Siggel@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef CTIGLBSPLINEAPPROXINTERP_H
#define CTIGLBSPLINEAPPROXINTERP_H

#include <vector>
#include <Handle_Geom_BSplineCurve.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>

class TColgp_Array1OfPnt;
class TColStd_Array1OfInteger;
class gp_Pnt;

namespace tigl {

struct ProjectResult
{
    ProjectResult(double p, double e)
        : parameter(p), error(e)
    {
    }

    double parameter;
    double error;
};

struct CTiglApproxResult
{
    Handle(Geom_BSplineCurve) curve;
    double error;
};

class CTiglBSplineApproxInterp
{
public:
    CTiglBSplineApproxInterp(const TColgp_Array1OfPnt& points, int nControlPoints, int degree=3);

    /// The specified point will be interpolated instead of approximated
    void InterpolatePoint(size_t pointIndex, bool withKink=false);

    /// Returns the resulting curve and the fit error
    CTiglApproxResult FitCurve(const std::vector<double>& initialParms = std::vector<double>()) const;

    /// Fits the curve by optimizing the parameters.
    /// Important: Parameters of points that are interpolated are not optimized
    CTiglApproxResult FitCurveOptimal(const std::vector<double>& initialParms = std::vector<double>(), int maxIter=10) const;

private:
    ProjectResult projectOnCurve(const gp_Pnt& pnt, const Handle(Geom_Curve)& curve, double inital_Parm) const;
    std::vector<double> computeParameters(double alpha) const;
    void computeKnots(int ncp, const std::vector<double>& params, std::vector<double>& knots, std::vector<int>& mults) const;

    CTiglApproxResult solve(const std::vector<double>& params, const TColStd_Array1OfReal& knots, const TColStd_Array1OfInteger& mults) const;

    void optimizeParameters(const Handle(Geom_Curve)& curve, std::vector<double>& parms) const;
    
    /// curve coordinates to be fitted by the B-spline
    TColgp_Array1OfPnt m_pnts;

    std::vector<size_t> m_indexOfInterpolated;
    std::vector<size_t> m_indexOfApproximated;
    std::vector<size_t> m_indexOfKinks;

    /// degree of the B-spline
    int m_degree;

    /// Number of control points of the B-spline
    int m_ncp;
};

} // namespace tigl

#endif // CTIGLBSPLINEAPPROXINTERP_H
