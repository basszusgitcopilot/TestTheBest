#include "TestItemArithmeticAddition.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemArithmeticAddition::TestItemArithmeticAddition() {
    constexpr int32_t min = -100;
    constexpr int32_t max = 100;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
}

auto TestItemArithmeticAddition::operator==(const TestItem &other) const -> bool {
    const TestItemArithmeticAddition &otherItem = dynamic_cast<const TestItemArithmeticAddition &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemArithmeticAddition::getQuestion() const -> std::string { return "Was ergibt " + std::to_string(a) + " + " + std::to_string(b) + "?\n"; }

auto TestItemArithmeticAddition::getRightAnswer() const -> std::string { return std::to_string(a + b); }
auto TestItemArithmeticAddition::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest