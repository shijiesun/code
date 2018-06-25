#include <iostream>

template<unsigned n>                 // general case: the value of
struct Factorial {                   // Factorial<n> is n times the value
                                     // of Factorial<n-1>

    enum { value = n * Factorial<n-1>::value };

};

template<>                           // special case: the value of
struct Factorial<0> {                // Factorial<0> is 1
    enum { value = 1 };

};


int main()
{
    std::cout << Factorial<5>::value << std::endl;            // prints 120
    std::cout << Factorial<10>::value << std::endl;           // prints 3628800
}
