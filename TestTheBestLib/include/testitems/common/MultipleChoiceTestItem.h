#pragma once

#include "MathUtils.h"
#include "TestItem.h"
#include <memory>

namespace com::prog::testthebest {
template <class T> class MultipleChoiceTestItem : public TestItem {
  public:
    MultipleChoiceTestItem() {
        while (testItemList.size() < numOfChoices) {
            auto const item = std::make_shared<T>();
            bool found = false;
            for (auto const &it : testItemList) {
                if (it->equals(*item)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                continue;
            }
            testItemList.emplace_back(item);
        }
        rightSelection = createRandomNumber<uint8_t>(1, testItemList.size());
    };

    [[nodiscard]] auto getMaxNumOfQuestions() const -> uint16_t override { return testItemList.at(rightSelection - 1)->getMaxNumOfQuestions(); };

    [[nodiscard]] auto getSelectedItemQuestion() const -> std::string { return testItemList.at(rightSelection - 1)->getQuestion(); }

    [[nodiscard]] auto equals(const TestItem &other) const -> bool override {
        auto otherItem = dynamic_cast<const MultipleChoiceTestItem<T> &>(other);
        return getSelectedItemQuestion() == otherItem.getSelectedItemQuestion();
    };

    [[nodiscard]] auto getQuestion() const -> std::string override {
        std::string question = testItemList.at(rightSelection - 1)->getQuestion() + "\n";
        for (uint8_t i = 1; i <= testItemList.size(); ++i) {
            question += std::to_string(i) + ". " + testItemList.at(i - 1)->getRightAnswer() + "\n";
        }
        return question;
    };

    auto getRightAnswer() const -> std::string override { return std::to_string(rightSelection); };

    auto checkAnswer(const std::string &answer) -> CheckAnswerResult override {
        bool ok = (answer == std::to_string(rightSelection)) || (answer == std::to_string(rightSelection) + ".");
        std::string rightAnswer = std::to_string(rightSelection) + ". " + testItemList.at(rightSelection - 1)->getRightAnswer();
        return {.ok = ok, .rightAnswer = rightAnswer};
    };

  private:
    static constexpr uint32_t numOfChoices = 4;
    std::vector<std::shared_ptr<T>> testItemList;
    uint8_t rightSelection = 1;
};
} // namespace com::prog::testthebest