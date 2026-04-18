#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAlgebraLinearFactorization3 : public TestItem {
  public:
    TestItemAlgebraLinearFactorization3();
    auto equals(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    double a;
    double b;
    double c;
};
} // namespace com::prog::testthebest