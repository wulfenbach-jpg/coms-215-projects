#ifndef DATE_H
#define DATE_H

/* 
    Alex Lee
    COMS 215
    11 March 2024
    Professor Harden
    Fraction.h

    The Fraction class creates objects that represent mathematical fractions.
    They store two things as a fraction, a numerator and a denominator.
    The following functions are available:

    Fraction();
        post: The calling object has been created and initialized to 0/1.

    Fraction(int inNum, int inDenom);
        pre: inDenom is not equal to 0.
        post: The calling object has been modified, where the numerator is equal to
        inNum, and the denominator is equal to inDenom.

    Fraction addedTo(const Fraction& inFrac) const;
        post: Returns a Fraction object assigned to the sum of the calling object and the
        parameter Fraction.

    Fraction subtract(const Fraction& inFrac) const;
        post: Returns a Fraction object assigned to the difference of the calling object
        and the parameter Fraction.

    Fraction multipliedBy(const Fraction& inFrac) const;
        post: Returns a Fraction object assigned to the product of the calling object
        and the parameter Fraction.

    Fraction dividedBy(const Fraction& inFrac) const;
        post: Returns a Fraction object assigned to the quotient of the calling object
        and the parameter Fraction.

    bool isEqualTo(const Fraction& inFrac);
        post: Returns true if the calling object is equal to the parameter function.
              Otherwise, returns false.

    void print() const;
        post: The calling object has been printed to the console in the format: numerator/denominator.
    
*/

class Fraction {
    public:
        Fraction();
        Fraction(int inNum, int inDenom);
        Fraction addedTo(const Fraction& inFrac) const;
        Fraction subtract(const Fraction& inFrac) const;
        Fraction multipliedBy(const Fraction& inFrac) const;
        Fraction dividedBy(const Fraction& inFrac) const;
        bool isEqualTo(const Fraction& inFrac);
        void print() const;

    private:
        int numerator;
        int denominator;
        void simplify();
};

#endif