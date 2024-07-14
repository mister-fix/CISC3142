#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
    public:
        // Arg constructor
        Rational(int = 0, int = 1);

        // Single arg constructor
        Rational(int num) {
            this->num = num;
            this->denom = 1;
        };

        Rational add(const Rational&) const;
        Rational sub(const Rational&) const;
        Rational mul(const Rational&) const;
        Rational div(const Rational&) const;

        Rational &addInPlace(const Rational&);
        Rational &subInPlace(const Rational&);
        Rational &mulInPlace(const Rational&);
        Rational &divInPlace(const Rational&);

        Rational neg() const;
        Rational inv() const;
        
        int getNumerator() const;
        int getDenominator() const;
        
        int compareTo(const Rational&) const;
        bool equals(const Rational&) const;

        // To string method
        void print(std::ostream &os) const;

    private:
        int num;
        int denom;
};

inline std::ostream &operator << (std::ostream &os, const Rational &r) {
    r.print(os);

    return os;
}

#endif