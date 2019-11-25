#include <iostream>
#include <stdexcept>

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
        if (denominator == 0) {
            throw std::invalid_argument("Zero division");
        }
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

Rational operator* (const Rational& l, const Rational& r) {
    return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/ (const Rational& l, const Rational& r) {
    if (r.Numerator() == 0) {
        throw std::domain_error("Zero division");
    }
    return Rational(l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator());
}

bool operator== (const Rational& l, const Rational& r) {
    long new_denominator = lcm(l.Denominator(), r.Denominator());
    long l_numerator = l.Numerator() * (new_denominator / l.Denominator());
    long r_numerator = r.Numerator() * (new_denominator / r.Denominator());
    return l_numerator == r_numerator;
}

bool operator< (const Rational& l, const Rational& r) {
    long new_denominator = lcm(l.Denominator(), r.Denominator());
    long l_numerator = l.Numerator() * (new_denominator / l.Denominator());
    long r_numerator = r.Numerator() * (new_denominator / r.Denominator());
    return l_numerator < r_numerator;
}


int main() {
    try {
        Rational r(1, 0);
        std::cout << "Doesn't throw in case of zero denominator" << std::endl;
        return 1;
    } catch (std::invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        std::cout << "Doesn't throw in case of division by zero" << std::endl;
        return 2;
    } catch (std::domain_error&) {
    }

    std::cout << "OK" << std::endl;
    return 0;
}