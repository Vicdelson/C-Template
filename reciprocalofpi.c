#include <stdio.h>

//if you want to define a float
//make sure to add a decimal , or it will 
//became an int 
#define RECIPROCAL_OF_PI (1.0f/3.14159f)

int main()
{
    float pi = RECIPROCAL_OF_PI;
    printf("pi is : %f", pi);
    
    return 0;
}