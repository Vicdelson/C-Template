long long int first, second;

long long int trueFalse = 1;//say this as boolean

void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
 if(trueFalse == 1)
    {
        k = k * 2;//because of k/2
        trueFalse = -1;
    }
    if(k == 0)
    {
        *f2k = 0;//*f2k =1
        *f2k1 = 1;
        return;
    }
    
    fib_fast_doubling(k/2, f2k, f2k1);

    first = 2 * *f2k1 - *f2k;//2 * f(k+1) - fk
    first = (*f2k * temp3);   //F(2k) = f(k) * [2 * f(k+1) - fk]
    second = ((*f2k) * (*f2k) + (*f2k1) * (*f2k1)); //F(2k + 1)
    
     /*if (k & 1)
   {
       uint64_t tmp = *f2k1;
       *f2k1 = *f2k + *f2k1;
       *f2k = tmp;
   }*/

    if(k % 2 == 0)
    {
        *f2k = first;
        *f2k1 = second;
    } 
    else if(k % 2 == 1)
    {
        *f2k = second;
        *f2k1 = first + second;
    }
}