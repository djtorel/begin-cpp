/**
 *
 * Frank's Carpet Cleaning Service
 * Charges $30 per room
 * Sales tax rate is 6%
 * Estimates are valid for 30 days
 *
 * Prompt user for the number of rooms they would like cleaned
 * and provide an estimate such as:
 *
 * Estimate carpet cleaning service:
 * Number of rooms: 2
 * Price per room: $30
 * Cost: $60
 * Tax: $3.6
 * ================================
 * Total estimate: $63.6
 * The estimate is valid for 30 days
 *
 * Pseudocode:
 *  Prompt the user to enter the number of rooms
 * Display number of rooms
 * Display price per room
 *
 * Display cost: (number of rooms * price per room)
 * Display tax: number of rooms * pricer per room * tax rate
 * Display total estimate: (number of rooms * price per room) +
 *                         (number of rooms * price per room * tax rate)
 * Display estimate expiration time.
 *
 */

#include <iostream>

int main() {
    std::cout << "Hello, welcome to Frank's Carpet Cleaning Service"
              << std::endl;

    std::cout << "\nHow many rooms would you like cleaned? ";

    int number_of_rooms{0};
    std::cin >> number_of_rooms;

    const double PRICE_PER_ROOM{30.0};
    const double SALES_TAX_RATE{0.06};
    const int ESTIMATE_EXPIRY{30};

    std::cout << "\nEstimate for carpet cleaning service" << std::endl;
    std::cout << "Number of rooms: " << number_of_rooms << std::endl;
    std::cout << "Price per room: $" << PRICE_PER_ROOM << std::endl;
    std::cout << "Cost: $" << PRICE_PER_ROOM * number_of_rooms << std::endl;
    std::cout << "Tax: $" << PRICE_PER_ROOM * number_of_rooms * SALES_TAX_RATE
              << std::endl;

    std::cout << "=======================================" << std::endl;
    std::cout << "Total estimate: $"
              << (PRICE_PER_ROOM * number_of_rooms) +
                     (PRICE_PER_ROOM * number_of_rooms * SALES_TAX_RATE)
              << std::endl;
    std::cout << "This estimate is valid for " << ESTIMATE_EXPIRY << " days"
              << std::endl;

    std::cout << std::endl;
    return 0;
}