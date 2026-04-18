#pragma once

#include "MathUtils.h"
#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemVectorDotProduct : public TestItem {
  public:
    TestItemVectorDotProduct();
    auto operator==(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    Vector3D a;
    Vector3D b;
};
} // namespace com::prog::testthebest