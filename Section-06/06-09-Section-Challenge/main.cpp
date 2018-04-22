/**
 * Frank's Carpet Cleaning Service
 * Charges:
 *  $25 per small room
 *  $35 per large room
 * Sales tax rate is 6%
 * Estimates valid for 30 days
 *
 * Prompt the user for the number of small and large rooms they would like
 * cleaned and provide an estimate such as:
 *
 * Estimate for carpet cleaning service
 * Number of small rooms: 3
 * Number of large rooms: 1
 * Price per small room: $25
 * Price per large room: $35
 * Cost: $110
 * Tax: $6.6
 * ====================================
 * Total estimate: $116.6
 * This estimate is valid for 30 days
 */

#include <iostream>

int main() {

    const double SMALL_ROOM_PRICE{25.0};
    const double LARGE_ROOM_PRICE{35.0};
    const double SALES_TAX_RATE{0.06};
    const int ESTIMATE_EXPIRY{30};

    std::cout << "Hello, welcome to Frank's Carpet Cleaning Service."
              << std::endl;

    std::cout << "\nPlease enter the number of small rooms: ";
    int number_of_small_rooms{0};
    std::cin >> number_of_small_rooms;
    std::cout << number_of_small_rooms;

    std::cout << "Please enter the number of large rooms: ";
    int number_of_large_rooms{0};
    std::cin >> number_of_large_rooms;

    double sub_total{(SMALL_ROOM_PRICE * number_of_small_rooms) +
                     (LARGE_ROOM_PRICE * number_of_large_rooms)};
    double tax_total{sub_total * SALES_TAX_RATE};
    double total_estimate{sub_total + tax_total};

    std::cout << std::endl
              << "Estimate for carpet cleaning service" << std::endl
              << "Number of small rooms: " << number_of_small_rooms << std::endl
              << "Number of large rooms: " << number_of_large_rooms << std::endl
              << "Price per small room: $" << SMALL_ROOM_PRICE << std::endl
              << "Price per large room: $" << LARGE_ROOM_PRICE << std::endl
              << "Cost: $" << sub_total << std::endl
              << "Tax: $" << tax_total << std::endl
              << "====================================" << std::endl
              << "Total estimate: $" << total_estimate << std::endl
              << "This estimate is valid for " << ESTIMATE_EXPIRY << "days."
              << std::endl;

    return 0;
}