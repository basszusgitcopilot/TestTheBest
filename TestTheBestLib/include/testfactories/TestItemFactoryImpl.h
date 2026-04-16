#pragma once

#include "TestItemFactory.h"

namespace com::prog::testthebest {
class TestItemFactoryImpl : public TestItemFactory {
    auto createTestItem(const TestItemType type) -> std::shared_ptr<TestItem> override;
};
} // namespace com::prog::testthebest