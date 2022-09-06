#pragma once
#include "Deck.h"
#include"Player.h"
#include "House.h"

class Game
{
	public:
	Game(std::vector<std::string> names);
	void play();

	Deck deck;					 // колода карт
	House house;				 // рука дилера
	std::vector<Player> players; // вектор игроков.

		
};

