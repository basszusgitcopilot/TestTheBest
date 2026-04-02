#pragma once

#include "TestItem.h"
#include <cstdint>
#include <memory>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemListFactory {
  public:
    struct Configuration {
        uint8_t numOfAddition = 0;
        uint8_t numOfMcAddition = 0;
        uint8_t numOfMcAlgebraLinearFactorization = 0;
        uint8_t numOfMcAlgebraLinearFactorization3 = 0;
        uint8_t numOfMcAlgebraQuadraticEquation = 0;
        uint8_t numOfMcDifferentialRules = 0;
        uint8_t numOfMcIntegralRules = 0;
        uint8_t numOfMcIntegralDefiniteIntegral = 0;
        uint8_t numOfMcStochasticBernoulliExperiment = 0;
        uint8_t numOfMcStochasticCombination = 0;
        uint8_t numOfMcStereoSphereSurfaceAreaVolume = 0;
        uint8_t numOfMcStereoSphereVolume = 0;
        uint8_t numOfMcVectorCrossProduct = 0;
        uint8_t numOfMcVectorDotProduct = 0;
    };

    virtual auto createTestItemList(Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> = 0;

    static auto readConfigurationFromFile(std::string fileName) -> Configuration;

  private:
    static auto fillConfigurationValue(Configuration &configuration, std::string propertyName, uint8_t propertyValue) -> void;
};
} // namespace com::prog::testthebest