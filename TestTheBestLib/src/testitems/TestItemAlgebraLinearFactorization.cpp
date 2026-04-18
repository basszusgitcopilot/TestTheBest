#include "TestItemAlgebraLinearFactorization.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAlgebraLinearFactorization::TestItemAlgebraLinearFactorization() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
}

auto TestItemAlgebraLinearFactorization::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAlgebraLinearFactorization::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemAlgebraLinearFactorization &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAlgebraLinearFactorization::getQuestion() const -> std::string {
    return "Welche Zerlegung entspricht dieser Gleichung: x² + " + numberToString(a + b, 0) + "x + " + numberToString(a * b, 0) + " = 0";
}

auto TestItemAlgebraLinearFactorization::getRightAnswer() const -> std::string {
    return std::string("(x + ") + numberToString(a, 0) + ")*(x + " + numberToString(b, 0) + ") = 0";
}

auto TestItemAlgebraLinearFactorization::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest