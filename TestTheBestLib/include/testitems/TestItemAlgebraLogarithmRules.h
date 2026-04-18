#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAlgebraLogarithmRules : public TestItem {
  public:
    TestItemAlgebraLogarithmRules();
    auto equals(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    int32_t selectedIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"log_a(x)", "log_b(x) / log_b(a)"},   //
        {"log_a(x⋅y)", "log_a(x) + log_a(y)"}, //
        {"log_a(x/y)", "log_a(x) - log_a(y)"}, //
        {"log_a(x^y)", "y⋅log_a(x)"},          //
    };
};
} // namespace com::prog::testthebest