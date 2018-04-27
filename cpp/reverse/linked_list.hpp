#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <memory>

using namespace std;


namespace ssj {

    template<typename T>
    class node {
    public:
        T value_;
        node * next;

    public:
        node() {}

        explicit node(T v) : value_(move(v)), next(nullptr) {
        }

    private:
        node(const node & other);
        node & operator=(const node & other);
    };

    template<typename T>
    class linked_list {
    public:
        void push_back(T && val) {
            node<T> * n = new node<T>(move(val));
            n->next = nullptr;

            tail_->next = n;
            tail_ = tail_->next;
        }

        void push(T val) {
            auto p = head_->next;

            node<T> * n = new node<T>(move(val));

            if(p == nullptr) {
                head_->next = n;
                tail_ = n;
            } else {
                n->next = p;
                head_->next = n;
            }
        }


        T pop() {
            cout << "call linked_list::pop" << endl;
            if(!empty()) {
                auto p = head_->next;
                head_->next = p->next;
                p->next = nullptr;

                if(head_->next == nullptr) {
                    tail_ = head_;
                }

                if(p != nullptr) {
                    return move(p->value_);

                    delete p;
                    p = nullptr;
                }

            }
            return T();
        }

/*
        unique_ptr<node<T>> pop() {
            if(!empty()) {
                auto p = head_->next;
                head_->next = p->next;
                p->next = nullptr;

                if(head_->next == nullptr) {
                    tail_ = head_;
                }

                return unique_ptr<node<T>>(p);

  //if(p != nullptr) {
  //cout << "pop:" << p->value_ << endl;
  //delete p;
  //p = nullptr;
  //}

            }
            return nullptr;
        }
*/

        void reverse() {

        }

        void print() const {
            node<T> * p = head_->next;
            while(p != nullptr) {
                cout << p->value_ << endl;
                p = p->next;
            }
        }

        bool empty() const {
            return head_->next == nullptr;
        }

    public:
        linked_list() {
            head_ = new node<T>();
            head_->next = nullptr;
            tail_ = head_;
        }

        ~linked_list() {
            node<T> * p = head_;
            while(head_->next != nullptr) {
                pop();
            }

            if(head_ != nullptr) {
                delete head_;
                head_ = nullptr;
            }
            tail_ = nullptr;
        }


    private:
        linked_list(const linked_list & other);
        linked_list & operator=(const linked_list & other);

    private:
        node<T> * head_;
        node<T> * tail_;
    };

} // namespace ssj

#endif // __LINKED_LIST__
