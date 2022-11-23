long long int c = 1, temp1 = 0, temp2 = 1, temp3, temp4;
void fib_fast_doubling(unsigned k, uint64_t *f2k, uint64_t *f2k1)
{
 if(c == 1){
        k = k * 2;
        c = -1;
    }

    if(k == 0)
    {
        *f2k = 0;
        *f2k1 = 1;
        return;
    }
    
    
    fib_fast_doubling(k/2, f2k, f2k1);
    temp3 = 2 * *f2k1 - *f2k; //[2 * f(k+1) - fk]
    // printf("temp3: %d\n", temp3);
    
    temp3 = (*f2k * temp3);   //F(2k) = f(k) * [2 * f(k+1) - fk]
    temp4 = ((*f2k) * (*f2k) + (*f2k1) * (*f2k1)); //F(2k + 1)
    
    if(k%2 == 0){
        *f2k = temp3;
        *f2k1 = temp4;
    } else if(k%2 == 1){
        *f2k = temp4;
        *f2k1 = temp3 + temp4;
    }
    
    // printf("temp3: %d\n", temp3);
    // printf("temp4: %d\n", temp4);  
}