#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
// using namespace ariel;

/*----constructors----*/
Fraction::Fraction(const int &numerator, const int &denominator) : _numerator(numerator), _denominator(denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("denominator can't be equals to 0");
    }
    int reducer = gcd(numerator, denominator);
    this->_numerator = numerator / reducer;
    this->_denominator = denominator / reducer;
}
/*--------------------*/

int Fraction::gcd(int num1, int num2)
{ // took this function from google.
    if (num2 == 0)
    {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

Fraction Fraction::operator+(const float &second_num)
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    return (*this + temp);        // fra + fra
}
Fraction Fraction::operator+(const Fraction &second_num)
{
    int left_top = this->_numerator * second_num._denominator;  // calc the left numerator
    int rigth_top = this->_denominator * second_num._numerator; // calc the right numerator
    int top = left_top + rigth_top;                             // combine numerators
    int bottom = this->_denominator * second_num._denominator;  // make new denominator
    int reducer = gcd(top, bottom);                             // find gcd and reduce
    top = top / reducer;
    bottom = bottom / reducer;
    return Fraction(top, bottom); // fra + fra
}
Fraction operator+(const float &first_num, const Fraction &second_num)
{
    int num1 = first_num * 1000;
    Fraction temp(num1, 1000);
    return (temp + second_num); // fra + fra
}

Fraction Fraction::operator-(const float &second_num)
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    return (*this - temp);        // fra - fra
}
Fraction Fraction::operator-(const Fraction &second_num)
{
    int left_top = this->_numerator * second_num._denominator;  // calc the left numerator
    int rigth_top = this->_denominator * second_num._numerator; // calc the right numerator
    int top = left_top - rigth_top;                             // combine numerators
    int bottom = this->_denominator * second_num._denominator;  // make new denominator
    int reducer = gcd(top, bottom);                             // find gcd and reduce
    top = top / reducer;
    bottom = bottom / reducer;
    return Fraction(top, bottom); // fra - fra
}
Fraction operator-(const float &first_num, const Fraction &second_num)
{
    int num1 = first_num * 1000;
    Fraction temp(num1, 1000);
    return (temp - second_num); // fra - fra
}

Fraction Fraction::operator*(const float &second_num)
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    return (*this * temp);        // fra * fra
}
Fraction Fraction::operator*(const Fraction &second_num)
{
    int top = this->_numerator * second_num._numerator;        // combine numerators
    int bottom = this->_denominator * second_num._denominator; // make new denominator
    int reducer = gcd(top, bottom);                            // find gcd and reduce
    top = top / reducer;
    bottom = bottom / reducer;
    return Fraction(top, bottom); // fra * fra
}
Fraction operator*(const float &first_num, const Fraction &second_num)
{
    int num1 = first_num * 1000;
    Fraction temp(num1, 1000);
    return (temp * second_num); // fra * fra
}

Fraction Fraction::operator/(const float &second_num)
{
    if (second_num == 0)
    {
        throw invalid_argument("can't devide by 0");
    }
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    return (*this / temp);        // fra / fra
}
Fraction Fraction::operator/(const Fraction &second_num)
{
    if (second_num._numerator == 0)
    {
        throw invalid_argument("can't devide by 0");
    }
    int top = this->_numerator * second_num._denominator;    // combine numerators
    int bottom = this->_denominator * second_num._numerator; // make new denominator
    int reducer = gcd(top, bottom);                          // find gcd and reduce
    top = top / reducer;
    bottom = bottom / reducer;
    return Fraction(top, bottom); // fra / fra
}
Fraction operator/(const float &first_num, const Fraction &second_num) {
    int num1 = first_num * 1000;
    Fraction temp(num1, 1000);
    return (temp / second_num); // fra / fra
}

bool Fraction::operator==(float second_num) { return false; }
bool Fraction::operator==(Fraction second_num) { return false; }
bool operator==(float first_num, Fraction second_num) { return false; }

bool Fraction::operator>(float second_num) { return true; }
bool Fraction::operator>(Fraction second_num) { return true; }
bool operator>(float first_num, Fraction second_num) { return true; }

bool Fraction::operator<(float second_num) { return true; }
bool Fraction::operator<(Fraction second_num) { return true; }
bool operator<(float first_num, Fraction second_num) { return true; }

bool Fraction::operator>=(float second_num) { return true; }
bool Fraction::operator>=(Fraction second_num) { return true; }
bool operator>=(float first_num, Fraction second_num) { return true; }

bool Fraction::operator<=(float second_num) { return true; }
bool Fraction::operator<=(Fraction second_num) { return true; }
bool operator<=(float first_num, Fraction second_num) { return true; }

Fraction &Fraction::operator++()
{                                                             // prefix - ++n.
    this->_numerator = this->_numerator + this->_denominator; // add 1
    int reducer = gcd(this->_numerator, this->_denominator);  // find gcd
    this->_numerator = this->_numerator / reducer;            // reduction
    this->_denominator = this->_denominator / reducer;        // reduction
    return *this;
}
const Fraction Fraction::operator++(int)
{                          // postfix - n++.
    Fraction copy = *this; // make a copy
    ++*this;               // add 1
    return copy;           // return the copy
}

Fraction &Fraction::operator--()
{                                                             // prefix - ++n.
    this->_numerator = this->_numerator - this->_denominator; // add 1
    int reducer = gcd(this->_numerator, this->_denominator);  // find gcd
    this->_numerator = this->_numerator / reducer;            // reduction
    this->_denominator = this->_denominator / reducer;        // reduction
    return *this;
}
const Fraction Fraction::operator--(int)
{                          // postfix - n++.
    Fraction copy = *this; // make a copy
    --*this;               // add 1
    return copy;           // return the copy
}

ostream &operator<<(ostream &output, const Fraction &fraction) { return output; }
istream &operator>>(istream &input, Fraction &fraction) { return input; }
