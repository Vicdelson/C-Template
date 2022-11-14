#include <stdio.h>

int main(void)
{
  long k;
  unsigned char ch, temp, ad;
  scanf("%ld", &k);
  temp = getchar(); 
  ad = getchar();
  temp = getchar();
  ch = getchar();
  //k %= 26;
  while (ch != '\n')
  {
    if (ch <= 'z' && ch >= 'a')
    {
      ch += k;
      ch = ch - (ch > 'z' ? 26 : 0);
      ch = ch + (ch < 'a' ? 26 : 0);
      if (ad == 'a')
      {
        k++;
      }
      else if (ad = 'd')
      {
        k--;
      }
    }
    else if (ch <= 'Z' && ch >= 'A')
    {
      ch += k;
      ch = ch - (ch > 'Z' ? 26 : 0);
      ch = ch + (ch < 'A' ? 26 : 0);
      if (ad == 'a')
      {
        k++;
      }
      else if (ad == 'd')
      {
        k--;
      }
    }
    putchar(ch);
    ch = getchar();
    k %= 26;
  }
  return 0;
}