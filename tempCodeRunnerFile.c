#include <stdio.h>
int student_score[100001];


void ScoreAnalysis(int min, int max, int student_amount){
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < student_amount; i++){
        if(student_score[i] < min){
            a++;
        } else if(student_score[i] >= min && student_score[i] < max){
            b++;
        } else if(student_score[i] >= max){
            c++;
        }
    }
    printf("%d %d %d\n", a, b, c);

}

void scanScore(int studentAmount){
    for(int i = 0; i < studentAmount; i++){
        scanf("%d", &student_score[i]);
    }
}



int main(){
    int student_amount, interval_amount, min, max;
    scanf("%d", &student_amount);
    scanScore(student_amount);
    scanf("%d", &interval_amount);
    for(int i = 1; i <= interval_amount; i++){
        scanf("%d %d", &min, &max);
        ScoreAnalysis(min, max, student_amount);
    }
}