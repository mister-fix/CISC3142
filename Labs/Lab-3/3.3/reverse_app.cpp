#include "reverse.h"
#include <iostream>

using namespace std;

int main() {
    // Working with integer array
    cout << "Playing with int" << endl;
    int intArr[] = {10, 20, 30, 40, 50};
    cout << "Before: ";
    print<int>(intArr, 5);
    cout << endl;
    reverse<int>(intArr, 5);
    cout << "After: ";
    print<int>(intArr, 5);
    cout << endl << endl;
    
    // Working with double array
    cout << "Playing with double" << endl;
    double dblArr[] = {10.5, 20.5, 30.5, 40.5, 50.5, 60.5};
    cout << "Before: ";
    print<double>(dblArr, 6);
    cout << endl;
    reverse<double>(dblArr, 6);
    cout << "After: ";
    print<double>(dblArr, 6);
    cout << endl << endl;
    
    // Working with string array
    cout << "Playing with string" << endl;
    string strArr[] = {"ABC", "DE", "FGHI", "JK"};
    cout << "Before: ";
    print<string>(strArr, 4);
    cout << endl;
    reverse<string>(strArr, 4);
    cout << "After: ";
    print<string>(strArr, 4);
    cout << endl << endl;

    return 0;
};