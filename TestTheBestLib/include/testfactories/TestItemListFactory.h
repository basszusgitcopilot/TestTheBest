#pragma once

#include "GenTestConfiguration.h"
#include "TestItem.h"
#include <cstdint>
#include <memory>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemListFactory {
  public:
    virtual auto createTestItemList(TestConfiguration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> = 0;

    static auto readConfigurationFromFile(std::string fileName) -> TestConfiguration;

  private:
    static auto fillConfigurationValue(TestConfiguration &configuration, std::string propertyName, uint8_t propertyValue) -> void;
};
} // namespace com::prog::testthebest