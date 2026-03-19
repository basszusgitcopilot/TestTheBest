#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAddition : public TestItem {
  public:
    TestItemAddition();
    bool operator==(const TestItemAddition& other){
      return a == other.a && b == other.b;
    }
    auto getQuestion() -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t a;
    int32_t b;
};
} // namespace com::prog::latin::tester