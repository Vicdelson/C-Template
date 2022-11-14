#include <stdio.h>
int main() {
   int a, num, diff, tn, i;
   int sum = 0;
   printf(" enter 1st no of series: ");
   scanf("%d", &a);
   printf(" enter total no's in series: ");
   scanf("%d", &num);
   printf("enter Common Difference: ");
   scanf("%d", &diff);
   sum = (num * (2 * a + (num - 1) * diff)) / 2;
   tn = a + (num - 1) * diff;
   printf("
 sum of A.P series is : ");
   for(i = a; i <= tn; i = i + diff){
      if(i != tn)
         printf("%d + ", i);
      else
         printf("%d = %d", i, sum);
   }
   printf("
");
   return 0;
}
int sum(int a_i) {
    if(a_i < a_n)
    {
        return(a_i + sum(a_i + d));
    } 
    else if (a_i == a_n){
        return a_i;
    } 
}