#include <iostream>
#include <string>

using namespace std;

class Name {
    Name(string first, string last) {
        this.first = first;
        this.last = last;
    };

    private : std::string first, last;
};