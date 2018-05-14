#pragma once
#include <iostream>

class Mystring {
    // Global Overloaded << operator function
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    // Global Overloaded >> operator function
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

  private:
    char *str;

  public:
    // Constructor - no args
    Mystring();
    // Constructor - one arg
    Mystring(const char *s);

    // Copy constructor
    Mystring(const Mystring &source);

    // Move constructor
    Mystring(Mystring &&source);

    // Destructor
    ~Mystring();

    // Getters
    const char *get_str() const;
    int get_length() const;

    // Overloaded operators

    // Overloaded = operator (copy)
    Mystring &operator=(const Mystring &rhs);

    // Overloaded = operator (move)
    Mystring &operator=(Mystring &&rhs);

    // Overloaded - (unary minus). Returns lowercase version of the object's
    // string.
    Mystring operator-() const;

    // Overloaded + (unary plus). Returns uppercase version of Object's string.
    Mystring operator+() const;

    // Overloaded == (equality). Returns true if the two strings are equal.
    bool operator==(const Mystring &rhs) const;

    // Overloaded != (not equal). Returns true if the two strings are not equal.
    bool operator!=(const Mystring &rhs) const;

    // Overloaded < (less than). Returns true if lhs is lexically less than rhs.
    bool operator<(const Mystring &rhs) const;

    // Overloaded > (greater than). Returns true if lhs is lexally greater than
    // rhs.
    bool operator>(const Mystring &rhs) const;

    // Overloaded + (plus). Concatenate lhs string and rhs string.
    Mystring operator+(const Mystring &rhs) const;

    // Overloaded += (plus assign). Concatenate rhs and lhs and store result in
    // lhs object
    Mystring &operator+=(const Mystring &rhs);

    // Overloaded * (multiply). Repeat, results in string that is copied n
    // times.
    Mystring operator*(const unsigned int &rhs) const;

    // Overloaded *= (multiply assign). Repeat string on lhs n times and store
    // back in lhs object.
    Mystring &operator*=(const unsigned int &rhs);

    // Overloaded ++foo (pre increment). Return str in all caps.
    Mystring &operator++();

    // Overloaded foo++ (post increment). Return str in all caps post.
    Mystring operator++(int);

    // Overloaded --foo (pre decrement). Return str in all lowercase.
    Mystring &operator--();

    // Overloaded foo-- (post decrement). Return str in all lowercase post.
    Mystring operator--(int);
};
