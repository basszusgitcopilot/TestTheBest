#include "TestItemListFactory.h"
#include <iostream>
namespace com::prog::testthebest {
auto TestItemListFactory::fillConfigurationValue(TestConfiguration &configuration, std::string propertyName, uint8_t propertyValue) -> void {
    if (propertyName == "numOfAddition") {
        configuration.numOfAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfAddition") {
        configuration.numOfAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAddition") {
        configuration.numOfMcAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAlgebraLinearFactorization") {
        configuration.numOfMcAlgebraLinearFactorization = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAlgebraLinearFactorization3") {
        configuration.numOfMcAlgebraLinearFactorization3 = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAlgebraQuadraticEquation") {
        configuration.numOfMcAlgebraQuadraticEquation = propertyValue;
        return;
    }
    if (propertyName == "numOfMcIntegralDefiniteIntegral") {
        configuration.numOfMcIntegralDefiniteIntegral = propertyValue;
        return;
    }
    if (propertyName == "numOfMcIntegralRules") {
        configuration.numOfMcIntegralRules = propertyValue;
        return;
    }
    if (propertyName == "numOfMcDifferentialRules") {
        configuration.numOfMcDifferentialRules = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStereoSphereSurfaceAreaVolume") {
        configuration.numOfMcStereoSphereSurfaceAreaVolume = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStereoSphereVolume") {
        configuration.numOfMcStereoSphereVolume = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStochasticBernoulliExperiment") {
        configuration.numOfMcStochasticBernoulliExperiment = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStochasticCombination") {
        configuration.numOfMcStochasticCombination = propertyValue;
        return;
    }
    if (propertyName == "numOfMcVectorDotProduct") {
        configuration.numOfMcVectorDotProduct = propertyValue;
        return;
    }
    if (propertyName == "numOfMcVectorCrossProduct") {
        configuration.numOfMcVectorCrossProduct = propertyValue;
        return;
    }
    std::cerr << "ERROR: unknown property name: " << propertyName << std::endl;
}
} // namespace com::prog::testthebest