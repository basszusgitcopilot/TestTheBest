#pragma once

#include "MathUtils.h"
#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAnalyticGeometry2DLineLineIntersection : public TestItem {
  public:
    TestItemAnalyticGeometry2DLineLineIntersection();
    auto equals(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    Line2D l1;
    Line2D l2;
};
} // namespace com::prog::testthebest