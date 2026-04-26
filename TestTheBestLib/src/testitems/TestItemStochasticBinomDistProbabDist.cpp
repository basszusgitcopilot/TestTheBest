#include "TestItemStochasticBinomDistProbabDist.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStochasticBinomDistProbabDist::TestItemStochasticBinomDistProbabDist() {
    constexpr uint32_t xmin = 1;
    constexpr uint32_t xmax = 10;
    constexpr uint32_t nmin = 7;
    constexpr uint32_t nmax = 10;
    n = createRandomNumber(nmin, nmax);
    p = static_cast<double>(createRandomNumber(xmin, xmax - 1)) / xmax;
}

auto TestItemStochasticBinomDistProbabDist::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemStochasticBinomDistProbabDist::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemStochasticBinomDistProbabDist &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStochasticBinomDistProbabDist::getQuestion() const -> std::string {
    std::string question = "Gegeben eine Wahrscheinlichkeitsverteilung für eine binomialverteilte Zufallsgröße:\n";
    for (uint32_t k = 0; k <= n; ++k) {
        question += "k = " + std::to_string(k) + "; P(X = k) = " + numberToString(bernoulliChainProbability(n, k, p), 2) + "\n";
    };
    question += "Was sind der Erwartungswert und die Standardabweichung bei n = " + std::to_string(n) + "?\n";
    return question;
}

auto TestItemStochasticBinomDistProbabDist::getRightAnswer() const -> std::string {
    return "µ = " + numberToString(expectedValueBinomialDistribution(n, p), 2) + "; σ = " + numberToString(standardDeviationBinomialDistribution(n, p), 2);
}

auto TestItemStochasticBinomDistProbabDist::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest