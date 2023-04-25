#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Addition")
{
    Fraction num1(1, 2);
    Fraction num2(3, 4);
    float num3 = 1.943;
    float num4 = 0.469;
    CHECK(num1 + num2 == 1.25);                 // fra + fra
    CHECK(num2 + num1 == Fraction(5, 4));       // fra + fra
    CHECK(num1 + num3 == 2.443);                // fra + float
    CHECK(num1 + num4 == Fraction(969, 1000));  // fra + float
    CHECK(num3 + num2 == 2.693);                // float + fra
    CHECK(num4 + num2 == Fraction(1219, 1000)); // float + fra
    num1++;
    CHECK(num1 == 1.5);
    ++num2;
    CHECK(num2 == 1.75);
}

TEST_CASE("Substruction")
{
    Fraction num1(1, 2);
    Fraction num2(3, 4);
    float num3 = 1.943;
    float num4 = 0.469;
    CHECK(num1 - num2 == -0.25);            // fra + fra
    CHECK(num2 - num1 == Fraction(1, 4)); // fra + fra
    CHECK(num1 - num3 == -1.443);            // fra + float
    CHECK(num1 - num4 == Fraction(31, 1000)); // fra + float
    CHECK(num3 - num2 == 1.193);            // float + fra
    CHECK(num4 - num2 == Fraction(-281, 1000)); // float + fra
    num1--;
    CHECK(num1 == -0.5);
    --num2;
    CHECK(num2 == -0.75);
}

TEST_CASE("Multiplication")
{
    Fraction num1(1, 2);
    Fraction num2(3, 4);
    float num3 = 1.943;
    float num4 = 0.469;
    CHECK(num1 * num2 == 0.375);            // fra + fra
    CHECK(num2 * num1 == Fraction(3, 8)); // fra + fra
    CHECK(num1 * num3 == 0.9715);            // fra + float
    CHECK(num1 * num4 == Fraction(469, 2000)); // fra + float
    CHECK(num3 * num2 == 1.45725);            // float + fra
    CHECK(num4 * num2 == Fraction(1407, 4000)); // float + fra
}

TEST_CASE("Dividion")
{
    Fraction num1(1, 2);
    Fraction num2(3, 4);
    float num3 = 1.943;
    float num4 = 0.469;
    CHECK(num1 / num2 == 0.666);            // fra + fra
    CHECK(num2 / num1 == Fraction(3, 2)); // fra + fra
    CHECK(num1 / num3 == 0.257);            // fra + float
    CHECK(num1 / num4 == Fraction(500, 469)); // fra + float
    CHECK(num3 / num2 == 2.59);            // float + fra
    CHECK(num4 / num2 == Fraction(469, 750)); // float + fra
}

TEST_CASE("Comparion And Reduction")
{
    Fraction num1(1, 2);
    Fraction num2(5, 10);
    float num3 = 1.943;
    float num4 = 0.469;
    CHECK(num1 == num2);             
    CHECK(num2 == Fraction(30, 60));
    CHECK(num1 > num4);             
    CHECK(num2 < num3);              
}

//maybe add input and output.
