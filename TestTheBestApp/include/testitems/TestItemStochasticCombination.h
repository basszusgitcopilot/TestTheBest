#pragma once

#include "TestItem.h"
#include <cstdint>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStochasticCombination : public TestItem {
  public:
    TestItemStochasticCombination();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    uint32_t n;
    uint32_t k;
};
} // namespace com::prog::testthebest