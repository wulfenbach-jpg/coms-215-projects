#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

namespace cs_mystring {
    class MyString {
    public:
        MyString();
        MyString(const char* inString);
        MyString(const MyString& inString);
        ~MyString();
        MyString operator=(const MyString& inString);
        friend std::ostream& operator<<(std::ostream& out, const MyString& source);
        friend bool operator==(const MyString& lhs, const MyString& rhs);
        friend bool operator<(const MyString& lhs, const MyString& rhs);
        friend bool operator!=(const MyString& lhs, const MyString& rhs) { return !(lhs == rhs); }
        friend bool operator>(const MyString& lhs, const MyString& rhs) { return rhs < lhs; }
        friend bool operator<=(const MyString& lhs, const MyString& rhs) { return !(lhs > rhs); }
        friend bool operator>=(const MyString& lhs, const MyString& rhs) { return !(lhs < rhs); }
        char& operator[](int index);
        char operator[](int index) const;
        int length() const;
    private:
        char* string;
    };
}

#endif