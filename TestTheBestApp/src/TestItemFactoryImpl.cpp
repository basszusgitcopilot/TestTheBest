#include "TestItemFactoryImpl.h"

#include "TestItemAddition.h"
#include "TestItemFactory.h"

namespace com::prog::testthebest {
auto TestItemFactoryImpl::createTestItem(const Type type) -> std::shared_ptr<TestItem> {
    switch (type) {
    case Type::ADDITION: {
        return std::make_shared<TestItemAddition>();
    }
    default: {
        return nullptr;
    }
    }
}
} // namespace com::prog::testthebest