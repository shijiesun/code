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
//    while(1) {
    {
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
            auto node = ll.pop();
            cout << "pop:" << node->value << endl;
        }

        for (int i = 0; i < count; ++i) {
            ll.push(i);
        }

        cout << "after push" << endl;
        ll.print();

    }
    return 1;
}
