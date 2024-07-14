/*
    Write the implementation (.cpp file) of a class Counter containing:
        - An instance variable counter of type int, initialized to 0.
        - A function called increment that adds one to the instance variable counter. It does not accept parameters or return a value.
        - A function called getValue that doesn't accept any parameters. It returns the value of the instance variablec ounter.
        - A default constructor.
*/

#include "Counter.h"
#include <string>

using namespace std;

Counter::Counter() {
    counter = 0;
}

void Counter::increment() {
    counter++;
}

int Counter::getValue() {
    return counter;
}