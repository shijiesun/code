#include <iostream>

#include "sort.hpp"

using namespace std;

int main() {
    //int arr[] = {1,3,6,8,3,6,8,9};
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    //double arr[] = {0.0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};

    int length = sizeof(arr) / sizeof(int);

    //ssj::sort::bubble_sort<int>(arr, length);

    ssj::sort::insert_sort<int>(arr, length);

    cout << "after sort:";
    ssj::sort::print<int>(arr, length);

/*
    int a = 3;
    int b = 4;
    ssj::sort<int>::swap(a, b);

    cout << a << " " << b << endl;
*/
    return 0;
}
