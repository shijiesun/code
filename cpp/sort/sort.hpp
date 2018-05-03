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
        static int partition(T * arr, int begin, int end) {
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
        static bool heap_build(T * arr, int begin, int end) {
            bool flag = false;
            for(int i = end - 1; i > begin; --i) {
                int parent = (i - 1) >> 1;
                if(less(*(arr + i), *(arr + parent))) {
                    swap(*(arr + i), *(arr + parent));

                    flag = true;
                    //cout << "swap(" << *(arr + i) << "," << *(arr + parent) << ")" << endl;
                    //print(arr, begin, end);
                }
            }
            return flag;
        }

        template<typename T>
        static void heap_adjust(T * arr, int begin, int end) {
            int i = begin;
            while(i < end - 1) {
                int child1 = (i + 1) * 2;
                int child2 = child1 - 1;

                int child = -1;
                if(less(*(arr + child1), *(arr + child2))) {
                    child = child1;
                } else {
                    child = child2;
                }

                if(child < end && less(*(arr + child), *(arr + i))) {
                    swap(*(arr + child), *(arr + i));
                    cout << "swap(" << *(arr + child) << "," << *(arr + i) << ")" << endl;
                    print(arr, begin, end);
                }
                i = child;
            }

        }

        template<typename T>
        void heap_sort(T * arr, int begin, int end) {
            cout << "before:\t";
            print(arr, begin, end);

            while(heap_build(arr, begin, end));

            cout << "build:\t";
            print(arr, begin, end);

            for (int i = begin; i < end; ++i) {
                swap(*(arr + begin), *(arr + end - i - 1));
                cout << "pop swap(" << *(arr + begin) << "," << *(arr + end - i - 1) << ")" << endl;
                print(arr, begin, end - i - 1);


                heap_adjust(arr, begin, end - i - 1);

                cout << "-----adjust(" << i << "):\t";
                print(arr, begin, end);
            }

        }

        template<typename T>
        static void shell_insert(T * arr, int begin, int end, int d) {

            for (int i = begin; i < end; ++i) {
                for(int j = begin; j + d < end - i - 1; ++j) {
                    if(less(*(arr + j + d), *(arr + j))) {
                        swap(*(arr + j), *(arr + j + d));
                        cout << "d=" << d << " swap(" << j << "," << j + d << ")" << endl;
                        print(arr, begin, end);
                    }
                }
            }

        }

        template<typename T>
        void shell_sort(T * arr, int begin, int end) {
            if (arr == nullptr || end < 2) {
                return;
            }

            int d = (end - begin) >> 1;

            while(d > 0) {
                shell_insert(arr, begin, end, d);

                d /= 2;
            }
        }

        template<typename T>
        void merge(T * arr, int begin, int mid, int end) {
            T * temp = new T[end - begin];

            int start1 = begin;
            int end1 = mid;
            int start2 = mid;
            int end2 = end;

            int k = 0;

            cout << "before:\t";
            print(arr, begin, end);

            while(start1 < end1 && start2 < end2) {
                if(less(arr[start1], arr[start2])) {
                    temp[k++] = arr[start1++];
                } else {
                    temp[k++] = arr[start2++];
                }
            }


            while(start1 < end1) {
                temp[k++] = arr[start1++];
            }

            while(start2 < end2) {
                temp[k++] = arr[start2++];
            }

            for (int i = 0; i < end - begin; ++i) {
                *(arr + begin + i) = *(temp + i);
            }

            cout << "after:\t";
            print(arr, begin, end);

            delete [] temp;
        }
        
        template<typename T>
        void merge_sort(T * arr, int begin, int end) {
            if(begin + 1 >= end) return;

            int mid = (begin + end) >> 1;

            merge_sort(arr, begin, mid);
            merge_sort(arr, mid, end);

            merge(arr, begin, mid, end);

        }

    }


}//namespace ssj

#endif
