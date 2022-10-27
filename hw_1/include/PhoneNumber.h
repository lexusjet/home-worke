#ifndef PHONENUMBER_H
#define PHONENUMBER_H

#include <string>
#include <optional>
#include <iostream>
#include <tuple>

class PhoneNumber
{
    public:
        int country;
        int town;
        std::string number;
        std::optional<int> special;

    public:
        PhoneNumber(){};
        PhoneNumber(int a, int b, const char c);
        PhoneNumber(std::string a, std::string b, std::string c);
        PhoneNumber(int a, int b, const char* c, std::optional<int> d);
        PhoneNumber(std::string a, std::string b, std::string c, std::string d);
        PhoneNumber(int a, int b, std::string c): country(a), town(b), number(c) {}
//        PhoneNumber(int a, int b, std::string c, int d): country(a), town(b), number(c),  special(d) {}



        void operator=(PhoneNumber b);
        bool operator <(PhoneNumber b) const;
        bool operator >(PhoneNumber b) const;
        bool operator ==(PhoneNumber b) const;

        friend std::ostream & operator <<(std::ostream & ss, PhoneNumber a);

};

#endif // PHONENUMBER_H
