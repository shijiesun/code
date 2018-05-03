#ifndef __SSJ_SORT__
#define __SSJ_SORT__

#include <iostream>
#include <memory.h>

using namespace std;

namespace ssj {

    namespace sort {

        template<typename T>
        void print(const T * arr, int begin, int end) {
            for (int i = begin; i < end; ++i) {
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
        bool less(const T & a, const T & b) {
            return a < b;
        }
/*
  template<>
  bool less(const int & a, const int & b) {
  return a > b;
  }
*/
        template<typename T>
        void bubble_sort(T * arr, int begin, int end) {
            if (arr == nullptr || end < 2) {
                return;
            }

            for (int i = begin; i < end; ++i) {
                for(int j = begin; j < end - i - 1; ++j) {
                    if(less(*(arr + j + 1), *(arr + j))) {
                        swap(*(arr + j), *(arr + j + 1));
                        print(arr, begin, end);
                    }
                }
            }
        }

        template<typename T>
        void insert_sort(T * arr, int begin, int end) {
            if (arr == nullptr || end < 2) {
                return;
            }

            for (int i = begin + 1; i < end; ++i) {
                for(int j = begin; j < i; ++j) {
                    if(less(*(arr + i), *(arr + j))) {
                        T a = move(*(arr + i));
                        for(int k = i - 1; k >= j; --k) {
                            *(arr + k + 1) = *(arr + k);
                        }
                        *(arr + j) = a;
                        print(arr, begin, end);
                    }
                }
            }
        }

        template<typename T>
        void quick_sort(T * arr, int begin, int end) {
            cout << "quick_sort(" << begin << "," << end << ")" << endl;
            cout << "before:\t";

            print(arr, begin, end);

            int i = begin + 1;
            int j = end - 1;

            if(i >= j) return;

            int pivot = begin;

            while(i < j) {

                while(i < j && !less(*(arr + j), *(arr + pivot))) {
                    --j;
                }

                while(i < j && !less(*(arr + pivot), *(arr + i))) {
                    ++i;
                }

                if(i <= j && less(*(arr + j), *(arr + i))) {
                    swap(*(arr + i), *(arr + j));
                    cout << "swap_ij:(" << i << "," << j << ")" << endl;
                    print(arr, begin, end);
                }

            }

            cout << "j:" << j << endl;

            if(less(*(arr + j), *(arr + pivot))) {
                swap(*(arr + pivot), *(arr + j));
                cout << "swap_pivot:(" << pivot << "," << j << ")" << endl;
                cout << "after:\t";
                print(arr, begin, end);

                quick_sort(arr, begin, j);
                quick_sort(arr, j + 1, end);
            } else {
                ++begin;
                quick_sort(arr, begin, end);
            }
        }
    }
}//namespace ssj

#endif
