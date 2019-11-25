#include <iostream>
#include <sstream>

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

std::ostream& operator<< (std::ostream& s, const Rational& r) {
    s << r.Numerator() << '/' << r.Denominator();
    return s;
}

std::istream& operator>> (std::istream& s, Rational& r) {
    if (s.peek() == EOF) {
        return s;
    }
    long numerator;
    long denominator;
    s >> numerator;
    s.ignore(1);
    s >> denominator;
    r = Rational(numerator, denominator);
    return s;
}


int main() {
    {
        std::ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
            return 1;
        }
    }

    {
        std::istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            std::cout << "5/7 is incorrectly read as " << r << std::endl;
            return 2;
        }
    }

    {
        std::istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << std::endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            std::cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << std::endl;
            return 4;
        }
    }

    std::cout << "OK" << std::endl;
    return 0;
}