#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64_t;

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
   if (k == 0)
   {
       *f2k = 1;
       *f2k1 = 1;
       return;
   }
   uint64_t fk, fk1;
   fib_fast_doubling(k / 2, &fk, &fk1);
   *f2k1 = fk * fk + fk1 * fk1;
   *f2k = fk * (fk1 * 2 - fk);
   if (k & 1)
   {
       uint64_t tmp = *f2k1;
       *f2k1 = *f2k + *f2k1;
       *f2k = tmp;
   }
}
int main()
{
   unsigned k;
   scanf("%u", &k);
   uint64_t f2k, f2k1;
   fib_fast_doubling(k / 2, &f2k, &f2k1);
   printf("%llu", (k & 0x1) ? f2k1 : f2k);
   return 0;
}