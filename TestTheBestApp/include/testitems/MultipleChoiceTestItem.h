#pragma once

#include "TestItem.h"
#include "TestItemFactory.h"

namespace com::prog::testthebest {
template<class T>
class MultipleChoiceTestItem: public TestItem{
  public:
    MultipleChoiceTestItem(){
        
    };
    auto operator==(const TestItem& other) -> bool{
        const T otherItem = dynamic_cast<const T &>(other);
        return *this == otherItem;        
    };
    auto getQuestion() -> std::string{return "";};
    auto getRightAnswer() -> std::string {return "";};
    auto checkAnswer(const std::string &answer) -> CheckAnswerResult {return {};};
private:
    static constexpr int8_t numOfChoices = 4;
    std::vector<std::shared_ptr<T>> testItemList;
};
}