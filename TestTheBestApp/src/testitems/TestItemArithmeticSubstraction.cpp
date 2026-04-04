#include "TestItemArithmeticSubstraction.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemArithmeticSubstraction::TestItemArithmeticSubstraction() {
    constexpr int32_t min = -100;
    constexpr int32_t max = 100;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
}

auto TestItemArithmeticSubstraction::operator==(const TestItem &other) const -> bool {
    const TestItemArithmeticSubstraction &otherItem = dynamic_cast<const TestItemArithmeticSubstraction &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemArithmeticSubstraction::getQuestion() const -> std::string { return "Was ergibt " + std::to_string(a) + " - " + std::to_string(b) + "?\n"; }

auto TestItemArithmeticSubstraction::getRightAnswer() const -> std::string { return std::to_string(a - b); }
auto TestItemArithmeticSubstraction::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest