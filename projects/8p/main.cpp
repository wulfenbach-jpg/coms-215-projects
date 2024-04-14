#include <iostream>
#include <cstring>
using namespace std;

// post: returns last index where char target is found in inString. returns -1 if is not present. case-sensitive.
int lastIndexOf(const char* inString, char target);

// post: alters inString to be reversed in place.
void reverse(char* inString);

// post: alters inString by replacing all target chars with replacementChars. returns number of replacements made.
int replace(char* inString, char target, char replacementChar);

// post: returns if inString is a palindrome.
bool isPalindrome(const char* inString);

// converts inString to uppercase.
void toupper(char* inString);

// returns number of letters in string.
int numLetters(const char* inString);

int main() {
   char dog[10] = "Corgi";
   char country[8] = "america";
   char testStr[15] = "1234567890abcd";
   char palindrome[7] = "Hannah";

   cout << "No index of a in string Corgi. Should return -1. Returns: " << lastIndexOf(dog, 'a') << endl;
   cout << "Index of a in string america. Should return 6. Returns: " << lastIndexOf(country, 'a') << endl << endl;

   reverse(country);
   cout << "Swapping america. Should print acirema. Prints: " << country << endl;
   reverse(testStr);
   cout << "Swapping testString. Should print dcba0987654321. Prints: " << testStr << endl << endl;
   // undoing reverses
   reverse(country);
   reverse(testStr);

   cout << "Replacing all a's in america with $'s. " << replace(country, 'a', '$') << " replacements made. Should print $meric$. Prints: " << country << endl;
   cout << "Replacing all z's in corgi with $'s. " << replace(dog, 'z', '$') << " replacements made. Should print Corgi. Prints: " << dog << endl << endl;

   cout << "Hannah is a palindrome. Should return 1. Returns: " << isPalindrome(palindrome) << endl;
   cout << "Corgi is not a palindrome. Should return 0. Returns: " << isPalindrome(dog) << endl << endl;

   toupper(dog);
   cout << "Capitalizing Corgi. Should return CORGI. Returns: " << dog << endl;
   toupper(country);
   cout << "Capitalizing $meric$. Should return $MERIC$. Returns: " << country << endl << endl;

   cout << "Testing letter counting. Should return 4. Returns: " << numLetters(testStr) << endl;
   cout << "Should return 6. Returns " << numLetters(palindrome) << endl << endl;



   return 0;
}

int lastIndexOf(const char* inString, char target) {
   int strLen = strlen(inString);
   int lastIndex = -1;
   for (int i = strLen - 1; i >= 0 && lastIndex == -1; i--) {
      if (inString[i] == target) {
         lastIndex = i;
      }
   }
   return lastIndex;
}

void reverse(char* inString) {
   int stringLength = strlen(inString);
   
   for (int i = 0; i < stringLength / 2; i++) {
      swap(inString[i], inString[stringLength - (i + 1)]);
   }
}

int replace(char* inString, char target, char replacementChar) {
   int replacementsMade = 0;
   for (int i = 0; inString[i] != '\0'; i++) {
      if (inString[i] == target) {
         inString[i] = replacementChar;
         replacementsMade++;
      }
   }
   return replacementsMade;
}

bool isPalindrome(const char* inString) {
   int stringLength = strlen(inString);
   int palindromicLettersFound = 0;

   for (int i = 0; i < stringLength / 2; i++) {
      if (tolower(inString[i]) == tolower(inString[stringLength - (i + 1)])) {
         palindromicLettersFound++;
      }
   }

   return palindromicLettersFound == stringLength / 2;
}

void toupper(char* inString) {
   for (int i = 0; inString[i] != '\0'; i++) {
      inString[i] = toupper(inString[i]);
   }
}

int numLetters(const char* inString) {
   int numLetters = 0;
   for (int i = 0; inString[i] != '\0'; i++) {
      if (isalpha(inString[i]) != false) {
         numLetters++;
      }
   }
   return numLetters;
}