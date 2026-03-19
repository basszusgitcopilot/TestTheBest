#pragma once

#include "KnowledgeTestItem.h"

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestItem : public KnowledgeTestItem {
public:    
    bool operator==(const TestItem& other){return true;}
};
}