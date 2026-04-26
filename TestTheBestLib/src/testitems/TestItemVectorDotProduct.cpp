#include "TestItemVectorDotProduct.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemVectorDotProduct::TestItemVectorDotProduct() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a.x = createRandomNumber(min, max);
    a.y = createRandomNumber(min, max);
    a.z = createRandomNumber(min, max);
    b.x = createRandomNumber(min, max);
    b.y = createRandomNumber(min, max);
    b.z = createRandomNumber(min, max);
}

auto TestItemVectorDotProduct::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemVectorDotProduct::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemVectorDotProduct &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemVectorDotProduct::getQuestion() const -> std::string {
    return "Viktor möchte das Skalarprodukt von zwei Vektoren bekommen: (" + numberToString(a.x) + ", " + numberToString(a.y) + ", " + numberToString(a.z) +
           ")⋅(" + numberToString(b.x) + ", " + numberToString(b.y) + ", " + numberToString(b.z) +
           "). Welches Ergebnis bekommt er, wenn er richtig rechnet? Wie groß ist der Winkel zwischen den zwei Vektoren?\n";
}

auto TestItemVectorDotProduct::getRightAnswer() const -> std::string {
    if (vectorLength3D(a) > 0 && vectorLength3D(b) > 0) {
        auto angle = angleBetweenVectors(a, b) * 180 / M_PI;
        return numberToString(dotProduct3D(a, b)) + "; " + numberToString(angle, 2) + "°";
    }
    return "Winkel kann man nicht bestimmen";
}

auto TestItemVectorDotProduct::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest