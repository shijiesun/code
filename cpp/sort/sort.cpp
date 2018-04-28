#include <iostream>

#include "sort.hpp"

using namespace std;

int main() {
    //int arr[] = {1,3,6,8,3,6,8,9};
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    //double arr[] = {0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0};
    //int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int length = sizeof(arr) / sizeof(int);

    ssj::sort<int>::bubble_sort(arr, length);

    cout << "after sort:";
    ssj::sort<int>::print(arr, length);

/*
    int a = 3;
    int b = 4;
    ssj::sort<int>::swap(a, b);

    cout << a << " " << b << endl;
*/
    return 0;
}
