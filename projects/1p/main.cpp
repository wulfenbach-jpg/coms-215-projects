/*
   ALEX LEE
   6 FEBRUARY 2024
   COMS 215
   DAVID HARDEN
   Project 4.5 / Assignment 1P
   This program requests user input in the format M/DD/YY. This program then checks to see if the month times the date equals the year value.
   If so, it will state a message stating that the date is 'magic.' If not, it will state a message saying the message is 'not magic.'
*/

#include <iostream>
using namespace std;

int main() {
   int month;
   int day;
   int year;

   cout << "Enter a date in the format month/day/2-digit-year: ";
   cin >> month;
   cin.ignore();
   cin >> day;
   cin.ignore();
   cin >> year;

   if (month * day == year) {
      cout << "That is a magic date!" << endl;
   }
   else {
      cout << "That is not a magic date!" << endl;
   }

}