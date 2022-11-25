#include<stdio.h>
int N; 
//solve function calling
void solve(int *A, int *B, int *op_cnt);

int main(){
    int A[1<<17] = {0};
    int B[1<<17] = {0};
    int op_cnt = 0;

    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i<N; i++)
        scanf("%d", &B[i]);

    solve(A, B, &op_cnt);
    printf("%d\n", op_cnt);
    for(int i = 0; i<N; i++)
        printf("%d ", A[i]);
}

void solve(int *A, int *B, int *op_cnt)
{
    for(int i=0;i<N;i++)
    {
        /* swapping the numbers if second array element 
        is bigger than the first array element */
        
        if(B[i]>A[i])
        {
            int temp=B[i];
            B[i]=A[i];
            A[i]=temp;
            
            /*counts number of array elements, if second array 
              elements bigger than first array elements */
            *op_cnt=*op_cnt+1;
        }
    }
    //printf("\n");
    /*printf("%d\n", *op_cnt);
    // printing the array
    
    for(int i = 0; i<N; i++)
    printf("%d ", A[i]);*/
}