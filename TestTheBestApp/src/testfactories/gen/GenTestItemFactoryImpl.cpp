#include "TestItemFactoryImpl.h"

#include "MultipleChoiceTestItem.h"
#include "TestItemAlgebraLinearFactorization.h"
#include "TestItemAlgebraLinearFactorization3.h"
#include "TestItemAlgebraLogarithmRules.h"
#include "TestItemAlgebraQuadraticEquation.h"
#include "TestItemArithmeticAddition.h"
#include "TestItemArithmeticSubstraction.h"
#include "TestItemDifferentialRules.h"
#include "TestItemFunctionsInverse.h"
#include "TestItemIntegralDefinite.h"
#include "TestItemIntegralRules.h"
#include "TestItemStereoSphereSurfaceVolume.h"
#include "TestItemStereoSphereVolume.h"
#include "TestItemStochasticBernoulliExperiment.h"
#include "TestItemStochasticCombination.h"
#include "TestItemTrigonometryRules.h"
#include "TestItemVectorCrossProduct.h"
#include "TestItemVectorDotProduct.h"

namespace com::prog::testthebest {
auto TestItemFactoryImpl::createTestItem(const TestItemType TestItemType) -> std::shared_ptr<TestItem> {
    switch (TestItemType) {
    case TestItemType::ALGEBRA_LINEAR_FACTORIZATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLinearFactorization>>();
    }
    case TestItemType::ALGEBRA_LINEAR_FACTORIZATION_3: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLinearFactorization3>>();
    }
    case TestItemType::ALGEBRA_LOGARITHM_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLogarithmRules>>();
    }
    case TestItemType::ALGEBRA_QUADRATIC_EQUATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraQuadraticEquation>>();
    }
    case TestItemType::ARITHMETIC_ADDITION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemArithmeticAddition>>();
    }
    case TestItemType::ARITHMETIC_SUBSTRACTION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemArithmeticSubstraction>>();
    }
    case TestItemType::DIFFERENTIAL_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemDifferentialRules>>();
    }
    case TestItemType::FUNCTIONS_INVERSE: {
        return std::make_shared<MultipleChoiceTestItem<TestItemFunctionsInverse>>();
    }
    case TestItemType::INTEGRAL_DEFINITE: {
        return std::make_shared<MultipleChoiceTestItem<TestItemIntegralDefinite>>();
    }
    case TestItemType::INTEGRAL_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemIntegralRules>>();
    }
    case TestItemType::STEREO_SPHERE_SURFACE_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereSurfaceVolume>>();
    }
    case TestItemType::STEREO_SPHERE_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereVolume>>();
    }
    case TestItemType::STOCHASTIC_BERNOULLI_EXPERIMENT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticBernoulliExperiment>>();
    }
    case TestItemType::STOCHASTIC_COMBINATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticCombination>>();
    }
    case TestItemType::TRIGONOMETRY_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemTrigonometryRules>>();
    }
    case TestItemType::VECTOR_CROSS_PRODUCT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemVectorCrossProduct>>();
    }
    case TestItemType::VECTOR_DOT_PRODUCT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemVectorDotProduct>>();
    }
    default: {
        return nullptr;
    }
    }
}
} // namespace com::prog::testthebest