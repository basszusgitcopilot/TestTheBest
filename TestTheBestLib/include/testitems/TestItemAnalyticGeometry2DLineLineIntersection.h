#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAnalyticGeometry2DLineLineIntersection : public TestItem {
  public:
    TestItemAnalyticGeometry2DLineLineIntersection();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    double a1;
    double a2;
    double b1;
    double b2;
    double x1;
    double x2;
    double y1;
    double y2;
};
} // namespace com::prog::testthebest