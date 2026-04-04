#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStereoCalculations : public TestItem {
  public:
    TestItemStereoCalculations();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    double surfaceArea;
};
} // namespace com::prog::testthebest