#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemVectorDotProduct : public TestItem {
  public:
    TestItemVectorDotProduct();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t a1 = 0;
    int32_t a2 = 0;
    int32_t a3 = 0;
    int32_t b1 = 0;
    int32_t b2 = 0;
    int32_t b3 = 0;
};
} // namespace com::prog::testthebest