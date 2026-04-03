#include "TestItemFactoryImpl.h"

#include "MultipleChoiceTestItem.h"
#include "TestItemAddition.h"
#include "TestItemAlgebraLinearFactorization.h"
#include "TestItemAlgebraLinearFactorization3.h"
#include "TestItemAlgebraQuadraticEquation.h"
#include "TestItemDifferentialRules.h"
#include "TestItemFactory.h"
#include "TestItemIntegralDefinite.h"
#include "TestItemIntegralRules.h"
#include "TestItemStereoSphereSurfaceVolume.h"
#include "TestItemStereoSphereVolume.h"
#include "TestItemStochasticBernoulliExperiment.h"
#include "TestItemStochasticCombination.h"
#include "TestItemVectorCrossProduct.h"
#include "TestItemVectorDotProduct.h"

namespace com::prog::testthebest {
auto TestItemFactoryImpl::createTestItem(const TestItemType TestItemType) -> std::shared_ptr<TestItem> {
    switch (TestItemType) {
    case TestItemType::ADDITION: {
        return std::make_shared<TestItemAddition>();
    }
    case TestItemType::MC_ADDITION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAddition>>();
    }
    case TestItemType::MC_ALGEBRA_LINEAR_FACTORIZATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLinearFactorization>>();
    }
    case TestItemType::MC_ALGEBRA_LINEAR_FACTORIZATION3: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLinearFactorization3>>();
    }
    case TestItemType::MC_ALGEBRA_QUADRATIC_EQUATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraQuadraticEquation>>();
    }
    case TestItemType::MC_DIFFERENTIAL_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemDifferentialRules>>();
    }
    case TestItemType::MC_INTEGRAL_DEFINITE_INTGRAL: {
        return std::make_shared<MultipleChoiceTestItem<TestItemIntegralDefinite>>();
    }
    case TestItemType::MC_INTEGRAL_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemIntegralRules>>();
    }
    case TestItemType::MC_STEREO_SPHERE_SURFACEAREA_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereSurfaceVolume>>();
    }
    case TestItemType::MC_STEREO_SPHERE_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereVolume>>();
    }
    case TestItemType::MC_STOCHASTIC_BERNOULLI_EXPERIMENT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticBernoulliExperiment>>();
    }
    case TestItemType::MC_STOCHASTIC_COMBINATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticCombination>>();
    }
    case TestItemType::MC_VECTOR_DOT_PRODUCT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemVectorDotProduct>>();
    }
    case TestItemType::MC_VECTOR_CROSS_PRODUCT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemVectorCrossProduct>>();
    }
    default: {
        return nullptr;
    }
    }
}
} // namespace com::prog::testthebest