#include "TestItemIntegralRules.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemIntegralRules::TestItemIntegralRules() {
    constexpr int32_t min = 0;
    const int32_t max = rules.size() - 1;
    ruleIndex = createRandomNumber(min, max);
}

auto TestItemIntegralRules::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemIntegralRules::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemIntegralRules &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemIntegralRules::getQuestion() const -> std::string { return "Was ist die Stammfunktion von " + rules.at(ruleIndex).first + " ?\n"; }

auto TestItemIntegralRules::getRightAnswer() const -> std::string { return rules.at(ruleIndex).second; }

auto TestItemIntegralRules::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest