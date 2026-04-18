#pragma once

#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStereoSphereSurfaceVolume : public TestItem {
  public:
    TestItemStereoSphereSurfaceVolume();
    [[nodiscard]] auto equals(const TestItem &other) const -> bool override;
    [[nodiscard]] auto getQuestion() const -> std::string override;
    [[nodiscard]] auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    double radius;
};
} // namespace com::prog::testthebest