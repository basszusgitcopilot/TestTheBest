#pragma once

#include "TestDialogFactory.h"
#include "TestItemListFactory.h"
#include <string>

namespace com::prog::testthebest {
class TestDialogFactoryImpl : public TestDialogFactory {
  public:
    TestDialogFactoryImpl();
    auto createTestDialog(std::string propertiesFile) -> std::shared_ptr<KnowledgeTestDialog> override;

  private:
    std::shared_ptr<TestItemListFactory> m_testItemListFactory;
};
} // namespace com::prog::testthebest