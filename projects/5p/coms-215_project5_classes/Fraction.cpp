#include <iostream>
#include <cassert>
#include "Fraction.h"
using namespace std;

/*

    Class Invariant: a Fraction object has 2 int data members:
    numerator stores an integer numerator of a mathematical fraction.
    denominator stores the integer denominator of a mathematical fraction.
    Internal operations should always ensure that the fraction is stored in the
    lowest terms utilizing the private simplify() function. Efforts are made to
    prevent the client from providing an invalid denominator in the parameterized function
    by utilizing <cassert>'s assert() function.

*/

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int inNum, int inDenom) {
    numerator = inNum;
    denominator = inDenom;
    assert(denominator != 0);
    simplify();
}

Fraction Fraction::addedTo(const Fraction& inFrac) const {
    Fraction result;

    result.denominator = denominator * inFrac.denominator;
    result.numerator = (numerator * inFrac.denominator) + (inFrac.numerator * denominator);
    
    result.simplify();
    return result;
}

Fraction Fraction::subtract(const Fraction& inFrac) const {
    Fraction result;

    result.denominator = denominator * inFrac.denominator;
    result.numerator = (numerator * inFrac.denominator) - (inFrac.numerator * denominator);

    result.simplify();
    return result;
}

Fraction Fraction::multipliedBy(const Fraction& inFrac) const {
    Fraction result;

    result.denominator = denominator * inFrac.denominator;
    result.numerator = numerator * inFrac.numerator;

    result.simplify();
    return result;
}

Fraction Fraction::dividedBy(const Fraction& inFrac) const {
    Fraction result;

    result.denominator = denominator * inFrac.numerator;
    result.numerator = numerator * inFrac.denominator;

    result.simplify();
    return result;
}

bool Fraction::isEqualTo(const Fraction& inFrac) {
    return numerator * inFrac.denominator == inFrac.numerator * denominator;
}

void Fraction::print() const {
    cout << numerator << '/' << denominator;
}

/*
    post: calling Fraction object is simplified to least terms.

    The simplify() function begins by searching for the greatest number.
    It's first preassigned to the value of the numerator private data member.
    This is specifically for the case where the numerator is equal to the denominator.
    Finding the greatest number of the two data members, the function then iterates,
    starting from 1, and incrementally going up one at a time.
    If the remainder of both members divided by i is equal to 0, that means both have i as
    a factor. Thus, the function divides both members by i.

    An example of how operation would work would be like the following fraction (3/6):
    1. The greatest number is set to 3.
    2. 6 is greater than 3, so the greatest number is set to 6.
    3. The program begins iterating, beginning at 1.
    4. Both sides are divided by 1, leaving the same integers.
    5. Both sides are then divided by 3. The program skips over 2 because it fails the condition
       set in the if() statement.
    6. The calling fraction, 3/6, is now instead 1/2.
    7. Nothing past 3 divides into either 1 or 2 without a remainder.

*/
void Fraction::simplify() {
    int greatestNum = numerator > denominator ? numerator : denominator;

    for (int i = 2; i < greatestNum; i++) {
        while (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
        }
    }
}