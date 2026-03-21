#include "TestItemListFactoryImpl.h"
#include "TestItemFactoryImpl.h"

namespace com::prog::testthebest {
TestItemListFactoryImpl::TestItemListFactoryImpl() : testItemFactory{std::make_shared<TestItemFactoryImpl>()} {}

auto TestItemListFactoryImpl::getNumOfItems(const TestItemListFactory::Configuration &config, TestItemFactory::Type type) -> uint8_t {
    switch (type) {
    case TestItemFactory::Type::ADDITION: {
        return config.numOfAddition;
    }
    case TestItemFactory::Type::MC_ADDITION: {
        return config.numOfMcAddition;
    }
    case TestItemFactory::Type::MC_STEREO_SPHERE_VOLUME: {
        return config.numOfMcStereoSphereVolume;
    }
    default: {
        return 0;
    }
    }
}

auto TestItemListFactoryImpl::createTestItemList(TestItemListFactory::Configuration config) -> std::vector<std::shared_ptr<KnowledgeTestItem>> {
    std::vector<std::shared_ptr<KnowledgeTestItem>> listAll;
    for (uint8_t type = 0; type < static_cast<uint8_t>(TestItemFactory::Type::MAX_TYPE); ++type) {
        auto num = getNumOfItems(config, static_cast<TestItemFactory::Type>(type));
        std::vector<std::shared_ptr<TestItem>> list;
        for (int8_t i = 0; i < num; ++i) {
            bool found;
            do {
                auto item = testItemFactory->createTestItem(static_cast<TestItemFactory::Type>(type));
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