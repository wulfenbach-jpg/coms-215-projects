/*
   ALEX LEE
   12 FEBRUARY 2024
   COMS 215
   DAVID HARDEN
   Project 7.4 / Assignment 2P
   This program simulates a simplified version of the card game Blackjack.
   The player is first given two integers, each of which is from 1-10, with equally weighted probabilities of getting any number. 
   The program counts the total added count of the player's cards (the randomized integers passed to the player at the start).
   The player is given the choice, after being told their total, to choose and add another card.
   The goal is to get to the number 21 in total.
   If the player gets the number 21, the program prints Congratulations!
   If the player gets over the number 21, the program prints Bust.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   int runningTotal;
   int startingCard1;
   int startingCard2;
   int tempCardValue;
   char stillPlaying;
   char wantsAnotherCard;
   // srand(static_cast<unsigned>(time(nullptr)));
   do {
      startingCard1 = rand() % 10 + 1;
      startingCard2 = rand() % 10 + 1;
      cout << "First cards: " << startingCard1 << ", " << startingCard2 << endl;
      runningTotal = startingCard1 + startingCard2;
      cout << "Total: " << runningTotal << endl;
      
      cout << "Do you want another card (y/n)? ";
      cin >> wantsAnotherCard;

      while (wantsAnotherCard == 'y') {
         tempCardValue = rand() % 10 + 1;
         cout << "Card: " << tempCardValue << endl;
         runningTotal += tempCardValue;
         cout << "Total: " << runningTotal << endl;

         if (runningTotal == 21) {
            cout << "Congratulations!" << endl;
            wantsAnotherCard = 'n';
         }
         else if (runningTotal > 21) {
            cout << "Bust." << endl;
            wantsAnotherCard = 'n';
         }
         else {
            cout << "Do you want another card (y/n)? ";
            cin >> wantsAnotherCard;
         }
      }
      cout << "Would you like to play again (y/n)? ";
      cin >> stillPlaying;
   } while (stillPlaying == 'y');

   return 0;
}
