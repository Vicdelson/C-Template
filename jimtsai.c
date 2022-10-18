#include <stdio.h>

int main(void)
{
	char a[1000];	
	int l=0;
	float score=0.0,credit=0.0;
	do{
		scanf("%c",&a[l]);
		l++;
	}
	while(a[l-1]!='\n');
	for(int i=0;i<l;i++){
		if(a[i]=='\n')break;

		int x = a[i]-'0';

		float y=0.0;

		i++;
		if(a[i]=='A'){
			y=4.0;
		}else if(a[i]=='B'){
			y=3.0;
		}else if(a[i]=='C'){
			y=2.0;
		}else{
			y=0.0;
		}
		if(a[i+1]=='+'){
			y+=0.3;
			i++;
		}else if(a[i+1]=='-')
		{
			y-=0.3;
			i++;
		}
		score+=x*y;
		credit+=x;
	}
	printf("%.2f",score/credit);
	return 0;
}