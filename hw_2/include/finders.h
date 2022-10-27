#ifndef FINDERS_H
#define FINDERS_H

#include <string>
#include <map>
#include <algorithm>

bool _find(const char a){
    static std::string rus_vewel = "������������������";
    return (rus_vewel.find(a ,0) != std::string::npos) ;
}

bool _for(const char a){
    static std::string rus_vewel = "������������������";
    for( auto i : rus_vewel){
        if(i == a) return true;
    }
    return false;
}
bool ttt (const char a)
{
if((a =='�' || a =='�') || (a =='�'|| a =='�')) return true;
else if((a =='�' || a =='�') || (a =='�'|| a =='�')) return true;
else if((a =='�' || a =='�') || (a =='�'|| a =='�')) return true;
else if((a =='�' || a =='�') || (a =='�'|| a =='�')) return true;
else if(a =='�' || a =='�') return true;
else return false;
}
bool is_rus_vowel(const char a){
    static std::map<char, int> rus_vowel {
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1},
        {'�', 1}, {'�', 1}
    };
    return rus_vowel.find(a) != rus_vowel.end();
}

int vowel_search_1(const std::string& str ){
    return std::count_if(str.begin(), str.end(), _find);
}

int vowel_search_2(const std::string& str ){
    return std::count_if(str.begin(), str.end(), _for);
}

int vowel_search_3(const std::string& str ){
    int anser = 0;
    for(auto i : str){
            if(_find(i)) anser++;
    }
    return anser;
}

int vowel_search_4(const std::string& str ){
    int anser = 0;
    for(auto i : str){
            if(_for(i)) anser++;
    }
    return anser;
}

int vowel_search_my(const std::string& str){
    return std::count_if(str.begin(),str.end(), is_rus_vowel);
}
int vowel_search_m1(const std::string& str){
    return std::count_if(str.begin(),str.end(), ttt);
}

#endif // FINDERS_H
