#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {

    const int cents_per_dollar{100};
    const int cents_per_quarter{25};
    const int cents_per_dime{10};
    const int cents_per_nickel{5};

    cout << "Enter amount in cents: ";

    int cents{0};
    cin >> cents;

    int dollars{cents / cents_per_dollar};
    cents %= cents_per_dollar;

    int quarters{cents / cents_per_quarter};
    cents %= cents_per_quarter;

    int dimes{cents / cents_per_dime};
    cents %= cents_per_dime;

    int nickels{cents / cents_per_nickel};
    cents %= cents_per_nickel;

    int pennies = cents;

    cout << "Your change is as follows: " << endl
         << "dollars:\t" << dollars << endl
         << "quarters:\t" << quarters << endl
         << "dimes:\t\t" << dimes << endl
         << "nickels:\t" << nickels << endl
         << "pennies:\t" << pennies << endl;

    return 0;
}
