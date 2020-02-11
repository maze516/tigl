#include "CCPACSCurvePointListXYZ.h"

namespace tigl
{

CCPACSCurvePointListXYZ::CCPACSCurvePointListXYZ()
    : m_kinksVec(*this, &CCPACSCurvePointListXYZ::BuildKinks)
{

}

void CCPACSCurvePointListXYZ::ReadCPACS(const TixiDocumentHandle &tixiHandle, const std::string &xpath)
{
    generated::CPACSCurvePointListXYZ::ReadCPACS(tixiHandle, xpath);

    m_kinksVec.clear();
}

const std::vector<unsigned int>& CCPACSCurvePointListXYZ::GetKinksAsVector() const
{
    return m_kinksVec.value();
}

void CCPACSCurvePointListXYZ::BuildKinks(std::vector<unsigned int> &kinks) const
{
    if (GetKinks()) {
        auto kinkAsDouble = GetKinks()->AsVector();

        kinks.clear();
        std::transform(std::begin(kinkAsDouble), std::end(kinkAsDouble), std::back_inserter(kinks), [](double v) {
            return static_cast<unsigned int>(v);
        });
    }
    else {
        kinks.empty();
    }
}


} // namespace tigl
