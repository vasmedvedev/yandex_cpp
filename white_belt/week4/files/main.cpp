#include <iostream>
#include <fstream>


int main() {
    std::ifstream input;
    input.open("input.txt");
    std::string line;
    if (input) {
        while (getline(input, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "Error!" << std::endl;
    }
    return 0;
}