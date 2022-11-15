#include "rational.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::ios;

int Rational::doubleBase = 1000000;

int Rational::gcd(int numerator, int denomator) {
    if ( numerator == 0)
        return denomator;
    return gcd(denomator % numerator, numerator);
}

void Rational::simplifiedFraction() {
    int _gcd = gcd(this->num(), this->den());
    int newNum = this->num() / _gcd;
    int newDen = this->den() / _gcd;
    this->num(newNum);
    this->den(newDen);
}

void Rational::checkIfDenIsNeg() {
    if(this->den() < 0) {
        this->den(this->den() * -1);
        int newNum = this->num() * -1;
        this->num(newNum);
    }
}

ostream& Rational::print(ostream& out) const {
    if(this->den() == 1) {
        return cout << this->num() << endl;
    }
    else {
        return cout << this->num() << "/" << this->den() << endl;
    }
}

istream& Rational::scan(istream& in){
    char slash;

    in >> numerator;
    if (in >> slash && slash != '/') {
        in.putback(slash);
        in.setstate(ios::failbit);
    }
    in >> denomator;

    return in;
}

Rational Rational::operator*(const Rational &rhs) const {
    Rational u;
    int num = this->num() * rhs.num();
    int den = this->den() * rhs.den();

    u.num(num);
    u.den(den);

    u.simplifiedFraction();
    u.checkIfDenIsNeg();

    return u;
}

Rational Rational::operator/(const Rational &rhs) const {
    Rational u;
    if(rhs.den() == 0) {
        throw std::domain_error("denomator can not be 0");
    }

    int num = this->num() * rhs.den();
    int den = this->den() * rhs.num();

    u.num(num);
    u.den(den);

    u.simplifiedFraction();
    u.checkIfDenIsNeg();
    return u;
}

Rational Rational::operator-() const {
    Rational u;
    int num = this->num() * -1;
    int den = this->den();

    u.num(num);
    u.den(den);
    return u;
}

Rational Rational::operator+(const Rational &rhs) const {
    Rational u;

    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    u.num(lhsNum + rhsNum);
    u.den(lhsDen);

    u.simplifiedFraction();
    u.checkIfDenIsNeg();
    return u;
}

Rational Rational::operator-(const Rational &rhs) const {
    Rational u;

    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    u.num(lhsNum - rhsNum);
    u.den(lhsDen);

    u.simplifiedFraction();
    u.checkIfDenIsNeg();
    return u;
}

Rational &Rational::operator+=(const Rational &rhs) {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    int newNum = lhsNum + rhsNum;

    this->num(newNum);
    this->den(rhsDen);

    simplifiedFraction();
    checkIfDenIsNeg();
    return *this;
}

Rational &Rational::operator-=(const Rational &rhs) {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    int newNum = lhsNum - rhsNum;

    this->num(newNum);
    this->den(lhsDen);

    simplifiedFraction();
    checkIfDenIsNeg();
    return *this;
}

Rational &Rational::operator*=(const Rational &rhs) {
    int num = this->num() * rhs.num();
    int den = this->den() * rhs.den();

    this->num(num);
    this->den(den);

    simplifiedFraction();
    checkIfDenIsNeg();
    return *this;
}

Rational &Rational::operator/=(const Rational &rhs) {
    if(rhs.den() == 0) {
        throw std::domain_error("denomator can not be 0");
    }

    int num = this->num() * rhs.den();
    int den = this->den() * rhs.num();

    this->num(num);
    this->den(den);

    simplifiedFraction();
    checkIfDenIsNeg();
    return *this;
}

Rational &Rational::operator++() {
    Rational rhs {1,1};

    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    int newNum = lhsNum + rhsNum;

    this->num(newNum);
    this->den(rhsDen);

    return *this;
}

Rational Rational::operator++(int) {
    Rational rhs {1,1};

    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    int newNum = lhsNum + rhsNum;

    this->num(newNum);
    this->den(rhsDen);

    return *this;
}

Rational &Rational::operator--() {
    Rational rhs {1,1};
    Rational rt = {this->num(), this->den()};
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    int newNum = lhsNum - rhsNum;

    this->num(newNum);
    this->den(rhsDen);

    return rt;
}

Rational Rational::operator--(int) {
    Rational rhs {1,1};
    Rational rt = {this->num(), this->den()};
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    int newNum = lhsNum - rhsNum;

    this->num(newNum);
    this->den(rhsDen);

    return rt;
}

bool Rational::operator==(const Rational &rhs) const {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    if(lhsNum == rhsNum) { return true; }
    else { return false; }
}

bool Rational::operator!=(const Rational &rhs) const {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    if(lhsNum != rhsNum) { return true; }
    else { return false; }
}

bool Rational::operator<(const Rational &rhs) const {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    if(lhsNum < rhsNum) { return true; }
    else { return false; }
}

bool Rational::operator>(const Rational &rhs) const {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    if(lhsNum > rhsNum) { return true; }
    else { return false; }
}

bool Rational::operator>=(const Rational &rhs) const {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    if(lhsNum >= rhsNum) { return true; }
    else { return false; }
}

bool Rational::operator<=(const Rational &rhs) const {
    int lhsNum = this->num() * rhs.den();
    int lhsDen = this->den() * rhs.den();

    int rhsNum = rhs.num() * this->den();
    int rhsDen = rhs.den() * this->den();

    if(lhsNum <= rhsNum) { return true; }
    else { return false; }
}


Rational::operator int() const {
    return this->num() / this->den();
}

Rational::operator double() const {
    return double(this->num() / double(this->den()));
}

Rational::Rational(const int& other) {
    this->num(other);
    this->den(1);
}

Rational::Rational(double other) {
    this->num(other * doubleBase);
    this->den(this->den() * doubleBase);

    simplifiedFraction();
    checkIfDenIsNeg();
}
