#include "Account.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    Account dom_account;
    dom_account.set_name("Dom's account");
    dom_account.set_balance(1000.0);

    if (dom_account.deposit(200.0)) {
        std::cout << "Deposit OK" << std::endl;
    } else {
        std::cout << "Deposit not allowed" << std::endl;
    }

    if (dom_account.withdraw(500.0)) {
        std::cout << "Withdraw OK" << std::endl;
    } else {
        std::cout << "Insufficient funds" << std::endl;
    }

    if (dom_account.withdraw(1500.0)) {
        std::cout << "Withdraw OK" << std::endl;
    } else {
        std::cout << "Insufficient funds" << std::endl;
    }

    std::cout << "Balance: " << dom_account.get_balance() << std::endl;

    return 0;
}
