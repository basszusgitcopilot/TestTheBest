#include "TestItemListFactory.h"
#include <iostream>
namespace com::prog::testthebest {
auto TestItemListFactory::fillConfigurationValue(TestConfiguration &configuration, std::string propertyName, uint8_t propertyValue) -> void {
    if (propertyName == "numOfAlgebraLinearFactorization") {
        configuration.numOfAlgebraLinearFactorization = propertyValue;
        return;
    }
    if (propertyName == "numOfAlgebraLinearFactorization3") {
        configuration.numOfAlgebraLinearFactorization3 = propertyValue;
        return;
    }
    if (propertyName == "numOfAlgebraLogarithmRules") {
        configuration.numOfAlgebraLogarithmRules = propertyValue;
        return;
    }
    if (propertyName == "numOfAlgebraQuadraticEquation") {
        configuration.numOfAlgebraQuadraticEquation = propertyValue;
        return;
    }
    if (propertyName == "numOfAnalyticGeometry2DLineLineIntersection") {
        configuration.numOfAnalyticGeometry2DLineLineIntersection = propertyValue;
        return;
    }
    if (propertyName == "numOfArithmeticAddition") {
        configuration.numOfArithmeticAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfArithmeticSubstraction") {
        configuration.numOfArithmeticSubstraction = propertyValue;
        return;
    }
    if (propertyName == "numOfDifferentialRules") {
        configuration.numOfDifferentialRules = propertyValue;
        return;
    }
    if (propertyName == "numOfFunctionsInverse") {
        configuration.numOfFunctionsInverse = propertyValue;
        return;
    }
    if (propertyName == "numOfIntegralDefinite") {
        configuration.numOfIntegralDefinite = propertyValue;
        return;
    }
    if (propertyName == "numOfIntegralRules") {
        configuration.numOfIntegralRules = propertyValue;
        return;
    }
    if (propertyName == "numOfStereoCalculations") {
        configuration.numOfStereoCalculations = propertyValue;
        return;
    }
    if (propertyName == "numOfStereoRules") {
        configuration.numOfStereoRules = propertyValue;
        return;
    }
    if (propertyName == "numOfStereoSphereSurfaceVolume") {
        configuration.numOfStereoSphereSurfaceVolume = propertyValue;
        return;
    }
    if (propertyName == "numOfStereoSphereVolume") {
        configuration.numOfStereoSphereVolume = propertyValue;
        return;
    }
    if (propertyName == "numOfStochasticBernoulliExperiment") {
        configuration.numOfStochasticBernoulliExperiment = propertyValue;
        return;
    }
    if (propertyName == "numOfStochasticCombination") {
        configuration.numOfStochasticCombination = propertyValue;
        return;
    }
    if (propertyName == "numOfTrigonometryRules") {
        configuration.numOfTrigonometryRules = propertyValue;
        return;
    }
    if (propertyName == "numOfVectorCrossProduct") {
        configuration.numOfVectorCrossProduct = propertyValue;
        return;
    }
    if (propertyName == "numOfVectorDotProduct") {
        configuration.numOfVectorDotProduct = propertyValue;
        return;
    }
    std::cerr << "ERROR: unknown property name: " << propertyName << std::endl;
}
} // namespace com::prog::testthebest