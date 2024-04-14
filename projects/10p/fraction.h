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

    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
        pre: Calling object is either an int or Fraction object
        post: Returns Fraction object assigned to sum of calling object and parameter fraction;
    
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
        pre: Calling object is either an int or Fraction object
        post: Returns Fraction object assigned to difference of calling object and parameter fraction;

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
        pre: Calling object is either an int or Fraction object
        post: Returns Fraction object assigned to product of calling object and parameter fraction;

    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);
        pre: Calling object is either an int or Fraction object
        post: Returns Fraction object assigned to product of calling object and parameter fraction;

    friend std::ostream& operator<<(std::ostream& out, const Fraction& rhs);
        post: Fraction is printed to screen in reduced form. Whole numbers are printed without
        a denominator. Improper fractions are printed as mixed numbers. Negative fractions
        and mixed numbers are printed with a leading minus sign.

    friend std::istream& operator>>(std::istream& in, Fraction& rhs);
        pre: Calling stream is populated with fractions, in format num/denom, int+num/denom.
        post: Parameter Fraction object is assigned to Fraction objects read in input stream in simplified form.

    friend bool operator==(const Fraction& lhs, const Fraction& rhs);
        pre: Calling or parameter objects are Fractions or integers
        post: Returns boolean value true if calling and parameter objects are equal. Returns false otherwise.

    friend bool operator<(const Fraction& lhs, const Fraction& rhs);
        pre: Calling or parameter objects are Fractions or integers
        post: Returns boolean value true if calling object is less than parameter object. Returns false otherwise.

    friend bool operator!=(const Fraction& lhs, const Fraction& rhs) { return !(lhs == rhs); }
        pre: Calling or parameter objects are Fractions or integers
        post: Returns boolean value true if calling object is not equal to parameter object. Returns false otherwise.

    friend bool operator>(const Fraction& lhs, const Fraction& rhs) { return rhs < lhs; }
        pre: Calling or parameter objects are Fractions or integers
        post: Returns boolean value true if calling object is greater than parameter object. Returns false otherwise.

    friend bool operator<=(const Fraction& lhs, const Fraction& rhs) { return !(lhs > rhs); }
        pre: Calling or parameter objects are Fractions or integers
        post: Returns boolean value true if calling object is less than or equal to parameter object. Returns false otherwise.

    friend bool operator>=(const Fraction& lhs, const Fraction& rhs) { return !(lhs < rhs); }
        pre: Calling or parameter objects are Fractions or integers
        post: Returns boolean value true if calling object is greater than or equal to parameter object. Returns false otherwise.

    Fraction operator+=(const Fraction& rhs);
        pre: Calling or parameter objects are Fractions or integers
        post: Calling object is assigned to the sum of itself and the parameter object. Returns value of calling object.

    Fraction operator-=(const Fraction& rhs);
        pre: Calling or parameter objects are Fractions or integers
        post: Calling object is assigned to the difference of itself and the parameter object. Returns value of calling object.

    Fraction operator*=(const Fraction& rhs);
        pre: Calling or parameter objects are Fractions or integers
        post: Calling object is assigned to the product of itself and the parameter object. Returns value of calling object.

    Fraction operator/=(const Fraction& rhs);
        pre: Calling or parameter objects are Fractions or integers
        post: Calling object is assigned to the quotient of itself and the parameter object. Returns value of calling object.

    Fraction operator++();
        post: 1 is added to calling Fraction. Returns new value.

    Fraction operator++(int);
        post: 1 is added to calling Fraction. Returns old value.

    Fraction operator--();
        post: 1 is removed from calling Fraction. Returns new value.

    Fraction operator--(int);
        post: 1 is removed from calling Fraction. Returns old value.
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