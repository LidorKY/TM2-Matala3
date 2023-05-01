#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <limits>
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
    if ((this->_numerator > 0 && this->_denominator < 0) || (this->_numerator < 0 && this->_denominator < 0))
    {
        this->_numerator *= -1;
        this->_denominator *= -1;
    }
}
Fraction::Fraction(const float &num) : _numerator(1000 * num), _denominator(1000)
{
    int reducer = gcd(_numerator, _denominator); // reduction
    _numerator /= reducer;
    _denominator /= reducer;
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
    return this->_numerator;
}
int Fraction::getDenominator()
{
    return this->_denominator;
}
void Fraction::setNumerator(int num)
{
    this->_numerator = num;
}
void Fraction::setDenominator(int num)
{
    this->_denominator = num;
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
    int right_top = this->_denominator * second_num._numerator; // calc the right numerator
    int top = left_top + right_top;                             // combine numerators
    int bottom = this->_denominator * second_num._denominator;  // make new denominator
    if (__builtin_mul_overflow(this->_numerator, second_num._denominator, &left_top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_mul_overflow(this->_denominator, second_num._numerator, &right_top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_add_overflow(left_top, right_top, &top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_mul_overflow(this->_denominator, second_num._denominator, &bottom))
    {
        throw std::overflow_error("overflow in denominator.");
    }
    int reducer = gcd(top, bottom); // find gcd and reduce
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
    int right_top = this->_denominator * second_num._numerator; // calc the right numerator
    int top = left_top - right_top;                             // combine numerators
    int bottom = this->_denominator * second_num._denominator;  // make new denominator
    if (__builtin_mul_overflow(this->_numerator, second_num._denominator, &left_top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_mul_overflow(this->_denominator, second_num._numerator, &right_top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_sub_overflow(left_top, right_top, &top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_mul_overflow(this->_denominator, second_num._denominator, &bottom))
    {
        throw std::overflow_error("overflow in denominator.");
    }
    int reducer = gcd(top, bottom); // find gcd and reduce
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
    if (__builtin_mul_overflow(this->_numerator, second_num._numerator, &top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_mul_overflow(this->_denominator, second_num._denominator, &bottom))
    {
        throw std::overflow_error("overflow in denominator.");
    }
    int reducer = gcd(top, bottom); // find gcd and reduce
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
        throw runtime_error("can't devide by 0");
    }
    int num2 = second_num * 1000; // get only 3 digits after the decimal point.
    Fraction temp(num2, 1000);    // make a temp fraction.
    return (*this / temp);        // fra / fra
}
Fraction Fraction::operator/(const Fraction &second_num)
{
    if (second_num._numerator == 0)
    {
        throw runtime_error("can't devide by 0");
    }
    int top = this->_numerator * second_num._denominator;    // combine numerators
    int bottom = this->_denominator * second_num._numerator; // make new denominator
    if (__builtin_mul_overflow(this->_numerator, second_num._denominator, &top))
    {
        throw std::overflow_error("overflow in numerator.");
    }
    if (__builtin_mul_overflow(this->_denominator, second_num._numerator, &bottom))
    {
        throw std::overflow_error("overflow in denominator.");
    }
    int reducer = gcd(top, bottom); // find gcd and reduce
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
    if (*this == Fraction(second_num))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Fraction::operator==(const Fraction &second_num) const
{
    const float temp = 1000.0;
    int x = (int)(((float)_numerator / (float)_denominator) * temp);
    int y = (int)(((float)second_num._numerator / (float)second_num._denominator) * temp);
    if (x == y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator==(const float &first_num, const Fraction &second_num)
{
    if (Fraction(first_num) == second_num)
    {
        return true;
    }
    else
    {
        return false;
    }
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
Fraction Fraction::operator++(int)
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
Fraction Fraction::operator--(int)
{                          // postfix - n++.
    Fraction copy = *this; // make a copy
    --*this;               // add 1
    return copy;           // return the copy
}

ostream &operator<<(ostream &output, Fraction &fraction)
{
    output << fraction.getNumerator() << "/" << fraction.getDenominator();
    return output;
}

istream &operator>>(istream &input, Fraction &fraction)
{
    if (input >> fraction._numerator) // check if input is successful
    {
        if (input >> fraction._denominator) // check if input is successful
        {
            if (fraction._denominator == 0)
            {
                throw runtime_error("error in input.");
            }
            else
            {
                if ((fraction._numerator > 0 && fraction._denominator < 0) || (fraction._numerator < 0 && fraction._denominator < 0))
                {
                    fraction._numerator *= -1;
                    fraction._denominator *= -1;
                }
            }
        }
        else
        {
            throw runtime_error("error in input."); // there is no input for the denominator.
        }
    }
    else
    {
        throw runtime_error("error in input."); // the buffer is empty.
    }

    return input;
}
