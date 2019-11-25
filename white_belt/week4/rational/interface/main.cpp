#include <iostream>

int gcd(int x, int y) {
    do
    {
        int t = x % y;
        x = y;
        y = t;
    } while (y);
    return x;
}


class Rational {
public:
    Rational() {
        _numerator = 0;
        _denominator = 1;
    }

    Rational(int numerator, int denominator) {
        if (numerator == 0) {
            _numerator = 0;
            _denominator = 1;
            return;
        }

        bool negative = denominator * numerator < 0;
        int div = gcd(numerator, denominator);
        int sign = negative ? -1 : 1;

        _numerator = abs(numerator / div) * sign;
        _denominator = abs(denominator / div);
    }

    int Numerator() const {
        return _numerator;
    }

    int Denominator() const {
        return _denominator;
    }

private:
    int _numerator;
    int _denominator;
};

int main() {

    std::cout << "OK" << std::endl;
    return 0;
}
