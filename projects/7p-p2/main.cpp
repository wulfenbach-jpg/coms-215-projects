/*
ALEX LEE
COMS 215
HARDEN
19 MAR 2024

This program records high-score data. The program asks the user to enter the number of scores. It then respectively creates two dynamic arrays, each sized accordingly.
It then asks the user to enter the previously-entered number of names and scores. It then prints those scores in descending order.
*/

#include <iostream>
#include <utility>
using namespace std;


// void readData(string names[], int scores[], int size);
//   post: dynamic arrays names[] and scores[] are set to user-input size and are populated
void readData(string names[], int scores[], int size);


// sortData(string names[], int scores[], int size);
//   post: data in names[] and scores[] arrays are sorted into descending order
void sortData(string names[], int scores[], int size);


// displayData(const string names[], const int scores[], int size);
//   post: prints list of names and corresponding scores
void displayData(const string names[], const int scores[], int size);

int main() {
   int size;

   // reads # of scores and allocates dynamic arrays to heap
   cout << "How many scores will you enter?: ";
   cin >> size;
   string* names = new string[size];
   int* scores = new int[size];

   readData(names, scores, size); // populates dynamic arrays
   sortData(names, scores, size); // sorts arrays into descending order
   displayData(names, scores, size); // prints out names and scores

   // deallocates names and scores from heap
   delete [] names;
   delete [] scores;

   return 0;
}

void readData(string names[], int scores[], int size) {
   for (int i = 0; i < size; i++) {
      cout << "Enter the name for score #" << i + 1 << ": ";
      cin >> names[i];
      cout << "Enter the score for score #" << i + 1 << ": ";
      cin >> scores[i];
   }
   cout << endl;
}

void sortData(string names[], int scores[], int size) {
   for (int i = 0; i < size - 1; i++) {
      int greatestIndex = i;

      for (int count = i + 1; count < size; count++) {
         if (scores[count] > scores[greatestIndex]) {
            greatestIndex = count;
         }
      }

      swap(scores[greatestIndex], scores[i]);
      swap(names[greatestIndex], names[i]);
   }
      
  
}

void displayData(const string names[], const int scores[], int size) {
   cout << "Top Scorers:" << endl;
   for (int i = 0; i < size; i++) {
      cout << names[i] << ": " << scores[i] << endl;
   }
}