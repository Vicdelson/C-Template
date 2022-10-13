#include<stdio.h>
int main(){

    int i, j, n;

    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int count=0, maxCount=0;
    for(i=0;i<n;i++) {
        count = 0;
        for(j=0;j<n;j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
         }
    }

    printf("%d",maxCount);
	
	return 0;
}