#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAddition : public TestItem {
  public:
    TestItemAddition();
    auto operator==(const TestItem& other) -> bool override;
    auto getQuestion() -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t a;
    int32_t b;
};
} // namespace com::prog::latin::tester