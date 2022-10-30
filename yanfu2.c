#include <stdio.h>

int main() {
    int d[6]={0},d1,d2;//d[6]={0} means the 6 discs=0 0 0 0 0 0
    for(int i=0; i<75; i++){
        scanf("%d %d", &d1, &d2);
        if(d2%2==0){
            if(d[d1-1]==0){
                d[d1-1]=9;
            }else{d[d1-1]--;};

        }else{
            if(d[d1-1]==9){
                d[d1-1]=0;
            }else{d[d1-1]++;}
            
        }

    }
    for(int j=0; j<6; j++){
        printf("%d ", d[j]);

    }
    return 0;
}