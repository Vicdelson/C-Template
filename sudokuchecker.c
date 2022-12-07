#include <stdlib.h>
void sort_section(int *ptr, int *qtr) {
    int swap;
    int length = qtr - ptr;
    if(length < 0){
      length = abs(length);
      for(int i = 0; i < length; i++){
        for(int j = 0; j < length - i; j++){
          if(qtr[j] > qtr[j+1]){
            swap = qtr[j];
            qtr[j] = qtr[j+1];
            qtr[j+1] = swap;
          }
        }
        for(int z = 0; z < length + 1; z++){
        printf("%d ", qtr[z]);
      } printf("\n");
      }
    } else{
      for(int i = 0; i < length; i++){
      for(int j = 0; j < length - i; j++){
        if(ptr[j] > ptr[j+1]){
            swap = ptr[j];
            ptr[j] = ptr[j+1];
            ptr[j + 1] = swap;
        }
      }
      for(int z = 0; z < length + 1; z++){
        printf("%d ", ptr[z]);
      } printf("\n");
    }
    }
    

    
    
}