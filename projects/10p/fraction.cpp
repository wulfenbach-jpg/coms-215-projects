#include <iostream>
#include <cassert>
#include "fraction.h"
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

namespace cs_fraction {
   Fraction::Fraction(int inNum, int inDenom) {
      assert(inDenom != 0);

      numerator = inNum;
      denominator = inDenom;

      simplify();
   }

   Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
      Fraction result;

      result.denominator = lhs.denominator * rhs.denominator;
      result.numerator = (lhs.numerator * rhs.denominator) + (rhs.numerator * lhs.denominator);

      result.simplify();
      return result;
   }

   Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
      Fraction result;

      result.denominator = lhs.denominator * rhs.denominator;
      result.numerator = (lhs.numerator * rhs.denominator) - (rhs.numerator * lhs.denominator);

      result.simplify();
      return result;
   }

   Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
      Fraction result;

      result.denominator = lhs.denominator * rhs.denominator;
      result.numerator = lhs.numerator * rhs.numerator;

      result.simplify();
      return result;
   }

   Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
      Fraction temp;
      Fraction result;

      temp.denominator = rhs.numerator;
      temp.numerator = rhs.denominator;

      result = lhs * temp;

      result.simplify();
      return result;
   }

   ostream& operator<<(ostream& out, const Fraction& rhs) {
      if (rhs.denominator == 1) {
         out << rhs.numerator;
      } else if (abs(rhs.numerator) > rhs.denominator && rhs.denominator != 1) {
         out << rhs.numerator / rhs.denominator << "+" << abs((rhs.numerator % rhs.denominator)) << "/" << rhs.denominator;
      } else {
         out << rhs.numerator << "/" << rhs.denominator;
      }
      return out;
   }

   istream& operator>>(istream& in, Fraction& rhs) {
      int temp;
      Fraction tempFrac;

      in >> temp;

      if (in.peek() == '+') {
         rhs = temp;
         in.ignore();
         in >> tempFrac.numerator;
         in.ignore();
         in >> tempFrac.denominator;
         rhs = (temp > 0) ? rhs + tempFrac : rhs - tempFrac;
         rhs.simplify();
      } else if (in.peek() == '/') {
         rhs.numerator = temp;
         in.ignore();
         in >> rhs.denominator;
         rhs.simplify();
      } else {
         rhs = temp;
      }

      return in;
   }

   bool operator==(const Fraction& lhs, const Fraction& rhs) {
      return (lhs.numerator * rhs.denominator) == (rhs.numerator * lhs.denominator);
   }

   bool operator<(const Fraction& lhs, const Fraction& rhs) {
      return (lhs.numerator * rhs.denominator) < (rhs.numerator * lhs.denominator);
   }

   Fraction Fraction::operator+=(const Fraction& rhs) {
      *this = *this + rhs;

      this->simplify();
      return *this;
   }

   Fraction Fraction::operator-=(const Fraction& rhs) {
      *this = *this - rhs;

      this->simplify();
      return *this;
   }

   Fraction Fraction::operator*=(const Fraction& rhs) {
      *this = *this * rhs;

      this->simplify();
      return *this;
   }

   Fraction Fraction::operator/=(const Fraction& rhs) {
      *this = *this / rhs;

      this->simplify();
      return *this;
   }

   Fraction Fraction::operator++() {
      *this += 1;

      this->simplify();
      return *this;
   }

   Fraction Fraction::operator++(int) {
      Fraction temp = *this;
      *this += 1;
      
      this->simplify();
      temp.simplify();
      return temp;
   }

   Fraction Fraction::operator--() {
      *this -= 1;

      this->simplify();
      return *this;
   }

   Fraction Fraction::operator--(int) {
      Fraction temp = *this;
      *this -= 1;

      this->simplify();
      temp.simplify();
      return temp;
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

   */
   void Fraction::simplify() {
      int greatestNum = numerator > denominator ? numerator : denominator;

      for (int i = 2; i < greatestNum; i++) {
         while (numerator % i == 0 && denominator % i == 0) {
            numerator /= i;
            denominator /= i;
         }
      }

      if (abs(numerator) % denominator == 0) {
         numerator = numerator / denominator;
         denominator = 1;
      }

      if (denominator < 0) {
         numerator *= -1;
         denominator *= -1;
      }

      if (numerator == 0) {
         denominator = 1;
      }
   }
}
