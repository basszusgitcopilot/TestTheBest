#include "TestItemListFactory.h"
#include <fstream>
#include <iostream>

namespace com::prog::testthebest {
auto TestItemListFactory::readConfigurationFromFile(std::string fileName) -> TestConfiguration {
    std::ifstream propertiesFile;
    propertiesFile.open(fileName);
    if (!propertiesFile.is_open()) {
        std::cerr << "ERROR: cannot open file " << fileName << std::endl;
    }

    TestConfiguration configuration;
    std::string line;
    while (std::getline(propertiesFile, line)) {

        if (line.empty() || line.find('#') != std::string::npos) {
            continue;
        }
        auto pos = line.find('=');
        if (pos == std::string::npos) {
            continue;
        }
        if (pos == 0) {
            continue;
        }
        if (pos == line.length() - 1) {
            continue;
        }
        auto propName = line.substr(0, pos);
        auto propValueStr = line.substr(pos + 1, pos);
        try {
            uint8_t propValueInt = std::stoi(propValueStr);
            fillConfigurationValue(configuration, propName, propValueInt);
        } catch (std::exception const &e) {
            std::cerr << "ERROR: cannot parse value: " << line << std::endl;
            continue;
        }
    }
    propertiesFile.close();

    return configuration;
}
} // namespace com::prog::testthebest