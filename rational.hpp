#include <stdexcept>
#include <iostream>
using std::ostream;
using std::istream;

class Rational {
private:
    int numerator = 0;
    int denomator = 1;

public:
    Rational() = default;
    static int doubleBase;
    Rational(int numerator, int denomator) {
        this->numerator = numerator;
        if (denomator == 0){
            throw std::domain_error("denomator can not be 0");
        }
        this->denomator = denomator;

        simplifiedFraction();
        checkIfDenIsNeg();
    }

    //Getters
    int num() const { return numerator;   }
    int den() const { return denomator;   }

    //Setters
    void num(int numerator) {this->numerator = numerator;}
    void den(int denomator) {this->denomator = denomator;}

    //Math Operators
    Rational operator +(Rational const& rhs) const;
    Rational operator -(Rational const& rhs) const;
    Rational operator *(Rational const& rhs) const;
    Rational operator /(Rational const& rhs) const;

    //Math Assignment Operators
    Rational& operator +=(Rational const& rhs);
    Rational& operator -=(Rational const& rhs);
    Rational& operator *=(Rational const& rhs);
    Rational& operator /=(Rational const& rhs);

    //Compare Operators
    bool operator ==(Rational const& rhs) const;
    bool operator !=(Rational const& rhs) const;
    bool operator < (Rational const& rhs) const;
    bool operator > (Rational const& rhs) const;
    bool operator >=(Rational const& rhs) const;
    bool operator <=(Rational const& rhs) const;

    //Uniary minus
    Rational operator -() const;

    //Prefix Math Assignment Operators
    Rational& operator ++();
    Rational& operator --();

    //Postfix Math Assignment Operators
    Rational operator ++(int);
    Rational operator --(int);

    //Conversion Operators
    operator double() const;
    operator int() const;
    Rational(int const& other);
    Rational(double other);


    //HELPER FUNCTIONS
    void simplifiedFraction();
    void checkIfDenIsNeg();
    int gcd(int numerator, int denomator);
    ostream& print(ostream& out) const;
    istream& scan(istream& in);
};

//Stream operators
inline ostream& operator <<(ostream& out, Rational const& frac) { return frac.print(out);}
inline istream& operator >>(istream& in, Rational& r) {return r.scan(in);}