#include "Mystring.h"
#include <iostream>

int main() {
    Mystring a{"Hello"};
    Mystring b;

    b = a;

    b = "This is a test";

    a.display();
    b.display();

    return 0;
}
