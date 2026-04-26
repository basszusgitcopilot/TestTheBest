#include "TestItemStochasticBinomDistFormulas.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStochasticBinomDistFormulas::TestItemStochasticBinomDistFormulas() {
    constexpr uint32_t xmin = 1;
    constexpr uint32_t xmax = 10;
    constexpr uint32_t n1max = 100;
    constexpr uint32_t n2min = 101;
    constexpr uint32_t n2max = 200;
    x = createRandomNumber(xmin, xmax);
    n1 = createRandomNumber(x + 1, n1max);
    n2 = createRandomNumber(n2min, n2max);
}

auto TestItemStochasticBinomDistFormulas::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemStochasticBinomDistFormulas::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemStochasticBinomDistFormulas &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStochasticBinomDistFormulas::getQuestion() const -> std::string {
    return "Auf einem Radweg haben im Durchschnitt " + std::to_string(x) + " Radfahrer aus " + std::to_string(n1) +
           " ein Elektrofahrrad. Was ist die erwartete Anzahl der Elektrofahrräder unter " + std::to_string(n2) +
           " Radfahrer? Wie hoch ist die Standardabweichung?";
}

auto TestItemStochasticBinomDistFormulas::getRightAnswer() const -> std::string {
    double p = static_cast<double>(x) / n1;
    return "µ = " + numberToString(expectedValueBinomialDistribution(n2, p), 2) + "; σ = " + numberToString(standardDeviationBinomialDistribution(n2, p), 2);
}

auto TestItemStochasticBinomDistFormulas::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest