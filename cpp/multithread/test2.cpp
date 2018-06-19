#include <iostream>
#include <thread>

using namespace std;


void fun1() {
    std::cout << "hello" << std::endl;
}

class factor {
public:
    void operator()(string & msg) {
        cout << "-----thread:" << msg << endl;
        msg = "I changed it";
    }
};

int main() {
    //std::thread t1(fun1);
    string msg = "I love abc";
    std::thread t1(factor(), std::ref(msg));

    if(t1.joinable()) {
        t1.join();
    }

    cout << "main:" << msg << endl;

    return 0;
}
