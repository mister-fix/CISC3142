// #include <iostream>
// #include "mystring.h"
// #include "mystring_exception.h"
// #include <cstring>
// #pragma warning(disable : 4996)

// namespace mystring {
//     string::string(const char *cs)
//     {
//         this->cs = new char[strlen(cs) + 1];
//         strcpy(this->cs, cs);
//     }

//     string::string(const string &s)
//     {
//         cs = new char[length() + 1];
//         strcpy(cs, s.cs);
//     }

//     string::~string()
//     {
//         delete cs;
//     }

//     string &string::operator =(const string &rhs)
//     {
//         if (this != &rhs)
//         {
//             delete cs;
//             cs = new char[rhs.length()];
//             strcpy(cs, rhs.cs);
//         }
//         return *this;
//     }

//     char &string::operator [](int index)
//     {
//         if(index < 0 || index >= length()) {
//             throw string_Exception("Index out of bounds");
//         }
//         else {
//             return cs[index];
//         }
//     }

//     string &string::operator +=(const string &s)
//     {
//         char *temp = new char[length() + s.length() + 1];
//         strcpy(temp, cs);
//         strcat(temp, s.cs);

//         delete cs;
//         this->cs = temp;
//         return *this;
//     }

//     int string::length() const
//     {
//         if (cs == NULL) {
//             return 0;
//         }
//         return strlen(cs);
//     }

//     std::ostream &operator <<(std::ostream &os, const string &s)
//     {
//         os << s.cs;
//         return os;
//     }

//     string operator +(const string &s1, const string &s2)
//     {
//         char *temp = new char[s1.length() + s2.length() + 1];
//         strcpy(temp, s1.cs);
//         strcat(temp, s2.cs);
//         return string(temp);
//     }

//     void string::clear() {
//         cs[0] = '\0';
//     }
// }