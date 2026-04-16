#include "TestItemVectorCrossProduct.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemVectorCrossProduct::TestItemVectorCrossProduct() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a1 = createRandomNumber(min, max);
    a2 = createRandomNumber(min, max);
    a3 = createRandomNumber(min, max);
    b1 = createRandomNumber(min, max);
    b2 = createRandomNumber(min, max);
    b3 = createRandomNumber(min, max);
}

auto TestItemVectorCrossProduct::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemVectorCrossProduct::operator==(const TestItem &other) const -> bool {
    const TestItemVectorCrossProduct &otherItem = dynamic_cast<const TestItemVectorCrossProduct &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemVectorCrossProduct::getQuestion() const -> std::string {
    return "Hektor möchte den Vektorprodukt (Kreuzprodukt) von zwei Vektoren bekommen: (" + std::to_string(a1) + ", " + std::to_string(a2) + ", " +
           std::to_string(a3) + ")⨯(" + std::to_string(b1) + ", " + std::to_string(b2) + ", " + std::to_string(b3) +
           "). Welches Ergebnis bekommt er, wenn er richtig rechnet?\n";
}

auto TestItemVectorCrossProduct::getRightAnswer() const -> std::string {
    return "(" + std::to_string(a2 * b3 - a3 * b2) + "; " + std::to_string(a3 * b1 - a1 * b3) + "; " + std::to_string(a1 * b2 - a2 * b1) + ")";
}

auto TestItemVectorCrossProduct::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest