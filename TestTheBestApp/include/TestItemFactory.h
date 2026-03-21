#pragma once

#include <memory>
#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest{
class TestItemFactory{
public:    
    enum class Type{
        ADDITION = 0,
        MC_ADDITION
    };

    virtual auto createTestItem(const Type type) ->  std::shared_ptr<TestItem> = 0;
};
}