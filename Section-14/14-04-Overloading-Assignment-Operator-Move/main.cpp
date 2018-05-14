#include "Mystring.h"
#include <iostream>

int main() {
    Mystring a{"Hello"};
    a = Mystring{"Hola"};

    a = "Bonjour";

    a.display();

    return 0;
}
