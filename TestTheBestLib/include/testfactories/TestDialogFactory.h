#pragma once

#include "KnowledgeTestDialog.h"
#include <string>

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestDialogFactory {
  public:
    virtual ~TestDialogFactory() = default;

    virtual auto createTestDialog(std::string propertiesFile) -> std::shared_ptr<KnowledgeTestDialog> = 0;
};
} // namespace com::prog::testthebest