/*
    Write the implmenetation (.cpp file) of the Counter class from the Counter2.cpp exercise. Here is the full specification of the class:
        - A data member counter of type int.
        - A constructor that takes one int argument.
        - A function called increment that accepts no parameters and returns no value.
        - A function called decrement that accepts no parameters and returns no value.
        - A function called getValue that accepts no parameters and returns an int.
*/

#include "Counter2.h"

using namespace std;

Counter2::Counter2(int aCounter) {
    counter = aCounter;
}

void Counter2::increment() {
    counter++;
}

void Counter2::decrement() {
    counter--;
}

int Counter2::getValue() {
    return counter;
}