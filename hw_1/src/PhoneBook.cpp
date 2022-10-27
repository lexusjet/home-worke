#include "PhoneBook.h"

std::vector<std::string> slicer(const std::string& input );

PhoneBook::PhoneBook(std::ifstream & ss){
// file format
//SECOND_NAME FIRST_NAME PATRONIMIC + 3 815 5554755\n

/*

1. прочиать файл
2. разбить буффер на строки
3. полученные строки разбить на 3 подстроки для персоны и одну для телефона

*/
    using namespace std;
    if (!ss.is_open()) return;

    ss.seekg (0, ss.end);
    size_t length = ss.tellg();
    ss.seekg (0, ss.beg);

    string buffer;
    buffer.resize(length);
    ss.read(&buffer[0], length);

    auto init_pair = []( vector<string>& inp)
    {
        auto itr = inp.begin();
        auto itr_delim = find(inp.begin(), inp.end(), "+");
        Person pers;
        pers.sername = *(itr);
        pers.name = *(itr++);

        if((++itr) != itr_delim) pers.patronymic = *itr;
        itr = itr_delim+1;

        PhoneNumber num;
        num.country = stoi(*(itr++));
        num.town = stoi(*itr++);
        num.number = (*itr++);

        if(itr != inp.end()) num.special = stoi(*itr);
        return(make_pair(pers, num));
    };

    int new_pos , pos = 0;
    while(true)
    {
        new_pos = buffer.find("\n",pos);
        if(new_pos == buffer.npos) return;
        vector<string> slice = slicer(buffer.substr(pos, new_pos - pos));
        this->phonebook.push_back(init_pair(slice));
        pos = new_pos+1;
    }
}

std::vector<std::string> slicer(const std::string& input ){
    using namespace std;
    vector <string> anser;
    int pos = 0;
    while(true)
    {
        int new_pos = input.find(" ", pos);
        if(new_pos == input.npos)
        {
            anser.push_back(input.substr(pos, input.size()- pos));
            return anser;
        }
        anser.push_back(input.substr(pos, new_pos - pos));
        pos = new_pos+1;
    }
}

void PhoneBook::SortByName() {
    using namespace std;
    auto compare = [](const auto &a, const auto &b){
        return(a.first < b.first);
    };
    std::sort(this->phonebook.begin(), this->phonebook.end(), compare);
}

void PhoneBook::SortByPhone(){
    using namespace std;
    auto compare = [](const auto &a, const auto &b){ return (a.second < b.second);};
    sort(this->phonebook.begin(), this->phonebook.end(), compare);
}

void PhoneBook::ChangePhoneNumber(Person a, PhoneNumber b){
    using namespace std;
    for(auto i:phonebook){
            if(i.first == a)
            {
                return i.second = b;
            }
    }
//    int volume =0;
//    PhoneNumber* ptr= nullptr;
//    for(size_t i = 0; i < phonebook.size(); i++){
//        if(phonebook[i].first == a){
//
//                if(volume >= 1){
//                    return;
//                }
//                else{
//                    volume++;
//                    *ptr = phonebook[i].second;
//                }
//        }
//    }
//    if(volume) *ptr = b;
}

std::tuple<std::string , PhoneNumber> PhoneBook::GetPhoneNumber(std::string  second_name){
    using namespace std;
    tuple<string ,PhoneNumber> anser;
    get<0>(anser) = "not found";
    int trio = 0;
    for(auto i: this->phonebook){
        if(i.first.sername == second_name){
            if(trio >=1){
                get<0>(anser) = "found more than 1";
                return anser;
            }
            else{
                trio = true;
                get<0>(anser) = "";
                get<1>(anser) = i.second;
            }
        }
    }
    return anser;
}

std::ostream & operator <<(std::ostream & ss, PhoneBook a){
    for(auto & i : a.phonebook)
    {
        ss<< i.first << " "<< i.second<< std::endl;
    }
    return ss;
}
