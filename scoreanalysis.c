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
    int limit[intervals][2];

    for(int i=0;i<intervals;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d", &limit[i][j]);
        }
    }
    /*for(int i=0; i < intervals; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
    }*/

    for(int i=0;i < intervals;i++)
    {
        for(int j=0;j<N;j++)
        {
            int low= limit[i][0];
            int high=limit[i][1];
            
            if(score[j] < low)
            {
                x++;
                //low[i]=x;
            }
            else if(score[j]>=low&&score[j]<high)
            {
                y++;
                //mid[i]=y;
            }
            else if(score[j]>=high) //if(score[j]>=A[i])
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