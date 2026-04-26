#pragma once

#include "TestItem.h"
#include <cstdint>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStochasticBinomDistFormulas : public TestItem {
  public:
    TestItemStochasticBinomDistFormulas();
    [[nodiscard]] auto equals(const TestItem &other) const -> bool override;
    [[nodiscard]] auto getQuestion() const -> std::string override;
    [[nodiscard]] auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    uint32_t n1;
    uint32_t n2;
    uint32_t x;
};
} // namespace com::prog::testthebest