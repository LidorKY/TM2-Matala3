#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Fraction.hpp"
using namespace std;
// using namespace ariel;

/*----constructors----*/
Fraction::Fraction(const int &numerator, const int &denominator)
{
    this->_numerator = numerator;
    this->_denominator = denominator;
}
/*--------------------*/

int gcd() { return 0; }

Fraction Fraction::operator+(const float &second_num) const { return *this; }
Fraction Fraction::operator+(const Fraction &second_num) const { return *this; }
Fraction operator+(const float &first_num, const Fraction &second_num) { return Fraction(1, 2); }

Fraction Fraction::operator-(const float &second_num) const { return *this; }
Fraction Fraction::operator-(const Fraction &second_num) const { return *this; }
Fraction operator-(const float &first_num, const Fraction &second_num) { return Fraction(1, 2); }

Fraction Fraction::operator*(const float &second_num) const { return *this; }
Fraction Fraction::operator*(const Fraction &second_num) const { return *this; }
Fraction operator*(const float &first_num, const Fraction &second_num) { return Fraction(1, 2); }

Fraction Fraction::operator/(const float &second_num) const { return *this; }
Fraction Fraction::operator/(const Fraction &second_num) const { return *this; }
Fraction operator/(const float &first_num, const Fraction &second_num) { return Fraction(1, 2); }

bool Fraction::operator==(float second_num) { return true; }
bool Fraction::operator==(Fraction second_num) { return true; }
bool operator==(float first_num, Fraction second_num) { return true; }

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

Fraction &Fraction::operator++() { return *this; }         // prefix - ++n. minute 27.
const Fraction Fraction::operator++(int) { return *this; } // postfix - n++. minute 27.

Fraction &Fraction::operator--() { return *this; }         // prefix - ++n. minute 27.
const Fraction Fraction::operator--(int) { return *this; } // postfix - n++. minute 27.

ostream &operator<<(ostream &output, const Fraction &fraction) { return output; }
istream &operator>>(istream &input, Fraction &fraction) { return input; }
