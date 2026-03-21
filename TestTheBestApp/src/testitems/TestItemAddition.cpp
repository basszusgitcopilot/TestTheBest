#include "TestItemAddition.h"
#include "Utils.h"

namespace com::prog::testthebest {

TestItemAddition::TestItemAddition() {
    constexpr int32_t min = -100;
    constexpr int32_t max = 100;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
}

auto TestItemAddition::operator==(const TestItem &other) const -> bool {
    const TestItemAddition &otherItem = dynamic_cast<const TestItemAddition &>(other);
    return getRightAnswer() == otherItem.getRightAnswer();
};

auto TestItemAddition::getQuestion() -> std::string { return "Was ergibt " + std::to_string(a) + " + " + std::to_string(b) + "?"; }

auto TestItemAddition::getRightAnswer() const -> std::string { return std::to_string(a + b); }

auto TestItemAddition::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest