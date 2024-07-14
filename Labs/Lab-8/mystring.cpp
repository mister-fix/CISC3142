#include <iostream>
#include <cstring>
#include "mystring.h"
#include "mystring_exception.h"

namespace mystring {
    // Constructor
    string::string(const char *cs) : cs(new char[strlen(cs) + 1]) {
        strcpy(this->cs, cs);
    }

    // copy string
    string::string(const string &s) : string(s.cs) {
        // cs = new char[length() + 1];
        strcpy(cs, s.cs);
    }

    // delete
    string::~string() {
        delete[] cs;
    }

    // check equal
    string &string::operator =(const string &rhs) {
        strcpy(cs, rhs.cs);

        return *this;
    }

    // get index
    char &string::operator [](int index) {
        if(index < 0 || index >= length()) {
            throw string_Exception("Index out of bounds");
        }
        else {
            return cs[index];
        }
    }

    // concat
    string &string::operator +=(const string &s) {
        int nLength = length() + s.length();
        char *c1 = new char[nLength + 1];

        strcpy(c1, cs);
        strcat(c1, s.cs);

        delete[] cs;
        cs = c1;

        return *this;
    }

    // length
    int string::length() const {
        return strlen(this->cs);
    }

    // clear
    void string::clear() {
        cs[0] = '\0';
    }

    // ostream
    std::ostream &operator <<(std::ostream &os, const string &s) {
        os << s.cs;

        return os;
    }

    // add
    string operator +(const string &s1, const string &s2) {
        string s3(s1);
        s3 += s2;

        return s3;
    }
}