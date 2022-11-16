#include <stdio.h>
#include <stdlib.h>

#define ARRAY 30

int recipe[ARRAY],times,craft[ARRAY][ARRAY],items=0;

int totalItem();

int main()
{
    scanf("%d", &times);
    
    for(int i=1;i<=times;i++)
    {
        scanf("%d", &recipe[i]);
        if(recipe[i]!= 0)
        {
            for(int j=0;j<recipe[i];j++)
            {
                scanf("%d ", &craft[i][j]);
            }
        }
        else
        {
            craft[i][0] = i;
        }
    }
    for(int i=1;i<=times;i++)
    {
        totalItem(i);
    }
    printf("%d",items);
}

int totalItem(int crafting)
{
    if(craft[crafting][0] == crafting)
    {
        items++;
    }
    else
    {
        for(int j = 0; craft[crafting][j]!=0;j++)
        {
            totalItem(craft[crafting][j]);
        }
    }
}