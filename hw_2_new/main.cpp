#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <queue>

#include <algorithm>
#include <functional>
#include <utility>

#include <thread>
#include <mutex>
#include <condition_variable>

#include "File.h"
#include "finders.h"

bool eof = false;
int anser = 0;
std::mutex mtx;

//std::condition_variable cv;
//bool new_data = false;

//void thread_foo(std::string & str){
//    using namespace std;
//    auto predicat = [](){return (new_data);};
//    while(true){
//            unique_lock<mutex> lck(mtx);
//            cv.wait(lck,predicat);
//            anser += vowel_search_1(str);
//            new_data = false;
//            if(eof) break;
//            cv.notify_one();
//    }
//}

void th_que(std::queue<std::string> & que){
    using namespace std;

    string buf;
    while(que.size()|| !eof ){
        if(!que.size())
            this_thread::yield();
        else{
            unique_lock<mutex> lck(mtx);
            buf = move(que.front());
            que.pop();
            lck.unlock();
            anser += vowel_search_1(buf);
        }
    }
}

int main()
{
    using namespace std;
    const int BUFFER_SIZE = 60000;

    const char file_name[] = "25452548.txt";

    ifstream book(file_name);
    if(!book.is_open()) return 0;

    queue<string> que;
    thread qu (th_que, ref(que));

    while(book.eof()){
        string buf(BUFFER_SIZE, '\0');
        book.read(&buf[0], BUFFER_SIZE);
        unique_lock<mutex> lck(mtx);
        que.push(move(buf));
        lck.unlock();
    }
    eof = true;
    book.close();
    qu.join();


//    const size_t MAX_SIZE = 2;
//    auto pred = [](){return !new_data;};
//    size_t i = 0;
//    string buffers[buf_amount];
//    string ref_str = buffers[0];
//    thread counter(thread_foo, ref(que));
//    while(true){
//        buffers[i].clear();
//        buffers[i].resize(BUFFER_SIZE);
//        book.read(&buffers[i][0] ,BUFFER_SIZE);
//
//        unique_lock<mutex> lck(mtx);
//        cv.wait(lck, pred);
//
//        ref_str = buffers[i];
//        new_data = true;
//        if(book.eof()){
//            eof = true;
//            cv.notify_one();
//            break;
//        }
//
//        i = (i+1) == buf_amount ? 0 : (++i);
//        cv.notify_one();
//    }
//    counter.join();


    cout<< anser << endl;
    return 0;
}
