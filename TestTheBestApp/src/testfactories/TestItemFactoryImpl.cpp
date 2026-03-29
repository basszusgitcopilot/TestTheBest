#include "TestItemFactoryImpl.h"

#include "MultipleChoiceTestItem.h"
#include "TestItemAddition.h"
#include "TestItemAlgebraLinearFactorization.h"
#include "TestItemAlgebraLinearFactorization3.h"
#include "TestItemAlgebraQuadraticEquation.h"
#include "TestItemDefiniteIntegral.h"
#include "TestItemDifferentialRules.h"
#include "TestItemFactory.h"
#include "TestItemIntegralRules.h"
#include "TestItemStereoSphereSurfaceVolume.h"
#include "TestItemStereoSphereVolume.h"
#include "TestItemStochasticBernoulliExperiment.h"
#include "TestItemStochasticCombination.h"

namespace com::prog::testthebest {
auto TestItemFactoryImpl::createTestItem(const Type type) -> std::shared_ptr<TestItem> {
    switch (type) {
    case Type::ADDITION: {
        return std::make_shared<TestItemAddition>();
    }
    case Type::MC_ADDITION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAddition>>();
    }
    case Type::MC_ALGEBRA_LINEAR_FACTORIZATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLinearFactorization>>();
    }
    case Type::MC_ALGEBRA_LINEAR_FACTORIZATION3: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraLinearFactorization3>>();
    }
    case Type::MC_ALGEBRA_QUADRATIC_EQUATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemAlgebraQuadraticEquation>>();
    }
    case Type::MC_DIFFERENTIAL_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemDifferentialRules>>();
    }
    case Type::MC_INTEGRAL_DEFINITE_INTGRAL: {
        return std::make_shared<MultipleChoiceTestItem<TestItemDefiniteIntegral>>();
    }
    case Type::MC_INTEGRAL_RULES: {
        return std::make_shared<MultipleChoiceTestItem<TestItemIntegralRules>>();
    }
    case Type::MC_STEREO_SPHERE_SURFACEAREA_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereSurfaceVolume>>();
    }
    case Type::MC_STEREO_SPHERE_VOLUME: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStereoSphereVolume>>();
    }
    case Type::MC_STOCHASTIC_BERNOULLI_EXPERIMENT: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticBernoulliExperiment>>();
    }
    case Type::MC_STOCHASTIC_COMBINATION: {
        return std::make_shared<MultipleChoiceTestItem<TestItemStochasticCombination>>();
    }
    default: {
        return nullptr;
    }
    }
}
} // namespace com::prog::testthebest