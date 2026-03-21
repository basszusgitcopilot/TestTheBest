#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemQuadraticEquation : public TestItem {
  public:
    TestItemQuadraticEquation();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    double a;
    double b;
    double c;
};
} // namespace com::prog::testthebest