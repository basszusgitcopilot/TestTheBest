#include "TestDialogFactoryImpl.h"
#include "KnowledgeTestDialogImpl.h"
#include "TestItemListFactoryImpl.h"

namespace com::prog::testthebest {
TestDialogFactoryImpl::TestDialogFactoryImpl() : m_testItemListFactory{std::make_shared<TestItemListFactoryImpl>()} {}
auto TestDialogFactoryImpl::createTestDialog() -> std::shared_ptr<KnowledgeTestDialog> {
    auto testDialog = std::make_shared<KnowledgeTestDialogImpl>();
    auto listItems = m_testItemListFactory->createTestItemList({.numOfAddition = 2, .numOfMcAddition = 2});
    testDialog->addTestItems(listItems);
    return testDialog;
}
}; // namespace com::prog::testthebest