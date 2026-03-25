#pragma once

#include "TestItem.h"
#include <cstdint>
#include <memory>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemListFactory {
  public:
    struct Configuration {
        uint8_t numOfAddition;
        uint8_t numOfMcAddition;
        uint8_t numOfMcAlgebraLinearFactorization;
        uint8_t numOfMcAlgebraLinearFactorization3;
        uint8_t numOfMcAlgebraQuadraticEquation;
        uint8_t numOfMcStochasticCombination;
        uint8_t numOfMcStereoSphereSurfaceAreaVolume;
        uint8_t numOfMcStereoSphereVolume;
    };

    virtual auto createTestItemList(Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> = 0;
};
} // namespace com::prog::testthebest