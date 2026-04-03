#include "TestItemTrigonometryRules.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemTrigonometryRules::TestItemTrigonometryRules() {
    constexpr int32_t min = 0;
    const int32_t max = rules.size() - 1;
    selectedIndex = createRandomNumber(min, max);
}

auto TestItemTrigonometryRules::operator==(const TestItem &other) const -> bool {
    const TestItemTrigonometryRules &otherItem = dynamic_cast<const TestItemTrigonometryRules &>(other);
    return getRightAnswer() == otherItem.getRightAnswer();
};

auto TestItemTrigonometryRules::getQuestion() -> std::string { return "Wie kann man die Gleichung fortsetzen? " + rules.at(selectedIndex).first + " = ... \n"; }

auto TestItemTrigonometryRules::getRightAnswer() const -> std::string { return rules.at(selectedIndex).second; }

auto TestItemTrigonometryRules::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest