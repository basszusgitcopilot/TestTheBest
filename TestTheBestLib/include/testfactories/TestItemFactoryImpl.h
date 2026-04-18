#pragma once

#include "TestItemFactory.h"

namespace com::prog::testthebest {
class TestItemFactoryImpl : public TestItemFactory {
  public:
    virtual ~TestItemFactoryImpl() = default;
    auto createTestItem(TestItemType type) -> std::shared_ptr<TestItem> override;
};
} // namespace com::prog::testthebest