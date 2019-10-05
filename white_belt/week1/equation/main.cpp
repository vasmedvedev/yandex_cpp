#include <iostream>
#include <cmath>

int main() {
    double a, b ,c, d, x, y;
    std::cin >> a >> b >> c;

    if (a == 0 && b == 0) {
        return 0;
    }

    if (a == 0) {
        std::cout << (0 - c) / b << std::endl;
        return 0;
    }

    d = (b * b) - (4 * a * c);

    if (d < 0) {
        return 0;
    } else if (d == 0) {
        std::cout << (-1 * b) / (2 * a) << std::endl;
    } else if (d > 0) {
        x = ((-1 * b) + sqrt(d)) / (2 * a);
        y = ((-1 * b) - sqrt(d)) / (2 * a);
        std::cout << x << ' ' << y << std::endl;
    }
    return 0;
}