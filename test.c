#include <stdio.h>

int a_1, a_n, d;
//a_1 first term
//a_n last term
//d common difference

int sum(int a_i);

int main()
{
    scanf("%d %d %d", &a_1, &a_n, &d);
    printf("%d", sum(a_1));
    return 0;
}
//sum = (num * (2 * a + (num - 1) * diff)) / 2;
   //tn = a + (num - 1) * diff;
int sum(int a_i) {
    if (a_i==a_n)
    {
        return a_i;
    }
    else if(a_i < a_n)
    {   
        return a_i+sum(a_i+d);
    }
}