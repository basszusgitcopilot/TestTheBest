#include "TestItemAnalyticGeometry2DLineLineIntersection.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAnalyticGeometry2DLineLineIntersection::TestItemAnalyticGeometry2DLineLineIntersection() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a1 = createRandomNumber(min, max);
    a2 = createRandomNumber(min, max);
    b1 = createRandomNumber(min, max);
    b2 = createRandomNumber(min, max);
    x1 = createRandomNumber(min, max);
    x2 = createRandomNumber(min, max);
    y1 = createRandomNumber(min, max);
    y2 = createRandomNumber(min, max);
}

auto TestItemAnalyticGeometry2DLineLineIntersection::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAnalyticGeometry2DLineLineIntersection::operator==(const TestItem &other) const -> bool {
    const TestItemAnalyticGeometry2DLineLineIntersection &otherItem = dynamic_cast<const TestItemAnalyticGeometry2DLineLineIntersection &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAnalyticGeometry2DLineLineIntersection::getQuestion() const -> std::string {
    return "Gegeben eine Linie mit zwei Punkten: A(" + numberToString(a1) + ";" + numberToString(a2) + "), B(" + numberToString(b1) + ";" + numberToString(b2) +
           "), und eine andere Linie mit zwei Punkten: X(" + numberToString(x1) + ";" + numberToString(x2) + "), Y(" + numberToString(y1) + ";" +
           numberToString(y2) + "). Wo schneiden sich die Linien?\n";
}

// Linie1: (a1,a2)+i*((b1-a1),(b2-a2))
// Linie2: (x1,x2)+k*((y1-x1),(y2-x2))

// a1+i*(b1-a1) = x1+k*(y1-x1)
// a2+i*(b2-a2) = x2+k*(y2-x2)

// (a1+i*(b1-a1))*(y2-x2)/(y1-x1) = (x1+k*(y1-x1))*(y2-x2)/(y1-x1) = x1*(y2-x2)/(y1-x1)+k*(y2-x2)
// a2+i*(b2-a2) - (a1+i*(b1-a1))*(y2-x2)/(y1-x1) = x2 - x1*(y2-x2)/(y1-x1)
// i*((b2-a2)-(b1-a1)*(y2-x2)/(y1-x1))+a2-a1*(y2-x2)/(y1-x1)=x2 - x1*(y2-x2)/(y1-x1)
// i = (x2-x1*(y2-x2)/(y1-x1)-a2+a1*(y2-x2)/(y1-x1))/((b2-a2)-(b1-a1)*(y2-x2)/(y1-x1))

// k=(a1+i*(b1-a1)-x1)/(y1-x1)

auto TestItemAnalyticGeometry2DLineLineIntersection::getRightAnswer() const -> std::string {
    double i = (x2 - x1 * (y2 - x2) / (y1 - x1) - a2 + a1 * (y2 - x2) / (y1 - x1)) / ((b2 - a2) - (b1 - a1) * (y2 - x2) / (y1 - x1));
    double k = (a1 + i * (b1 - a1) - x1) / (y1 - x1);
    double s1 = a1 + i * (b1 - a1);
    double s2 = a2 + i * (b2 - a2);

    return std::string("S(") + numberToString(s1, 2) + ";" + numberToString(s2, 2) + ")";
}

auto TestItemAnalyticGeometry2DLineLineIntersection::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest