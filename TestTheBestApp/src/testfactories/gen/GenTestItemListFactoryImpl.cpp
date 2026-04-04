#include "TestItemListFactoryImpl.h"
namespace com::prog::testthebest {
auto TestItemListFactoryImpl::getNumOfItems(const TestConfiguration &config, TestItemType type) -> uint8_t {
    switch (type) {
    case TestItemType::ALGEBRA_LINEAR_FACTORIZATION: {
        return config.numOfAlgebraLinearFactorization;
    }
    case TestItemType::ALGEBRA_LINEAR_FACTORIZATION_3: {
        return config.numOfAlgebraLinearFactorization3;
    }
    case TestItemType::ALGEBRA_LOGARITHM_RULES: {
        return config.numOfAlgebraLogarithmRules;
    }
    case TestItemType::ALGEBRA_QUADRATIC_EQUATION: {
        return config.numOfAlgebraQuadraticEquation;
    }
    case TestItemType::ARITHMETIC_ADDITION: {
        return config.numOfArithmeticAddition;
    }
    case TestItemType::ARITHMETIC_SUBSTRACTION: {
        return config.numOfArithmeticSubstraction;
    }
    case TestItemType::DIFFERENTIAL_RULES: {
        return config.numOfDifferentialRules;
    }
    case TestItemType::FUNCTIONS_INVERSE: {
        return config.numOfFunctionsInverse;
    }
    case TestItemType::INTEGRAL_DEFINITE: {
        return config.numOfIntegralDefinite;
    }
    case TestItemType::INTEGRAL_RULES: {
        return config.numOfIntegralRules;
    }
    case TestItemType::STEREO_CALCULATIONS: {
        return config.numOfStereoCalculations;
    }
    case TestItemType::STEREO_RULES: {
        return config.numOfStereoRules;
    }
    case TestItemType::STEREO_SPHERE_SURFACE_VOLUME: {
        return config.numOfStereoSphereSurfaceVolume;
    }
    case TestItemType::STEREO_SPHERE_VOLUME: {
        return config.numOfStereoSphereVolume;
    }
    case TestItemType::STOCHASTIC_BERNOULLI_EXPERIMENT: {
        return config.numOfStochasticBernoulliExperiment;
    }
    case TestItemType::STOCHASTIC_COMBINATION: {
        return config.numOfStochasticCombination;
    }
    case TestItemType::TRIGONOMETRY_RULES: {
        return config.numOfTrigonometryRules;
    }
    case TestItemType::VECTOR_CROSS_PRODUCT: {
        return config.numOfVectorCrossProduct;
    }
    case TestItemType::VECTOR_DOT_PRODUCT: {
        return config.numOfVectorDotProduct;
    }
    default: {
        return 0;
    }
    }
}
} // namespace com::prog::testthebest