#include <stdio.h>
#include <stdlib.h>

int main()
{
   int CheckAdultUtil (int age);
   {
    if (age >= 18)
        return 1;
    else
        return 0;
   }

    void CheckAdult(int)
    {
        if (CheckAdultUtil(age))
            cout << "You are an adult\n";
        else
            cout << "You are not an adult\n";
    }
    int main()
    {
        int age = 25;

        CheckAdult(age);

        return 0
    }
}