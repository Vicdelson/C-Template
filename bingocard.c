#include <stdio.h>
#include <stdlib.h>

#define BINGO 0
#define LINES 0

int main()
{
    int array[8][8];
    int num[64];
    int Bingo = BINGO;
    int Lines = LINES;
    
    int columns,rows,select;

    for(rows = 0;rows < 8; rows++)
    {
        for(columns = 0;columns < 8; columns++)
        {
            scanf("%d",&array[rows][columns]);
        }
    }
    for(rows = 0; rows < 64; rows++)
    {
        scanf("%d", &num[rows]);
    }
    for(rows = 0; rows < 8; rows++)
    {
        for(columns = 0;columns < 8; columns++)
        {
            for(select = 0; select < 64; select++)
            {
                if(array[rows][columns] == num[select])
                {
                    array[rows][columns] = NULL;
                    break;
                }
            }
        }
    }
    for(rows = 0;rows < 8; rows++)
    {
        for(columns = 0;columns < 8; columns++)
        {
            if(array[rows][columns] == NULL)
            {
                Bingo++;
            }
        }
        if(Bingo == 8)
        {
            Lines++;
        }
        Bingo = 0;
    }
    Bingo = 0;
    for(rows = 0;rows < 8; rows++)
    {
        for(columns = 0;columns < 8; columns++ )
        {
            if(array[columns][rows] == NULL)
            {
                Bingo++;
            }
        }
        if(Bingo == 8)
        {
            Lines++;
            Bingo = 0;
        }
        else
        {
            Bingo = 0;
        }
    }
    Bingo = 0;
    for(rows = 0; rows < 8;)
    {
        for(columns = 0; columns < 8; columns++)
        {
            if(array[rows][columns] == NULL)
            {
                Bingo++;
                array[rows][columns] = 1;
            }
            rows++;
        }
        if(Bingo == 8)
        {
            Lines++;
        }
        Bingo = 0;
    }
    for(rows = 0; rows < 8;)
    {
        for(columns = 7; columns >= 0; columns--)
        {
            if (array[rows][columns] == NULL)
            {
                Bingo++;
            }
            rows++;
        }
        if(Bingo == 8)
        {
            Lines++;
        }
        Bingo = 0;
    }
    printf("%d", Lines);
}