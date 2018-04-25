#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
    std::vector<std::string> options{
        "P - Print numbers",
        "A - Add a number",
        "M - Display mean of the numbers",
        "S - Display the smallest number",
        "L - Display the largest number",
        "Q - Quit",
    };

    std::vector<int> numbers{};
    bool quit = false;
    while (!quit) {
        cout << endl;
        for (auto option : options) {
            cout << option << endl;
        }

        cout << "\nEnter your choice: ";
        char selection{};
        cin >> selection;

        switch (selection) {
        case 'Q':
        case 'q':
            quit = true;
            break;
        case 'P':
        case 'p': {
            if (numbers.size() == 0) {
                cout << "[] - The list is empty" << endl;
            } else {
                cout << "[ ";
                for (auto number : numbers) {
                    cout << number << " ";
                }
                cout << "]" << endl;
            }
            break;
        }
        case 'A':
        case 'a': {
            cout << "Enter an integer to add to the list: ";
            int entry{};
            cin >> entry;
            numbers.push_back(entry);
            cout << entry << " added." << endl;
            break;
        }
        case 'M':
        case 'm': {
            if (numbers.size() == 0) {
                cout << "The list is empty" << endl;
            } else {
                double sum{0};
                for (auto number : numbers) {
                    sum += number;
                }
                double mean{sum / numbers.size()};
                cout << "The mean is: " << mean << endl;
            }
            break;
        }
        case 'S':
        case 's': {
            if (numbers.size() == 0) {
                cout << "The list is empty" << endl;
            } else {
                int smallest{numbers[0]};
                for (auto number : numbers) {
                    if (number < smallest) {
                        smallest = number;
                    }
                }
                cout << "The smallest number is: " << smallest << endl;
            }
            break;
        }
        case 'L':
        case 'l': {
            if (numbers.size() == 0) {
                cout << "The list is empty" << endl;
            } else {
                int largest{numbers[0]};
                for (auto number : numbers) {
                    if (number > largest) {
                        largest = number;
                    }
                }
                cout << "The largest number is: " << largest << endl;
            }
            break;
        }
        default:
            cout << "\nUnknown selection, please try again." << endl;
        }
    }
}
