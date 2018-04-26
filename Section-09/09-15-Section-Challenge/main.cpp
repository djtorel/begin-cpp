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

    char selection{};
    std::vector<int> numbers{};
    do {
        cout << endl;
        for (auto option : options) {
            cout << option << endl;
        }

        cout << "\nEnter your choice: ";
        cin >> selection;

        if (selection == 'p' || selection == 'P') {
            if (numbers.size() == 0) {
                cout << "[] - The list is empty" << endl;
            } else {
                cout << "[ ";
                for (auto number : numbers) {
                    cout << number << " ";
                }
                cout << "]" << endl;
            }
        } else if (selection == 'a' || selection == 'A') {
            cout << "Enter an integer to add to the list: ";
            int entry{};
            cin >> entry;
            numbers.push_back(entry);
            cout << entry << " added." << endl;
        } else if (selection == 'm' || selection == 'M') {
            if (numbers.size() == 0) {
                cout << "The list is empty" << endl;
            } else {
                int sum{0};
                for (auto number : numbers) {
                    sum += number;
                }
                cout << "The mean is: "
                     << static_cast<double>(sum) / numbers.size() << endl;
            }
        } else if (selection == 's' || selection == 'S') {
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
        } else if (selection == 'l' || selection == 'L') {
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
        } else if (selection == 'q' || selection == 'Q') {
            cout << "Goodbye" << endl;
        } else {
            cout << "\nUnknown selection, please try again." << endl;
        }
    } while (selection != 'q' && selection != 'Q');
}
