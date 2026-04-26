#pragma once

#include "TestItem.h"
#include <cstdint>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStochasticBinomDistProbabDist : public TestItem {
  public:
    TestItemStochasticBinomDistProbabDist();
    [[nodiscard]] auto equals(const TestItem &other) const -> bool override;
    [[nodiscard]] auto getQuestion() const -> std::string override;
    [[nodiscard]] auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    uint32_t n;
    double p;
};
} // namespace com::prog::testthebest