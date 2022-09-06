#pragma once
#include "GenericPlayer.h"
class Player :
    public GenericPlayer
{
public:
    Player(std::string name_) :GenericPlayer(name_) {};

    //���������� � ������������, ����� �� ��� ��� ���� ����� � ���������� ����� ������������ � ���� true ��� false.
    bool IsHitting() const override;

    void Win() const;

    void Lose() const;

    void Push() const;


};

