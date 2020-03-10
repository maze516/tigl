#include "CCPACSCurvePointListXYZ.h"

#include "tiglcommonfunctions.h"

#include <iterator>

namespace tigl
{

CCPACSCurvePointListXYZ::CCPACSCurvePointListXYZ()
    : m_cache(*this, &CCPACSCurvePointListXYZ::BuildCache)
{

}

void CCPACSCurvePointListXYZ::ReadCPACS(const TixiDocumentHandle &tixiHandle, const std::string &xpath)
{
    generated::CPACSCurvePointListXYZ::ReadCPACS(tixiHandle, xpath);

    m_cache.clear();
}

const std::vector<unsigned int>& CCPACSCurvePointListXYZ::GetKinksAsVector() const
{
    return m_cache->kinks;
}

const ParamMap& CCPACSCurvePointListXYZ::GetParamsAsMap() const
{
    return m_cache->paramMap;
}

void CCPACSCurvePointListXYZ::BuildCache(CachedObjects& cache) const
{
    cache.kinks.clear();
    if (GetKinks()) {
        auto kinkAsDouble = GetKinks()->AsVector();

        auto& kinks = cache.kinks;
        kinks.clear();
        std::transform(std::begin(kinkAsDouble), std::end(kinkAsDouble), std::back_inserter(kinks), [](double v) {
            return static_cast<unsigned int>(v);
        });
        std::sort(std::begin(kinks), std::end(kinks));
    }

    cache.paramMap.clear();
    if (GetParameterMap()) {
        const auto& cpacsMap = GetParameterMap().value();
        auto params = cpacsMap.GetParamAsVector();
        auto idx = cpacsMap.GetPointIndexAsVector();

        if (idx.size() != params.size()) {
            throw CTiglError("Number of parameters does not match number of indices");
        }

        for (size_t i = 0; i < params.size(); ++i) {
            auto key = idx[i];
            auto value = params[i];
            cache.paramMap[key] = value;
        }
    }

}

} // namespace tigl
