#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Person.h"
#include "PhoneNumber.h"

#include <tuple>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
class PhoneBook
{
    public:
        PhoneBook(std::ifstream & ss);
        void SortByName();
        void SortByPhone();
        std::tuple<std::string , PhoneNumber> GetPhoneNumber(std::string second_name);
        void ChangePhoneNumber(Person a, PhoneNumber b);

        friend std::ostream & operator <<(std::ostream & ss, PhoneBook a);
    protected:
        std::vector<std::pair<Person, PhoneNumber>> phonebook;
//    private:
};

#endif // PHONEBOOK_H
