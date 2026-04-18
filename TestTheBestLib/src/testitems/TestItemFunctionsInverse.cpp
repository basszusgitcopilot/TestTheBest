#include "TestItemFunctionsInverse.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemFunctionsInverse::TestItemFunctionsInverse() {
    constexpr int32_t min = 0;
    const int32_t max = rules.size() - 1;
    selectedIndex = createRandomNumber(min, max);
}

auto TestItemFunctionsInverse::getMaxNumOfQuestions() const -> uint16_t { return rules.size(); }

auto TestItemFunctionsInverse::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemFunctionsInverse &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemFunctionsInverse::getQuestion() const -> std::string { return "Was ist die Inversfunktion von " + rules.at(selectedIndex).first + " ?\n"; }

auto TestItemFunctionsInverse::getRightAnswer() const -> std::string { return rules.at(selectedIndex).second; }

auto TestItemFunctionsInverse::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest