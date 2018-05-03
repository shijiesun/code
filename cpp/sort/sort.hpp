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
        int partition(T * arr, int begin, int end) {
            int i = begin + 1;
            int j = end - 1;

            while(i < j) {

                while(i < j && !less(*(arr + j), *(arr + begin))) {
                    --j;
                }

                while(i < j && !less(*(arr + begin), *(arr + i))) {
                    ++i;
                }

                if(i <= j && less(*(arr + j), *(arr + i))) {
                    swap(*(arr + i), *(arr + j));
                    cout << "swap_ij:(" << i << "," << j << ")" << endl;
                    print(arr, begin, end);
                }

            }
            return j;
        }

        template<typename T>
        void quick_sort(T * arr, int begin, int end) {

            if(begin >= end) return;

            cout << "quick_sort(" << begin << "," << end << ")" << endl;
            cout << "before:\t";

            print(arr, begin, end);

            int pivot = partition(arr, begin, end);

            cout << "pivot:" << pivot << endl;

            if(less(*(arr + pivot), *(arr + begin))) {
                swap(*(arr + begin), *(arr + pivot));
                cout << "swap_pivot:(" << pivot << "," << pivot << ")" << endl;
                cout << "after:\t";
                print(arr, begin, end);

                quick_sort(arr, begin, pivot);
                quick_sort(arr, pivot + 1, end);
            } else {
                ++begin;
                quick_sort(arr, begin, end);
            }
        }

        template<typename T>
        void heap_sort(T * arr, int begin, int end) {

        }
    }


}//namespace ssj

#endif
