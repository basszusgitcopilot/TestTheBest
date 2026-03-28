#include "TestItemStereoSphereSurfaceVolume.h"
#include "MathUtils.h"

namespace com::prog::testthebest {

TestItemStereoSphereSurfaceVolume::TestItemStereoSphereSurfaceVolume() {
    constexpr int min = 1;
    constexpr int max = 100;
    radius = createRandomNumber(min, max);
}

auto TestItemStereoSphereSurfaceVolume::operator==(const TestItem &other) const -> bool {
    const TestItemStereoSphereSurfaceVolume &otherItem = dynamic_cast<const TestItemStereoSphereSurfaceVolume &>(other);
    return getRightAnswer() == otherItem.getRightAnswer();
};

auto TestItemStereoSphereSurfaceVolume::getQuestion() -> std::string {
    return "Gegeben ist eine Kugel mit dem Radius r = " + numberToString(radius, 0) + " cm. Gesucht ist die Oberfläche und das Volumen.";
}

auto TestItemStereoSphereSurfaceVolume::getRightAnswer() const -> std::string {
    double surfaceArea = 4.0 * M_PI * std::pow(radius, 2);
    double volume = 4.0 / 3.0 * M_PI * std::pow(radius, 3);
    return std::string("A = ") + numberToString(surfaceArea, 2) + " cm²; V = " + numberToString(volume, 2) + " cm³";
}

auto TestItemStereoSphereSurfaceVolume::checkAnswer(const std::string &answer) -> CheckAnswerResult {
    auto rightAnswer = getRightAnswer();
    return {answer == rightAnswer, rightAnswer};
}
} // namespace com::prog::testthebest