#include <iostream>

using namespace std;


template<typename InputIterator, typename T, typename FunObj>
T accumulate(InputIterator first, InputIterator last, T init, FunObj fun) {
    while(first != last) {
        init = fun(init, *first);
        ++first;
    }
    return init;
}

template<typename T>
class Test {
public:
    T operator()(const T & x, const T & y) {
        return x + y;
    }
};


int main(int argc, char * argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6};

    int x = ::accumulate(&a[0], &a[5], 0, Test<int>());

    cout << x << endl;
    return 0;
}
