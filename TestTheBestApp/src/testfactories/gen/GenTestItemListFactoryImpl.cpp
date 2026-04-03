#include "TestItemListFactoryImpl.h"
namespace com::prog::testthebest {
auto TestItemListFactoryImpl::getNumOfItems(const TestConfiguration &config, TestItemType type) -> uint8_t {
    switch (type) {
    case TestItemType::ADDITION: {
        return config.numOfAddition;
    }
    case TestItemType::MC_ADDITION: {
        return config.numOfMcAddition;
    }
    case TestItemType::MC_ALGEBRA_QUADRATIC_EQUATION: {
        return config.numOfMcAlgebraQuadraticEquation;
    }
    case TestItemType::MC_ALGEBRA_LINEAR_FACTORIZATION: {
        return config.numOfMcAlgebraLinearFactorization;
    }
    case TestItemType::MC_ALGEBRA_LINEAR_FACTORIZATION3: {
        return config.numOfMcAlgebraLinearFactorization3;
    }
    case TestItemType::MC_INTEGRAL_DEFINITE_INTGRAL: {
        return config.numOfMcIntegralDefiniteIntegral;
    }
    case TestItemType::MC_INTEGRAL_RULES: {
        return config.numOfMcIntegralRules;
    }
    case TestItemType::MC_DIFFERENTIAL_RULES: {
        return config.numOfMcDifferentialRules;
    }
    case TestItemType::MC_STEREO_SPHERE_SURFACEAREA_VOLUME: {
        return config.numOfMcStereoSphereSurfaceAreaVolume;
    }
    case TestItemType::MC_STEREO_SPHERE_VOLUME: {
        return config.numOfMcStereoSphereVolume;
    }
    case TestItemType::MC_STOCHASTIC_BERNOULLI_EXPERIMENT: {
        return config.numOfMcStochasticBernoulliExperiment;
    }
    case TestItemType::MC_STOCHASTIC_COMBINATION: {
        return config.numOfMcStochasticCombination;
    }
    case TestItemType::MC_VECTOR_DOT_PRODUCT: {
        return config.numOfMcVectorDotProduct;
    }
    case TestItemType::MC_VECTOR_CROSS_PRODUCT: {
        return config.numOfMcVectorCrossProduct;
    }
    default: {
        return 0;
    }
    }
}
} // namespace com::prog::testthebest