#include <iostream>

int main() {
    std::string s;
    const char f = 'f';
    std::cin >> s;
    unsigned short int counter = 0;
    unsigned long result = 0;

    for(unsigned long i = 0; i <= s.length(); ++i) {
        if (s[i] == f) {
            ++counter;
            if (counter == 2) {
                result = i;
            }
        }
    }

    switch(counter) {
        case 0:
            std::cout << -2;
            break;
        case 1:
            std::cout << -1;
            break;
        default:
            std::cout << result;
    }
    std::cout << std::endl;
    return 0;
}