#include "Deck.h"
#include <algorithm>

Deck::Deck()
{
	Populate();
	Shuffle();
}

//������� ����������� ������ �� 52 ����, ���������� �� ������������.
void Deck::Populate()
{
	hand.reserve(52 * 4);
	deck.reserve(52 * 4);

	for (int i = diamonds; i <= spades; i++)
	{
		for (int j = two; j <= ace; j++)
		{
			deck.push_back(Card(i, j, open));
			hand.push_back(&deck.back());
		}
	}	
}

// �����, ������� ������ �����, ����� ������������ ������� �� ���������� STL random_shuffle
void Deck::Shuffle()
{
	std::srand(std::time(0));
	auto lmd = [](int x){return(std::rand() % x);};
	std::random_shuffle(hand.begin(), hand.end() ,lmd);
}

// �����, ������� ������� � ���� ���� �����
void Deck::Deal(Hand& aHand)
{	
	aHand.Add(hand.back());
	hand.pop_back();
}

// ������� ������ �������������� ����� �� ��� ���, ���� �� ����� � ����� �� ��������
void Deck::AddltionalCards(GenericPlayer& aGenerlcPlayer)
{
	std::cout << aGenerlcPlayer.name << " ";

	while (deck.size())
	{		
		if (aGenerlcPlayer.IsBoosted() == true)
		{
			std::cout << std::endl;
			aGenerlcPlayer.Bust();
			return;
		}
		else if (aGenerlcPlayer.IsHitting() == true)
		{
			Deal(aGenerlcPlayer);
			std::cout << *aGenerlcPlayer.hand.back() << u8" ";
		}
		else 
		{
			std::cout << std::endl;
			return;
		}
	}
}