#include "Game.h"
Game::Game(std::vector<std::string> names)
{
	for (size_t i = 0; i < names.size(); i++)
	{
		players.push_back( Player(names[i]) );
	}
}
void Game::play()
{
	using namespace std;

	auto print_line = []() {cout << "__________________\n"; };
	while (players.size()) 
	{
		// раздаем карты игрокам
		for (size_t i = 0; i < players.size(); i++)
		{
			deck.Deal(static_cast<Player&>(players[i]));
			deck.Deal(static_cast<Player&>(players[i]));
		}

		// раздаем карты казино
		deck.Deal(static_cast<House&>(house));
		house.FlipFirstCard();
		print_line();
		// выводится на экран информация о картах каждого игра, в т.ч. и для дилера
		for (size_t i = 0; i < players.size(); i++)
		{			
			cout << players[i].name << " cards\n" << players[i] << endl;
			print_line();
		}
		cout << "House cards \n" << house << endl;
		print_line();

		//Затем раздаются игрокам дополнительные карты
		for (size_t i = 0; i < players.size(); i++)
		{
			deck.AddltionalCards(static_cast<Player&>(players[i]));
			print_line();
		}

		//Потом показывается первая карта дилера 
		house.FlipFirstCard();
		cout << "House cards \n" << house << endl;
		print_line();

		//дилер набирает карты
		deck.AddltionalCards(static_cast<House&>(house));

		// После этого выводится сообщение, кто победил, а кто проиграл.
		for (size_t i = 0; i < players.size(); i++)
		{
			if (players[i].IsBoosted() == true) players[i].Lose();
			else if(house.IsBoosted() == true) players[i].Win();
			else if (players[i].GetValue() > house.GetValue()) players[i].Win();
			else if (players[i].GetValue() == house.GetValue()) players[i].Push();
			else players[i].Lose();
		}

		//В конце руки всех игроков очищаются
		for (size_t i = 0; i < players.size(); i++)
		{
			players[i].Clear();
		}
		house.Clear();

		for (size_t i = 0; i < players.size(); i++)
		{
			string str;
			do
			{
				cout << players[i].name << " want to continue playing [y/n]: ";
				cin >> str;
				if (str == "y" || str == "yes") break;
				else if (str == "n" || str == "no")
				{
					players.erase(players.begin() + i);
					i--;
					break;
				}

				str.clear();
				cout << "Incorect input, please try again.\n";
			} while (true);
		}		
	}
}


