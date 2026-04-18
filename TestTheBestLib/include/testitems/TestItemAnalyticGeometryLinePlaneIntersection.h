#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemAnalyticGeometryLinePlaneIntersection : public TestItem {
  public:
    TestItemAnalyticGeometryLinePlaneIntersection();
    [[nodiscard]] auto equals(const TestItem &other) const -> bool override;
    [[nodiscard]] auto getQuestion() const -> std::string override;
    [[nodiscard]] auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    double a1;
    double a2;
    double a3;
    double b1;
    double b2;
    double b3;
    double c1;
    double c2;
    double c3;
    double x1;
    double x2;
    double x3;
    double y1;
    double y2;
    double y3;
};
} // namespace com::prog::testthebest