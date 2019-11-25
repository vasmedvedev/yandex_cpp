#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    int n, m;
    int s = 0;
    std::ifstream input("input.txt");
    input >> n >> m;

    for(size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            input >> s;
            input.ignore(1);
            std::cout <<  std::setw(10) << s;
            if (j != m - 1) {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
    return 0;
}