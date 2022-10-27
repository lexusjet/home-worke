#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <optional>
#include <iostream>


class Person
{
    public:
        std::string sername;
        std::string name;
        std::optional <std::string> patronymic;

    public:
        Person(){};
        Person(std::initializer_list<std::string> args);
        Person( const char srnm, const char nm);
        Person( std::string srnm, std::string nm):sername(srnm),name(nm){}
        Person(std::string srnm, std::string nm, std::string ptrnmc): sername(srnm),name(nm),patronymic(ptrnmc){}

        bool operator>(Person b) const;
        bool operator<(Person b) const;
        bool operator ==(Person b) const;

        friend std::ostream & operator<<(std::ostream& ss, const Person a);
};


#endif // PERSON_H
