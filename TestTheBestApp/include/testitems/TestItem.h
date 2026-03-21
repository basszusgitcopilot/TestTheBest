#pragma once

#include "KnowledgeTestItem.h"
#include <string>

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestItem : public KnowledgeTestItem {
public:    
    virtual auto operator==(const TestItem& other) -> bool = 0;
    virtual auto getRightAnswer() -> std::string = 0;
};
}