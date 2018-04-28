#ifndef __SSJ_SORT__
#define __SSJ_SORT__

#include <iostream>
#include <memory.h>

using namespace std;

namespace ssj {

    template<typename T>
    class sort {
    public:
        static void bubble_sort(T * arr, int length) {
            if (arr == nullptr || length < 2) {
                return;
            }

            for (int i = 0; i < length; ++i) {
                for(int j = 0; j < length - i - 1; ++j) {
                    if(*(arr + j) > *(arr + j + 1)) {
                        swap(*(arr + j), *(arr + j + 1));
                        //print(arr, length);
                    }
                }
            }
        }

        static void print(const T * arr, int length) {
            for (int i = 0; i < length; ++i) {
                cout << *(arr + i) << " ";
            }
            cout << endl;
        }

        static void swap(T & a, T & b) {
            T t = move(a);
            a = move(b);
            b = move(t);
        }
    };
}//namespace ssj

#endif
