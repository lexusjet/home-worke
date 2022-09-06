#include "Player.h"
#include <iostream>
#include <string>

//спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
bool Player::IsHitting() const 
{
	using namespace std;
	string str;

	do {
		cout << "do you need one more caard ? [y/n]: ";
		getline(cin, str);
		if (str == "y" || str == "yes") return true;
		else if (str == "n" || str == "no") return false;
		
		str.clear();
		cout << "Incorect input, please try again.\n";
		
	} while (true);
}

// печатем что игрок выйграл
void Player::Win() const
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleTextAttribute(handle, GREEN);
	std::cout << "Player " << name << " Win\n";
	std::cout.flush();
	SetConsoleTextAttribute(handle, WHITE);
}

// печатем что игрок проиграл
void Player::Lose() const
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	SetConsoleTextAttribute(handle, RED);
	std::cout << "Player " << name << " Lost\n";
	std::cout.flush();
	SetConsoleTextAttribute(handle, WHITE);
}

// печатем что игрок сыграл вничью
void Player::Push() const
{
	std::cout <<"The player " << name << " has tied\n";
}