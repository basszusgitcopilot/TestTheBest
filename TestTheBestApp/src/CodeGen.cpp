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

int main(int argc, char **args) {
    std::cout << "Starting CodeGen..." << std::endl;

    if (argc != 2) {
        std::cerr << "Number of arguments invalid: " << argc << std::endl;
    }

    auto itemNames = getTestItemNames(args[1]);
    for (const auto &name : itemNames) {
        std::cout << toScreamingSnakeCase(name) << std::endl;
    }

    // std::ofstream dialogstream;
    // dialogstream.open(fileName);
    // dialogstream.close();

    std::cout << "CodeGen finished." << std::endl;
}