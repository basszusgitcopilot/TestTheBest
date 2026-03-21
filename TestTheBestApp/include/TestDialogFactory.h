#pragma once

#include "KnowledgeTestDialog.h"

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestDialogFactory {
  public:
    virtual ~TestDialogFactory() = default;

    virtual auto createTestDialog() -> std::shared_ptr<KnowledgeTestDialog> = 0;
};
} // namespace com::prog::testthebest