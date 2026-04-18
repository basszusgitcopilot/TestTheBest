#include "TestItemStereoSphereVolume.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStereoSphereVolume::TestItemStereoSphereVolume() {
    constexpr int min = 1;
    constexpr int max = 100;
    surfaceArea = createRandomNumber(min, max);
}

auto TestItemStereoSphereVolume::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemStereoSphereVolume::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemStereoSphereVolume &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStereoSphereVolume::getQuestion() const -> std::string {
    return "Eine Kugel hat eine Oberfläche " + numberToString(surfaceArea, 0) + " m². Gesucht ist das Volumen.";
}

auto TestItemStereoSphereVolume::getRightAnswer() const -> std::string {
    double radius = 0.5 * std::sqrt(surfaceArea / M_PI);
    double volume = 4.0 / 3.0 * M_PI * std::pow(radius, 3);
    return numberToString(volume, 2) + " m³";
}

auto TestItemStereoSphereVolume::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest