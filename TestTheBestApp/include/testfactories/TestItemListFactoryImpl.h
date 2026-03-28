#pragma once

#include "TestItemFactory.h"
#include "TestItemListFactory.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemListFactoryImpl : public TestItemListFactory {
  public:
    TestItemListFactoryImpl();
    auto createTestItemList(TestItemListFactory::Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> override;

  private:
    std::shared_ptr<TestItemFactory> testItemFactory;
    auto getNumOfItems(const TestItemListFactory::Configuration &config, TestItemFactory::Type type) -> uint8_t;
};
} // namespace com::prog::testthebest