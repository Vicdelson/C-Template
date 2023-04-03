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