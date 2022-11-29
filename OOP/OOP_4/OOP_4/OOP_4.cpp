#include <iostream>
#include <iostream>
#include <string>
#include <cassert> // для assert()
#include <time.h>
#include < vector>
#include <utility>
using namespace std;


class ArrayInt
{
private:
    int m_length;
    int* m_data;

    void sorted(size_t begin_, size_t end_ , bool(*comp)(int a, int b))
    {
        int comporand = m_data[begin_ + ((end_ - begin_) / 2)];
        size_t begin = begin_;
        size_t end = end_;

        if ((end_ - begin_ ) <= 1)
        {
            if (comp(m_data[end_], m_data[begin_]))
            {
                int buf = m_data[begin_];
                m_data[begin_] = m_data[end_];
                m_data[end_] = buf;
            }
            return;
        }


        while(begin < end)
        {
            while ((begin <= end) && (comp(m_data[begin], comporand) )) begin++;
            while ((begin <= end) && (comp(comporand, m_data[end]) )) end--;

            if(begin < end) 
            {
                int buf = m_data[begin];
                m_data[begin] = m_data[end];
                m_data[end] = buf;
                begin++;
                end--;
            }
        }

        if (begin_ < end) sorted(begin_, end, comp);
        if (begin < end_) sorted(begin, end_, comp);
    }

public:
    ArrayInt() : m_length(0), m_data(nullptr) { }

    ArrayInt(int _size) : m_length(_size)
    {
        if (_size > 0)
            m_data = new int[m_length];
        else
            m_data = nullptr;
    }

    ArrayInt(int _size, int init_value) : m_length(_size)
    {
        if (_size > 0)
            m_data = new int[m_length];
        else
            m_data = nullptr;
        for (size_t i = 0; i < m_length; i++)
        {
            m_data[i] = init_value;
        }
    }

    ~ArrayInt()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    int size()
    {
        return m_length;
    }

    friend ostream& operator<<(ostream& out, ArrayInt& AI);

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void clear()
    {
        if (m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }
    }

    void resize(int newSize)
    {
        if (newSize == m_length) return;
        if (newSize <= 0)
        {
            clear();
            return;
        }
        int* newData = new int[newSize];
        int CopySize = (newSize >= m_length) ? m_length : newSize;
        for (size_t i = 0; i < CopySize; i++)
        {
            newData[i] = m_data[i];
        }
        delete m_data;
        m_data = newData;
        m_length = newSize;
    }

    void insert(int value, int index)
    {
        resize(m_length + 1);
        for (size_t i = m_length - 1; i > index; i--)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = value;
    }

    void pop_back()
    {
        if (m_length > 0)
            m_length--;
        return;
    }

    void pop_front()
    {
        for (size_t i = 0; i < --m_length; i++)
        {
            m_data[i] = m_data[i + 1];
        }
    }

    void sort(int begin , int end , bool (*comp)(int a, int b) = [](int x, int y) {return x < y; }) 
    {
        sorted(begin, (end-1), comp);
    }
    void sort() { sorted(0, (this->m_length - 1), [](int x, int y) {return x < y; }); }
};
ostream& operator<<(ostream& out, ArrayInt& AI)
{
    for (size_t i = 0; i < AI.size(); i++)
    {
        out << AI.m_data[i] << " ";
    }
    return out;
}

size_t finde_orginals(vector<int> vec);

int main()
{
    srand(time(0));
    ArrayInt a(20);
    vector<int> tst;



    for (size_t i = 0; i < a.size(); i++)
    {      
        a[i] = rand() % 120;
        tst.push_back(rand()% 10);
    }
    auto lambda_1 = [](int x, int y) { return(x > y); };
    a.sort();
    cout << a << endl;
    cout<<  finde_orginals(tst)<< endl;

    
}


size_t finde_orginals(vector<int> vec)
{
    vector<pair<int, int> >buf;
    buf.reserve(vec.size() / 2);
    bool orginal = true;
    for (size_t i = 0; i < vec.size(); i++, orginal = true)
    {
        for (size_t j = 0; j < buf.size(); j++)
        {
            if (buf[j].first == vec[i])
            {
                buf[j].second++;
                orginal = false;
                break;
            }
        }
        if (orginal) buf.push_back(make_pair(vec[i], 0));
    }
    size_t anser = 0;
    for (size_t i = 0; i < buf.size(); i++)
    {
        if (buf[i].second == 0) anser++;
    }
    return anser;
}
