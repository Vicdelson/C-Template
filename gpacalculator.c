#include<stdio.h>
#define MAX 100

int main(void)
{
    char score[100];
    int number= 0;
    float grade = 0.0, credit = 0.0;

    /*int n = 0, number;
    float grade,credit = 0.0, total= 0.0;*/

    do
    {
		scanf("%c",&score[number]);
		number++;
	}
	while(score[number-1] != '\n');
	for(int i = 0;i < number;i++)
    {
		if(score[i] == '\n') break;
		int total = score[i] -'0';
        float point = 0.0;
		i++;
        
        switch(score[i])
        {
            case 'A':
                point = 4.0;
                break;
            case 'B':
                point = 3.0;
                break;
            case 'C':
                point = 2.0;
                break;
            case 'F':
                point = 0.0;
                break;
        }
        switch(score[i+1])
        {
            case '+':
                point += 0.3;
                i++;
                break;
            case '-':
                point -= 0.3;
                i++;
                break;
        }
		grade += point*total;
		credit += total;
	}
	printf("%.2f",grade/credit);
	return 0;
}
    /*while(score != '\n')
    {
        scanf("%c",&score);
        if(score >= '1' && score <= '9')
        {
            number = score - '0';
            goToGrade = true;
        }

        if(goToGrade == true){
            switch(score){
            case 'A':
                grade = 4.0;
                foundGrade = true;
                goToGrade = false;
                break;
            case 'B':
                grade = 3.0;
                foundGrade = true;
                goToGrade = false;
                break;
            case 'C':
                grade = 2.0;
                foundGrade = true;
                goToGrade = false;

                break;
            case 'F':
                grade = 0.0;
                foundGrade = true;
                goToGrade = false;

                break;
        }
        }

       if(score == '+' && foundGrade == true)
        {
            grade += 0.3;
            total += grade * number;
            credit += number;
            foundGrade = false;
        } else if(score == '-' && foundGrade == true)
        {
            grade -= 0.3;
            total += grade * number;
            credit += number;
            foundGrade = false;
        } else{
            total += grade * number;
            credit += number;
            foundGrade = false;
        }
        
    }*/