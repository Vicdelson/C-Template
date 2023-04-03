#include <iostream>
using namespace std;

int main() {
    unsigned int data = 0x00000000;
    char c1, c2, c3, c4;
    cout << "Please input 4 characters: " << endl;
    cin >> c1 >> c2 >> c3 >> c4;

    data |= (unsigned char) c1;   // Set the first 8 bits of data to the ASCII code of c1
    data <<= 8;                   // Shift data left by 8 bits
    data |= (unsigned char) c2;   // Set the next 8 bits of data to the ASCII code of c2
    data <<= 8;                   // Shift data left by 8 bits
    data |= (unsigned char) c3;   // Set the next 8 bits of data to the ASCII code of c3
    data <<= 8;                   // Shift data left by 8 bits
    data |= (unsigned char) c4;   // Set the last 8 bits of data to the ASCII code of c4

    cout << "The encrypted result is (decimal): " << data << endl;
    cout << "The encrypted result is (hex): 0x" << hex << data << endl;

    return 0;
}
