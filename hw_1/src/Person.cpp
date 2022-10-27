#include "Person.h"
#include <tuple>

Person::Person( const char srnm, const char nm){
    name = nm;
    sername = srnm;
}
Person::Person(std::initializer_list<std::string> args)
{
    auto  itr = args.begin();
    sername = *(itr++);
    name = *(itr++);
    if(args.size()> 2)
        patronymic = *itr;
}


bool Person::operator<( Person b) const
{
    if(this->patronymic && b.patronymic)
    {
        return std::tie(this->sername, this->name, *this->patronymic) <
        std::tie(b.sername, b.name, *b.patronymic);
    }
    else if(this->patronymic)
    {
        return std::tie(this->sername, this->name, *this->patronymic) <
        std::tie(b.sername, b.name, "");
    }
    else if(b.patronymic)
    {
        return std::tie(this->sername, this->name, "") <
        std::tie(b.sername, b.name, *b.patronymic);
    }
    else
    {
        return std::tie(this->sername, this->name) <
        std::tie(b.sername, b.name);
    }
}
bool Person::operator>(Person b) const
{
    if(this->patronymic && b.patronymic)
    {
        return std::tie(this->sername, this->name, *this->patronymic) >
        std::tie(b.sername, b.name, *b.patronymic);
    }
    else if(this->patronymic)
    {
        return std::tie(this->sername, this->name, *this->patronymic) >
        std::tie(b.sername, b.name, "");
    }
    else if(b.patronymic)
    {
        return std::tie(this->sername, this->name, "") >
        std::tie(b.sername, b.name, *b.patronymic);
    }
    else
    {
        return std::tie(this->sername, this->name) >
        std::tie(b.sername, b.name);
    }
}

bool Person::operator ==(Person b) const
{
    if(this->patronymic && b.patronymic)
    {
        return std::tie(this->sername, this->name, *this->patronymic) ==
        std::tie(b.sername, b.name, *b.patronymic);
    }
    else if(this->patronymic)
    {
        return std::tie(this->sername, this->name, *this->patronymic) ==
        std::tie(b.sername, b.name, "");
    }
    else if(b.patronymic)
    {
        return std::tie(this->sername, this->name, "") ==
        std::tie(b.sername, b.name, *b.patronymic);
    }
    else
    {
        return std::tie(this->sername, this->name) ==
        std::tie(b.sername, b.name);
    }
}

std::ostream & operator<<(std::ostream& ss, const Person a)
{
    ss<< a.sername <<" "<<a.name<< " " <<(a.patronymic? (*a.patronymic): "");
    return ss;
}
