#ifndef FRACT_HPP
#define FRACT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include <numeric>
/*
    # The + operator to add two fractions and return their sum as another fraction in reduced form.
    # The - operator to subtract two fractions and return their difference as another fraction in reduced form.
    # The * operator to multiply two fractions and return their product as another fraction in reduced form.
    # The / operator to divide two fractions and return their quotient as another fraction in reduced form.
    # The == operator to compare two fractions for equality and return true or false.
    # All comparison operations (>,<,>=,<=)
    # The ++ and -- operator that adds (or substracts) 1 to the fraction. implement both pre and post fix.
    # The << operator to print a fraction to an output stream in the format “numerator/denominator”.
    # The >> operator to read a fraction from an input stream by taking two integers as input.
    # All operators should work on both sides on fractions and floats type variables.
      on a float var you need use up to 3 digits beyond the desimal point for acuracy.
*/

namespace ariel
{
    class Fraction
    {
    private:
        int _numerator, _denominator;

    public:
        // Constructors
        Fraction();
        Fraction(float);
        Fraction(const int &numerator, const int &denominator);
        void reduceGCD(int &new_numerator, int &new_denominator);

        // getters
        int getNumerator() const { return _numerator; };
        int getDenominator() const { return _denominator; };

        // operators
        Fraction operator+(const Fraction &);
        Fraction operator+(const float &);
        // why friend?
        // ans: it needs to access the private members of the Fraction
        //      to allow to perform float + fraction
        friend Fraction operator+(const float &, const Fraction &);

        Fraction operator-(const Fraction &);
        Fraction operator-(const float &);
        friend Fraction operator-(const float &, const Fraction &);

        Fraction operator*(const Fraction &);
        Fraction operator*(const float &);
        friend Fraction operator*(const float &, const Fraction &);

        Fraction operator/(const Fraction &);
        Fraction operator/(const float &);
        friend Fraction operator/(const float &, const Fraction &);

        // //if operators
        bool operator==(const Fraction &other) const;
        bool operator==(const float &flo) const;
        friend bool operator==(const float &flo, const Fraction &other);

        bool operator>(const Fraction &other) const;
        bool operator>(const float &flo) const;
        friend bool operator>(const float &flo, const Fraction &other);

        bool operator<(const Fraction &other) const;
        bool operator<(const float &flo) const;
        friend bool operator<(const float &flo, const Fraction &other);

        bool operator>=(const Fraction &other) const;
        bool operator>=(const float &flo) const;
        friend bool operator>=(const float &flo, const Fraction &other);

        bool operator<=(const Fraction &other) const;
        bool operator<=(const float &flo) const;
        friend bool operator<=(const float &flo, const Fraction &other);

        //++ / --
        // why '&' ? : return a refrence after increament the value
        Fraction &operator++();   // Prefix: ++n
        Fraction operator++(int); // Postfix: n++
        Fraction &operator--();   // Prefix: --n
        Fraction operator--(int); // Postfix: n--
        // friend input/output
        // why '&' ? : return areference is to allow chaining multiple stream operations together.
        friend std::ostream &operator<<(std::ostream &, const Fraction &);
        friend std::istream &operator>>(std::istream &, Fraction &);

    };
}

#endif