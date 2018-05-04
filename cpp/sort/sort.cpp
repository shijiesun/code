#include <iostream>

#include "sort.hpp"

using namespace std;

int main() {
    //int arr[] = {1,3,6,8,3,6,8,9};
    //int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    //int arr[] = {3,2,4,1};
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    //int arr[] = {49, 38, 65, 97, 76, 13, 27, 50};

    //double arr[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

    int length = sizeof(arr) / sizeof(int);

    //ssj::sort::bubble_sort<int>(arr, 0, length);

    //ssj::sort::insert_sort<int>(arr, 0, length);

    //ssj::sort::quick_sort<int>(arr, 0, length);

    //ssj::sort::heap_sort<int>(arr, 0, length);

    //ssj::sort::shell_sort<int>(arr, 0, length);

    //ssj::sort::merge_sort<int>(arr, 0, length);

    ssj::sort::counting_sort<int>(arr, 0, length);

    cout << "after sort:";
    ssj::sort::print<int>(arr, 0, length);

/*
    int a = 3;
    int b = 4;
    ssj::sort<int>::swap(a, b);

    cout << a << " " << b << endl;
*/
    return 0;
}
