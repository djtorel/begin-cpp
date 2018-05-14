#pragma once
#include <iostream>

class Mystring {
  private:
    char *str;

  public:
    // No args constructor
    Mystring();
    // One arg constructor
    Mystring(const char *s);

    // Copy constructor
    Mystring(const Mystring &source);
    // Move constructor
    Mystring(Mystring &&source);

    // Destructor
    ~Mystring();

    /*********************************************************************
     * Member functions
     *********************************************************************/

    // Getters
    const char *get_string() const;
    int get_length() const;

    // Assignment operator overload (copy)
    Mystring &operator=(const Mystring &rhs);

    // Assignment operator overload (move)
    Mystring &operator=(Mystring &&rhs);

    /*********************************************************************
     * Global operator overrides - Done as friends of class.
     *********************************************************************/

    // Insertion operator (<<) overload
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);

    // Extraction operator (>>) overload
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

    // Unary minus (-) operator - Returns str in lowercase
    friend Mystring operator-(const Mystring &obj);

    // Unary plus (+) operator - Returns str in uppercase
    friend Mystring operator+(const Mystring &obj);

    // Overloaded --foo (pre decrement). Return str in all lowercase.
    friend Mystring &operator--(Mystring &obj);

    // Overloaded foo-- (post decrement). Return str in all lowercase post.
    friend Mystring operator--(Mystring &obj, int);

    // Overloaded ++foo (pre increment). Return str in all caps.
    friend Mystring &operator++(Mystring &obj);

    // Overloaded foo++ (post increment). Return str in all caps post.
    friend Mystring operator++(Mystring &obj, int);

    // Equality (==) operator - Returns true if lhs.str and rhs.str are equal
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);

    // Not equal (!=) operator - Returns true if lhs.str and rhs.str are not
    // equal
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);

    // Less than (<) operator - Returns true if lhs.str is lexically less than
    // rhs.str
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);

    // Greater than (>) operator - Returns true if lhs.str is lexically greater
    // than rhs.str
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);

    // Plus (+) operator - Concatenate lhs.str with rhs.str
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

    // Plus assign (+=) operator - Concatenate lhs.str with rhs.str and assign
    // to lhs.str
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);

    // Multiply (*) operator - Multiply lhs.str n times and return result
    friend Mystring operator*(const Mystring &lhs, const unsigned int &rhs);

    // Multiply assign (*=) - Multiply lhs.str n times and assign result to
    // lhs.str
    friend Mystring &operator*=(Mystring &lhs, const unsigned int &rhs);
};
