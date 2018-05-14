#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif
#include "Mystring.h"
#include <cctype>
#include <cstring>
#include <iostream>

// No-args constructor
Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source) : str(source.str) {
    source.str = nullptr;
    std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() {
    // if (str == nullptr) {
    //     std::cout << "Calling destructor for Mystring : nullptr" <<
    //     std::endl;
    // } else {
    //     std::cout << "Calling destructor for Mystring : " << str <<
    //     std::endl;
    // }
    delete[] str;
}

// Overloaded assignment operator (copy)
Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Using copy assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }

    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

// Overloaded assignment operator (move)
Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) {
        return *this;
    }

    delete[] str;
    str = rhs.str;

    rhs.str = nullptr;

    return *this;
}

// Make lowercase (- unarity operator overloaded)
Mystring Mystring::operator-() const {
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(static_cast<unsigned char>(buff[i]));
    }
    Mystring temp{buff};
    delete[] buff;
    return temp;
}

// Overloaded + operator. Concatenation.
Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t buff_size = std::strlen(str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};

    delete[] buff;
    return temp;
}

// Equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }
