#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

/*

    ALEX LEE
    PROFESSOR HARDEN
    COMS 215
    mystring.h

    The MyString class creates objects that hold a dynamically allocated single string with a character limit of 127.
    The following functions are available:

    MyString();
        post: constructs MyString object with empty string data member.

    MyString(const char* inString);
        pre: inString is a declared/assigned char array.
        post: constructs MyString object with populated string data member copying inString.

    MyString(const MyString& inString);
        pre: inString is a declared/assigned MyString object with an assigned string data member.
        post: constructs MyString object with populated string data member copying inString.

    ~MyString();
        post: deallocates memory for calling object string data member.

    MyString operator=(const MyString& inString);
        post: calling MyString object is assigned with the deep copied string data member value of inString

    friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        pre: MyString source object has populated string data member
        post: contents of MyString are output into ostream

    friend std::istream& operator>>(std::istream& in, MyString& target);
        pre: calling input stream is populated with data
        post: string data member of MyString target is assigned to the contents of the input stream up to whitespace.

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
        pre: calling object is either a c-string or a MyString object
        post: returns MyString object with right-hand MyString object concatenated onto the string data member of the left hand object.

    friend bool operator==(const MyString& lhs, const MyString& rhs);
        post: returns true if the string data member of MyString lhs is equal to rhs

    friend bool operator<(const MyString& lhs, const MyString& rhs);
        post: returns true if the string data member of MyString lhs is ASCII less than rhs

    friend bool operator!=(const MyString& lhs, const MyString& rhs) { return !(lhs == rhs); }
        post: returns true if the string data member of MyString lhs is not equal to rhs

    friend bool operator>(const MyString& lhs, const MyString& rhs) { return rhs < lhs; }
        post: returns true if the string data member of MyString lhs is ASCII greater than rhs

    friend bool operator<=(const MyString& lhs, const MyString& rhs) { return !(lhs > rhs); }
        post: returns true if the string data member of MyString lhs is ASCII less than or equal to rhs

    friend bool operator>=(const MyString& lhs, const MyString& rhs) { return !(lhs < rhs); }
        post: returns true if the string data member of My String lhs is ASCII greater than or equal to rhs

    MyString operator+=(const MyString& right);
        post: calling MyString object has the string data member of the right-hand object concatenated upon its string data member

    char& operator[](int index);
        post: returns reference to char stored in index index of string data member

    char operator[](int index) const;
        post: returns read-only copy of char stored in index index of string data member

    int length() const;
        post: returns int number of characters in string data member of calling object

    void read(std::istream& in, char delimChar);
        pre: istream in is populated with appropriate data
        post: delimChar is assigned to lines up to user-input delimiter character

*/

namespace cs_mystring {
    class MyString {
    public:
        static const int MAX_INPUT_SIZE = 127;
        MyString();
        MyString(const char* inString);
        MyString(const MyString& inString);
        ~MyString();
        MyString operator=(const MyString& inString);
        friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        friend MyString operator+(const MyString& lhs, const MyString& rhs);
        friend bool operator==(const MyString& lhs, const MyString& rhs);
        friend bool operator<(const MyString& lhs, const MyString& rhs);
        friend bool operator!=(const MyString& lhs, const MyString& rhs) { return !(lhs == rhs); }
        friend bool operator>(const MyString& lhs, const MyString& rhs) { return rhs < lhs; }
        friend bool operator<=(const MyString& lhs, const MyString& rhs) { return !(lhs > rhs); }
        friend bool operator>=(const MyString& lhs, const MyString& rhs) { return !(lhs < rhs); }
        MyString operator+=(const MyString& right);
        char& operator[](int index);
        char operator[](int index) const;
        int length() const;
        void read(std::istream& in, char delimChar);
    private:
        char* string;
    };
}

#endif