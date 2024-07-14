/*
    Write the implmentation (.cpp file) of the Player class from the Player.h exercise. Again, the class contains:

    - A data member name of type string.
    - A data member score of type int.
    - A member function called setName that accepts a parameter and assigns it to name. The function returns no value.
    - A member function called setScore that accepts a parameter and assigns it to score. The function returns no value.
    - A member function called getName that accepts no parameters and returns the value of name.
    - A member function called getScore that accepts no parameters and returns the value of score.
*/

#include "player.h"
#include <string>

using namespace std;

void Player::setName(string aName) {
	name = aName;
}
void Player::setScore(int aScore) {
	score = aScore;
}

string Player::getName() {
	return name;
}