#include<stdio.h>

int main(void)
{
    int sequence,value,prefixsum = 0;
    scanf("%d",&sequence);
    for(int i = 0;i<sequence;i++)
    {
        scanf("%d",&value);
        prefixsum += value;
        if(prefixsum%value==0)
        {
            printf("%d %d",prefixsum, value);
            printf("\n");
        }
    }
}