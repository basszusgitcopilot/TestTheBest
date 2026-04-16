#pragma once

#include "GenTestItemType.h"
#include "TestItem.h"
#include <memory>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {
class TestItemFactory {
  public:
    virtual auto createTestItem(const TestItemType type) -> std::shared_ptr<TestItem> = 0;
};
} // namespace com::prog::testthebest