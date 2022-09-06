#pragma once
#include "Hand.h"
#include "GenericPlayer.h"
#include <array>

class Deck :
    public Hand
{
public:
    Deck();

    //Создает стандартную колоду из 52 карт, вызывается из конструктора.
    void Populate(); 

    // Метод, который тасует карты, можно использовать функцию из алгоритмов STL random_shuffle
    void Shuffle(); 

    // метод, который раздает в руку одну карту
    void Deal(Hand& aHand); 

    // раздает игроку дополнительные карты до тех пор, пока он может и хочет их получать
    void AddltionalCards(GenericPlayer& aGenerlcPlayer); 

private:

    // колода карт 
    std::vector<Card> deck;
};

