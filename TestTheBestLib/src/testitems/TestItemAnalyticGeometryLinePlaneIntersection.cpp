#include "TestItemAnalyticGeometryLinePlaneIntersection.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAnalyticGeometryLinePlaneIntersection::TestItemAnalyticGeometryLinePlaneIntersection() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
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
           numberToString(l.a.z) + "), Y(" + numberToString(l.b.x) + ";" + numberToString(l.b.y)+";" + numberToString(l.b.z) + "). Wo schneiden sie sich?\n";
}

auto TestItemAnalyticGeometryLinePlaneIntersection::getRightAnswer() const -> std::string {
    Vector3D pab = p.b - p.a;
    Vector3D pac = p.c - p.a;
    Vector3D n = crossProduct(pab, pac);

    Vector3D lab = l.b - l.a;

    double t = (n.x * (p.a.x - l.a.x) + n.y * (p.a.y - l.a.y) + n.z * (p.a.z - l.a.z)) / (n.x * lab.x + n.y * lab.y + n.z * lab.z);
    double s1 = l.a.x + lab.x * t;
    double s2 = l.a.y + lab.y * t;
    double s3 = l.a.z + lab.z * t;

    return std::string("S(") + numberToString(s1, 2) + ";" + numberToString(s2, 2) + ";" + numberToString(s3, 2) + ")";
}

auto TestItemAnalyticGeometryLinePlaneIntersection::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest