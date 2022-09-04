#pragma once
#include "GenericPlayer.h"
class House :
    public GenericPlayer
{
public:
    House(std::string name_ = "House"): GenericPlayer(name_){}
    bool IsHitting() const override;
    void FlipFirstCard();
};

