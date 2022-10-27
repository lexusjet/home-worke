#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <functional>
#include <utility>


#include "File.h"
#include "finders.h"


int exe_time(std::string& str,  std::function<int (std::string)> foo){
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int anser = foo(str);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    std::cout << "It took me " << time_span.count() << " seconds.";
    return anser;
}
template <typename T> void Swap(T* a, T* b){
    T buf = a;
    a = b;
    b= buf;
}

template <typename T> void SortPointers(std::vector<T> vec){
    auto compare = [](T* a, T* b){ return (*a < *b);};
    std::sort(vec.begin(), vec.end(), compare);
}



int main()
{
    const int BUFFER_SIZE = 10000;
    using namespace std;
    ifstream book("25452548.txt");

    if(!book.is_open()) return 0;

    string buffer;

    int anser[5] = {0, 0, 0, 0, 0};
    function<int(string)> func[5] = {vowel_search_1, vowel_search_2, vowel_search_3,vowel_search_4 , vowel_search_my};

    while(!book.eof()){
            buffer.clear();
            buffer.resize(BUFFER_SIZE);
            book.read(&buffer[0], BUFFER_SIZE);
            for(size_t i = 0; i < 5; i++)
                anser[i] += func[i](buffer);
    }
    for(auto i : anser) cout<< i << endl;

    book.close();
    return 0;
}
