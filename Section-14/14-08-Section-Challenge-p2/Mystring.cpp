#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES 1
#endif
#include "Mystring.h"
#include <cctype>
#include <cstring>
#include <iostream>

// No args constructor
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

/*********************************************************************
 * Member functions
 *********************************************************************/

// Getters
const char *Mystring::get_string() const { return str; }
int Mystring::get_length() const { return std::strlen(str); }

// Assignment operator overload (copy)
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

// Assignment operator overload (move)
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

/*********************************************************************
 * Global operator overrides - Done as s of class.
 *********************************************************************/

// Insertion operator (<<) overload
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// Extraction operator (>>) overload
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    // Create a large buffer (can be overrun...)
    char *buff = new char[1000];
    // Extract input into buff
    in >> buff;
    // Assign rhs to Mystring obj initialized with buff
    rhs = Mystring{buff};
    // Delete buff pointer
    delete[] buff;
    // Return in
    return in;
}

// Unary minus (-) operator - Returns str in lowercase
Mystring operator-(const Mystring &obj) {
    // Create buffer large enough got obj.str
    char *buff = new char[std::strlen(obj.str) + 1];

    // Copy obj.str to buffer
    std::strcpy(buff, obj.str);

    // Loop through buffer, assign buff[i] the lowercase value of buff[i]
    for (size_t i{0}; i < std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }

    // Create temp Mystring, initialize with buff
    Mystring temp{buff};

    // Delete buff pointer
    delete[] buff;

    // Return temp
    return temp;
}

// Unary plus (+) operator - Returns str in uppercase
Mystring operator+(const Mystring &obj) {
    // Create buffer large enough for obj.str + 1
    char *buff = new char[std::strlen(obj.str) + 1];

    // Copy obj.str into buffer
    std::strcpy(buff, obj.str);

    // Loop through buffer and assign buff[i] the uppercase value of buff[i]
    for (size_t i{0}; i < std::strlen(buff); i++) {
        buff[i] = std::toupper(buff[i]);
    }

    // Create temp Mystring object, initialize with buff
    Mystring temp{buff};

    // Delete buff pointer
    delete[] buff;

    // Return temp
    return temp;
}

// Overloaded --foo (pre decrement). Return str in all lowercase.
Mystring &operator--(Mystring &obj) {
    for (size_t i{0}; i < std::strlen(obj.str); i++) {
        obj.str[i] = std::tolower(obj.str[i]);
    }
    return obj;
}

// Overloaded foo-- (post decrement). Return str in all lowercase post.
Mystring operator--(Mystring &obj, int) {
    Mystring temp{obj};
    ++obj;
    return temp;
}

// Overloaded ++foo (pre increment). Return str in all caps.
Mystring &operator++(Mystring &obj) {
    for (size_t i{0}; i < 0; i++) {
        obj.str[i] = std::toupper(obj.str[i]);
    }
    return obj;
}

// Overloaded foo++ (post increment). Return str in all caps post.
Mystring operator++(Mystring &obj, int) {
    Mystring temp{obj};
    ++obj;
    return temp;
}

// Equality (==) operator - Returns true if lhs.str and rhs.str are equal
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Not equal (!=) operator - Returns true if lhs.str and rhs.str are not
// equal
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) != 0);
}

// Less than (<) operator - Returns true if lhs.str is lexically less than
// rhs.str
bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

// Greater than (>) operator - Returns true if lhs.str is lexically greater
// than rhs.str
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) > 0);
}

// Plus (+) operator - Concatenate lhs.str with rhs.str
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    // Create buffer large enough for lhs.str + rhs.str +1
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    // Copy lhs.str to buffer
    std::strcpy(buff, lhs.str);

    // strcat buff and rhs.str
    std::strcat(buff, rhs.str);

    // Create temp Mystring object and initialize with buffer
    Mystring temp{buff};

    // Delete buffer
    delete[] buff;

    // Return temp
    return temp;
}

// Plus assign (+=) operator - Concatenate lhs.str with rhs.str and assign
// to lhs.str
Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

// Multiply (*) operator - Multiply lhs.str n times and return result
Mystring operator*(const Mystring &lhs, const unsigned int &rhs) {
    // Create empty temp Mystring object
    Mystring temp{};
    // Loop rhs times and do lhs += lhs in each loop
    for (unsigned int i{0}; i < rhs; i++) {
        temp += lhs;
    }

    // Return temp
    return temp;
}

// Multiply assign (*=) - Multiply lhs.str n times and assign result to
// lhs.str
Mystring &operator*=(Mystring &lhs, const unsigned int &rhs) {
    lhs = lhs * rhs;
    return lhs;
}
