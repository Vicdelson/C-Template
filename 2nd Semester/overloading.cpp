#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Class for amount of money in U.s. currency
class Money
{
    public:
        Money();
        Money(double amount);
        Money(int theDollars, int theCents);
        Money(int theDollars);
        double getAmount()const;
        int getDollars()const;
        int getCents()const;
        friend const Money operator +(const Money& amount1, const Money& amount2);
        friend const Money operator -(const Money& amount1, const Money& amount2);
        friend bool operator ==(const Money& amount1, const Money& amount2);
        friend const Money operator -(const Money& amount);
        friend ostream& operator <<(ostream& outputStream, const Money& amount);
        friend istream& operator >>(istream& inputStream, Money& amount);
    private:
        int dollars;//A negative amount is represented as negative dollars and
        int cents; //negative cents. Negative $4.50 is represented as -4 and -50.
        int dollarsPart(double amount) const;
        int centsPart(double amount) const;
        int round(double number) const;
};

int main()
{
    Money yourAmount, myAmount(10,9);
    cout << "Enter an amount of money: ";
    cin >> yourAmount;
    cout << "Your amount is " << yourAmount << endl;
    cout << "My amount is " << myAmount << endl; 

    if(yourAmount == myAmount)
        cout << "We have the same amounts.\n";
    else
        cout <<"One of us is richer.\n";

    Money ourAmount = yourAmount + myAmount;
    cout << yourAmount << " + " << myAmount
        <<" equals " << ourAmount << endl;

    Money diffAmount = yourAmount - myAmount;
    cout <<yourAmount << " - " << myAmount
        <<" equals " << diffAmount << endl;

    return 0; 
}

ostream& operator <<(ostream& outputStream, const Money& amount)
{
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if(amount.dollars < 0 || amount.cents < 0)
        //accounts for dollars == 0  or cents == 0
        outputStream << "$-";
    else
        outputStream << "$";
    outputStream << absDollars;

    if(absCents >= 10)
        outputStream << '.' << absCents;
    else
        outputStream << ',' << '0' << absCents;
    
    return outputStream;
}

//Uses iostream and cstdlib:
istream& operator >>(istream& inputStream, Money& amount)
{
    char dollarSign;
    inputStream >> dollarSign; //hopefully
    if(dollarSign != '$')
    {
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }

    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);

    amount.cents = amount.centsPart(amountAsDouble);

    return inputStream;
}