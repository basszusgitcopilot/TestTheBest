#pragma once

#include "KnowledgeTestItem.h"
#include <cstdint>
#include <string>

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestItem : public KnowledgeTestItem {
  public:
    virtual auto operator==(const TestItem &other) const -> bool = 0;
    virtual auto getMaxNumOfQuestions() const -> uint16_t = 0;
};
} // namespace com::prog::testthebest