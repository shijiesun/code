#include <stdio.h>
#include <iostream>

#include "linked_list.hpp"

using namespace std;

class data_t {

    friend ostream & operator<<(ostream & out, const data_t & data);

public:
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
    //while(true)
    {
        ssj::linked_list<data_t> ll;

        int count = 1;

        cout << "==================== push_back" << endl;

        for (int i = 0; i < count; ++i) {
            ll.push_back(data_t(i));
            //data_t a(i);
            //ll.push_back(a);
        }

        ll.print();

        cout << "==================== reverse" << endl;

        //ll.reverse();
        ll.reverse2();

        ll.print();

        cout << "==================== pop" << endl;
        while(!ll.empty()) {
            data_t value = ll.pop();
            cout << "pop:" << value << endl;
        }

        auto temp = ll.pop();
        cout << "pop empty:" << temp << endl;


        cout << "==================== push" << endl;

        for (int i = 0; i < count; ++i) {
            //data_t a(i);
            //ll.push(a);
            //cout << "push:" << a.value_ << endl;

            ll.push(data_t(i));


        }

        ll.print();

        cout << "==================== end" << endl;
    }
    return 1;
}
