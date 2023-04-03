#include <iostream>
using namespace std;

int main() {
    unsigned int data = 0x00000000;  // initialize data variable to 0

    char c1, c2, c3, c4;

    cout << "Please input 4 characters: " << endl;

    cin >> c1 >> c2 >> c3 >> c4;

    // bitwise OR to combine the ASCII codes of the four characters into one unsigned int variable
    data = ((unsigned int)c1 << 24) | ((unsigned int)c2 << 16) | ((unsigned int)c3 << 8) | (unsigned int)c4;

    cout << "The encrypted result is (decimal): " << data << endl;
    cout << "The encrypted result is (hex): 0x" << hex << data << endl;

    return 0;
}
