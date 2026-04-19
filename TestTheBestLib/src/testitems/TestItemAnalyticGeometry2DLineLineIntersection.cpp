#include "TestItemAnalyticGeometry2DLineLineIntersection.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemAnalyticGeometry2DLineLineIntersection::TestItemAnalyticGeometry2DLineLineIntersection() {
    constexpr int32_t min = -10;
    constexpr int32_t max = 10;
    do {
        l1.a.x = createRandomNumber(min, max);
        l1.a.y = createRandomNumber(min, max);
        l1.b.x = createRandomNumber(min, max);
        l1.b.y = createRandomNumber(min, max);
        l2.a.x = createRandomNumber(min, max);
        l2.a.y = createRandomNumber(min, max);
        l2.b.x = createRandomNumber(min, max);
        l2.b.y = createRandomNumber(min, max);
    } while ((l1.a.x == l1.b.x && l1.a.y == l1.b.y) || (l2.a.x == l2.b.x && l2.a.y == l2.b.y));
}

auto TestItemAnalyticGeometry2DLineLineIntersection::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemAnalyticGeometry2DLineLineIntersection::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemAnalyticGeometry2DLineLineIntersection &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemAnalyticGeometry2DLineLineIntersection::getQuestion() const -> std::string {
    return "Gegeben eine Linie mit zwei Punkten: A(" + numberToString(l1.a.x) + ";" + numberToString(l1.a.y) + "), B(" + numberToString(l1.b.x) + ";" +
           numberToString(l1.b.y) + "), und eine andere Linie mit zwei Punkten: X(" + numberToString(l2.a.x) + ";" + numberToString(l2.a.y) + "), Y(" +
           numberToString(l2.b.x) + ";" + numberToString(l2.b.y) + "). Wo schneiden sich die Linien?\n";
}

auto TestItemAnalyticGeometry2DLineLineIntersection::getRightAnswer() const -> std::string {
    if (areLinesParallel2D(l1, l2)) {
        return "Die Linen sind parallel.";
    }
    auto s = lineLineIntersection2D(l1, l2);
    return std::string("S(") + numberToString(s.x, 2) + ";" + numberToString(s.y, 2) + ")";
}

auto TestItemAnalyticGeometry2DLineLineIntersection::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest