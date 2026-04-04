#include "TestItemStereoRules.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStereoRules::TestItemStereoRules() {
    constexpr int32_t min = 0;
    const int32_t max = rules.size() - 1;
    ruleIndex = createRandomNumber(min, max);
}

auto TestItemStereoRules::getMaxNumOfQuestions() const -> uint16_t { return rules.size(); }

auto TestItemStereoRules::operator==(const TestItem &other) const -> bool {
    const TestItemStereoRules &otherItem = dynamic_cast<const TestItemStereoRules &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStereoRules::getQuestion() const -> std::string {
    return "Superman möchte " + rules.at(ruleIndex).first + " berechnen. Welche Formel soll er verwenden?\n";
}

auto TestItemStereoRules::getRightAnswer() const -> std::string { return rules.at(ruleIndex).second; }

auto TestItemStereoRules::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest