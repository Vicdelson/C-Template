#include <stdio.h>

int main() {
    int student_num, interval_num, count_a=0, count_b=0,count_c=0, a,b;
    scanf("%d", &student_num);
    int score[student_num];
    for(int i=0; i<student_num; i++){
        scanf("%d", &score[i]);
    }
    scanf("%d", &interval_num);
    int interval[interval_num][2];
    for(int j=0; j<interval_num; j++){
        for(int k=0; k<2; k++){
            scanf("%d", &interval[j][k]);
        }
    }
    for(int l=0;l<interval_num;l++){
        for(int o=0;o<student_num;o++){
            a=interval[l][0];
            b=interval[l][1];
            if(score[o]<a){
                count_a++;
            }
            if(a<=score[o]&&score[o]<b){
                count_b++;
            }
            if(b<=score[o]){
                count_c++;
            }
        }
        printf("%d %d %d\n", count_a, count_b, count_c);
        count_c=0;
        count_b=0;
        count_a=0;

    }

    return 0;
}