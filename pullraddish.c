#include <stdio.h>
#include <stdlib.h>

int pull_radish(int *l, int *r, int *pos, int x);

int main()
{
    int N, y, x;
    scanf("%d %d %d", &N, &y, &x);
    int *farm = malloc(N * sizeof(int));

    // initialize farm[N]
    for (int i = 0; i < N; i++)
    {
        farm[i] = 1;
    }

    int total = pull_radish(&farm[0], &farm[N - 1], &farm[y], x);
    printf("%d\n", total);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", farm[i]);
    }

    return 0;
}

// l represents the first radish to the left 左邊第一個
// r represents the first radish to the right 右邊第一個
// pos represents Ariel's position
// x represents the interval
int pull_radish(int *l, int *r, int *pos, int x)
{
    int left = 0, right = 0, total = 0;
    while ((pos - left) >= l || (pos + right) <= r)
    {
        left += x;
        right += x;
        if ((pos - left) >= l && *(pos - left) == 1)
        {
            *(pos - left) = 0;
            total++;
        }
        if ((pos + right) <= r && *(pos + right) == 1)
        {
            *(pos + right) = 0;
            total++;
        }
    }
    return total;
}