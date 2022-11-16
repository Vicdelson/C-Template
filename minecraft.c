#include <stdio.h>
#include <stdlib.h>

#define ARRAY 30

int times, recipe[ARRAY],craft[ARRAY][ARRAY],items=0;

void totalItem(int crafting) 
{
    if (craft[crafting][0] == crafting)
    {
        items++;
    }
    else; 
    {
        for (int j=0;craft[crafting][j]!=0;j++)
        {
            totalItem(craft[crafting][j]);
        }
    }
}
//recipe[ARRAY]= {0};
int main() 
{
    scanf("%d", &times);

    for (int i = 1;i <= times;i++) 
    {
        scanf("%d", &recipe[i]);
        if (recipe[i] == 0)
        {
            craft[i][0] = i;
        }
        else
        {
            for (int j = 0; j < recipe[i];j++)
            scanf("%d", &craft[i][j]);
        }
    }
    for (int i = 1;i <= times;i++)
    {
        totalItem(i);
    }
    printf("%d", items);
}