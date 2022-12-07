#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ARRAY 1000

int i = 0, monstersBlood = 0,indicator = 0,round = 0, end = 0, dist = 0;
char temp; 
char input[MAX_ARRAY] = {0};
bool def;

int main()
{
    

    scanf("%d %d", &dist, &monstersBlood);
    temp = getchar();
    temp = getchar();
    //printf("%s", temp);
    while (1)
    {
        if (temp == '.' || temp == ',')
        {
            indicator += 1;
            input[i] = '\0';
            i = 0;
            
            if (strcmp(input, "PATA PATA PATA PON") == 0)
            {
                dist -= 1;
                round += 1;
            }
            else if (strcmp(input, "PON PON PATA PON") == 0)
            {
                if (dist <= 3)
                {
                    monstersBlood -= 1;
                }
                round += 1;
            }
            else if (strcmp(input, "CHAKA CHAKA PATA PON") == 0)
            {
                dist += 1;
                def = true;
                round += 1;
            }
            else
            {
                def = 0;
            }

            if (indicator % 10 == 0)
            {
                end += 1;
            }
            if (dist == 0)
            {
                printf("NO %d\n", monstersBlood);
                exit(0);
            }
            if (monstersBlood == 0)
            {
                printf("YES %d\n", round);
                exit(0);
            }
            if (indicator % 10 == 0 && def == 0)
            {
                printf("NO %d\n", monstersBlood);
                exit(0);
            }
            if (end == 3)
            {
                printf("NO %d\n", monstersBlood);
                exit(0);
            }
            if (temp == '\n')
                break;
        }
        else if(temp == '\n')
        {
            indicator += 1;
            input[i] = '\0';
            i = 0;
            
            if (strcmp(input, "PATA PATA PATA PON") == 0)
            {
                dist -= 1;
                round += 1;
            }
            else if (strcmp(input, "PON PON PATA PON") == 0)
            {
                if (dist <= 3)
                {
                    monstersBlood -= 1;
                }
                round += 1;
            }
            else if (strcmp(input, "CHAKA CHAKA PATA PON") == 0)
            {
                dist += 1;
                def = true;
                round += 1;
            }
            else
            {
                def = 0;
            }
            if (indicator % 10 == 0)
            {
                end += 1;
            }
            if (dist == 0)
            {
                printf("NO %d\n", monstersBlood);
                exit(0);
            }
            if (monstersBlood == 0)
            {
                printf("YES %d\n", round);
                exit(0);
            }
            if (indicator % 10 == 0 && def == 0)
            {
                printf("NO %d\n", monstersBlood);
                exit(0);
            }
            if (end == 3)
            {
                printf("NO %d\n", monstersBlood);
                exit(0);
            }
            // printf("%d %d %d %d %d\n", distance, hp, round, count, endround);
            if (temp == '\n')
                break;
        }
        else
        {
            input[i] = temp;
            i++;
        }
        temp = getchar();
    }
}