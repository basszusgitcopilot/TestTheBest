#pragma once

#include "TestItem.h"
#include <cstdint>
#include <vector>

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest {

class TestItemStochasticBernoulliExperiment : public TestItem {
  public:
    TestItemStochasticBernoulliExperiment();
    auto equals(const TestItem &other) const -> bool override;
    auto getQuestion() const -> std::string override;
    auto getRightAnswer() const -> std::string override;
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override;
    auto getMaxNumOfQuestions() const -> uint16_t override;

  private:
    uint32_t n;
    uint32_t k;
    uint32_t numOfA;
    uint32_t numOfB;
    double p;
    uint8_t questionIndex;

    const std::string placeholderNumOfA{"$NUM_OF_A"};
    const std::string placeholderNumOfB{"$NUM_OF_B"};
    const std::string placeholderNumOfTrials{"$NUM_OF_TRIALS"};
    const std::string placeholderNumOfHits{"$NUM_OF_HITS"};

    std::vector<std::string> possibleQuestions = {
        "In einer Urne befinden sich " + placeholderNumOfA + " rote und " + placeholderNumOfB + " schwarze Kugeln. Es werden " + placeholderNumOfTrials +
            " Kugeln mit Zurücklegen entnommen. Was ist die "
            "Wahrscheinlichkeit, dass genau " +
            placeholderNumOfHits + " rote unter den " + placeholderNumOfTrials + " Kugeln sind.",
        "In einem großen Zylinder sind " + placeholderNumOfA + " weiße und " + placeholderNumOfB + " schwarze Kaninchen. Es werden " + placeholderNumOfTrials +
            " Kaninchen mit Zurücklegen entnommen. Was ist die "
            "Wahrscheinlichkeit, dass genau " +
            placeholderNumOfHits + " weiße unter den " + placeholderNumOfTrials + " Kaninchen sind.",
        "In einer Tüte sind " + placeholderNumOfA + " rote und " + placeholderNumOfB + " gelbe Gummibärchen. Es werden " + placeholderNumOfTrials +
            " Gummibärchen mit Zurücklegen entnommen. Was ist die "
            "Wahrscheinlichkeit, dass genau " +
            placeholderNumOfHits + " rote unter den " + placeholderNumOfTrials + " Gummibärchen sind.",
        "In einer Kiste sind " + placeholderNumOfA + " rote und " + placeholderNumOfB + " grüne Äpfel. Es werden " + placeholderNumOfTrials +
            " Äpfel mit Zurücklegen entnommen. Was ist die "
            "Wahrscheinlichkeit, dass genau " +
            placeholderNumOfHits + " rote unter den " + placeholderNumOfTrials + " Äpfeln sind."};
};
} // namespace com::prog::testthebest