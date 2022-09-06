#include "Deck.h"
#include <algorithm>

Deck::Deck()
{
	Populate();
	Shuffle();
}

//Создает стандартную колоду из 52 карт, вызывается из конструктора.
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

// Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
void Deck::Shuffle()
{
	std::srand(std::time(0));
	auto lmd = [](int x){return(std::rand() % x);};
	std::random_shuffle(hand.begin(), hand.end() ,lmd);
}

// метод, который раздает в руку одну карту
void Deck::Deal(Hand& aHand)
{	
	aHand.Add(hand.back());
	hand.pop_back();
}

// раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
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