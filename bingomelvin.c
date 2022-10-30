#include <stdio.h>

int main(){
    int bingo [8][8];
    int input[64];
    int bingo_number = 0, zero_num = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            scanf("%d", &bingo[i][j]);
        }
    }

    for(int i = 0; i < 64; i++){
        scanf("%d", &input[i]);
    }

    int index = 0;

    //Replace with 0 if found the number
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int x = 0; x < 64; x++){
                if(bingo[i][j] == input[x]){
                    bingo[i][j] = 0;
                    break;
                }
            }
        }
    }



    
    // //Check horizontal 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(bingo[i][j] == 0){
                zero_num++;
            }
        }
        if(zero_num == 8){
            bingo_number++;
        } 
        zero_num = 0;
    }

    //Check vertically
    zero_num = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(bingo[j][i] == 0){
                zero_num++;
            }           
        }
        if(zero_num == 8){
                bingo_number++;
                zero_num = 0;
        } else{
                zero_num = 0;
        }
    }


    // //Check diagonal left to right
    zero_num = 0;
    for(int i = 0; i < 8;){
        for(int j = 0; j < 8; j++){
            if(bingo[i][j] == 0){
                zero_num++;
                bingo[i][j] = 1;
            }
            i++;
        }
        if(zero_num == 8){
            bingo_number++;
        } 
        zero_num = 0;
    }

    // //Check print
    // for(int i = 0 ; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         printf("%d ", bingo[i][j]);
    //     }
    //     printf("\n");
    // }

    // // //Check diagonal right to left
    for(int i = 0; i < 8;){
        for(int j = 7; j >= 0; j--){
            if(bingo[i][j] == 0){
                zero_num++;
            }
            i++;
        }
        if(zero_num == 8){
            bingo_number++;
        } 
        zero_num = 0;
    }

    // //     //Check print
    // for(int i = 0 ; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         printf("%d ", bingo[i][j]);
    //     }
    //     printf("\n");
    // }
           

    printf("%d", bingo_number);
}