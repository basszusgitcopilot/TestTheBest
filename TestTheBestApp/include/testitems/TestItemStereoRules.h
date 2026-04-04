#pragma once

#include "TestItem.h"
#include <memory>
#include <string>
#include <utility>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStereoRules : public TestItem {
  public:
    TestItemStereoRules();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t ruleIndex;

    const std::vector<std::pair<std::string, std::string>> rules{
        {"das Volumen eines Würfels", "a³"},                 //
        {"die Oberfläche eines Würfels", "6a²"},             //
        {"das Volumen eines Quaders", "a⋅b⋅c"},              //
        {"die Oberfläche eines Quaders", "2(ab + ac + bc)"}, //
    };
};
} // namespace com::prog::testthebest