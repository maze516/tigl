#ifndef CCPACSCURVEPOINTLISTXYZ_H
#define CCPACSCURVEPOINTLISTXYZ_H

#include "tigl_internal.h"
#include "generated/CPACSCurvePointListXYZ.h"
#include "Cache.h"

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

private:
    void BuildKinks(std::vector<unsigned int>& kinks) const;

    Cache<std::vector<unsigned int>, CCPACSCurvePointListXYZ> m_kinksVec;
};

} // namespace tigl

#endif // CCPACSCURVEPOINTLISTXYZ_H
