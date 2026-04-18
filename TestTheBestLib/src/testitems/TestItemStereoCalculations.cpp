#include "TestItemStereoCalculations.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStereoCalculations::TestItemStereoCalculations() {
    constexpr int32_t min = 10;
    constexpr int32_t max = 100;
    surfaceArea = createRandomNumber(min, max);
}

auto TestItemStereoCalculations::getMaxNumOfQuestions() const -> uint16_t { return std::numeric_limits<uint16_t>::max(); }

auto TestItemStereoCalculations::equals(const TestItem &other) const -> bool {
    auto otherItem = dynamic_cast<const TestItemStereoCalculations &>(other);
    return getRightAnswer() == otherItem.getRightAnswer() || getQuestion() == otherItem.getQuestion();
};

auto TestItemStereoCalculations::getQuestion() const -> std::string {
    return "Albus Dumbledore hat einen Kugel, einen Tetraeder und einen Würfel. Die Oberfläche jedes einzelnen beträgt " + numberToString(surfaceArea, 0) +
           " cm². Berechne das Gesamtvolumen der drei Körper!";
}

auto TestItemStereoCalculations::getRightAnswer() const -> std::string {
    double radiusSphere = std::sqrt(surfaceArea / 4 / M_PI);
    double volumeSphere = 4.0 / 3.0 * M_PI * radiusSphere * radiusSphere * radiusSphere;
    double edgeCube = std::sqrt(surfaceArea / 6);
    double volumeCube = edgeCube * edgeCube * edgeCube;
    double edgeTetraeder = std::sqrt(surfaceArea / std::numbers::sqrt3);
    double volumeTetraeder = std::numbers::sqrt2 / 12 * edgeTetraeder * edgeTetraeder * edgeTetraeder;
    return numberToString(volumeSphere + volumeCube + volumeTetraeder, 2);
}
auto TestItemStereoCalculations::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest