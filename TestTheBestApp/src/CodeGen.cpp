#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto getTestItemNames(std::string path) -> std::vector<std::string> {
    std::vector<std::string> result;
    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_regular_file()) {
            result.emplace_back(entry.path().stem());
        }
    }
    return result;
}

int main(int argc, char **args) {
    std::cout << "Starting CodeGen..." << std::endl;

    if (argc != 2) {
        std::cerr << "Number of arguments invalid: " << argc << std::endl;
    }

    auto itemNames = getTestItemNames(args[1]);
    for (const auto &name : itemNames) {
        std::cout << name << std::endl;
    }

    // std::ofstream dialogstream;
    // dialogstream.open(fileName);
    // dialogstream.close();

    std::cout << "CodeGen finished." << std::endl;
}