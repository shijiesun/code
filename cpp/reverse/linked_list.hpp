#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>

using namespace std;


namespace ssj {

    template<typename T>
    class node {
    public:
        T value;
        node * next;

    public:
        node() {}

        node(const T & v) : value(v), next(nullptr) {
        }

    private:
        node(const node & other);
        node & operator=(const node & other);
    };

    template<typename T>
    class linked_list {
    public:
        void push(const T & val) {
            node<T> * n = new node<T>(val);
            n->next = nullptr;

            tail->next = n;
            tail = tail->next;
        }

        void pop() {
            //todo
        }

        void print() {
            node<T> * p = head->next;
            while(p->next != nullptr) {
                cout << p->value << endl;
                p = p->next;
            }
        }

        bool empty() {
            return head == tail;
        }

    public:
        linked_list() {
            head = new node<T>();
            head->next = nullptr;
            tail = head;
        }

        ~linked_list() {
            node<T> * p = head;
            while(head->next != nullptr) {
                pop();
            }

            if(head != nullptr) {
                delete head;
                head = nullptr;
            }
            tail = nullptr;
        }


    private:
        linked_list(const linked_list & other);
        linked_list & operator=(const linked_list & other);

    private:
        node<T> * head;
        node<T> * tail;
    };

} // namespace ssj

#endif // __LINKED_LIST__
