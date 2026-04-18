#pragma once

#include "KnowledgeTestItem.h"
#include <cstdint>

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestItem : public KnowledgeTestItem {
  public:
    [[nodiscard]] virtual auto equals(const TestItem &other) const -> bool = 0;
    [[nodiscard]] virtual auto getMaxNumOfQuestions() const -> uint16_t = 0;
};
} // namespace com::prog::testthebest