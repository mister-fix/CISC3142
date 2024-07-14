#include "rational.h"
#include "rational_exception.h"
#include "gcd.h"
#include <iostream>

using namespace std;

// Constructor
Rational::Rational(int num, int denom) {
	if(denom == 0) throw RationalException("Cannot set denominator to 0");
	
	int val = gcd(num, denom);
	
	this->num = num / val;
	this->denom = denom / val;
}

// Add method
Rational Rational::add(const Rational &r) const {
	int numerator = r.denom * num + r.num * denom;
	int denominator = r.denom * denom;

	return Rational(numerator, denominator);
}

// Subtraction method
Rational Rational::sub(const Rational &r) const {
	int numerator = r.denom * num - r.num * denom;
	int denominator = r.denom * denom;

	return Rational(numerator, denominator);
}

// Multiplication method
Rational Rational::mul(const Rational &r) const {
	return Rational((r.num * num), (r.denom * denom));
}

// Division method
Rational Rational::div(const Rational &r) const {
	return Rational(r.denom * num, r.num * denom);
}

// Add in place method
Rational &Rational::addInPlace(const Rational &r) {
	Rational result = this->add(r);

	this->num = result.getNumerator();
	this->denom = result.getDenominator();
	
	return *this;
}

// Subtract in place method
Rational &Rational::subInPlace(const Rational &r) {
	Rational result = this->sub(r);

	this->num = result.getNumerator();
	this->denom = result.getDenominator();

	return *this;
}

// Multiply in place method
Rational &Rational::mulInPlace(const Rational &r) {
	Rational result = this->mul(r);

	this->num = result.getNumerator();
	this->denom = result.getDenominator();

	return *this;
}

// Divide in place method
Rational &Rational::divInPlace(const Rational &r) {
	Rational result = this->div(r);

	this->num = result.getNumerator();
	this->denom = result.getDenominator();

	return *this;
}

// Negate method
Rational Rational::neg() const {
	return Rational((-1) * num, denom);	
}

// Inverse method
Rational Rational::inv() const {
	return Rational(denom, num);	
}

// Get numerator
int Rational::getNumerator() const {
	return num;
}

// Get denominator
int Rational::getDenominator() const {
	return denom;
}

// Comparison method
int Rational::compareTo(const Rational &r) const {
	int top = num * r.getDenominator();
	int bottom = denom * r.getNumerator();
	
	if(top == bottom) return 0;
	else if(top < bottom) return -1;
	else return 1;
}

// Equals method
bool Rational::equals(const Rational &r) const {
	return num == r.num && denom == r.denom;
}

// Print method
void Rational::print(std::ostream &os) const {
	if(denom == 1) {
		os << num;
	}
	else {
		os << num << "/" << denom;
	}
}