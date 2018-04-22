/**
 * Section 7 Challenge
 *
 * Write a C++ program as follows:
 *
 * Declare 2 empty vectors of integers named
 * vector1 and vector2, respectively.
 *
 * Add 10 and 20 to vector1 dynamically using push_back
 * Display the elements in vector1 using the at() method as well as its size
 * using the size() method
 *
 * Add 100 and 200 to vector2 dynamically using push_back
 * Display the elements in vector2 using the at() method as well as its size
 * using the size() method
 *
 * Declare an empty 2D vector called vector_2d
 * Remember, that a 2D vector is a vector of vector<int>
 *
 * Add vector1 to vector_2d dynamically using push_back
 * add vector2 to the vector_2d dynamically using push_back
 *
 * Display the elements in vector_2d using the at() method
 *
 * Change vector1.at(0) to 1000
 *
 * Display the elements in vector_2d again using the at() method
 *
 * Display the elements in vector1
 *
 * What dis you expect? Did you get what you expected? What do you think
 * happened?
 */
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    // Declare 2 empty vectors of integers named vector1 and vector2
    vector<int> vector1{}, vector2{};
    // Add 10 and 20 to vector1 using push_back
    vector1.push_back(10);
    vector1.push_back(20);

    // Display the elements in vector1 using at() method
    cout << "\nElements in vector1:" << endl
         << "[" << vector1.at(0) << " , " << vector1.at(1) << "]" << endl
         << "vector1 contains " << vector1.size() << " elements" << endl;

    // Add 100 and 200 to vector2 using push_back
    vector2.push_back(100);
    vector2.push_back(200);

    // Display the elements in vector2 using at() method
    cout << "\nElements in vector2:" << endl
         << "[" << vector2.at(0) << " , " << vector2.at(1) << "]" << endl
         << "vector2 contains " << vector1.size() << " elements" << endl;

    // Declare an empty 2D vector called vector_2d
    vector<vector<int>> vector_2d{};

    // Add vector1 to vector_2d using push_back
    vector_2d.push_back(vector1);
    // Add vector2 to vector_2d using push_back
    vector_2d.push_back(vector2);

    // Display the elements in the vector_2d using the at() method
    cout << "\nElements in vector_2d:" << endl
         << "[[" << vector_2d.at(0).at(0) << " , " << vector_2d.at(0).at(1)
         << "] , [" << vector_2d.at(1).at(0) << " , " << vector_2d.at(1).at(1)
         << "]]" << endl
         << "vector_rd contains " << vector_2d.size() << " elements" << endl;

    // Change vector1.at(0) to 1000
    vector1.at(0) = 1000;

    // Display the elements in vector_2d again
    cout << "\nElements in vector_2d:" << endl
         << "[[" << vector_2d.at(0).at(0) << " , " << vector_2d.at(0).at(1)
         << "] , [" << vector_2d.at(1).at(0) << " , " << vector_2d.at(1).at(1)
         << "]]" << endl;

    // Display the elements in vector1
    cout << "\nElements in vector1:" << endl
         << "[" << vector1.at(0) << " , " << vector1.at(1) << "]" << endl;

    // What did I expect to print?
    //  I expected that the elements in vector_2d wouldn't change, because this
    //  was asked. It must mean that push_back() copies the values and does not
    //  push the pointer into the array. So vector1 changes to not reflect in
    //  vector_2d.

    return 0;
}
