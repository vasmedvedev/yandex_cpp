#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> container;
    int count;
    int number;
    std::cin >> count;

    for (int i = 0; i < count; ++i) {
        std::cin >> number;
        container.push_back(number);
    }
    std::sort(container.begin(), container.end(), [](int a, int b){
        a *= (a < 0) ? -1 : 1;
        b *= (b < 0) ? -1 : 1;
        return a < b;
    });
    for (const auto& n : container) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;
    return 0;
}