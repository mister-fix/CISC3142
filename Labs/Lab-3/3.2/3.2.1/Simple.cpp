#include "Simple.h"

#include <iostream>

using namespace std;

int main() {
    cout << "Working with int" << endl;
	Simple<int> si(10);
	cout << "After initialization to 10 si: " << si.getVal() << endl;
	si.setVal(23);
	cout << "After setVal(23) si: " << si.getVal() << endl;
	cout << "Calling print: ";
	si.print();
	cout << endl << endl;

    cout << "Working with double" << endl;
    Simple<double> sd(10.5);
    cout << "After initialization to 10.5 sd: " << sd.getVal() << endl;
    sd.setVal(23.5);
    cout << "After setVal(23.5) sd: " << sd.getVal() << endl;
    cout << "Calling print: ";
    sd.print();
    cout << endl << endl;

    cout << "Working with string" << endl;
    Simple<string> ss("Hello");
    cout << "After initialization to \"Hello\" ss: " << ss.getVal() << endl;
    ss.setVal("Goodbye");
    cout << "After setVal(\"Goodbye\") ss: " << ss.getVal() << endl;
    cout << "Calling print: ";
    ss.print();
    cout << endl << endl;

    return 0;
};