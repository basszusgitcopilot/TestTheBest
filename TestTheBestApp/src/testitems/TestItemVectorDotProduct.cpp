#include "TestItemVectorDotProduct.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemVectorDotProduct::TestItemVectorDotProduct() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a1 = createRandomNumber(min, max);
    a2 = createRandomNumber(min, max);
    a3 = createRandomNumber(min, max);
    b1 = createRandomNumber(min, max);
    b2 = createRandomNumber(min, max);
    b3 = createRandomNumber(min, max);
}

auto TestItemVectorDotProduct::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemVectorDotProduct::operator==(const TestItem &other) const -> bool {
    const TestItemVectorDotProduct &otherItem = dynamic_cast<const TestItemVectorDotProduct &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemVectorDotProduct::getQuestion() const -> std::string {
    return "Viktor möchte den Skalarprodukt von zwei Vektoren bekommen: (" + std::to_string(a1) + ", " + std::to_string(a2) + ", " + std::to_string(a3) +
           ")⋅(" + std::to_string(b1) + ", " + std::to_string(b2) + ", " + std::to_string(b3) +
           "). Welches Ergebnis bekommt er, wenn er richtig rechnet? Wie groß ist der Winkel zwischen den zwei Vektoren?\n";
}

auto TestItemVectorDotProduct::getRightAnswer() const -> std::string {
    int32_t dotProduct = a1 * b1 + a2 * b2 + a3 * b3;
    double lengthA = vectorLength(a1, a2, a3);
    double lengthB = vectorLength(b1, b2, b3);

    std::string angleString = "Winkel kann man nicht bestimmen";
    if (lengthA > 0 && lengthB > 0) {
        double angle = std::acos(dotProduct / lengthA / lengthB) * 180 / M_PI;
        angleString = numberToString(angle, 2) + "°";
    }
    return std::to_string(dotProduct) + "; " + angleString;
}

auto TestItemVectorDotProduct::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest