#include "TestItemIntegralDefinite.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemIntegralDefinite::TestItemIntegralDefinite() {
    constexpr int32_t min = -10;
    const int32_t max = 10;
    ax3 = createRandomNumber(min, max);
    ax2 = createRandomNumber(min, max);
    ax1 = createRandomNumber(min, max);
    ax0 = createRandomNumber(min, max);
    t0 = createRandomNumber(min, max);
    t1 = createRandomNumber(t0 + 1, max + 1);
}

auto TestItemIntegralDefinite::operator==(const TestItem &other) const -> bool {
    const TestItemIntegralDefinite &otherItem = dynamic_cast<const TestItemIntegralDefinite &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemIntegralDefinite::getQuestion() const -> std::string {
    return "Die Geschwindigkeit einer Turboschnecke (helix celeris) kann man mit folgender Funktion beschreiben: v(t) = " + numberToString(ax3, 0) + "t³ + " +
           numberToString(ax2, 0) + "t² + " + numberToString(ax1, 0) + "t + " + numberToString(ax0, 0) +
           ". Wie lang ist der Weg, die sie zwischnen t0 = " + numberToString(t0, 0) + " und t1 = " + numberToString(t1, 0) + " macht?";
}

auto TestItemIntegralDefinite::calculateIntegralValue(double t) const -> double {
    return ((double)ax3 / 4) * std::pow(t, 4) + ((double)ax2 / 3) * std::pow(t, 3) + ((double)ax1 / 2) * std::pow(t, 2) + (double)ax0 * t;
}

auto TestItemIntegralDefinite::getRightAnswer() const -> std::string { return std::to_string(calculateIntegralValue(t1) - calculateIntegralValue(t0)); }

auto TestItemIntegralDefinite::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest