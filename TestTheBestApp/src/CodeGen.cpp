#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto getTestItemNames(std::string path) -> std::vector<std::string> {
    std::vector<std::string> result;
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            result.emplace_back(entry.path().stem().string().substr(std::string("TestItem").length()));
        }
    }
    std::sort(result.begin(), result.end());
    return result;
}

auto toScreamingSnakeCase(std::string text) -> std::string {
    std::string result;

    for (int32_t i = 0; i < text.length(); ++i) {
        if (i > 0 && text.at(i) == std::toupper(text.at(i))) {
            result.append("_");
        }
        result += text.at(i);
    }
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

auto generateProperties(const std::string &path, const std::vector<std::string> &names) -> void {
    std::ofstream dialogstream;
    dialogstream.open(path);

    for (const auto &name : names) {
        dialogstream << "numOf" << name << "=1" << std::endl;
    }

    dialogstream.close();
}

auto generateGenTestConfigurationH(const std::string &path, const std::vector<std::string> &names) -> void {
    std::ofstream dialogstream;
    dialogstream.open(path);

    dialogstream <<
        R"(#pragma once

#include <cstdint>

namespace com::prog::testthebest {
struct TestConfiguration {)"
                 << std::endl;

    for (const auto &name : names) {
        dialogstream << "    uint8_t numOf" << name << " = 0;" << std::endl;
    }

    dialogstream <<
        R"(};
} // namespace com::prog::testthebest
)";

    dialogstream.close();
}

auto generateGenTestItemTypeH(const std::string &path, const std::vector<std::string> &names) -> void {
    std::ofstream dialogstream;
    dialogstream.open(path);

    dialogstream <<
        R"(#pragma once

namespace com::prog::testthebest {
enum class TestItemType {
)";

    bool first = true;
    for (const auto &name : names) {
        dialogstream << "    " << toScreamingSnakeCase(name);
        if (first) {
            dialogstream << " = 0";
            first = false;
        }
        dialogstream << "," << std::endl;
    }

    dialogstream <<
        R"(    MAX_TYPE
};
} // namespace com::prog::testthebest)";

    dialogstream.close();
}

auto generateGenTestItemFactoryImplCpp(const std::string &path, const std::vector<std::string> &names) -> void {
    std::ofstream dialogstream;
    dialogstream.open(path);

    dialogstream <<
        R"(#include "TestItemFactoryImpl.h"

#include "MultipleChoiceTestItem.h"
)";

    for (const auto &name : names) {
        dialogstream << "#include \"TestItem" << name << ".h\"" << std::endl;
    }

    dialogstream <<
        R"(
namespace com::prog::testthebest {
auto TestItemFactoryImpl::createTestItem(const TestItemType TestItemType) -> std::shared_ptr<TestItem> {
    switch (TestItemType) {
)";

    for (const auto &name : names) {
        dialogstream << "    case TestItemType::" << toScreamingSnakeCase(name) << ": {" << std::endl;
        dialogstream << "        return std::make_shared<MultipleChoiceTestItem<TestItem" << name << ">>();" << std::endl;
        dialogstream << "    }" << std::endl;
    }

    dialogstream <<
        R"(    default: {
        return nullptr;
    }
    }
}
} // namespace com::prog::testthebest)";

    dialogstream.close();
}

auto generateGenTestItemListFactoryCpp(const std::string &path, const std::vector<std::string> &names) -> void {
    std::ofstream dialogstream;
    dialogstream.open(path);

    dialogstream <<
        R"(#include "TestItemListFactory.h"
#include <iostream>
namespace com::prog::testthebest {
auto TestItemListFactory::fillConfigurationValue(TestConfiguration &configuration, std::string propertyName, uint8_t propertyValue) -> void {
)";

    for (const auto &name : names) {
        dialogstream << "    if (propertyName == \"numOf" << name << "\") {" << std::endl;
        dialogstream << "        configuration.numOf" << name << " = propertyValue;" << std::endl;
        dialogstream << "        return;" << std::endl;
        dialogstream << "    }" << std::endl;
    }

    dialogstream <<
        R"(    std::cerr << "ERROR: unknown property name: " << propertyName << std::endl;
}
} // namespace com::prog::testthebest)";

    dialogstream.close();
}

auto generateGenTestItemListFactoryImplCpp(const std::string &path, const std::vector<std::string> &names) -> void {
    std::ofstream dialogstream;
    dialogstream.open(path);

    dialogstream <<
        R"(#include "TestItemListFactoryImpl.h"
namespace com::prog::testthebest {
auto TestItemListFactoryImpl::getNumOfItems(const TestConfiguration &config, TestItemType type) -> uint8_t {
    switch (type) {
)";

    for (const auto &name : names) {
        dialogstream << "    case TestItemType::" << toScreamingSnakeCase(name) << ": {" << std::endl;
        dialogstream << "        return config.numOf" << name << ";" << std::endl;
        dialogstream << "    }" << std::endl;
    }

    dialogstream <<
        R"(    default: {
        return 0;
    }
    }
}
} // namespace com::prog::testthebest)";

    dialogstream.close();
}

int main(int argc, char **args) {
    std::cout << "Starting CodeGen..." << std::endl;

    if (argc != 2) {
        std::cerr << "Number of arguments invalid: " << argc << std::endl;
    }

    std::string rootPath(args[1]);
    std::string testItemsPath(rootPath + "/TestTheBestApp/include/testitems/");
    auto itemNames = getTestItemNames(testItemsPath);
    generateProperties(rootPath + "/TestTheBest.properties", itemNames);
    generateGenTestConfigurationH(rootPath + "/TestTheBestApp/include/testfactories/gen/GenTestConfiguration.h", itemNames);
    generateGenTestItemTypeH(rootPath + "/TestTheBestApp/include/testfactories/gen/GenTestItemType.h", itemNames);
    generateGenTestItemFactoryImplCpp(rootPath + "/TestTheBestApp/src/testfactories/gen/GenTestItemFactoryImpl.cpp", itemNames);
    generateGenTestItemListFactoryCpp(rootPath + "/TestTheBestApp/src/testfactories/gen/GenTestItemListFactory.cpp", itemNames);
    generateGenTestItemListFactoryImplCpp(rootPath + "/TestTheBestApp/src/testfactories/gen/GenTestItemListFactoryImpl.cpp", itemNames);

    std::cout << "CodeGen finished." << std::endl;
}