/*
    Write the interface (.h file) of a class GasTank containing:
        - A data member named amount of type double.
        - A constructor that accepts no parameters.
        - A function named addGas that accepts a parameter of type double and returns no value.
        - A function named useGas that accepts a parameter of type double and returns no value.
        - A function named isEmpty that accepts no parameters and returns a boolean value.
        - A function named getGasLevel that accepts no parameters and returns a double.
*/

class GasTank {
    public:
        GasTank();
        void addGas(double);
        void useGas(double);
        bool isEmpty();
        double getGasLevel();

    private:
        double amount;
};