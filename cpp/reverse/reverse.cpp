#include <stdio.h>
#include <iostream>

#include "linked_list.hpp"

using namespace std;

class data_t {

private:
    int value_;
public:
    data_t(int v) : value_(v) {
    }




};

int main() {
    while(1) {

        ssj::linked_list<int> ll;

        int count = 10;

        for (int i = 0; i < count; ++i) {
            ll.push_back(i);
        }

        cout << "after push_back" << endl;
        ll.print();

        ll.reverse();

        cout << "after reverse" << endl;
        ll.print();

        while(!ll.empty()) {
            auto value = ll.pop();
            cout << "pop:" << value << endl;
        }

        for (int i = 0; i < count; ++i) {
            ll.push(i);
        }

        cout << "after push" << endl;
        ll.print();

    }
    return 1;
}
