#include "TestItemQuadraticEquation.h"
#include "Utils.h"
#include <iostream>

namespace com::prog::testthebest {

TestItemQuadraticEquation::TestItemQuadraticEquation() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a = createRandomNumber(min, max);
    b = createRandomNumber(min, max);
    c = createRandomNumber(min, max);
}

auto TestItemQuadraticEquation::operator==(const TestItem &other) const -> bool {
    const TestItemQuadraticEquation &otherItem = dynamic_cast<const TestItemQuadraticEquation &>(other);
    std::cout << "TestItemQuadraticEquation: " << getRightAnswer() << " ?= " << otherItem.getRightAnswer() << std::endl;
    return getRightAnswer() == otherItem.getRightAnswer();
};

auto TestItemQuadraticEquation::getQuestion() -> std::string {
    return "Was sind die Lösungen dieser Gleichung: " + numberToString(a, 0) + "x² + " + numberToString(b, 0) + "x + " + numberToString(c, 0);
}

auto TestItemQuadraticEquation::getRightAnswer() const -> std::string {
    double discriminant = std::pow(b, 2) - 4 * a * c;
    if (discriminant < 0) {
        return "keine reelle Lösung";
    } else if (discriminant == 0) {
        return numberToString(-b / (2 * a), 2);
    } else {
        double x1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double x2 = (-b - std::sqrt(discriminant)) / (2 * a);
        return std::string("x1 = ") + numberToString(x1, 2) + "; x2 = " + numberToString(x2, 2);
    }
}

auto TestItemQuadraticEquation::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest