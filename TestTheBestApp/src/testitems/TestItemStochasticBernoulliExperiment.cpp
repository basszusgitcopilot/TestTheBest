#include "TestItemStochasticBernoulliExperiment.h"
#include "MathUtils.h"
#include "StringUtils.h"

namespace com::prog::testthebest {

TestItemStochasticBernoulliExperiment::TestItemStochasticBernoulliExperiment() {
    constexpr uint32_t nmin = 11;
    constexpr uint32_t nmax = 20;
    constexpr uint32_t kmin = 2;
    constexpr uint32_t kmax = 6;
    constexpr uint32_t numOfAMin = 1;
    constexpr uint32_t numOfAMax = 20;
    constexpr uint32_t numOfBMin = 1;
    constexpr uint32_t numOfBMax = 20;
    k = createRandomNumber(kmin, kmax);
    n = createRandomNumber(k, nmax);
    numOfA = createRandomNumber(numOfAMin, numOfAMax);
    numOfB = createRandomNumber(numOfBMin, numOfBMax);

    questionIndex = createRandomNumber(static_cast<uint8_t>(0), static_cast<uint8_t>(possibleQuestions.size() - 1));
}

auto TestItemStochasticBernoulliExperiment::operator==(const TestItem &other) const -> bool {
    const TestItemStochasticBernoulliExperiment &otherItem = dynamic_cast<const TestItemStochasticBernoulliExperiment &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStochasticBernoulliExperiment::getQuestion() const -> std::string {
    auto question = possibleQuestions.at(questionIndex);
    question = replace(question, placeholderNumOfA, std::to_string(numOfA));
    question = replace(question, placeholderNumOfB, std::to_string(numOfB));
    question = replace(question, placeholderNumOfTrials, std::to_string(n));
    question = replace(question, placeholderNumOfHits, std::to_string(k));

    return question;
}

auto TestItemStochasticBernoulliExperiment::getRightAnswer() const -> std::string {
    std::string rightAnswer = numberToString(
        bincoeff(n, k) * std::pow((double)numOfA / (double)(numOfA + numOfB), k) * std::pow((double)numOfB / (double)(numOfA + numOfB), n - k), 5);
    return rightAnswer;
}

auto TestItemStochasticBernoulliExperiment::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest