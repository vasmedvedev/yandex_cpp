#include <iostream>

int Factorial(int x) {
    if (x < 0) {
        return 1;
    }
    int result = 1;
    for(int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int x;
    std::cin >> x;
    std::cout << Factorial(x);
    return 0;
}