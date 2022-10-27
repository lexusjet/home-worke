#include <iostream>
#include <list>
#include <utility>
#include <numeric>
#include <cmath>
#include <vector>


//1. �������� �������, ����������� � ����� ������ ������������ ����� �������, �������� �������� ����� �������� ��������������� ���� ��� ���������.
void first_func(std::list<double> & lst){
    lst.push_back(std::accumulate(lst.begin(), lst.end(), 0)  / lst.size());
}

// 2. ������� �����, �������������� �������. ����������� � ��� �����, ����������� ������������ �������. ��� ���������� ����������� ���������� �� STL.
double determinant(const std::vector<std::vector<double>> & matrix){
    if(matrix.size() != matrix[0].size()) return 0;


    if(matrix.size()== 2){
        return (matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]);
    }
    double anser = 0;

//    for(auto i: matrix){
//        for(auto j :i) std::cout<<j<<" ";
//        std::cout<<std::endl;
//    }

//  ������� ������������ �� ������ ������ ������
    std::vector<std::vector<double>> minor;
    for(int i = 0, sign = 1; i < matrix.size(); i++){
        minor.resize(matrix.size()-1);
        for(size_t j = 1; j< matrix.size(); j++){
            for(size_t k = 0; k< matrix.size(); k++){
                if(k!= i){
                    minor[j-1].push_back(matrix[j][k]);
                }
            }
        }
        anser += (sign * matrix[0][i]) *determinant(minor);
        minor.clear();
        sign = sign==-1 ? 1:(-1);
    }
    return anser;
}
// 3. ����������� ����������� ����� ���������, � ������� �������� ����� ����� ���������������� �� ��������� ����� ����� � ����� for-range-based.
class Myiterator{
protected:
    int* ptr__ = nullptr;

public:
    Myiterator(int* ptr):ptr__(ptr){};
    Myiterator(){};
    int operator++(){
        int buf = *ptr__;
        ptr__++;
        return buf;
    };

    int operator--(){
        int buf = *ptr__;
        ptr__++;
        return buf;
    };
    bool operator!= (Myiterator b){
        return (ptr__ != b.ptr__);
    };
    int& operator* (){ return *ptr__;};
};


/*
    1. �������� �������, ����������� � ����� ������ ������������ ����� �������, �������� �������� ����� �������� ��������������� ���� ��� ���������.
    2. ������� �����, �������������� �������. ����������� � ��� �����, ����������� ������������ �������. ��� ���������� ����������� ���������� �� STL.
    3. ����������� ����������� ����� ���������, � ������� �������� ����� ����� ���������������� �� ��������� ����� ����� � ����� for-range-based.
*/

int main()
{
    using namespace std;
    vector<double> tst= {3,2,3};
    vector<vector<double>> matrix = {{3,2,5,4}, {1,1,1,1}, {5,8,9,1}, {1,5,6,7} };

    cout << determinant(matrix) << endl;

    return 0;
}
