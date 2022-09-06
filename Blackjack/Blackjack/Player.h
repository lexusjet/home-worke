#pragma once
#include "GenericPlayer.h"
class Player :
    public GenericPlayer
{
public:
    Player(std::string name_) :GenericPlayer(name_) {};

    //спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде true или false.
    bool IsHitting() const override;

    void Win() const;

    void Lose() const;

    void Push() const;


};

