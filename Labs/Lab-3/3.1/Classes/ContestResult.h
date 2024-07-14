/*
    Write the interface (.h file) of a class ContestResult containing:

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

class ContestResult {
    private:
        string winner = "";
        string secondPlace = "";
        string thirdPlace = "";

    public:
        void setWinner(string aWinner);
        void setSecondPlace(string aSecondPlace);
        void setThirdPlace(string aThirdPlace);

        string getWinner();
        string getSecondPlace();
        string getThirdPlace();
};