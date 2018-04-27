#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

// Prototypes for getting user selection
void display_menu();
char get_selection();

// Prototypes for handling menu selections
void handle_print(const std::vector<int> &v);
void handle_add(std::vector<int> &numbers);
void handle_mean(const std::vector<int> &v);
void handle_smallest(const std::vector<int> &v);
void handle_largest(const std::vector<int> &v);
void handle_quit();
void handle_unknown_selection();

// Prototypes for functions that work with list, display it, and calculate.
void print_list(const std::vector<int> &v);
double calculate_mean(const std::vector<int> &v);
int calculate_smallest(const std::vector<int> &v);
int calculate_largest(const std::vector<int> &v);
bool is_empty(const std::vector<int> &v);
void print_result(const char *message, const std::vector<int> &v,
                  int function(const std::vector<int> &v));
void print_result(const char *message, const std::vector<int> &v,
                  double function(const std::vector<int> &v));

// Handle errors
void print_error(const char *message);

int main() {
    char selection{};
    std::vector<int> numbers{};
    do {
        display_menu();
        selection = get_selection();

        switch (selection) {
        case 'P':
            handle_print(numbers);
            break;
        case 'A':
            handle_add(numbers);
            break;
        case 'M':
            handle_mean(numbers);
            break;
        case 'S':
            handle_smallest(numbers);
            break;
        case 'L':
            handle_largest(numbers);
            break;
        case 'Q':
            handle_quit();
            break;
        default:
            handle_unknown_selection();
        }
    } while (selection != 'Q');
}

void display_menu() {
    std::vector<std::string> options{
        "P - Print numbers",
        "A - Add a number",
        "M - Display mean of the numbers",
        "S - Display the smallest number",
        "L - Display the largest number",
        "Q - Quit",
    };

    cout << endl;
    for (auto option : options) {
        cout << option << endl;
    }

    cout << "\nEnter your choice: ";
}

char get_selection() {
    char selection{};
    cin >> selection;
    return std::toupper(selection);
}

void handle_print(const std::vector<int> &v) {
    if (is_empty(v)) {
        print_error("[] - The list is empty");
    } else {
        print_list(v);
    }
}

void print_list(const std::vector<int> &v) {
    cout << "[ ";
    for (auto number : v) {
        cout << number << " ";
    }
    cout << "]" << endl;
}

void handle_add(std::vector<int> &numbers) {
    int entry{};
    cout << "Enter an integer to add to the list: ";
    cin >> entry;
    numbers.push_back(entry);
    cout << entry << " added." << endl;
}

void handle_mean(const std::vector<int> &v) {
    if (is_empty(v)) {
        print_error("The list is empty, cannot calculate mean");
    } else {
        print_result("The mean is: ", v, calculate_mean);
    }
}

double calculate_mean(const std::vector<int> &v) {
    int sum{0};
    for (auto number : v) {
        sum += number;
    }

    return static_cast<double>(sum) / v.size();
}

void handle_smallest(const std::vector<int> &v) {
    if (is_empty(v)) {
        print_error("The list is empty, cannot calculate smallest");
    } else {
        print_result("The smallest number is: ", v, calculate_smallest);
    }
}

int calculate_smallest(const std::vector<int> &v) {
    int smallest{v[0]};
    for (auto number : v) {
        if (number < smallest) {
            smallest = number;
        }
    }

    return smallest;
}

void handle_largest(const std::vector<int> &v) {
    if (is_empty(v)) {
        print_error("The list is empty, cannot calculate largest");
    } else {
        print_result("The largest number is: ", v, calculate_largest);
    }
}

int calculate_largest(const std::vector<int> &v) {
    int largest{v[0]};
    for (auto number : v) {
        if (number > largest) {
            largest = number;
        }
    }

    return largest;
}

void print_result(const char *message, const std::vector<int> &v,
                  int function(const std::vector<int> &v)) {
    cout << message << function(v) << endl;
}

void print_result(const char *message, const std::vector<int> &v,
                  double function(const std::vector<int> &v)) {
    cout << message << function(v) << endl;
}

void handle_quit() { cout << "Goodbye" << endl; }

void handle_unknown_selection() {
    cout << "\nUnknown selection, please try again." << endl;
}

bool is_empty(const std::vector<int> &v) { return v.size() == 0; }

void print_error(const char *message) { cout << message << endl; }
