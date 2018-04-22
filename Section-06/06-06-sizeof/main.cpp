#include <iostream>
#include <climits>

using namespace std;

int main() {
    cout << "sizeof information" << endl;
    cout << "===============================" << endl;
    
    cout << "char: " << sizeof(char) << " bytes." << endl;
    cout << "int: " << sizeof(int) << " bytes." << endl;
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
    cout << "short: " << sizeof(short) << " bytes." << endl;
    cout << "long: " << sizeof(long) << " bytes." << endl;
    
    return 0;
}