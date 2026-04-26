#pragma once

#include "TestItem.h"
#include <memory>
#include <string>
#include <utility>
#include <vector>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemIntegralRules : public TestItem {
  public:
    TestItemIntegralRules();
    [[nodiscard]] auto equals(const TestItem &other) const -> bool override;
    [[nodiscard]] auto getQuestion() const -> std::string override;
    [[nodiscard]] auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    int32_t ruleIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"f(x) = x^n", "F(x) = 1/(n+1)*x^(n+1) + c"},                //
        {"f(x) = g(x) + h(x)", "F(x) = G(x) + H(x)"},                //
        {"f(x) = c*g(x)", "F(x) = c*U(x)"},                          //
        {"f(x) = 1/x, x > 0", "F(x) = ln(x) + c"},                   //
        {"f(x) = 1/x², x ≠ 0", "F(x) = -1/x + c"},                   //
        {"f(x) = 1/√x, x > 0", "F(x) = 2*√x + c"},                   //
        {"f(x) = e^x", "F(x) = e^x + c"},                            //
        {"f(x) = a^x, x > 0, x ≠ 1", "F(x) = a^x * 1/ln(a) + c"},    //
        {"f(x) = 1/(1 + x²)", "F(x) = arctan(x) + c"},               //
        {"f(x) = 1/√(1-x²), |x| ≤ 1", "F(x) = arcsin(x) + c"},       //
        {"f(x) = 1/√(x²+1)", "F(x) = ln(x+√(x²+1)) + c"},            //
        {"f(x) = 1/√(x²-1), |x| > 1", "F(x) = |ln(x+√(x²-1))| + c"}, //
        {"f(x) = sin(x)", "F(x) = -cos(x) + c"},                     //
        {"f(x) = cos(x)", "F(x) = sin(x) + c"},                      //
        {"f(x) = 1/(sin²(x))", "F(x) = -cot(x) + c"},                //
        {"f(x) = 1/(cos²(x))", "F(x) = tan(x) + c"},                 //
    };
};
} // namespace com::prog::testthebest