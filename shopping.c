#include<stdio.h>
#include<math.h>

int main()
{
    int yen,tax,after_tax,tax_rate,tax3;
    float exchange_rate1=0.2966f;
    float exchange_rate2=0.2178f;
    int ntd1,ntd2,tot;
    scanf("%d", &yen);
    ntd1 = lround(yen * exchange_rate1);
    int tax1= lround(ntd1*(1+0.08));
    ntd2 = lround(yen *exchange_rate2);
    if(yen<=5000)
    {
        tax=lround(ntd2*(1+0.1f));
        tot=tax1-tax;
        printf("%d",tot);
    }
    else
    {
        printf("%d", ntd1-ntd2);
    }
    //int tot=tax1-tax;
    //printf("%d",tot);
}