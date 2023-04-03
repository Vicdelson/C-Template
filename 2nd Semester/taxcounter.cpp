#include <iostream>
using namespace std;

int main()
{
    double sales = 95000.00;
    double stateTax = sales * 4 / 100;
    double countyTax = sales * 2 / 100;
    cout << sales+stateTax << endl << sales+countyTax;
}