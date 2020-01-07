#include <iostream>
#include "String.hpp"

int main(void) {
    String a, b;
    a = b = "Hello";

    a.printStringValue();
    b.printStringValue();

    std::cout << a[0] << std::endl; //read
    a.printStringValue();
    b.printStringValue();

    a[0] = 'h'; //write
    a.printStringValue();
    b.printStringValue();
}
