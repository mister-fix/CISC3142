/*
    Write the implementation (.cpp file) of the GasTank class of the previous exercise. The full specification of the class is:
        - A data member named amount of type double.
        - A constructor that accepts no parameters. The constructor initializes the data member amount to 0.
        - A function named addGas that accepts a parameter of type double. The value of the amount data member is increased by the value of the parameter.
        - A function named useGas that accepts a parameter of type double. The value of the amount data member is decreased by the value of the parameter.
          However, if the value of amount is decreased below 0, the amount is set to 0.
        - A function named isEmpty that accepts no parameters and returns a boolean value. isEmpty returns a boolean value: tru eif the value of amount is than 0.1, and false otherwise.
        - A function named getGasLevel that accepts no parameters. getGasLevel returns the value of the amount data member.
*/

#include "GasTank.h"

using namespace std;

GasTank::GasTank() {
	amount = 0;
}
void GasTank::addGas(double addAmount) {
	amount += addAmount;
}
void GasTank::useGas(double useAmount) {
	amount -= useAmount;
	
	if(amount < 0) amount = 0;
}
bool GasTank::isEmpty() {
	if(amount < 0.1) return true;
	
	return false;
}
double GasTank::getGasLevel() {
	return amount;
}