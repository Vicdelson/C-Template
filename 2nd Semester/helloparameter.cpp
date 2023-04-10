#include <iostream>
#include <string>

using namespace std;

class Timer {
    public:
    void hello(string name)
    {
        cout << "Hello " << name << "!!!" << endl;
    }};

int main()
{
    Timer tmr;
    string username;
    cout << "Please enter your name: ";
    getline(cin, username);
    tmr.hello(username);
    return 0;
}

/*Difference Between getline() and cin
string str ;

getline(cin, str);
cout << "getline() get " << str
<< "\t length = " << str.length() << endl;

> ./getline_cin
getline() get NCKU is best !
NCKU is best!
length = 13

cin >> str;
cout << " cin get " << str
<< "\t length = " << str.length() << endl;
NCKU is best!
cin get NCKU length = 4*/