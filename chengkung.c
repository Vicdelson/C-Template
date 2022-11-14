#include<stdio.h>

int main()
{
    int array[3][30];
    int two[3][30];
    int k=1;
    int l;
    int things[100],amount[100];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            array[i][j]=10;
            two[i][j]=k;
            k++;
        }
    }  //printf("%d",two[0][4]);
    int cust,earn=0;
    scanf("%d", &cust);
    for(int i = 0;i<cust;i++)
    {
        scanf("%d %d",&things[i],&amount[i]);
    }
    for(int c=0;c<cust;c++)
    {
        for(int i=0;i<3;i++)
        {   
            for(int j=0;j<10;j++)
            {
                if(two[i][j]==things[i])
                {
                    if(array[i][j]!=0)
                    {
                    array[i][j]-=amount[i];
                        if(two[i][j]<10)
                    {
                    earn+=10;
                }
                else if(two[i][j]>10&&two[i][j]<=20)
                {
                    earn+=20;
                }
                else if(two[i][j]>20&&two[i][j]<=30)
                {
                    earn+=30;
                }
                }
                else
                {
                    earn+=0;
                }
            }
        }
        }
    }
 for(int i=0;i<1;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",array[i][j]);
        }
    }
            printf("\n");
    for(int i=1;i<2;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",array[i][j]);
        }
    }
            printf("\n");
    for(int i=2;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d ",array[i][j]);
        }
    }
    printf("\n");
    printf("Earned: $%d", earn);
}
    /*for(int i=0;i<1;i++)
    {
        for(int j=0;j<10;j++)
        {
            array[i][j];
            earn+=10;
        }
    }
    for(int i=1;i<2;i++)
    {
        for(int j=0;j<10;j++)
        {
            earn+=20;
        }
    }
    for(int i=2;i<3;i++)
    {
        for(int j=0;j<10;j++)
        {
            array[i][j]=30;
        }
    }
    }*/
