#include "TestItemListFactory.h"
#include <fstream>
#include <iostream>

namespace com::prog::testthebest {
auto TestItemListFactory::fillConfigurationValue(Configuration &configuration, std::string propertyName, uint8_t propertyValue) -> void {
    if (propertyName == "numOfAddition") {
        configuration.numOfAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfAddition") {
        configuration.numOfAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAddition") {
        configuration.numOfMcAddition = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAlgebraLinearFactorization") {
        configuration.numOfMcAlgebraLinearFactorization = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAlgebraLinearFactorization3") {
        configuration.numOfMcAlgebraLinearFactorization3 = propertyValue;
        return;
    }
    if (propertyName == "numOfMcAlgebraQuadraticEquation") {
        configuration.numOfMcAlgebraQuadraticEquation = propertyValue;
        return;
    }
    if (propertyName == "numOfMcIntegralRules") {
        configuration.numOfMcIntegralRules = propertyValue;
        return;
    }
    if (propertyName == "numOfMcDifferentialRules") {
        configuration.numOfMcDifferentialRules = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStereoSphereSurfaceAreaVolume") {
        configuration.numOfMcStereoSphereSurfaceAreaVolume = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStereoSphereVolume") {
        configuration.numOfMcStereoSphereVolume = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStochasticBernoulliExperiment") {
        configuration.numOfMcStochasticBernoulliExperiment = propertyValue;
        return;
    }
    if (propertyName == "numOfMcStochasticCombination") {
        configuration.numOfMcStochasticCombination = propertyValue;
        return;
    }
    std::cerr << "ERROR: unknown property name: " << propertyName << std::endl;
}

auto TestItemListFactory::readConfigurationFromFile(std::string fileName) -> Configuration {
    std::ifstream propertiesFile;
    propertiesFile.open(fileName);
    if (!propertiesFile.is_open()) {
        std::cerr << "ERROR: cannot open file " << fileName << std::endl;
    }

    Configuration configuration;
    std::string line;
    while (std::getline(propertiesFile, line)) {

        if (line.empty() || line.find('#') != line.npos) {
            continue;
        }
        auto pos = line.find('=');
        if (pos == line.npos) {
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
        } catch (std::exception e) {
            std::cerr << "ERROR: cannot parse value: " << line << std::endl;
            continue;
        }
    }
    propertiesFile.close();

    return configuration;
}
} // namespace com::prog::testthebest