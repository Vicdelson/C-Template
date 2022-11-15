#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARRAY 1024

int N;
int sign[ARRAY];
char rps[ARRAY];
char bs[ARRAY];

void judge(int mark, int x, int y, int z)
{
    if(bs[mark] == 'b')
    {
        if(x > y)
        {
            sign[z] = x;
        }
        else if(x < y)
        {
            sign[z] = y;
        }
    }
    else if(bs[mark] == 's')
    {
        if(x < y)
        {
            sign[z]=x;
        }
        else if(x > y)
        {
            sign[z]=y;
        }
    }
}
int compete(int mark)
{
    int win = 0;
    for(int i= 0;i < N;)
    {
        //rock < paper < scissor < rock
        /*
        r p s
        p s r 
        s r p
        */
        if(rps[i]=='r'&& rps[i+1]== 'p')
        {
            sign[win] = i+1;
            win++;
            i += 2;
        }
        else if(rps[i]=='p'&& rps[i+1]=='s')
        {
            sign[win] = i+1;
            win++;
            i += 2;
        }
        else if(rps[i]=='s'&& rps[i+1]=='r')
        {
            sign[win] = i+1;
            win++;
            i += 2;
        }
        else if(rps[i]=='r'&& rps[i+1]== 's')
        {
            sign[win] = i;
            win++;
            i += 2;
        }
        else if(rps[i]=='p'&& rps[i+1]=='r')
        {
            sign[win] = i;
            win++;
            i += 2;
        }
        else if(rps[i]=='s'&& rps[i+1]=='p')
        {
            sign[win] = i;
            win++;
            i += 2;
        }
        /*=================================*/
        else
        {
            if(bs[mark] == 'b')
            {
                sign[win] = i+1;
                win++;
                i += 2;
            }
            else if(bs[mark] == 's')
            {
                sign[win] = i;
                win++;
                i += 2;
            }
        }
    }
    return ++mark;
}



void innings(int mark, int stage,int arbitrary)
{
    if(stage < log2(N))
    {
        //rock < paper < scissor < rock
        /*
        r p s
        p s r 
        s r p
        */
        int win = 0;
        int newvar= N / arbitrary;
        for(int i= 0; i<newvar;i+=2)
        {
            if(rps[sign[i]]=='r'&& rps[sign[i+1]]== 'p')
            {
                sign[win++] = sign[i+1];
            }
            else if(rps[sign[i]]=='p'&& rps[sign[i+1]]=='s')
            {
                sign[win++] = sign[i+1];
            }
            else if(rps[sign[i]]=='s'&& rps[sign[i+1]]=='r')
            {
                sign[win++] = sign[i+1];
            }
            else if(rps[sign[i]]=='r'&& rps[sign[i+1]]== 's')
            {
                sign[win++] = sign[i+1];
            }
            else if(rps[sign[i]]=='p'&& rps[sign[i+1]]=='r')
            {
                sign[win++] = sign[i+1];
            }
            else if(rps[sign[i]]=='s'&& rps[sign[i+1]]=='p')
            {
                sign[win++] = sign[i+1];
            }
        /*=================================*/
            else if(rps[sign[i]]=='r'&& rps[sign[i+1]]== 'r')
            {
                judge(mark,sign[i],sign[i+1],win);
                win++;
            }
            else if(rps[sign[i]]=='p'&& rps[sign[i+1]]=='p')
            {
                judge(mark,sign[i],sign[i+1],win);
                win++;
            }
            else if(rps[sign[i]]=='s'&& rps[sign[i+1]]=='s')
            {
                judge(mark,sign[i],sign[i+1],win);
                win++;
            }
        }
        innings(++mark,++stage, arbitrary);
    }
}
int main()
{
    scanf("%d", &N);
    int var,arbitrary = 1, mark = 0;
    for(int i = 0; i < N;i++)
    {
        scanf("%c", &rps[i]);
    }
    scanf(" ");
    for(int i = 0;i < log2(N); i++)
    {
        scanf("%c", &bs[i]);
    }
    if(N==1)
    {
        printf("1");
        return 0;
    }

    mark = compete(mark);
    innings(mark,1,2);

    printf("%d", sign[0]+1);
    //prs
}
