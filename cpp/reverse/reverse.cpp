#include <stdio.h>
#include <iostream>

#include "linked_list.hpp"

using namespace std;

class data_t {

    friend ostream & operator<<(ostream & out, const data_t & data);

private:
    int value_;
public:
    data_t() : value_(-1) {
        cout << "default data_t construct called" << endl;
    }
    
    explicit data_t(int v) : value_(v) {
        cout << "data_t construct called" << endl;
    }

    data_t(const data_t & other) : value_(other.value_) {
        cout << "copy data_t construction" << endl;
    }

    data_t & operator=(const data_t & other) {
        value_ = other.value_;
        cout << "copy data_t assign" << endl;
        return *this;
    }

    data_t(data_t && other) : value_(other.value_) {
        cout << "==========move data_t construction" << endl;
    }

    data_t & operator=(data_t && other) {
        value_ = other.value_;
        cout << "==========move data_t assign" << endl;
        return *this;
    }
};


ostream & operator<<(ostream & out, const data_t & data) {
    out << data.value_;
    return out;
}

int main() {
    //while(1) {
    {
        ssj::linked_list<data_t> ll;

        int count = 10;

        for (int i = 0; i < count; ++i) {
            ll.push_back(data_t(i));
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

        auto temp = ll.pop();
        cout << "pop empty:" << temp << endl;

        for (int i = 0; i < count; ++i) {
            data_t a(i);
            data_t b = move(a);
            ll.push(b);
        }

        cout << "after push" << endl;
        ll.print();

    }
    return 1;
}
