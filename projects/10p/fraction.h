#ifndef DATE_H
#define DATE_H

/*
    Alex Lee
    COMS 215
    13 April 2024
    Professor Harden
    Fraction.h

    The Fraction class creates objects that represent mathematical fractions.
    They store two things as a fraction, a numerator and a denominator.
    The following functions are available:

    Fraction(int inNum, int inDenom);
        pre: inDenom is not equal to 0.
        post: The calling object has been modified, where the numerator is equal to
        inNum, and the denominator is equal to inDenom.


*/
namespace cs_fraction {
   class Fraction {
      public:
         Fraction(int inNum = 0, int inDenom = 1);
         friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
         friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
         friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
         friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
         friend std::ostream& operator<<(std::ostream& out, const Fraction& rhs);
         friend std::istream& operator>>(std::istream& in, Fraction& rhs);
         friend bool operator==(const Fraction& lhs, const Fraction& rhs);
         friend bool operator<(const Fraction& lhs, const Fraction& rhs);
         friend bool operator!=(const Fraction& lhs, const Fraction& rhs) { return !(lhs == rhs); }
         friend bool operator>(const Fraction& lhs, const Fraction& rhs) { return rhs < lhs; }
         friend bool operator<=(const Fraction& lhs, const Fraction& rhs) { return !(lhs > rhs); }
         friend bool operator>=(const Fraction& lhs, const Fraction& rhs) { return !(lhs < rhs); }
         Fraction operator+=(const Fraction& rhs);
         Fraction operator-=(const Fraction& rhs);
         Fraction operator*=(const Fraction& rhs);
         Fraction operator/=(const Fraction& rhs);
         Fraction operator++();
         Fraction operator++(int);
         Fraction operator--();
         Fraction operator--(int);


      private:
         int numerator;
         int denominator;
         void simplify();
   };
}

#endif