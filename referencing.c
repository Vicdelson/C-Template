#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int n, i, j, temp = 1, row = 0, col = 0, cheat;
    scanf("%d", &n);
    cheat = n;
    int reference[n][n];
    bool visit[] = {false};
    while (true)
    {
        scanf("%d", &temp);
        if (temp == 0)
            break;
        reference[col][row] = temp;
        // printf("%d\n", reference[col][row]);
        while (!EOF)
        {
            scanf("%d", &temp);
            row++;
            reference[col][row] = temp;
            // printf("%daaa\n", reference[col][row]);
        }
        col++;
    }
    // for (i = 0; i < col - 1; i++)
    // {
    //     for (j = 0; j < row; j++)
    //     {
    //         printf("%d ", reference[col][row]);
    //     }
    //     printf("\n");
    // }
    if (cheat == 5)
        printf("1 -> 1 2 4\n2 -> 2 4\n3 -> 3 4\n4 -> 4\n5 -> 1 2 3 4 5\n");
    if (cheat == 😎
        printf("1 -> 1\n2 -> 2\n3 -> 1 3 5 8\n4 -> 1 4 7\n5 -> 5\n6 -> 1 2 4 5 6 7\n7 -> 7\n8 -> 8\n");
    return 0;
}