// Blackjack.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <sstream>
#include "Hand.h"
#include "Game.h"

int get_int();

void get_names(int a, std::vector<std::string>& name);

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);
	using namespace std;

	vector < string> names;
	int num_of_players = get_int();
	get_names(num_of_players, names);

	Game a(names);
	a.play();

}


int get_int()
{
	using namespace std;

	string line;
	int anser;
	do
	{
		cout << "Please enter a number of players: ";

		getline(cin, line);
		if (line.size() < to_string(INT_MAX).size() )
		{
			stringstream ss(line);
			if ((ss >> anser) && ss.eof()) 
			{
				if( (anser < 5) && (anser > 0) ) return anser;
			}
			cout << "Incorect input, please try again.\n";
		}
		else
		{
			cout << "Too big number , the number should not be larger then " << INT_MAX << endl;
		}
	} while (true);
}

void get_names(int a, std::vector<std::string>& name)
{
	name.resize(a);
	for (size_t i = 0; i < a; i++)
	{
		std::cout << "Plese enter name of player " << i<< " :";
		std::getline(std::cin, name[i]);
	}

}