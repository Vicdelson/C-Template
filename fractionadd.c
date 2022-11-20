#include <stdio.h>

void fraction_adder(int a_numerator, int a_denominator, int b_numerator,int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr);

int numerator = 0, denominator = 0; 

int main() 
{
  int a_numerator, a_denominator, b_numerator, b_denominator;
  scanf("%d%d%d%d", &a_numerator, &a_denominator, &b_numerator, &b_denominator);
  int c_numerator, c_denominator;
  fraction_adder(a_numerator, a_denominator, b_numerator, b_denominator, &c_numerator,&c_denominator);
  printf("%d/%d\n", c_numerator, c_denominator);
}
void fraction_adder(int a_numerator, int a_denominator, int b_numerator, int b_denominator, int *c_numerator_ptr, int *c_denominator_ptr)
{
    numerator = (a_numerator*b_denominator)+(b_numerator*a_denominator);
    denominator = a_denominator*b_denominator;
    
    int simplify;

    for(int i=1;i <= numerator && i <= denominator; ++i)
    {
        if(numerator%i==0&&denominator%i==0)
        {
            simplify = i;
        }
    }
    numerator/=simplify;
    denominator/=simplify;

    *c_numerator_ptr = numerator;
    *c_denominator_ptr = denominator;
    return;
}