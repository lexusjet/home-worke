#include <iostream>
#include <array>
#include <deque>
#include <time.h>
#include <vector>
#include <list>
#include <stack>
#include  <queue>
#include <numeric>
#include <algorithm>
#include <math.h>
/*
1.  Имеется отсортированный массив целых чисел. Необходимо разработать функцию insert_sorted,
    которая принимает вектор и новое число и вставляет новое число в определенную позицию в векторе,
    чтобы упорядоченность контейнера сохранялась. Реализуйте шаблонную функцию insert_sorted,
    которая сможет аналогично работать с любым контейнером, содержащим любой тип значения.
*/
template<typename T1, typename T2> void insert_sorted(T1 & a, T2 b){
    if(a.back() <= b )
        a.push_back(b);
    else
        a.insert(std::find_if(a.begin(), a.end(), [b](auto a){return a > b;}), b);
}
template<typename T> void insert_sorted(std::stack<T>& a ,T b){
    if(a.top() <= b)
        a.push(b);
    else{
        std::stack<T> new_st;
        while(a.size()){
            if(a.top()> b){
                new_st.push(a.top());
                a.pop();
            }
            else{
                a.push(b);
                break;
            }
        }
        while(new_st.size()){
            a.push(new_st.top());
            new_st.pop();
        }
    }
}

/*
2.  Сгенерируйте вектор a, состоящий из 100 вещественный чисел, представляющий собой значения аналогового сигнала.
    На основе этого массива чисел создайте другой вектор целых чисел b, представляющий цифровой сигнал, в котором будут откинуты дробные части чисел.
    Выведите получившиеся массивы чисел. Посчитайте ошибку, которой обладает цифровой сигнал по сравнению с аналоговым по формуле:
*/



double ADC(double analog){
    auto predict = [analog](auto a){return a > analog;};
    const double step = double(2)/double(256);
    double j = -1;
    std::array<double, 256> compare;
//    for(size_t i= 0; i <256; i++){
//        compare[i] = j;
//        j+=step;
//    }
    for(double & i :compare){
        i = j;
        j+=step;
    }
    auto anser = std::find_if(compare.begin(), compare.end(),predict);
    if(anser == compare.end()) return compare.back();
    return *anser;
}

double foo(std::vector<double> &anlg, std::vector<double>& dig){
    std::vector<double> anser;
    auto equation = [](double a, double b){return std::pow((a-b), 2);};
    for(size_t i = 0; i < anlg.size(); i++){
        anser.push_back(equation(anlg[i] , dig[i]));
    }
    return std::accumulate(anser.begin(), anser.end(),0.0);
}

const size_t LENGTH = 10;

int main()
{
    using namespace std;
    srand(time(0));

    vector<double> analog;
    for(size_t i = 0; i < 100; i++){
        analog.push_back(sin(static_cast<double>(i) /20));
    }

    vector<double>  digital;
    for(auto i: analog) digital.push_back(ADC(i));


    cout<< foo(analog, digital);

    return 0;
}
