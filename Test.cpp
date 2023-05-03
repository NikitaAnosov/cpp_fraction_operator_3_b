#include "doctest.h"
#include <stdexcept>          // exptions
#include "sources/Fraction.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("check '+'")
{
    Fraction a(1,5);
    Fraction b(2,5);
    CHECK((a + a) == b);
    float c = 1.2;
    Fraction d(7,5);
    CHECK((a + c) == d);
    CHECK((c + a) == d);
}

TEST_CASE("check '-'")
{
    Fraction a(1,5);
    Fraction b(25,5);
    CHECK((a - a) == 0);
    float c = 4.2;
    Fraction d(4,1);
    CHECK((c - a) == d);
    Fraction e(4,5);
    CHECK((b - c) == e);
}

TEST_CASE("check '/'")
{
    Fraction a(1,5);
    Fraction b(2,5);
    CHECK((a / a) == 1);
    float c = 1.2;
    Fraction d(1,6);
    CHECK((a / c) == d);
    Fraction e(6,1);
    CHECK((c / a) == e);
}

TEST_CASE("check '*'")
{
    Fraction a(1,5);
    Fraction b(1,25);
    CHECK((a * a) == b);
    float c = 1.2;
    Fraction d(6,25);
    CHECK((a * c) == d);
    CHECK((c * a) == d);
}

TEST_CASE("create fraction")
{
    CHECK_NOTHROW(Fraction(1,5));
    CHECK_THROWS(Fraction(1,0));
}

TEST_CASE("check Postfix: n++")
{
    Fraction a(1,2);
    CHECK((a++) == 0.5);
    CHECK(a == 1.5);
}

TEST_CASE("check Prefix: ++n")
{
    Fraction a(1,2);
    CHECK((++a) == 1.5);
    CHECK(a == 1.5);
}

TEST_CASE("check Postfix: n--")
{
    Fraction a(3,2);
    CHECK((a--) == 1.5);
    CHECK(a == 0.5);
}

TEST_CASE("check Prefix: --n")
{
    Fraction a(3,2);
    CHECK((--a) == 0.5);
    CHECK(a == 0.5);
}

TEST_CASE("check '=='")
{
    Fraction a(1,2);
    Fraction b(4,2);
    CHECK((a == b) == false);
    CHECK((a == 0.5) == true);
    CHECK((1.5 == a) == false);
}

TEST_CASE("check '<'")
{
    Fraction a(1,3);
    Fraction b(4,2);
    CHECK((a < b) == true);
    CHECK((a < 2.5) == true);
    CHECK((2.5 < a) == false);
}

TEST_CASE("check '>'")
{
    Fraction a(1,3);
    Fraction b(4,2);
    CHECK((a > b) == false);
    CHECK((a > 0) == true);
    CHECK((0 > a) == false);   
}

TEST_CASE("check '>='")
{
    Fraction a(1,2);
    Fraction b(4,2);
    CHECK((a >= b) == false);
    CHECK((a >= 0.5) == true);
    CHECK((0 >= a) == false);
}

TEST_CASE("check '<='")
{
    Fraction a(1,2);
    Fraction b(4,2);
    CHECK((a <= b) == true);
    CHECK((a <= 0.5) == true);
    CHECK((4.5 <= a) == false);
}

TEST_CASE("check '<<'")
{
    Fraction a(1,2);
    CHECK_NOTHROW((cout << a));
}