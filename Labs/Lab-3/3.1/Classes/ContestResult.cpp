/*
    Write the implementation (.cpp file) of the ContestResult class from the ContestResult.h exercise. Again, the class contains:

    - A data member winner of type , initialized to the empty string.
    - A data member secondPlace of type , initiaized to the empty string.
    - A data member thirdPlace of type , initiaized to the empty string.
    - A member function called setWinner that has one parameter, whose value it assigns to the data member winner.
    - A member function called setSecondPlace that has one parameter, whose value it assigns to the data member secondPlace.
    - A member function called setThirdPlace that has one parameter, whose value it assigns to the data member thirdPlace.
    - A member function called getWinner that has no parameters and that returns the value of the data member winner.
    - A member function called getSecondPlace that has no parameters and that returns the value of the data member secondPlace.
    - A member function called getThirdPlace that has no parameters and that returns the value of the data member thirdPlace.
*/

#include "ContestResult.h"
#include <string>

using namespace std;

void ContestResult::setWinner(string aWinner) {
    winner = aWinner;
}
void ContestResult::setSecondPlace(string aSecondPlace) {
    secondPlace = aSecondPlace;
}
void ContestResult::setThirdPlace(string aThirdPlace) {
    thirdPlace = aThirdPlace;
}

string ContestResult::getWinner() {
    return winner;
}
string ContestResult::getSecondPlace() {
    return secondPlace;
}
string ContestResult::getThirdPlace() {
    return thirdPlace;
}