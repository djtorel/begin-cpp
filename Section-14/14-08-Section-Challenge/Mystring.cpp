#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif
#include "Mystring.h"
#include <cctype>
#include <cstring>
#include <iostream>

// Global Overloaded << operator function
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// Global Overloaded >> operator function
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    // Create large buffer (can overrun...)
    char *buff = new char[1000];

    // istream in to buff
    in >> buff;

    // Assign rhs to buff
    rhs = Mystring{buff};

    // Delete buff
    delete[] buff;

    // Return in
    return in;
}

// No arg constructor
Mystring::Mystring() : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// One arg constructor
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
    // std::cout << "Copy constructor used" << std::endl;
}

// Move constructor
Mystring::Mystring(Mystring &&source) : str{source.str} {
    source.str = nullptr;
    // std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring::~Mystring() { delete[] str; }

// Getters
const char *Mystring::get_str() const { return str; }
int Mystring::get_length() const { return std::strlen(str); }

// Overloaded operators

// Overloaded = operator (copy).
Mystring &Mystring::operator=(const Mystring &rhs) {
    // std::cout << "Using copy assignment" << std::endl;
    if (rhs.str == nullptr) {
        return *this;
    }

    delete[] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Overloaded = operator (move).
Mystring &Mystring::operator=(Mystring &&rhs) {
    // std::cout << "Using move assignment" << std::endl;
    if (rhs.str == nullptr) {
        return *this;
    }

    delete[] str;
    str = rhs.str;
    rhs.str = nullptr;

    return *this;
}

// Overloaded - (minus) operator. Returns lowercase version of the object's
// string.
Mystring Mystring::operator-() const {
    // Create buffer
    char *buff = new char[std::strlen(str) + 1];
    // Copy str to buffer
    std::strcpy(buff, str);
    // Loop through buffer string and convert to lowercase
    for (size_t i{0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    // Create temp Mystring initialized from buff
    Mystring temp{buff};
    // Delete buff pointer
    delete[] buff;
    // Return temp
    return temp;
}

// Overloaded + (unary plus). Returns uppercase version of Object's string.
Mystring Mystring::operator+() const {
    // Create buffer large enough for str + 1
    char *buff = new char[std::strlen(str) + 1];

    // Copy str to buffer
    std::strcpy(buff, str);

    // Loop over buffer and set buff[i] to upper case
    for (size_t i{0}; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }

    // Create temp Mystring initialize to buff
    Mystring temp{buff};

    // Delete buff pointer
    delete[] buff;

    // Return temp
    return temp;
}

// Overloaded == (equality). Returns true if the two strings are equal.
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

// Overloaded != (not equal). Returns true if the two strings are not equal.
bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

// Overloaded < (less than). Returns true if lhs is lexically less than rhs.
bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

// Overloaded > (greater than). Returns true if lhs is lexally greater than rhs.
bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

// Overloaded + (plus). Concatenate lhs string and rhs string.
Mystring Mystring::operator+(const Mystring &rhs) const {
    // Create buffer big enough for str, and rhs.str plus null char
    char *buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];
    // Copy str into buff
    std::strcpy(buff, str);
    // Concat buff and rhs.str
    std::strcat(buff, rhs.str);
    // Create temp Mystring to return
    Mystring temp{buff};
    // Delete buff pointer
    delete[] buff;

    // Return temp
    return temp;
}

// Overloaded += (plus assign). Concatenate rhs and lhs and store result in
// lhs object
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// Overloaded * (multiply). Repeat, results in string that is copied n times.
Mystring Mystring::operator*(const unsigned int &rhs) const {
    Mystring temp{};
    for (unsigned int i{0}; i < rhs; i++) {
        temp += *this;
    }
    return temp;
}

// Overloaded *= (multiply assign). Repeat string on lhs n times and store back
// in lhs object.
Mystring &Mystring::operator*=(const unsigned int &rhs) {
    *this = *this * rhs;
    return *this;
}

// Overloaded ++foo (pre increment). Return str in all caps.
Mystring &Mystring::operator++() {
    for (size_t i{0}; i < std::strlen(str); i++) {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

// Overloaded foo++ (post increment). Return str in all caps post.
Mystring Mystring::operator++(int) {
    Mystring temp{*this};
    operator++();
    return temp;
}

// Overloaded --foo (pre decrement). Return str in all lowercase.
Mystring &Mystring::operator--() {
    for (size_t i{0}; i < std::strlen(str); i++) {
        str[i] = std::tolower(str[i]);
    }
    return *this;
}

// Overloaded foo-- (post decrement). Return str in all lowercase post.
Mystring Mystring::operator--(int) {
    Mystring temp{*this};
    operator--();
    return temp;
}
