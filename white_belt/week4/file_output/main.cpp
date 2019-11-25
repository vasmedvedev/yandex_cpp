#include <iostream>
#include <fstream>


int main() {
    std::ofstream output("output.txt");
    std::ifstream input("input.txt");
    std::string line;
    if (input) {
        while (getline(input, line)) {
            output << line << std::endl;
        }
    } else {
        std::cout << "Error!" << std::endl;
    }
    return 0;
}
