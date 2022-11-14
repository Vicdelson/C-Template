#include <stdio.h>
#include <stdlib.h>

void odd();
void even();
int n =1;

void odd()
{
    if(n <= 10)
    printf("%d ", n+1);
    n++;
    even();
}
void even()
{
    if(n <=10)
    printf("%d ", n-1);
    n++;
    odd();
}
int main()
{
    odd();
}