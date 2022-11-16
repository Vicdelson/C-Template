#include <stdio.h>
#include <stdlib.h>

#define ARRAY 30

int recipe[ARRAY],times,craft[ARRAY][ARRAY],items=0;

int totalItem();

int main() 
{
    scanf("%d", &times);
    for (int i = 0; i < times; i++) 
    {
        scanf("%d", &recipe[i+1]);
        if (recipe[i+1] != 0)
        {
            for (int j = 0; j < recipe[i+1]; j++)
            {
                scanf("%d", &craft[i+1][j]);
            }
        }
        else
        {
            craft[i][0] = i;
        }
    }
    for (int i = 0; i < times; i++)
    {
        totalItem(i+1);
    }
    printf("%d", items);
    return 0;
}

int totalItem(int crafting) 
{
    if (craft[crafting][0] != crafting)
    {
        for (int j = 0; craft[crafting][j] != 0; j++)
        {
            totalItem(craft[crafting][j]);
        }
    }
    else
    {
        items++;
    }
    return items;
}