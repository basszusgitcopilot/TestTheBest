#pragma once

#include "TestItemFactory.h"
#include "TestItemListFactory.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemListFactoryImpl : public TestItemListFactory {
  public:
    TestItemListFactoryImpl();
    virtual ~TestItemListFactoryImpl() = default;
    auto createTestItemList(TestConfiguration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> override;

  private:
    std::shared_ptr<TestItemFactory> testItemFactory;
    static auto getNumOfItems(const TestConfiguration &config, TestItemType type) -> uint8_t;
};
} // namespace com::prog::testthebest