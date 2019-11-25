#include <iostream>
#include <vector>
#include <map>
#include <set>

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

Rational operator* (const Rational& l, const Rational& r) {
    return Rational(l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator());
}

Rational operator/ (const Rational& l, const Rational& r) {
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
    {
        const std::set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            std::cout << "Wrong amount of items in the set" << std::endl;
            return 1;
        }

        std::vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            std::cout << "Rationals comparison works incorrectly" << std::endl;
            return 2;
        }
    }

    {
        std::map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            std::cout << "Wrong amount of items in the map" << std::endl;
            return 3;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}