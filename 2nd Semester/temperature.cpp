#include <iostream>
using namespace std;

int main()
{
    double fahrenheit, celcius;
    cout << "Enter Fahrenheit temperature :";
    cin >> fahrenheit;
    celcius = (fahrenheit - 32.0) * (5.0/9.0);
    cout << "Celsius equivalnt :" << celcius;
}