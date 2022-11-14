#include <stdio.h>

int main()
{
    int N;
    int x = 0, y = 0, z = 0;
    scanf("%d", &N);
    int score[N];

    for(int i=0;i<N;i++)
    {
        scanf("%d",&score[i]);
    }

    int intervals;
    scanf("%d",&intervals);
    int A[intervals];
    int B[intervals];

    for(int i=0; i < intervals; i++)
    {
        scanf("%d %d", &B[i], &A[i]);
    }

    for(int i=0;i < intervals; i++)
    {
        for(int j=0;j<N;j++)
        {
            if(score[j]<B[i])
            {
                x++;
                //low[i]=x;
            }
            else if(score[j]>=B[i]&&score[j]<A[i])
            {
                y++;
                //mid[i]=y;
            }
            else //if(score[j]>=A[i])
            {
                z++;
                //high[i]=z;
            }
        }
        printf("%d %d %d", x, y, z); //low[i], mid[i], high[i]);
        printf("\n");
        x=0;
        y=0;
        z=0;
    }
}