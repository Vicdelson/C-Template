#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void)
{
    int n, i, length[30], j, temp, result, length_min;
    bool same = true, change;
    unsigned char ch;
    unsigned char name[30][16], shortest[16];

    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &length[i]);
        ch = getchar();
        for (j = 0; j < length[i]; j++)
        {
            ch = getchar();
            name[i][j] = tolower(ch);
        }
    }
    temp = 1;
    for (i = 0; i < length[0]; i++)
    {
        shortest[i] = name[0][i];
    }
    length_min = length[0];
    temp = length_min;
    result = 1;

    for (i = 1; i <= n; i++)
    {
        same = false;
        if (length_min >= length[i])
        {
            temp = length[i];
        }
        for (j = 0; j < length_min; j++)
        {
            if (name[i][j] < shortest[j])
            {
                result++;
                // printf("%d %d %d\n", i, j, result);
                break;
            }
            else if (name[i][j] > shortest[j])
            {
                break;
            }
            if (name[i][j] == shortest[j])
            {
                same = true;
            }
            else
            {
                same = false;
            }
            // printf("%c", name[i][j]);
        }
        // printf("\n");
        if (same)
        {
            if (temp > length[i])
            {
                result++;
                // printf("%d\n", result);
            }
        }
        // printf("\n");
    }
    printf("%d", result);

    return 0;
}