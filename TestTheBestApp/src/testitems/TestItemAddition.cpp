#include "testitems/TestItemAddition.h"
#include <random>

namespace com::prog::testthebest {

TestItemAddition::TestItemAddition() {
    std::random_device randomDevice;
    std::default_random_engine randomEngine(randomDevice());

    constexpr int32_t max = 100;
    constexpr int32_t min = -100;
    std::uniform_int_distribution<int> uniformDistRight(min, max);
    a = uniformDistRight(randomEngine);
    b = uniformDistRight(randomEngine);
}

auto TestItemAddition::operator==(const TestItem &other) -> bool {
    const TestItemAddition otherAddition = dynamic_cast<const TestItemAddition &>(other);
    return a == otherAddition.a && b == otherAddition.b;
};

auto TestItemAddition::getQuestion() -> std::string { return "Was ergibt " + std::to_string(a) + " + " + std::to_string(b) + "?"; }

auto TestItemAddition::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = std::to_string(a + b);
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest