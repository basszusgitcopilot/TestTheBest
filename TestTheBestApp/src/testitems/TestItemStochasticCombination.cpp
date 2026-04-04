#include "TestItemStochasticCombination.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStochasticCombination::TestItemStochasticCombination() {
    constexpr uint32_t nmin = 11;
    constexpr uint32_t nmax = 100;
    constexpr uint32_t kmin = 2;
    constexpr uint32_t kmax = 6;
    n = createRandomNumber(nmin, nmax);
    k = createRandomNumber(kmin, kmax);
}

auto TestItemStochasticCombination::operator==(const TestItem &other) const -> bool {
    const TestItemStochasticCombination &otherItem = dynamic_cast<const TestItemStochasticCombination &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStochasticCombination::getQuestion() const -> std::string {
    return "Beim HyperSuperJackpot werden aus " + std::to_string(n) + " nummerierten Kugeln " + std::to_string(k) +
           " gezogen. Wie viele mögliche Kombinationen gibt es, wenn die Reihenfolge keine Rolle spielt?";
}

auto TestItemStochasticCombination::getRightAnswer() const -> std::string { return std::to_string(bincoeff(n, k)); }

auto TestItemStochasticCombination::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest