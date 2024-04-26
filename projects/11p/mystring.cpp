#pragma warning(disable:4996)
#include <iostream>
#include <cassert>
#include <cstring>
#include "mystring.h"
using namespace std;

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

    char& MyString::operator[](int index) {
        assert(index >= 0 && index < strlen(string));
        return string[index];
    }

    char MyString::operator[](int index) const {
        assert(index >= 0 && index < strlen(string));
        return string[index];
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
}