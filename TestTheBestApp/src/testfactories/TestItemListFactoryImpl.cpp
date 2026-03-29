#include "TestItemListFactoryImpl.h"
#include "TestItemFactoryImpl.h"
#include <iostream>

namespace com::prog::testthebest {
TestItemListFactoryImpl::TestItemListFactoryImpl() : testItemFactory{std::make_shared<TestItemFactoryImpl>()} {}

auto TestItemListFactoryImpl::getNumOfItems(const TestItemListFactory::Configuration &config, TestItemFactory::Type type) -> uint8_t {
    switch (type) {
    case TestItemFactory::Type::ADDITION: {
        return config.numOfAddition;
    }
    case TestItemFactory::Type::MC_ADDITION: {
        return config.numOfMcAddition;
    }
    case TestItemFactory::Type::MC_ALGEBRA_QUADRATIC_EQUATION: {
        return config.numOfMcAlgebraQuadraticEquation;
    }
    case TestItemFactory::Type::MC_ALGEBRA_LINEAR_FACTORIZATION: {
        return config.numOfMcAlgebraLinearFactorization;
    }
    case TestItemFactory::Type::MC_ALGEBRA_LINEAR_FACTORIZATION3: {
        return config.numOfMcAlgebraLinearFactorization3;
    }
    case TestItemFactory::Type::MC_INTEGRAL_RULES: {
        return config.numOfMcIntegralRules;
    }
    case TestItemFactory::Type::MC_DIFFERENTIAL_RULES: {
        return config.numOfMcDifferentialRules;
    }
    case TestItemFactory::Type::MC_STEREO_SPHERE_SURFACEAREA_VOLUME: {
        return config.numOfMcStereoSphereSurfaceAreaVolume;
    }
    case TestItemFactory::Type::MC_STEREO_SPHERE_VOLUME: {
        return config.numOfMcStereoSphereVolume;
    }
    case TestItemFactory::Type::MC_STOCHASTIC_BERNOULLI_EXPERIMENT: {
        return config.numOfMcStochasticBernoulliExperiment;
    }
    case TestItemFactory::Type::MC_STOCHASTIC_COMBINATION: {
        return config.numOfMcStochasticCombination;
    }
    default: {
        return 0;
    }
    }
}

auto TestItemListFactoryImpl::createTestItemList(TestItemListFactory::Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> {
    std::vector<std::shared_ptr<KnowledgeTestItem>> listAll;
    for (uint8_t type = 0; type < static_cast<uint8_t>(TestItemFactory::Type::MAX_TYPE); ++type) {
        auto num = getNumOfItems(config, static_cast<TestItemFactory::Type>(type));
        std::vector<std::shared_ptr<TestItem>> list;
        for (int8_t i = 0; i < num; ++i) {
            bool found;
            do {
                auto item = testItemFactory->createTestItem(static_cast<TestItemFactory::Type>(type));
                found = false;
                for (const auto &it : list) {
                    if (*it == *item) {
                        found;
                    }
                }
                if (!found) {
                    list.push_back(item);
                    break;
                }
            } while (true);
        }
        listAll.insert(std::end(listAll), std::begin(list), std::end(list));
    }
    return listAll;
}
} // namespace com::prog::testthebest