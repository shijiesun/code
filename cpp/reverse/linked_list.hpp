#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <iostream>
#include <memory>
#include <assert.h>

using namespace std;


namespace ssj {

    template<typename T>
    class node {
    public:
        T value_;
        node * next_;

    public:
        node() : value_(-1), next_(nullptr) {
            cout << "----------------------------node() -----------" << endl;
        }

        explicit node(T v) : value_(move(v)), next_(nullptr) {
            cout << "----------------------------node() -----------" << endl;
        }

        ~node() {
            cout << "---------------------------- ~node() -----------" << endl;
        }

    private:
        node(const node & other);
        node & operator=(const node & other);
    };

    template<typename T>
    class linked_list {
    public:
        //三种写法对比右值,左值引用,值传递的对比
        void push_back(T && val) {
            cout << "call push_back rvalue" << endl;
            node<T> * n = new node<T>(move(val));
            n->next_ = nullptr;

            tail_->next_ = n;
            tail_ = tail_->next_;
        }

        void push_back(const T & val) {
            cout << "call push_back lvalue reference" << endl;
            node<T> * n = new node<T>(val);
            n->next_ = nullptr;

            tail_->next_ = n;
            tail_ = tail_->next_;
        }

        void push(T val) {
            node<T> * n = new node<T>(move(val));

            push_ptr_(n, head_, tail_);
        }


        T pop() {
            cout << "call linked_list::pop" << endl;
            auto p = pop_ptr_(head_, tail_);
            T a;
            if(p != nullptr) {
                a = move(p->value_);

                delete p;
                p = nullptr;
            }

            return a;
        }

/*
  unique_ptr<node<T>> pop() {
  if(!empty()) {
  auto p = head_->next_;
  head_->next_ = p->next_;
  p->next_ = nullptr;

  if(head_->next_ == nullptr) {
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

        //所谓反向,其实时利用链表的插入和删除重新生产一个新的链表
        void reverse() {
            auto head = new node<T>();
            head->next_ = nullptr;
            auto tail = head;

            while(head_->next_ != nullptr) {
                auto n = pop_ptr_(head_, tail_);

                push_ptr_(n, head, tail);
            }
            delete head_;

            head_ = head;
            tail_ = tail;
        }

        void reverse2() {
            if(head_->next_ == nullptr || head_->next_->next_ == nullptr) return;
            auto p = head_->next_;
            auto q = p->next_;
            auto r = q->next_;

            p->next_ = nullptr;
            do {
                q->next_ = p;

                p = q;
                q = r;
                if(r != nullptr)
                    r = r->next_;
            } while(r != nullptr);

            if(q != nullptr) {
                q->next_ = p;
                head_->next_ = q;
            } else {
                if(p != nullptr) {
                    head_->next_ = p;
                }
            }

        }

        void print() const {
            node<T> * p = head_->next_;
            while(p != nullptr) {
                cout << p->value_ << endl;
                p = p->next_;
            }
        }

        bool empty() const {
            return head_->next_ == nullptr;
        }

        static void push_ptr_(node<T> * n, node<T> * head, node<T> * tail) {
            assert(n != nullptr);
            auto p = head->next_;
            head->next_ = n;
            if(p == nullptr) {
                tail = n;
            } else {
                n->next_ = p;
            }
        }

        static node<T> * pop_ptr_(node<T> * head, node<T> * tail) {
            if(head->next_ != nullptr) {
                auto p = head->next_;
                head->next_ = p->next_;
                p->next_ = nullptr;

                if(head->next_ == nullptr) {
                    tail = head;
                }
                return p;
            }
            return nullptr;
        }

    public:
        linked_list() {
            head_ = new node<T>();
            head_->next_ = nullptr;
            tail_ = head_;
        }

        ~linked_list() {
            node<T> * p = head_;
            while(head_->next_ != nullptr) {
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
