#include <iostream>
#include <thread>

using namespace std;


void fun1() {
    std::cout << "hello" << std::endl;
}

class factor {
public:
    void operator()(string msg) {
        for (int i = 0; i < 100; ++i) {
            cout << "-----thread:" << i << " msg:" << msg << endl;
        }

    }
};

int main() {
    //std::thread t1(fun1);
    factor f;
    string msg = "I love abc";
    std::thread t1(f, msg);

    try {
        for (int i = 0; i < 100; ++i) {
            cout << "main:" << i << endl;
        }

    } catch(...) {
        t1.join();
        throw;
    }


    if(t1.joinable()) {
        t1.join();
    }

    return 0;
}
