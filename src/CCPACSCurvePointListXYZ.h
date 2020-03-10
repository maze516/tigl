#ifndef CCPACSCURVEPOINTLISTXYZ_H
#define CCPACSCURVEPOINTLISTXYZ_H

#include "tigl_internal.h"
#include "generated/CPACSCurvePointListXYZ.h"
#include "Cache.h"
#include "CTiglInterpolatePointsWithKinks.h"


#include <Geom_BSplineCurve.hxx>

namespace  tigl
{

class CCPACSCurvePointListXYZ : public generated::CPACSCurvePointListXYZ
{
public:
    TIGL_EXPORT CCPACSCurvePointListXYZ();

    TIGL_EXPORT void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) override;

    /// Returns the parameters of the kinks. If no kinks are defined
    /// this list is empty.
    TIGL_EXPORT const std::vector<unsigned int>& GetKinksAsVector() const;

    /// Returns the map point-index vs parameter
    TIGL_EXPORT const ParamMap& GetParamsAsMap() const;

private:
    struct CachedObjects
    {
        std::vector<unsigned int> kinks;
        ParamMap paramMap;
    };
    void BuildCache(CachedObjects& cache) const;


    Cache<CachedObjects, CCPACSCurvePointListXYZ> m_cache;
};

} // namespace tigl

#endif // CCPACSCURVEPOINTLISTXYZ_H
