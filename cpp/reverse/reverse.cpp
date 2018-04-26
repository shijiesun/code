#include <stdio.h>
#include <iostream>

#include "linked_list.hpp"

using namespace std;
/*
typedef struct data {
    int value;

    struct data(int v) : value(v) {
    }

} data_t;
*/
int main() {
    ssj::linked_list<int> ll;

    int count = 10;

    for (int i = 0; i < count; ++i) {
        ll.push(i);
    }

    cout << "print linked_list" << endl;
    ll.print();

    /*
    while(!ll.empty())
        ll.pop();
    }
    */
    return 1;
}
