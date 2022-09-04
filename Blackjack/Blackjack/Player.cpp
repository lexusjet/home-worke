#include "Player.h"
#include <iostream>
#include <string>
bool Player::IsHitting() const 
{
	using namespace std;
	do {
		string str;
		cout << "Do you need one more caard ? [y/n]: \n";
		getline(cin, str);


		if (str == "y" || str == "yes") return true;
		else if (str == "n" || str == "no") return false; \
		else cout << "Incorect input, please try again.\n";
	} while (true);
}
void Player::Win() const
{
	std::cout << "Player " << name << "Win\n";
}
void Player::Lose() const
{
	std::cout << "Player " << name << "Lost\n";
}
void Player::Push() const
{
	std::cout <<"Åhe player " << name << " has tied\n";
}