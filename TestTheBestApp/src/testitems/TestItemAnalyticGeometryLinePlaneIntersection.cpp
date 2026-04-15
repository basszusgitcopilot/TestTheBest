#include "TestItemAnalyticGeometryLinePlaneIntersection.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAnalyticGeometryLinePlaneIntersection::TestItemAnalyticGeometryLinePlaneIntersection() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    a1 = createRandomNumber(min, max);
    a2 = createRandomNumber(min, max);
    a3 = createRandomNumber(min, max);
    b1 = createRandomNumber(min, max);
    b2 = createRandomNumber(min, max);
    b3 = createRandomNumber(min, max);
    c1 = createRandomNumber(min, max);
    c2 = createRandomNumber(min, max);
    c3 = createRandomNumber(min, max);
    x1 = createRandomNumber(min, max);
    x2 = createRandomNumber(min, max);
    x3 = createRandomNumber(min, max);
    y1 = createRandomNumber(min, max);
    y2 = createRandomNumber(min, max);
    y3 = createRandomNumber(min, max);
}

auto TestItemAnalyticGeometryLinePlaneIntersection::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAnalyticGeometryLinePlaneIntersection::operator==(const TestItem &other) const -> bool {
    const TestItemAnalyticGeometryLinePlaneIntersection &otherItem = dynamic_cast<const TestItemAnalyticGeometryLinePlaneIntersection &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAnalyticGeometryLinePlaneIntersection::getQuestion() const -> std::string {
    return "Gegeben eine Ebene mit drei Punkten: A(" + numberToString(a1) + ";" + numberToString(a2) + ";" + numberToString(a3) + "), B(" + numberToString(b1) +
           ";" + numberToString(b2) + ";" + numberToString(b3) + "), C(" + numberToString(c1) + ";" + numberToString(c2) + ";" + numberToString(c3) +
           "), und eine andere Linie mit zwei Punkten: X(" + numberToString(x1) + ";" + numberToString(x2) + ";" + numberToString(x3) + "), Y(" +
           numberToString(y1) + ";" + numberToString(y2) + numberToString(y3) + "). Wo schneiden sie sich?\n";
}

auto TestItemAnalyticGeometryLinePlaneIntersection::getRightAnswer() const -> std::string {
    double ab1 = b1 - a1;
    double ab2 = b2 - a2;
    double ab3 = b3 - a3;
    double ac1 = c1 - a1;
    double ac2 = c2 - a2;
    double ac3 = c3 - a3;
    double n1 = ab2 * ac3 - ab3 * ac2;
    double n2 = ab3 * ac1 - ab1 * ac3;
    double n3 = ab1 * ac2 - ab2 * ac1;

    double v1 = y1 - x1;
    double v2 = y2 - x2;
    double v3 = y3 - x3;

    double t = (n1 * (a1 - x1) + n2 * (a2 - x2) + n3 * (a3 - x3)) / (n1 * v1 + n2 * v2 + n3 * v3);
    double s1 = x1 + v1 * t;
    double s2 = x2 + v2 * t;
    double s3 = x3 + v3 * t;

    return std::string("S(") + numberToString(s1, 2) + ";" + numberToString(s2, 2) + ";" + numberToString(s3, 2) + ")";
}

auto TestItemAnalyticGeometryLinePlaneIntersection::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest