#include<stdio.h>
#define MAX 100
#include<stdbool.h>

int main(void)
{
    char name[100]={0};
    int number;
	bool value=true;
	scanf("%d\n",&number);
	scanf("%[^\n]s",name);
    for(int n=0;n<=number;n++)
	{		
		for(int i=0; name[i]!='\0'; i++)
		{
		if(value == true)
		{
			if(name[i] >= 'a' && name[i] <= 'z'){
                name[i] -= 32;
                value = false;
            } else if(name[i] >='A' && name[i] <='Z'){
                value = false;
            }
			continue;
		} else if (value == false){
			if(name[i] >= 'A' && name[i] <= 'Z'){
                name[i] += 32;
            }
		}
		
		if(name[i]==' ')
		{
			value = true;
			continue;
		}
        
		if(name[i] == ';' ||name[i] == '.' ||name[i] == ',')
		{
			name[i]='\n';
			n++;
            value = true;
            continue;
        }    
	}
	}
    printf("%s\n",name);
	return 0;
}