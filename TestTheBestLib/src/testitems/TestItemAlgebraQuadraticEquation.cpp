#include "TestItemAlgebraQuadraticEquation.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAlgebraQuadraticEquation::TestItemAlgebraQuadraticEquation() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
    c = createRandomNumber(min, max);
}

auto TestItemAlgebraQuadraticEquation::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAlgebraQuadraticEquation::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemAlgebraQuadraticEquation &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAlgebraQuadraticEquation::getQuestion() const -> std::string {
    return "Was sind die Lösungen dieser Gleichung: " + numberToString(a, 0) + "x² + " + numberToString(b, 0) + "x + " + numberToString(c, 0) + " = 0";
}

auto TestItemAlgebraQuadraticEquation::getRightAnswer() const -> std::string {
    double discriminant = std::pow(b, 2) - 4 * a * c;
    if (discriminant < 0) {
        return "keine reelle Lösung";
    }
    if (discriminant == 0) {
        return numberToString(-b / (2 * a), 2);
    }
    double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
    double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
    return std::string("x1 = ") + numberToString(x1, 2) + "; x2 = " + numberToString(x2, 2);
}

auto TestItemAlgebraQuadraticEquation::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest