#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemFunctionsInverse : public TestItem {
  public:
    TestItemFunctionsInverse();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    int32_t selectedIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"f(x) = sin(x)", "f(x) = sin⁻¹(x)"},  //
        {"f(x) = cos(x)", "f(x) = cos⁻¹(x)"},  //
        {"f(x) = tan(x)", "f(x) = tan⁻¹(x)"},  //
        {"f(x) = 2x", "f(x) = 0.5x"},          //
        {"f(x) = mx + t", "f(x) = x/m - t/m"}, //
        {"f(x) = x²", "f(x) = √x"},            //
    };
};
} // namespace com::prog::testthebest