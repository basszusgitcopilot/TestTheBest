#include "TestDialogFactoryImpl.h"
#include "KnowledgeTestDialogImpl.h"
#include "TestItemListFactoryImpl.h"

namespace com::prog::testthebest {
TestDialogFactoryImpl::TestDialogFactoryImpl() : m_testItemListFactory{std::make_shared<TestItemListFactoryImpl>()} {}
auto TestDialogFactoryImpl::createTestDialog() -> std::shared_ptr<KnowledgeTestDialog> {
    auto testDialog = std::make_shared<KnowledgeTestDialogImpl>();
    auto listItems = m_testItemListFactory->createTestItemList({
        .numOfAddition = 0,                        //
        .numOfMcAddition = 0,                      //
        .numOfMcAlgebraLinearFactorization = 0,    //
        .numOfMcAlgebraLinearFactorization3 = 1,   //
        .numOfMcAlgebraQuadraticEquation = 0,      //
        .numOfMcStochasticCombination = 0,         //
        .numOfMcStereoSphereSurfaceAreaVolume = 0, //
        .numOfMcStereoSphereVolume = 0,            //
    });
    testDialog->addTestItems(listItems);
    return testDialog;
}
}; // namespace com::prog::testthebest