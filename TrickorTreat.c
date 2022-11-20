#include<stdio.h>
#include<stdlib.h>
int array[1500];

int maxChandy( int size) ;
int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy( size));
    return 0;
}

int maxChandy( int size) 
{
    int a = 0;
    int b = 0;
    
    for (int i=0; i<size; i++)
    {
        if (i%2==0)
        {
            a =  ((a+array[i])>(b)?(a+array[i]):(b));
           
            
        }
        else
        {
            b = ((a)>(b+array[i])?(a):(b+array[i]));
            
        }
    }
    
    return ((a)>(b)?(a):(b));
}