#include <stdio.h>

int main(void)
{
    int n, time[30], departure_hour[30], departure_min[30], i, default_hour, default_min, x[30], minn_hour = 100, minn_min = 100, result = 0;
    scanf("%d :%d", &default_hour, &default_min);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d :%d %d", &x[i], &departure_hour[i], &departure_min[i], &time[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (departure_hour[i] > default_hour || (departure_hour[i] == default_hour && departure_min[i] >= default_min))
        {
            departure_hour[i] += time[i] / 60;
            departure_min[i] += time[i] % 60;
            if (departure_min[i] >= 60)
            {
                departure_hour[i] += departure_min[i] / 60;
                departure_min[i] = departure_min[i] % 60;
            }

            if (departure_hour[i] <= minn_hour)
            {
                if (departure_hour[i] == minn_hour && departure_min[i] <= minn_min)
                {
                    minn_hour = departure_hour[i];
                    minn_min = departure_min[i];
                    result = i;
                    // printf("%d %d %d\n", minn_hour, minn_min, i);
                }
                else if (departure_hour[i] < minn_hour)
                {
                    minn_hour = departure_hour[i];
                    minn_min = departure_min[i];
                    result = i;
                }
            }
        }
    }
    // printf("%d %d\n", minn_hour, minn_min);
    printf("%d", x[result]);
    return 0;
}