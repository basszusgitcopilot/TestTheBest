#include "TestItemListFactoryImpl.h"
#include "TestItemFactoryImpl.h"

namespace com::prog::testthebest {
TestItemListFactoryImpl::TestItemListFactoryImpl() : testItemFactory{std::make_shared<TestItemFactoryImpl>()} {}

auto TestItemListFactoryImpl::createTestItemList(TestItemListFactory::Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> {
    std::vector<std::shared_ptr<KnowledgeTestItem>> listAll;
    {
        std::vector<std::shared_ptr<TestItem>> list;
        for (int8_t i = 0; i < config.numOfAddition; ++i) {
            bool found;
            do {
                auto item = testItemFactory->createTestItem(TestItemFactory::Type::ADDITION);
                found = false;
                for (const auto &it : list) {
                    if (*it == *item) {
                        found;
                    }
                }
                if (!found) {
                    list.push_back(item);
                    break;
                }
            } while (true);
        }
        listAll.insert(std::end(listAll), std::begin(list), std::end(list));
    }
    return listAll;
}
} // namespace com::prog::testthebest