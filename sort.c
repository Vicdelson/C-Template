#include <stdio.h>

#define ARR_MAX 1000

void sort_section(int *ptr, int *qtr);

// Driver program to test above functions
int main() 
{
    int N, a, b;
    scanf("%d%d%d", &N, &a, &b);

    int arr[ARR_MAX] = {0};
    
    for (int i = 0; i < N; i++) 
    {
      scanf("%d", arr + i);
    }

    sort_section(&arr[a], &arr[b]);

    for (int i = 0; i < N; i++)   
    {
      printf("%d ", *(arr + i));
    }
}

int arr[ARR_MAX] = {0}, N = 0, i = 0, j = 0, k = 0, l= 0,
m=0,n=0,sort, dist;

// A function to implement bubble sort
/*void sort_section(int* ptr, int* qtr)
{
    int temp = *ptr;
    *ptr = *qtr;
    *qtr = temp;
    bubbleSort(int *ptr, int *qtr)
}
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
 
/* Function to print an array */
/*void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}*/

void sort_section(int *ptr, int *qtr) 
{
    /*for(N = 0;N < ARR_MAX; N++)
    {     
      if(ptr[N] == *qtr)
      {
          arr[N] = *(ptr + N);
          N++;
          break;
      }
      arr[N] = *(ptr + N);
    }

    for(i = 0; i < N - 1; i++)
    {
        for(j = 0; j < N - 1 - i; j++)
        {
            if(ptr[j] > ptr[j + 1])
            {
                l = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = l;   
            }
        }
        for(k = 0; k < N; k++)
        {
          printf("%d ", ptr[k]);
        } 
        printf("\n");      
    }*/
    dist = qtr - ptr;
    if(dist < 0)
    {
        length = abs(dist);

        for(i = 0;i < dist;i++)
        {
            for(j = 0;j < dist - i;j++)
            {
                if(qtr[j] > qtr[j+1])
                {
                    sort = qtr[j];
                    qtr[j] = qtr[j+1];
                    qtr[j+1] = swap;
                }  
            }
            for(k = 0;k < dist + 1;k++)
            {
                printf("%d ", qtr[k]);
            }
            printf("\n");
        }
    } 
    else
    {
        for(l = 0;l < dist; l++)
        {
            for(m = 0;m < dist - i;m++)
            {
                if(ptr[m] > ptr[m+1])
                {
                    sort = ptr[m];
                    ptr[m] = ptr[m+1];
                    ptr[m+1] = swap;
                }
            }
        for(n = 0;n < dist + 1;n++)
        {
            printf("%d ", ptr[n]);
        }
       printf("\n");
        }
    }
}