#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemTrigonometryRules : public TestItem {
  public:
    TestItemTrigonometryRules();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t selectedIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"tan(α)", "sin(α)/cos(α)"},                      //
        {"sin²(α) + cos²(α)", "1"},                       //
        {"sin(-α)", "-sin(α)"},                           //
        {"cos(-α)", "cos(α)"},                            //
        {"sin(α + β))", "sin(α)⋅cos(β) + cos(α)⋅sin(β)"}, //
        {"cos(α + β))", "cos(α)⋅cos(β) - sin(α)⋅sin(β)"}, //
        {"sin(α - β))", "sin(α)⋅cos(β) - cos(α)⋅sin(β)"}, //
        {"cos(α - β))", "cos(α)⋅cos(β) + sin(α)⋅sin(β)"}, //
        {"a/sin(α)", "b/sin(β) = c/sin(γ)"},              //
        {"a²", "b² + c² - 2ac⋅cos(α)"},                   //
        {"b²", "a² + c² - 2ac⋅cos(β)"},                   //
        {"c²", "a² + b² - 2ac⋅cos(γ)"},                   //
        {"sin(0°)", "0"},
        {"sin(30°)", "0.5"},
        {"sin(45°)", "(√2)/2"},
        {"sin(60°)", "(√3)/2"},
        {"sin(90°)", "1"},
        {"cos(0°)", "1"},
        {"cos(30°)", "(√3)/2"},
        {"cos(45°)", "(√2)/2"},
        {"cos(60°)", "0.5"},
        {"cos(90°)", "1"},
    };
};
} // namespace com::prog::testthebest