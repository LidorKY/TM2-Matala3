#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Fraction.hpp"
using namespace std;
// using namespace ariel;

// gal ben shitrit gave me an idea to multiply the number by 1000 to get 3 numbers after the decimal point.

/*----constructors----*/
Fraction::Fraction()
{
    Fraction(0, 1);
}
Fraction::Fraction(const int &numerator, const int &denominator) : _numerator(numerator), _denominator(denominator)
{
    if (denominator == 0)
    {
        throw invalid_argument("denominator can't be equals to 0");
    }
    int reducer = gcd(numerator, denominator); // reduction
    this->_numerator = (numerator / reducer);
    this->_denominator = (denominator / reducer);
}
Fraction::Fraction(const float &num)
{
    int temp = num * 1000;
    int reducer = gcd(temp, 1000); // reduction
    this->_numerator = (temp / reducer);
    this->_denominator = (1000 / reducer);

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

int Fraction::getNumerator()
{
    return _numerator;
}
int Fraction::getDenominator()
{
    return _denominator;
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
Fraction operator/(const float &first_num, const Fraction &second_num)
{
    int num1 = first_num * 1000;
    Fraction temp(num1, 1000);
    return (temp / second_num); // fra / fra
}

bool Fraction::operator==(const float &second_num) const
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    if (this->_numerator == temp._numerator && this->_denominator == temp._denominator)
    {
        return true;
    }
    return false;
}
bool Fraction::operator==(const Fraction &second_num) const
{
    if (this->_numerator == second_num._numerator && this->_denominator == second_num._denominator)
    {
        return true;
    }
    return false;
}
bool operator==(const float &first_num, const Fraction &second_num)
{
    int num2 = first_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);   // make a temp fraction.
    if (temp._numerator == second_num._numerator && temp._denominator == second_num._denominator)
    {
        return true;
    }
    return false;
}

bool Fraction::operator>(const float &second_num) const
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    if (this->_numerator * temp._denominator > this->_denominator * temp._numerator)
    {
        return true;
    }
    return false;
}
bool Fraction::operator>(const Fraction &second_num) const
{
    if (this->_numerator * second_num._denominator > this->_denominator * second_num._numerator)
    {
        return true;
    }
    return false;
}
bool operator>(const float &first_num, const Fraction &second_num)
{
    int num2 = first_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);   // make a temp fraction.
    if (temp._numerator * second_num._denominator > temp._denominator * second_num._numerator)
    {
        return true;
    }
    return false;
}

bool Fraction::operator<(const float &second_num) const
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    if (this->_numerator * temp._denominator < this->_denominator * temp._numerator)
    {
        return true;
    }
    return false;
}
bool Fraction::operator<(const Fraction &second_num) const
{
    if (this->_numerator * second_num._denominator < this->_denominator * second_num._numerator)
    {
        return true;
    }
    return false;
}
bool operator<(const float &first_num, const Fraction &second_num)
{
    int num2 = first_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);   // make a temp fraction.
    if (temp._numerator * second_num._denominator < temp._denominator * second_num._numerator)
    {
        return true;
    }
    return false;
}

bool Fraction::operator>=(const float &second_num) const
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    if (*this > temp || *this == temp)
    {
        return true;
    }
    return false;
}
bool Fraction::operator>=(const Fraction &second_num) const
{
    if (*this > second_num || *this == second_num)
    {
        return true;
    }
    return false;
}
bool operator>=(const float &first_num, const Fraction &second_num)
{
    int num2 = first_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);   // make a temp fraction.
    if (temp > second_num || temp == second_num)
    {
        return true;
    }
    return false;
}

bool Fraction::operator<=(const float &second_num) const
{
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    if (*this < temp || *this == temp)
    {
        return true;
    }
    return false;
}
bool Fraction::operator<=(const Fraction &second_num) const
{
    if (*this < second_num || *this == second_num)
    {
        return true;
    }
    return false;
}
bool operator<=(const float &first_num, const Fraction &second_num)
{
    int num2 = first_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);   // make a temp fraction.
    if (temp < second_num || temp == second_num)
    {
        return true;
    }
    return false;
}

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

ostream &operator<<(ostream &output, Fraction &fraction)
{
    return output << fraction.Fraction::getNumerator() << "/" << fraction.getDenominator();
}
istream &operator>>(istream &input, Fraction &fraction)
{
    // float a;
    // input >> a;

    return input; // need to fill this section.
}
