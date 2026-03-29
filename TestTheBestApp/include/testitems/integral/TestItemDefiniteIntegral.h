#pragma once

#include "TestItem.h"
#include <memory>
#include <string>
#include <utility>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemDefiniteIntegral : public TestItem {
  public:
    TestItemDefiniteIntegral();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;

  private:
    int32_t ax3 = 0;
    int32_t ax2 = 0;
    int32_t ax1 = 0;
    int32_t ax0 = 0;
    int32_t t0 = 0;
    int32_t t1 = 0;

    auto calculateIntegralValue(double t) const -> double;
};
} // namespace com::prog::testthebest