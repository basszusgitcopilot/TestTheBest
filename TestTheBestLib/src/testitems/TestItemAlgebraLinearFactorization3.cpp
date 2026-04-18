#include "TestItemAlgebraLinearFactorization3.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAlgebraLinearFactorization3::TestItemAlgebraLinearFactorization3() {
    constexpr int32_t min = -5;
    constexpr int32_t max = 5;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
    c = createRandomNumber(min, max);
}

auto TestItemAlgebraLinearFactorization3::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAlgebraLinearFactorization3::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemAlgebraLinearFactorization3 &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAlgebraLinearFactorization3::getQuestion() const -> std::string {
    // (x+a)(x+b)(x+c) = (x²+(a+b)x+ab)(x+c) = x³+(a+b)x²+abx+cx²+c(a+b)x+cab = x³+(a+b+c)x²+(ab+ca+cb)x+cab
    return "Welche Zerlegung entspricht dieser Gleichung: x³ + " + numberToString(a + b + c, 0) + "x² + " + numberToString(a * b + b * c + c * a, 0) + "x + " +
           numberToString(a * b * c, 0) + " = 0";
}

auto TestItemAlgebraLinearFactorization3::getRightAnswer() const -> std::string {
    return std::string("(x + ") + numberToString(a, 0) + ")*(x + " + numberToString(b, 0) + ")*(x + " + numberToString(c, 0) + ") = 0";
}

auto TestItemAlgebraLinearFactorization3::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest
