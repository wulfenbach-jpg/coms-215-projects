/*
   ALEX LEE
   24 FEBRUARY 2024
   COMS 215
   DAVID HARDEN
   Project 12.2 / Assignment 3P
   This program plays a number guessing game with the user. Given a number between a lower and upper limit, which are defined as global constants, in this case, 1 and 100, the program
   will make guesses whilst the user tells the program to guess either higher or lower.
*/

#include <iostream>
using namespace std;

const int LOWER_LIMIT = 1;
const int UPPER_LIMIT = 100;

void playOneGame();
void getUserResponseToGuess(int guess, char& result);
int getMidpoint(int low, int high);

int main() {
   char response;

   cout << "Ready to play (y/n)? ";
   cin >> response;
   while (response == 'y') {
      playOneGame();
      cout << "Great! Do you want to play again (y/n)? ";
      cin >> response;
   }
}

// Main gameplay function. Prompts user to think of a number between the upper limit and lower limit. Calls functions defined below for user input.
void playOneGame() {
   int computerGuess = 50;
   char result = ' ';
   int upperLimit = UPPER_LIMIT;
   int lowerLimit = LOWER_LIMIT;

   cout << "Think of a number between " << LOWER_LIMIT << " and " << UPPER_LIMIT << "." << endl;
   while (result != 'c') {
      getUserResponseToGuess(computerGuess, result);
      if (result == 'h') {
         lowerLimit = computerGuess + 1;
      }
      else if (result == 'l') {
         upperLimit = computerGuess - 1;
      }
      computerGuess = getMidpoint(lowerLimit, upperLimit);
   }
}

// User input function. Tells the user what its guess is and prompts them to tell them whether to go higher or lower for the next guess, put into the pass-by reference char& result utilized in playOneGame();
void getUserResponseToGuess(int guess, char& result) {
   cout << "My guess is " << guess << ". Enter 'l' if your number is lower, 'h' if it is higher, 'c' if it is correct: ";
   cin >> result;
}

// Gets the midpoint of two numbers. Utilizes integers to always choose the lowest of the low and high, essentially a flooring average fn().
int getMidpoint(int low, int high) {
   return (high + low) / 2;
}