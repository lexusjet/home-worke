#include <iostream>
#include <string>
#include <fstream>
#include "PhoneBook.h"

int main()
{
    using namespace std;
//
//    ifstream is("D:\\test.txt", ifstream::in);
//    PhoneBook a(is);
//    is.close();
//    cout << a<< endl;
//    string test = "kirov";
//    cout << "sorted list by full names"<<endl;
//    a.SortByName();
//    cout << a<< endl;
//    cout << "sorted list by phones"<<endl;
//    a.SortByPhone();
//    cout << a<< endl;
//


    ifstream file("test.txt", ifstream::in); // путь к файлу PhoneBook.txt PhoneBook book(file);
    PhoneBook book(file);
    file.close();
    cout << book;
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;
    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;
    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);

        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };
    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");
    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
    PhoneNumber(7, 123, "15344458", nullopt));
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
    PhoneNumber( 16, 465, "9155448", 13 ));
    cout << book;


    return 0;
}
