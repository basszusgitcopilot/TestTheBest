#include "TestItemAlgebraLogarithmRules.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAlgebraLogarithmRules::TestItemAlgebraLogarithmRules() {
    constexpr int32_t min = 0;
    const int32_t max = rules.size() - 1;
    selectedIndex = createRandomNumber(min, max);
}

auto TestItemAlgebraLogarithmRules::getMaxNumOfQuestions() const -> uint16_t { return rules.size(); }

auto TestItemAlgebraLogarithmRules::operator==(const TestItem &other) const -> bool {
    const TestItemAlgebraLogarithmRules &otherItem = dynamic_cast<const TestItemAlgebraLogarithmRules &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAlgebraLogarithmRules::getQuestion() const -> std::string {
    return "Wie kann man die Gleichung fortsetzen? " + rules.at(selectedIndex).first + " = ... \n";
}

auto TestItemAlgebraLogarithmRules::getRightAnswer() const -> std::string { return rules.at(selectedIndex).second; }

auto TestItemAlgebraLogarithmRules::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest