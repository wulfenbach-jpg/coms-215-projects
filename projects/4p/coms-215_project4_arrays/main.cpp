/*
    Alex Lee
    3/1/2024
    COMS 215
    Project 13.1

    This project takes inspiration from the classic card game poker.
    The program reads a number of cards from the user, defined by a global constant, HAND_SIZE.
    The program then analyzes those cards, and prints out the kind of poker hand represented by those cards.
    Card suits and face cards will be ignored for the sake of simplicity.
    The values the user inputs must be between LOWEST_NUM to HIGHEST_NUM, defined by global constants.
    There is no input validation required for this program, and the user is presumed to always input valid data.
    The poker hands are categorized into the following, organized from least to most valuable:
    
    |-----------|---------------------------------|
    | Hand Type | Description                     |
    |-----------|---------------------------------|
    |-----------|---------------------------------|
    | High Card | There are no matching cards     |
    |           | and the hand is not a straight. |
    |-----------|---------------------------------|
    | Pair      | Two of the cards are the same   |
    |-----------|---------------------------------|
    | Two Pair  | Two different pairs.            |
    |-----------|---------------------------------|
    | Three of  | Three matching cards.           |
    |  a kind   |                                 |
    |-----------|---------------------------------|
    | Straight  | 5 consecutive cards             |
    |           | * regardless of the orde        | 
    |-----------|---------------------------------|
    | Full      | A pair and three of a kind      |
    |     house |                                 |
    |-----------|---------------------------------|
    | Four of a | Four or more matching cards     |
    |    kind   |                                 |
    |-----------|---------------------------------|
*/

#include <iostream>
using namespace std;

const int HAND_SIZE = 5;
const int LOWEST_NUM = 2;
const int HIGHEST_NUM = 9;

void promptUserHand(int hand[]);
int countNum(int num, const int array[]);
int countPairs(const int array[]);
int findMin(const int array[]);
int findMax(const int array[]);
bool isPresentNTimes(int num, const int hand[]);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);

int main() {
    int userHand[HAND_SIZE];

    cout << "Enter " << HAND_SIZE << " numeric cards, no face cards. Use 2 - 9." << endl;
    promptUserHand(userHand);
    if (containsFourOfaKind(userHand) == true) {
        cout << "Four of a kind!" << endl;
    }
    else if (containsFullHouse(userHand) == true) {
        cout << "Full House!" << endl;
    }
    else if (containsStraight(userHand) == true) {
        cout << "Straight!" << endl;
    }
    else if (containsThreeOfaKind(userHand) == true) {
        cout << "Three of a kind!" << endl;
    }
    else if (containsTwoPair(userHand) == true) {
        cout << "Two Pair!" << endl;
    }
    else if (containsPair(userHand) == true) {
        cout << "Pair!" << endl;
    }
    else {
        cout << "High card!" << endl;
    }
    return 0;
}

/*
    Prompts the user to input HAND_SIZE integers and stores them in input integer array hand[].

    post: hand[] is populated with user-input integers.
*/
void promptUserHand(int hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i];
    }
}

// pre: array[] is populated with integers
// post: returns # of instances num i is present in array[]
int countNum(int num, const int array[]) {
    int numInstances = 0;
    for (int i = 0; i < HAND_SIZE; i++) {
        if (array[i] == num) {
            numInstances++;
        }
    }
    return numInstances;
}

// post: returns # of pairs found in an array as an integer.
int countPairs(const int array[]) {
    int pairsFound = 0;
    for (int i = LOWEST_NUM; i < HIGHEST_NUM; i++) {
        if (countNum(i, array) == 2) {
            pairsFound++;
        }
    }
    return pairsFound;
}

// post: returns min # in array[].
int findMin(const int array[]) {
    int minNum = array[0];
    for (int i = 0; i < HAND_SIZE; i++) {
        if (array[i] < minNum) {
            minNum = array[i];
        }
    }
    return minNum;
}

// post: returns max # in array[].

int findMax(const int array[]) {
    int maxNum = array[0];
    for (int i = 0; i < HAND_SIZE; i++) {
        if (array[i] > maxNum) {
            maxNum = array[i];
        }
    }
    return maxNum;
}

/*
* Iterating through array hand[], it will return true if there is an integer from
* LOWEST_NUM to HIGHEST_NUM that appears numIn times.
* 
* post: returns true if any integer appears numIn times
*/
bool isPresentNTimes(int numIn, const int hand[]) {
    bool presentNTimes = false;
    for (int i = LOWEST_NUM; i < HIGHEST_NUM; i++) {
        if (countNum(i, hand) == numIn) {
            presentNTimes = true;
        }
    }
    return presentNTimes;
}

// post:  returns true if and only if there are one or more pairs in the hand.  Note that
// this function returns false if there are more than two of the same card (and no other pairs).
bool containsPair(const int hand[]) {
    return countPairs(hand) >= 1;
}

// post: returns true if and only if there are two or more pairs in the hand. 
bool containsTwoPair(const int hand[]) {
    return countPairs(hand) == 2;
}

// post: returns true if and only if there are one or more three-of-a-kind's in the hand. 
bool containsThreeOfaKind(const int hand[]) {
    return isPresentNTimes(3, hand);
}

// post: returns true if there are 5 consecutive cards in the hand.
bool containsStraight(const int hand[]) {
    bool nonStraightFound = false;
    for (int i = findMin(hand); i <= findMax(hand); i++) {
        if (countNum(i, hand) != 1) {
            nonStraightFound = true;
        }
    }
    return !nonStraightFound;
}

// post: returns true if there is are one or more pairs and one or more three-of-a-kind's in the hand.  
bool containsFullHouse(const int hand[]) {
    return containsPair(hand) && containsThreeOfaKind(hand);
}

// post: returns true if there are one or more four-of-a-kind's in the hand.
bool containsFourOfaKind(const int hand[]) {
    return isPresentNTimes(4, hand) || isPresentNTimes(5, hand);
}