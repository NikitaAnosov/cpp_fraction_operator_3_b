#include "Fraction.hpp"
namespace ariel // namespace for linker command
{
    // Constructors
    Fraction::Fraction() : _numerator(1), _denominator(2) {}
    Fraction::Fraction(float flo)
    {
        // change type from float to fraction
        _denominator = 1000; // .000 max zero's after dot
        _numerator = 1000 * flo;
    };
    Fraction::Fraction(const int &numerator, const int &denominator)
        : _numerator(numerator), _denominator(denominator)
    {
        if (denominator == 0) // 1/0 = error
        {
            throw std::invalid_argument("denominator == 0");
        }
        // check if negative, and make only the numerator be negative OR positive in case that two of them negative
        if (denominator < 0)
        {
            this->_numerator *= -1;
            this->_denominator *= -1;
        }
        reduceGCD(this->_numerator, this->_denominator);
    };

    // reduce the fraction with gcd
    void Fraction::reduceGCD(int &new_numerator, int &new_denominator)
    {
        int gcd = std::gcd(new_numerator, new_denominator);
        new_numerator /= gcd;
        new_denominator /= gcd;
    }

    //////// (+) /////////
    Fraction Fraction::operator+(const Fraction &frac)
    {
        // 1   1     1"3 + 1*2
        // - + - =  ----------
        // 2   3       2*3
        long long new_numerator_long = static_cast<long long>(this->_numerator) * frac._denominator + frac._numerator * this->_denominator;
        int new_denominator = this->_denominator * frac._denominator;
        // check overflow
        // global for overflow check
        if (new_numerator_long < std::numeric_limits<int>::min() || new_numerator_long > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("overflow error");
        }
        int new_numerator = static_cast<int>(new_numerator_long);
        reduceGCD(new_numerator, new_denominator);
        return Fraction(new_numerator, new_denominator);
    }
    Fraction Fraction::operator+(const float &flo)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator+(const Fraction &other)
        return (*this + Fraction(flo));
    }
    Fraction operator+(const float &flo, const Fraction &frac)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator+(const Fraction &other)
        return (Fraction(flo) + frac);
    }

    //////// (-) /////////
    Fraction Fraction::operator-(const Fraction &frac)
    {
        // 1   1     1"3 - 1*2
        // - - - =  ----------
        // 2   3       2*3
        long long new_numerator_long = static_cast<long long>(this->_numerator) * frac._denominator - frac._numerator * this->_denominator;
        int new_denominator = this->_denominator * frac._denominator;
        // check overflow
        // global for overflow check
        if (new_numerator_long < std::numeric_limits<int>::min() || new_numerator_long > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("overflow error");
        }
        int new_numerator = static_cast<int>(new_numerator_long);
        reduceGCD(new_numerator, new_denominator);
        return Fraction(new_numerator, new_denominator);
    }
    Fraction Fraction::operator-(const float &flo)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator-(const Fraction &other)
        return (*this - Fraction(flo));
    }
    Fraction operator-(const float &flo, const Fraction &frac)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator-(const Fraction &other)
        return (Fraction(flo) - frac);
    }

    //////// (*) /////////
    Fraction Fraction::operator*(const Fraction &frac)
    {
        // 1   1       1*1
        // - * - =  ----------
        // 2   3       2*3
        long long new_numerator_long = static_cast<long long>(this->_numerator) * frac._numerator;
        long long new_denominator_long = static_cast<long long>(this->_denominator) * frac._denominator;
        // check overflow
        // global for overflow check
        // check numerators
        if (new_numerator_long < std::numeric_limits<int>::min() || new_numerator_long > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("overflow error");
        }
        // check denominators
        if (new_denominator_long < std::numeric_limits<int>::min() || new_denominator_long > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("overflow error");
        }
        int new_numerator = static_cast<int>(new_numerator_long);
        int new_denominator = static_cast<int>(new_denominator_long);
        reduceGCD(new_numerator, new_denominator);
        return Fraction(new_numerator, new_denominator);
    }
    Fraction Fraction::operator*(const float &flo)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator*(const Fraction &other)
        return (*this * Fraction(flo));
    }
    Fraction operator*(const float &flo, const Fraction &frac)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator*(const Fraction &other)
        return (Fraction(flo) * frac);
    }

    //////// (/) /////////
    Fraction Fraction::operator/(const Fraction &frac)
    {
        // 1   1       1 * 3
        // - : - =  ----------
        // 2   3       2 * 1
        // check if nomerator is 0
        if (frac._numerator == 0)
        {
            throw std::runtime_error("numerator == 0");
        }
        long long new_numerator_long = static_cast<long long>(this->_numerator) * frac._denominator;
        long long new_denominator_long = static_cast<long long>(this->_denominator) * frac._numerator;
        // check overflow
        // global for overflow check
        // check numerators
        if (new_numerator_long < std::numeric_limits<int>::min() || new_numerator_long > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("overflow error");
        }
        // check denominators
        if (new_denominator_long < std::numeric_limits<int>::min() || new_denominator_long > std::numeric_limits<int>::max())
        {
            throw std::overflow_error("overflow error");
        }
        int new_numerator = static_cast<int>(new_numerator_long);
        int new_denominator = static_cast<int>(new_denominator_long);
        reduceGCD(new_numerator, new_denominator);
        return Fraction(new_numerator, new_denominator);
    }
    Fraction Fraction::operator/(const float &flo)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator/(const Fraction &other)
        return (*this / Fraction(flo));
    }
    Fraction operator/(const float &flo, const Fraction &frac)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator/(const Fraction &other)
        return (Fraction(flo) / frac);
    }

    //////// if (==) /////////
    bool Fraction::operator==(const Fraction &other) const
    { // create a number from fraction up to 3 decimals after dot
        // example: 3.12345 -> 3123
        // and compare between two fractions
        int frac1 = (int)((float)this->_numerator / this->_denominator * 1000);
        int frac2 = (int)((float)other._numerator / other._denominator * 1000);
        return frac1 == frac2;
    }
    bool Fraction::operator==(const float &flo) const
    {
        // chagne float to a fraction
        //  and call to preveius func: operator==(const Fraction &other)
        return (*this == Fraction(flo));
    }
    bool operator==(const float &flo, const Fraction &other)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator==(const Fraction &other)
        return (Fraction(flo) == other);
    }

    //////// if (>) /////////
    bool Fraction::operator>(const Fraction &other) const
    {
        // tie the denominators
        // and compre only the numerators
        int numerator1 = this->_numerator * other._denominator;
        int numerator2 = this->_denominator * other._numerator;
        return (numerator1 > numerator2);
    }
    bool Fraction::operator>(const float &flo) const
    {
        // chagne float to a fraction
        //  and call to preveius func: operator>(const Fraction &other)
        return (*this > Fraction(flo));
    }
    bool operator>(const float &flo, const Fraction &other)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator>(const Fraction &other)
        return (Fraction(flo) > other);
    }

    //////// if (<) /////////
    bool Fraction::operator<(const Fraction &other) const
    {
        return !(*this == other) && !(*this > other);
    }
    bool Fraction::operator<(const float &flo) const
    {
        // chagne float to a fraction
        //  and call to preveius func: operator<(const Fraction &other)
        return (*this < Fraction(flo));
    }
    bool operator<(const float &flo, const Fraction &other)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator<(const Fraction &other)
        return (Fraction(flo) < other);
    }

    //////// if (>=) /////////
    bool Fraction::operator>=(const Fraction &other) const
    {
        return !(*this < other);
    }
    bool Fraction::operator>=(const float &flo) const
    {
        // chagne float to a fraction
        //  and call to preveius func: operator>=(const Fraction &other)
        return (*this >= Fraction(flo));
    }
    bool operator>=(const float &flo, const Fraction &other)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator>=(const Fraction &other)
        return (Fraction(flo) >= other);
    }

    //////// if (<=) /////////
    bool Fraction::operator<=(const Fraction &other) const
    {
        return !(*this > other);
    }
    bool Fraction::operator<=(const float &flo) const
    {
        // chagne float to a fraction
        //  and call to preveius func: operator<=(const Fraction &other)
        return (*this <= Fraction(flo));
    }
    bool operator<=(const float &flo, const Fraction &other)
    {
        // chagne float to a fraction
        //  and call to preveius func: operator<=(const Fraction &other)
        return (Fraction(flo) <= other);
    }

    // //++ / --
    Fraction &Fraction::operator++()
    { // Prefix ++n
        // 1/2 + 1 = (1+2)/2
        this->_numerator += this->_denominator;
        return *this;
    }
    Fraction Fraction::operator++(int forCompiler) // "int" is a flag that makes it postfix
    {                                              // Postfix n++
        Fraction save_frac(*this);                 // save before +1
        // call to previous func
        ++(*this);
        return save_frac;
    }
    Fraction &Fraction::operator--()
    { // Prefix --n
        // 1/2 - 1 = (1-2)/2
        this->_numerator -= this->_denominator;
        return *this;
    }
    Fraction Fraction::operator--(int forCompiler) // "int" is a flag that makes it postfix
    {                                              // Postfix n--
        Fraction save_frac(*this);                 // save before +1
        // call to previous func
        --(*this);
        return save_frac;
    }

    // <<
    std::ostream &operator<<(std::ostream &os, const Fraction &frac)
    {
        return (os << frac._numerator << "/" << frac._denominator); // example: 1/2
    }
    // >>
    std::istream &operator>>(std::istream &is, Fraction &frac)
    {
        int numerator, denominator;
        is >> numerator >> denominator;
        if (denominator == 0)
        {
            throw std::runtime_error("denominator == 0");
        }

        if (is.fail())
        {
            throw std::runtime_error("error with input");
        }
        frac._numerator = numerator;
        frac._denominator = denominator;
        // check if negative, and make only the numerator be negative 
        // OR positive in case that two of them negative
        if (frac._denominator < 0)
        {
            frac._numerator *= -1;
            frac._denominator *= -1;
        }
        return is;
    }


}
