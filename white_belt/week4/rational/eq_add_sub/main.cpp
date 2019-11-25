#include <iostream>

long gcd(long x, long y) {
    do
    {
        long t = x % y;
        x = y;
        y = t;
    } while (y);
    return x;
}

long lcm(long x, long y) {
    long temp = gcd(x, y);
    return temp ? (x / temp * y) : 0;
}


class Rational {
public:
    Rational() {
        _numerator = 0;
        _denominator = 1;
    }

    Rational(long numerator, long denominator) {
        if (numerator == 0) {
            _numerator = 0;
            _denominator = 1;
            return;
        }

        bool negative = denominator * numerator < 0;
        long div = gcd(numerator, denominator);
        long sign = negative ? -1 : 1;

        _numerator = abs(numerator / div) * sign;
        _denominator = abs(denominator / div);
    }

    long Numerator() const {
        return _numerator;
    }

    long Denominator() const {
        return _denominator;
    }

private:
    long _numerator;
    long _denominator;
};

Rational operator+ (const Rational& l, const Rational& r) {
    long new_denominator = lcm(l.Denominator(), r.Denominator());
    long l_numerator = l.Numerator() * (new_denominator / l.Denominator());
    long r_numerator = r.Numerator() * (new_denominator / r.Denominator());
    return Rational(l_numerator + r_numerator, new_denominator);
}

Rational operator- (const Rational& l, const Rational& r) {
    long new_denominator = lcm(l.Denominator(), r.Denominator());
    long l_numerator = l.Numerator() * (new_denominator / l.Denominator());
    long r_numerator = r.Numerator() * (new_denominator / r.Denominator());
    return Rational(l_numerator - r_numerator, new_denominator);
}

bool operator== (const Rational& l, const Rational& r) {
    long new_denominator = lcm(l.Denominator(), r.Denominator());
    long l_numerator = l.Numerator() * (new_denominator / l.Denominator());
    long r_numerator = r.Numerator() * (new_denominator / r.Denominator());
    return l_numerator == r_numerator;
}


int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            std::cout << "4/6 != 2/3" << std::endl;
            return 1;
        }
    }
    {
        Rational a(-2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        std::cout << c.Numerator() << '/' << c.Denominator() << std::endl;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            std::cout << "2/3 + 4/3 != 2" << std::endl;
            return 2;
        }
    }
    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            std::cout << "5/7 - 2/9 != 31/63" << std::endl;
            return 3;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}