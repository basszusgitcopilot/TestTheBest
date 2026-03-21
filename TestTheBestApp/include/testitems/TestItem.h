#pragma once

#include "KnowledgeTestItem.h"

using namespace com::prog::knowledgetest;
namespace com::prog::testthebest {
class TestItem : public KnowledgeTestItem {
public:    
    virtual bool operator==(const TestItem& other) = 0;
};
}