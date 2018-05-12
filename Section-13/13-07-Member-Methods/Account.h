#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account {
  private:
    // Attributes
    std::string name;
    double balance;

  public:
    // Methods
    void set_balance(double bal);
    double get_balance();
    void set_name(std::string n);
    std::string get_name();
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _ACCOUNT_H_
