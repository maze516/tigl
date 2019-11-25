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

const std::vector<double>& CCPACSCurvePointListXYZ::GetKinksAsVector() const
{
    return m_kinksVec.value();
}

void CCPACSCurvePointListXYZ::BuildKinks(std::vector<double> &kinks) const
{
    if (GetKinks()) {
        kinks = GetKinks()->AsVector();
    }
    else {
        kinks.empty();
    }
}


} // namespace tigl
