#include <stdio.h>
void hanoi_tower(int n,char a,char b,char c)
{
if(n == 1){
printf("[Disk %d] %c -> %c\n", n, a, c);
}
else{
hanoi_tower(n-1,a,c,b);
printf("[Disk %d] %c -> %c\n", n, a, c);
hanoi_tower(n-1,b,a,c);
}
}
int main()
{
int n;
printf("Input number of disks: ");
scanf("%d",&n);
hanoi_tower(n,'A','B','C');
return 0;
}