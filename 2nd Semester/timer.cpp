#include <iostream>
using namespace std;

class Timer {
public:
void hello()
{
cout << "Hello C++ !!!" << endl;
}};
/*The Timer class definition (lines 4–10) begins with keyword 
class and contains a member function called hello (lines 6–9) 
that displays a message on the screen (line 8).*/
int main()
{ // create object tmr|
// call member function hello()
Timer tmr;
tmr.hello();
return 0;
}
/*Need to make an object of class Timer (line 17) and call its
hello member function (line 18) to get line 8 to execute and
display the welcome message.*/