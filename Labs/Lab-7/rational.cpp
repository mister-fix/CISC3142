#include <iostream>
#include "rational.h"
#include "rational_exception.h"
#include "gcd.h"

using namespace std;

// Constructor
Rational::Rational(int num, int denom) {
    if(denom == 0) {
        throw RationalException("Cannot set denominator to 0");
    }

    int val = gcd(num, denom);

    this->num = num / val;
    this->denom = denom / val;
}

// Add in place
Rational &Rational::operator +=(const Rational &r) {
    *this+(this, r); // Using addition function

    return *this;
}

// Subtract in place
Rational &Rational::operator -=(const Rational &r) {
    *this-(this, r); // Using subtraction function

    return *this;
}

// Multiply in place
Rational &Rational::operator *=(const Rational &r) {
    *this*(this, r); // Using multiplication function

    return *this;
}

// Divide in place
Rational &Rational::operator /=(const Rational &r) {
    *this/(this, r); // Using division function

    return *this;
}

// Negate
Rational Rational::operator-() const {
    return Rational(-num, denom);
}

// Inverse
Rational Rational::inv() const {
    return Rational(denom, num);
}

// Comparison
int Rational::compareTo(const Rational &r) const {
    float f1 = (float)num / (float)denom;
    float f2 = (float)r.num / (float)r.denom;

    if(f1 > f2) return 1;
    else if(f1 == f2) return 0;
    else return -1;
}

// Get numerator
int Rational::getNumerator() const {
    return num;
}

// Get denominator
int Rational::getDenominator() const {
    return denom;
}

// Print
void Rational::print(std::ostream &os) const {
    if(denom == 1) {
        os << num;
    }
    else {
        os << num << "/" << denom;
    }
}

// Addition
Rational operator+(const Rational &r1, const Rational &r2) {
    int num = r1.num * r2.denom + r1.denom * r2.num;
    int denom = r1.denom * r2.denom;
    int g = gcd(num, denom);

    return Rational(num, denom);
}

// Subtraction
Rational operator-(const Rational &r1, const Rational &r2) {
    int num = r1.num * r2.denom - r1.denom * r2.num;
    int denom = r1.denom * r2.denom;
    int g = gcd(num, denom);

    return Rational(num, denom);
}

// Multiplication
Rational operator*(const Rational &r1, const Rational &r2) {
    int num = r1.num * r2.num;
    int denom = r1.denom * r2.denom;

    return Rational(num, denom);
}

// Division
Rational operator/(const Rational &r1, const Rational &r2) {
    int num = r1.num * r2.denom;
    int denom = r1.denom * r2.num;

    return Rational(num, denom);
}

// Equals
bool operator==(const Rational &r1, const Rational &r2) {
    return r1.num == r2.num && r1.denom == r2.denom;
}

// istream
std::istream &operator>>(std::istream &is, Rational &r) {
    int num, denom = 1;
    char t;

    is >> num;
    is.get(t);

    if(!is.eof()) {
        if(t == '/') is >> denom;
        else is.putback(t);
    }

    r = Rational(num, denom);

    return is;
}

// ostream
std::ostream &operator<<(std::ostream &os, const Rational &r) {
    r.print(os);

    return os;
}