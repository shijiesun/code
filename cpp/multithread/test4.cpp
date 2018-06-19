#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;

void print(const string & msg, int id) {
    std::lock_guard<std::mutex> guard(mu);
    //mu.lock();
    cout << msg << ":" << id << endl;
    //mu.unlock();
}

void fun1() {
    for (int i = 0; i < 100; ++i) {
        print("thread", i);
    }
}

int main() {
    std::thread t1(fun1);

    for (int i = 0; i < 100; ++i) {
        print("main", i);
    }
    t1.join();


    return 0;
}
