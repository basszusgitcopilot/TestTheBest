#include "TestItemAnalyticGeometryLinePlaneIntersection.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAnalyticGeometryLinePlaneIntersection::TestItemAnalyticGeometryLinePlaneIntersection() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    do {
        p.a.x = createRandomNumber(min, max);
        p.a.y = createRandomNumber(min, max);
        p.a.z = createRandomNumber(min, max);
        p.b.x = createRandomNumber(min, max);
        p.b.y = createRandomNumber(min, max);
        p.b.z = createRandomNumber(min, max);
        p.c.x = createRandomNumber(min, max);
        p.c.y = createRandomNumber(min, max);
        p.c.z = createRandomNumber(min, max);
        l.a.x = createRandomNumber(min, max);
        l.a.y = createRandomNumber(min, max);
        l.a.z = createRandomNumber(min, max);
        l.b.x = createRandomNumber(min, max);
        l.b.y = createRandomNumber(min, max);
        l.b.z = createRandomNumber(min, max);
    } while (p.a == p.b || p.a == p.c || p.b == p.c || l.a == l.b);
}

auto TestItemAnalyticGeometryLinePlaneIntersection::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAnalyticGeometryLinePlaneIntersection::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemAnalyticGeometryLinePlaneIntersection &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAnalyticGeometryLinePlaneIntersection::getQuestion() const -> std::string {
    return "Gegeben eine Ebene mit drei Punkten: A(" + numberToString(p.a.x) + ";" + numberToString(p.a.y) + ";" + numberToString(p.a.z) + "), B(" +
           numberToString(p.b.x) + ";" + numberToString(p.b.y) + ";" + numberToString(p.b.z) + "), C(" + numberToString(p.c.x) + ";" + numberToString(p.c.y) +
           ";" + numberToString(p.c.z) + "), und eine andere Linie mit zwei Punkten: X(" + numberToString(l.a.x) + ";" + numberToString(l.a.y) + ";" +
           numberToString(l.a.z) + "), Y(" + numberToString(l.b.x) + ";" + numberToString(l.b.y) + ";" + numberToString(l.b.z) + "). Wo schneiden sie sich?\n";
}

auto TestItemAnalyticGeometryLinePlaneIntersection::getRightAnswer() const -> std::string {
    if (isCoordinateOnPlane(l.a, p) && isCoordinateOnPlane(l.b, p)) {
        return "Die Linie befindet sich auf der Ebene.";
    }
    if (dotProduct3D(l.b - l.a, crossProduct(p.b - p.a, p.c - p.a)) == 0) {
        return "Die Line verläuft parallel zu aber außerhalb der Ebene.";
    }

    auto s = linePlaneIntersection(l, p);
    return std::string("S(") + numberToString(s.x, 2) + ";" + numberToString(s.y, 2) + ";" + numberToString(s.z, 2) + ")";
}

auto TestItemAnalyticGeometryLinePlaneIntersection::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest