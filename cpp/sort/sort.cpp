#include <iostream>

#include "sort.hpp"

using namespace std;

int main() {
    int arr[] = {1,3,6,8,3,6,8,9};

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
