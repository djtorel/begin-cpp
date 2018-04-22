#include <iostream>

int main() {

    char vowels[]{'a', 'e', 'i', 'o', 'u'};

    std::cout << "\nThe first vowel is: " << vowels[0] << std::endl;
    std::cout << "The last vowel is: " << vowels[4] << std::endl;

    double hi_temps[]{90.1, 89.8, 77.5, 81.6};
    std::cout << "\nThe first high temperature is: " << hi_temps[0];

    hi_temps[0] = 100.7;

    std::cout << "The first high temperature is now: " << hi_temps[0];

    int test_scores[5]{};

    std::cout << "\nFirst score at index 0: " << test_scores[0] << std::endl
              << "Second score at index 1: " << test_scores[1] << std::endl
              << "Third score at index 2: " << test_scores[2] << std::endl
              << "Fourth score at index 3: " << test_scores[3] << std::endl
              << "Fifth score at index 4: " << test_scores[4] << std::endl;

    return 0;
}
