#pragma once

#include "TestItemListFactory.h"
#include "TestItemFactory.h"

using namespace com::prog::knowledgetest;

namespace com::prog::testthebest{
class TestItemListFactoryImpl: public TestItemListFactory{
public:    
    TestItemListFactoryImpl();
     auto createTestItemList(TestItemListFactory::Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> override;
private:
    std::shared_ptr<TestItemFactory> testItemFactory;
};
}