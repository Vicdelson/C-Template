#include<stdio.h>
#include<stdlib.h>

int main()
{
    int alas,tinggi;
    double luas;
    char ch;
    while(ch != 't')
    {
        printf("Masukkan Alas Segitiga : ");
        scanf("%d", &alas);

        printf("Masukkan Tinggi Segitiga : ");
        scanf("%d", &tinggi);

        luas = 0.5*(alas*tinggi);

        printf("Luas Segitiga : %.1f", luas);
        printf("\n");
        printf("Apakah mau mengulang lagi y/t?");
        scanf(" %c", &ch);
    }
}