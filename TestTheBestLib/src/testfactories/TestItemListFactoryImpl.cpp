#include "TestItemListFactoryImpl.h"
#include "TestItemFactoryImpl.h"
#include <limits>

namespace com::prog::testthebest {
TestItemListFactoryImpl::TestItemListFactoryImpl() : testItemFactory{std::make_shared<TestItemFactoryImpl>()} {}
auto TestItemListFactoryImpl::createTestItemList(TestConfiguration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> {
    std::vector<std::shared_ptr<KnowledgeTestItem>> listAll;
    for (uint8_t type = 0; type < static_cast<uint8_t>(TestItemType::MAX_TYPE); ++type) {
        auto num = getNumOfItems(config, static_cast<TestItemType>(type));
        uint16_t maxNum = std::numeric_limits<uint16_t>::max();
        std::vector<std::shared_ptr<TestItem>> list;
        for (int8_t i = 0; i < num && i < maxNum; ++i) {
            bool found;
            do {
                auto item = testItemFactory->createTestItem(static_cast<TestItemType>(type));
                maxNum = item->getMaxNumOfQuestions();
                found = false;
                for (const auto &it : list) {
                    if (it->equals(*item)) {
                        found = true;
                        break;
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