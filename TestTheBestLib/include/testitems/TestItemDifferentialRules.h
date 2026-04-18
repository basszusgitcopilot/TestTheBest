#pragma once

#include "TestItem.h"
#include <string>
#include <utility>
#include <vector>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemDifferentialRules : public TestItem {
  public:
    TestItemDifferentialRules();
    [[nodiscard]] auto equals(const TestItem &other) const -> bool override;
    [[nodiscard]] auto getQuestion() const -> std::string override;
    [[nodiscard]] auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    int32_t ruleIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"f(x) = x", "f'(x) = 1"},                                           //
        {"f(x) = ax", "f'(x) = a"},                                          //
        {"f(x) = x+a", "f'(x) = 1"},                                         //
        {"f(x) = x^n", "f'(x) = n*x^(n-1))"},                                //
        {"f(x) = e^x", "f'(x) = e^x"},                                       //
        {"f(x) = a^x", "f'(x) = a^x*ln(a)"},                                 //
        {"f(x) = ln(x)", "f'(x) = 1/x"},                                     //
        {"f(x) = sin(x)", "f'(x) = cos(x)"},                                 //
        {"f(x) = cos(x)", "f'(x) = -sin(x)"},                                //
        {"f(x) = tan(x)", "f'(x) = 1/cos²(x)"},                              //
        {"f(x) = g(x) + h(x)", "f'(x) = g'(x) + h'(x)"},                     //
        {"f(x) = g(x)*h(x)", "f'(x) = g'(x)*h(x) + g(x)*h'(x)"},             //
        {"f(x) = g(x)/h(x)", "f'(x) = (g'(x)*h(x) - g(x)*h'(x)) / (h(x))²"}, //
        {"f(x) = g(h(x))", "f'(x) = g'(h(x))*h'(x)"},                        //
    };
};
} // namespace com::prog::testthebest