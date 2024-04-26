#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"
using namespace std;
/* 

    CLASS INVARIANT:
    A MyString object holds one data member, a dynamically allocated char array/c-string.
    Internal operations should always ensure that the object's char array is always dynamically allocated
    to the necessary size.

*/
namespace cs_mystring {
    MyString::MyString() {
        string = new char[1];
        strcpy(string, "");
    }

    MyString::MyString(const char* inString) {
        string = new char[strlen(inString) + 1];
        strcpy(string, inString);
    }

    MyString::MyString(const MyString& inString) {
        string = new char[strlen(inString.string) + 1];
        strcpy(string, inString.string);
    }

    MyString::~MyString() {
        delete[] string;
    }

    MyString MyString::operator=(const MyString& inString) {
        if (this != &inString) {
            delete[] string;
            string = new char[strlen(inString.string) + 1];
            strcpy(string, inString.string);
        }
        return *this;
    }

    ostream& operator<<(ostream& out, const MyString& source) {
        out << source.string;
        return out;
    }

    istream& operator>>(istream& in, MyString& target) {
        char temp[MyString::MAX_INPUT_SIZE + 1];

        in >> temp;
        delete[] target.string;
        target.string = new char[strlen(temp) + 1];
        strcpy(target.string, temp);

        return in;
    }
    
    MyString MyString::operator+=(const MyString& right) {
        *this = *this + right;

        return *this;
    }

    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(string));
        return string[index];
    }

    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(string));
        return string[index];
    }

    MyString operator+(const MyString& lhs, const MyString& rhs) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        MyString result;
        
        strcpy(temp, lhs.string);
        strcat(temp, rhs.string);
        delete[] result.string;
        result.string = new char[strlen(temp) + 1];
        strcpy(result.string, temp);

        return result;
    }

    bool operator==(const MyString& lhs, const MyString& rhs) {
        return strcmp(lhs.string, rhs.string) == 0;
    }

    bool operator<(const MyString& lhs, const MyString& rhs) {
        return strcmp(lhs.string, rhs.string) < 0;
    }

    int MyString::length() const { 
        return strlen(string); 
    }

    void MyString::read(std::istream& in, char delimChar) {
        char temp[MyString::MAX_INPUT_SIZE + 1];
        in.getline(temp, MyString::MAX_INPUT_SIZE, delimChar);
        delete[] string;
        string = new char[strlen(temp) + 1];
        strcpy(string, temp);
    }
}