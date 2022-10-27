#ifndef FINDERS_H
#define FINDERS_H

#include <string>
#include <map>
#include <algorithm>

bool _find(const char a){
    static std::string rus_vewel = "ÉéÓóÅåÀàÎîİıßÿÈèŞş";
    return (rus_vewel.find(a ,0) != std::string::npos) ;
}

bool _for(const char a){
    static std::string rus_vewel = "ÉéÓóÅåÀàÎîİıßÿÈèŞş";
    for( auto i : rus_vewel){
        if(i == a) return true;
    }
    return false;
}
bool ttt (const char a)
{
if((a =='Å' || a =='å') || (a =='À'|| a =='à')) return true;
else if((a =='ß' || a =='ÿ') || (a =='È'|| a =='è')) return true;
else if((a =='É' || a =='é') || (a =='Ó'|| a =='ó')) return true;
else if((a =='Î' || a =='î') || (a =='İ'|| a =='ı')) return true;
else if(a =='Ş' || a =='ş') return true;
else return false;
}
bool is_rus_vowel(const char a){
    static std::map<char, int> rus_vowel {
        {'É', 1}, {'é', 1},
        {'Ó', 1}, {'ó', 1},
        {'Å', 1}, {'å', 1},
        {'À', 1}, {'à', 1},
        {'Î', 1}, {'î', 1},
        {'İ', 1}, {'ı', 1},
        {'ß', 1}, {'ÿ', 1},
        {'È', 1}, {'è', 1},
        {'Ş', 1}, {'ş', 1}
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
