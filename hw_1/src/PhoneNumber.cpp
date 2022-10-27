#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(int a, int b, const char c)
{
    country = a;
    town = b;
    number = c;
}
PhoneNumber::PhoneNumber(int a, int b, const char* c, std::optional<int> d){
    country = a;
    town = b;
    number = c;
    if(d != std::nullopt)
        special= d;
}
PhoneNumber::PhoneNumber(std::string a, std::string b, std::string c)
{
    this->country = std::stoi(a);
    this->town = std::stoi(b);
    this->number = c;
}

PhoneNumber::PhoneNumber(std::string a, std::string b, std::string c , std::string d)
{
    this->country = std::stoi(a);
    this->town = std::stoi(b);
    this->number = c;
    this->special = std::stoi(d);
}

void PhoneNumber::operator=(PhoneNumber b){
    country = b.country;
    town =  b.town;
    number = b.number;
    special.reset();
    if(b.special)
        this->special = b.special;
}

bool PhoneNumber::operator <(PhoneNumber b) const {
    int zer =0;
    if(special && b.special)
    {
        return std::tie(country, town, number, *special)<
        std::tie(b.country, b.town, b.number, *b.special);
    }
    else if(special)
    {
        return std::tie(country, town, number, *special)<
        std::tie(b.country, b.town, b.number, zer);
    }
    else if(b.special)
    {
        return std::tie(country, town, number, zer)<
        std::tie(b.country, b.town, b.number, *b.special);;
    }
    else
    {
        return std::tie(country, town, number)<
        std::tie(b.country, b.town, b.number);
    }
}

bool PhoneNumber::operator >(PhoneNumber b) const
{
    int zer =0;
    if(this->special && b.special)
    {
        return std::tie(this->country, this->town, this->number, *this->special)>
        std::tie(b.country, b.town, b.number, *b.special);
    }
    else if(this->special)
    {
        return std::tie(this->country, this->town, this->number, *this->special)>
        std::tie(b.country, b.town, b.number, zer);
    }
    else if(b.special)
    {
        return std::tie(this->country, this->town, this->number, zer)>
        std::tie(b.country, b.town, b.number, *b.special);;
    }
    else
    {
        return std::tie(this->country, this->town, this->number)>
        std::tie(b.country, b.town, b.number);
    }
}

bool PhoneNumber::operator==(PhoneNumber b) const
{
    int zer =0;
    if(this->special && b.special)
    {
        return std::tie(this->country, this->town, this->number, *this->special)==
        std::tie(b.country, b.town, b.number, *b.special);
    }
    else if(this->special)
    {
        return std::tie(this->country, this->town, this->number, *this->special)==
        std::tie(b.country, b.town, b.number, zer);
    }
    else if(b.special)
    {
        return std::tie(this->country, this->town, this->number, zer)==
        std::tie(b.country, b.town, b.number, *b.special);;
    }
    else
    {
        return std::tie(this->country, this->town, this->number)==
        std::tie(b.country, b.town, b.number);
    }
}

std::ostream & operator <<(std::ostream & ss, PhoneNumber a)
{
    ss<<"+"<< a.country <<"("<< a.town <<")" << a.number <<" " << (a.special?std::to_string(*a.special): "" );

    return ss;
}

