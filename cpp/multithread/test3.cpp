#include <iostream>
#include <thread>

using namespace std;


void fun1() {
    std::cout << "hello" << std::endl;
}

class factor {
public:
    void operator()(string msg) {
        cout << "-----thread:" << msg << endl;
        msg = "I changed it";
    }
};

int main() {
    //std::thread t1(fun1);
    cout << std::this_thread::get_id() << endl;

    string msg = "I love abc";
    std::thread t1(factor(), std::move(msg));

    std::thread t2 = std::move(t1);

    cout << t2.get_id() << endl;

    t2.join();

    cout << "main:" << msg << endl;

    return 0;
}
