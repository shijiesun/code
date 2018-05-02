#ifndef __SSJ_SORT__
#define __SSJ_SORT__

#include <iostream>
#include <memory.h>

using namespace std;

namespace ssj {

    namespace sort {

        template<typename T>
        void print(const T * arr, int length) {
            for (int i = 0; i < length; ++i) {
                cout << *(arr + i) << " ";
            }
            cout << endl;
        }

        template<typename T>
        void swap(T & a, T & b) {
            T t = move(a);
            a = move(b);
            b = move(t);
        }

        template<typename T>
        bool compare(const T & a, const T & b) {
            return a < b;
        }

        template<>
        bool compare(const int & a, const int & b) {
            return a > b;
        }

        template<typename T>
        void bubble_sort(T * arr, int length) {
            if (arr == nullptr || length < 2) {
                return;
            }

            for (int i = 0; i < length; ++i) {
                for(int j = 0; j < length - i - 1; ++j) {
                    if(compare(*(arr + j), *(arr + j + 1))) {
                        swap(*(arr + j), *(arr + j + 1));
                        print(arr, length);
                    }
                }
            }
        }

        template<typename T>
        void insert_sort(T * arr, int length) {
            if (arr == nullptr || length < 2) {
                return;
            }

            for (int i = 1; i < length; ++i) {
                for(int j = 0; j < i; ++j) {
                    if(compare(*(arr + j), *(arr + i))) {
                        T a = move(*(arr + i));
                        for(int k = i - 1; k >= j; --k) {
                            *(arr + k + 1) = *(arr + k);
                        }
                        *(arr + j) = a;
                        print(arr, length);
                    }
                }
            }
        }
    }
}//namespace ssj

#endif
