#include <iostream>
#include <vector>

int main() {
    int decimal;
    std::string binary;
    std::vector<unsigned short int> digits;
    std::cin >> decimal;

    while (decimal != 0) {
        digits.push_back(decimal % 2);
        decimal /= 2;
    }

    for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
        std::cout << *it;
    }

    return 0;
}