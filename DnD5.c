#include <stdio.h>
#define N 6

int main()
{
    int discs[N]={0};
    int rows,columns1,columns2;
    for(rows = 0; rows < 75; rows++)
    {
        scanf("%d %d", &columns1, &columns2);
        if(columns1>=1&&columns1<=6&&columns2>=1&&columns2<=8)
        {
            if(columns2 % 2 == 0)
            {
                if(discs[columns1-1] == 0)
                {
                    discs[columns1-1]=9;
                }
                else
                {
                    discs[columns1-1] -= 1;
                }
            }
            else
            {
                if(discs[columns1-1]==9)
                {
                    discs[columns1-1]=0;
                }
                else
                {
                    discs[columns1-1] += 1;
                }
            }
        }
    }
    printf("%d %d %d %d %d %d", discs[0],discs[1],discs[2],discs[3],discs[4],discs[5]);
}