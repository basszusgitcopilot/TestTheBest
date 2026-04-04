#include "TestItemDifferentialRules.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemDifferentialRules::TestItemDifferentialRules() {
    constexpr int32_t min = 0;
    const int32_t max = rules.size() - 1;
    ruleIndex = createRandomNumber(min, max);
}

auto TestItemDifferentialRules::operator==(const TestItem &other) const -> bool {
    const TestItemDifferentialRules &otherItem = dynamic_cast<const TestItemDifferentialRules &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemDifferentialRules::getQuestion() const -> std::string { return "Was ist die Ableitung von " + rules.at(ruleIndex).first + " ?\n"; }

auto TestItemDifferentialRules::getRightAnswer() const -> std::string { return rules.at(ruleIndex).second; }

auto TestItemDifferentialRules::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest