//Driver program for the function unitPrice
#include <iostream>

using namespace std;

double unitPrice(int diameter, double price);

int main()
{
    double diameter, price;
    char ans;

    do 
    {
        cout << "Enter diameter and price\n";
        cin >> diameter >> price;
        cout << "unit Price is $"
            <<unitPrice(diameter,price) << endl;
        
        cout << "Test again? (y/n)";
        cin >> ans;
        cout << endl;
    } while(ans == 'y' || ans == 'Y');
    return 0;
}

double unitPrice(int diameter, double price)
{
    const double PI = 3.14159;
    double radius, area;

    radius = PI * radius * radius;
    return (price/area);
}