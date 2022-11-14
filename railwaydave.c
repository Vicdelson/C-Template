#include <stdio.h>
#define array 1000 

int main()
{
    int current_hour, current_minute, n, x[array], hour[array], minute[array], y[array],
    time_hour = 25, time_minute = 61 ,time = 0; 
    scanf("%d :%d", &current_hour, &current_minute);
    scanf("%d", &n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d %d :%d %d", &x[i],&hour[i],&minute[i],&y[i]);
    }

    for(int i=0;i < n; i++)
    {
        if(hour[i]>=current_hour&&minute[i]>=current_minute)
        {
            hour[i] += y[i]/60;
            minute[i]+=y[i]%60;

            if(hour[i] <= time_hour)
            {
                if(hour[i] == time_hour&&minute[i] <= time_minute)
                {
                    time_hour=hour[i];
                    time_minute=minute[i];
                    time = i;
                }
                else if(hour[i]<time_hour)
                {
                    time_hour = hour[i];
                    time_minute = minute[i];
                    time = i;
                }
            }
        }
    }
    printf("%d", x[time]);
}