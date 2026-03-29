#pragma once

#include "TestItem.h"
#include <memory>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemFactory {
  public:
    enum class Type {
        ADDITION = 0,
        MC_ADDITION,
        MC_ALGEBRA_LINEAR_FACTORIZATION,
        MC_ALGEBRA_LINEAR_FACTORIZATION3,
        MC_ALGEBRA_QUADRATIC_EQUATION,
        MC_DIFFERENTIAL_RULES,
        MC_INTEGRAL_RULES,
        MC_INTEGRAL_DEFINITE_INTGRAL,
        MC_STEREO_SPHERE_SURFACEAREA_VOLUME,
        MC_STEREO_SPHERE_VOLUME,
        MC_STOCHASTIC_BERNOULLI_EXPERIMENT,
        MC_STOCHASTIC_COMBINATION,
        MAX_TYPE
    };

    virtual auto createTestItem(const Type type) -> std::shared_ptr<TestItem> = 0;
};
} // namespace com::prog::testthebest