#pragma once
#include "Deck.h"
#include"Player.h"
#include "House.h"

class Game
{
	public:
	Game(std::vector<std::string> names);
	void play();

	Deck deck;					 // ������ ����
	House house;				 // ���� ������
	std::vector<Player> players; // ������ �������.

		
};

