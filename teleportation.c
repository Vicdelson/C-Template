#include <stdio.h>

unsigned long construct(unsigned char parts[16]);

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}
unsigned long construct(unsigned char parts[16]) 
{
  unsigned long long l1 = 0, l2 = 0;

  // Reorder the parts in little-endian order
  for (int i = 0; i < 8; i++) {
    l1 |= (unsigned long long)parts[i] << (8 * i);
    l2 |= (unsigned long long)parts[8 + i] << (8 * i);
  }

  // XOR the two parts to get the final result
  return l1 ^ l2;
}