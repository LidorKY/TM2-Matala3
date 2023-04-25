#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

namespace ariel
{
    // need to puth here the class probably
}

class Fraction
{
private:
    int _numerator;   // mone
    int _denominator; // mechane

public:
    /*----constructor----*/
    Fraction(const int &numerator, const int &denominator);
    /*-------------------*/

    //----functions----//
    int gcd(int num1, int num2);

    /*----addition----*/
    Fraction operator+(const float &second_num);
    Fraction operator+(const Fraction &second_num);
    friend Fraction operator+(const float &first_num, const Fraction &second_num);
    /*----------------*/

    /*----substruction----*/
    Fraction operator-(const float &second_num);
    Fraction operator-(const Fraction &second_num);
    friend Fraction operator-(const float &first_num, const Fraction &second_num);
    /*--------------------*/

    /*----multiplication----*/
    Fraction operator*(const float &second_num);
    Fraction operator*(const Fraction &second_num);
    friend Fraction operator*(const float &first_num, const Fraction &second_num);
    /*----------------------*/

    /*----division----*/
    Fraction operator/(const float &second_num);
    Fraction operator/(const Fraction &second_num);
    friend Fraction operator/(const float &first_num, const Fraction &second_num);
    /*----------------*/

    /*----exuals----*/
    bool operator==(float second_num);
    bool operator==(Fraction second_num);
    friend bool operator==(float first_num, Fraction second_num);
    /*--------------*/

    /*----bigger_than----*/
    bool operator>(float second_num);
    bool operator>(Fraction second_num);
    friend bool operator>(float first_num, Fraction second_num);
    /*-------------------*/

    /*----lower_than----*/
    bool operator<(float second_num);
    bool operator<(Fraction second_num);
    friend bool operator<(float first_num, Fraction second_num);
    /*------------------*/

    /*----bigger_or_equals----*/
    bool operator>=(float second_num);
    bool operator>=(Fraction second_num);
    friend bool operator>=(float first_num, Fraction second_num);
    /*-----------------------*/

    /*----lower_or_equals----*/
    bool operator<=(float second_num);
    bool operator<=(Fraction second_num);
    friend bool operator<=(float first_num, Fraction second_num);
    /*-----------------------*/

    /*----add_1----*/
    Fraction &operator++();         // prefix - ++n. minute 27.
    const Fraction operator++(int); // postfix - n++. minute 27.
    /*------------*/

    /*----substruct_1----*/
    Fraction &operator--();         // prefix - ++n. minute 27.
    const Fraction operator--(int); // postfix - n++. minute 27.
    /*-------------------*/

    /*----output----*/
    friend ostream &operator<<(ostream &output, const Fraction &fraction);
    /*--------------*/

    /*----intput----*/
    friend istream &operator>>(ostream &input, Fraction &fraction);
    /*--------------*/
};