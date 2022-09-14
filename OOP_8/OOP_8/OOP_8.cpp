// OOP_8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>

enum exeptions
{
    DivisionByZero = 99
};
class Ex
{
public:
    double x;
    Ex(double a): x(a) {}
    ~Ex() {}
};

class Bar
{
public:
    double y = 0;
    Bar() {};
    ~Bar() {};
    void set(double a)
    {
        if ((a + y) > 100)
        {
            Ex tmp(a * y);
            throw tmp;
        }
        y = a;
    }
};

class OffTheField
{
public:
    int a = 5;
    OffTheField(){};
    ~OffTheField(){};
};
class IllegalCommand
{
public:
    int b = 5;
    IllegalCommand() {};
    ~IllegalCommand() {};
};

class Robot
{
private:
    const size_t strings;
    const size_t colmns;
public:    
    size_t pos_str =0;
    size_t pos_clmn = 0;

    Robot(size_t size_a, size_t size_b) :strings(size_a), colmns(size_b) {}
    friend std::ostream& operator<<(std::ostream& ss, Robot robot);
    ~Robot() {};

    void move(size_t str , size_t clmn)
    {
        if((str >= strings)||(str < 0))
        {
            OffTheField tmp;
            throw tmp;
        }
        else if((clmn >= colmns)||(clmn < 0))
        {
            OffTheField tmp;
            throw tmp;
        }
        if(std::abs(static_cast<int>(str - pos_str)) > 1)
        {
            IllegalCommand tmp;
            throw tmp;
        }
        else if(std::abs( static_cast<int>(clmn - pos_clmn)) > 1)
        {
            IllegalCommand tmp;
            throw tmp;
        }

        pos_clmn = clmn;
        pos_str = str;
    }

};
std::ostream & operator<<(std::ostream & ss, Robot robot)
{
    using namespace std;
    cout << "Robot curent position is ( " << robot.pos_str << " , " << robot.pos_clmn << ")";
    return ss;
}

template <typename T> T div(T a, T b)
{
    if (b == 0) throw DivisionByZero;
    else return(a / b);
}

int main()
{
    int anser = 0;
    try
    {
        anser = div<int>(4, 1);
        std::cout << anser << std::endl;
    }
    catch (exeptions)
    {
        std::cout << "divison By zero" << std::endl;
    }

    Bar bar;
    do
    {
        int n;
        try
        {
            std::cin >> n;
            if (n == 0)break;
            bar.set(n);
        }
        catch(Ex ex)
        {
            std::cout << "exeption " << ex.x << " > 100" << std::endl;
        }
    } while (true);

    Robot robot(10, 10);
    do
    {
        int x;
        int y;
        try
        {
            std::cout << robot << std::endl;
            std::cin >> x;
            std::cin >> y;
            if (x == 99 && y == 99) break;
            robot.move(x, y);
        }
        catch(OffTheField exept)
        {
            std::cout << "Can't pass the border" << std::endl;
        }
        catch(IllegalCommand exept)
        {
            std::cout << "Input coordinates out off range " << std::endl;
        }
    
    } while (true);

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
