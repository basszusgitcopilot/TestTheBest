#include <fstream>
#include <iostream>

int main(int argc, char **args) {
    std::cout << "Starting CodeGen..." << std::endl;

    if (argc != 2) {
        std::cerr << "Number of arguments invalid: " << argc << std::endl;
    }

    // std::ofstream dialogstream;
    // dialogstream.open(fileName);
    // dialogstream.close();

    std::cout << "CodeGen finished." << std::endl;
}