#pragma once

#include <cstdint>
#include <memory>
#include "TestItem.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest{
class TestItemListFactory{
public:    
    struct Configuration{
        uint8_t numOfAddition;
        uint8_t numOfMcAddition;
    };

     virtual auto createTestItemList(Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> =0;
};
}