#pragma once
#include "Hand.h"
#include "GenericPlayer.h"
#include <array>

class Deck :
    public Hand
{
public:
    Deck();

    //������� ����������� ������ �� 52 ����, ���������� �� ������������.
    void Populate(); 

    // �����, ������� ������ �����, ����� ������������ ������� �� ���������� STL random_shuffle
    void Shuffle(); 

    // �����, ������� ������� � ���� ���� �����
    void Deal(Hand& aHand); 

    // ������� ������ �������������� ����� �� ��� ���, ���� �� ����� � ����� �� ��������
    void AddltionalCards(GenericPlayer& aGenerlcPlayer); 

private:

    // ������ ���� 
    std::vector<Card> deck;
};

