#include<stdio.h>
#include<stdbool.h>

int main(void)
{
    char name;
    int n = 0;
    int number;
	bool value=true;
    scanf("%d\n",&number);
   while(n != number)
	{		
        scanf("%c",&name);
		if(value == true)
		{
			if(name >= 'a' && name <= 'z'){
                name -= 32;
                value = false;
            } else if(name >='A' && name <='Z'){
                value = false;
            }
			
		} else if (value == false)
        {
			if(name >= 'A' && name <= 'Z'){
                name += 32;
            }
		}
		if(name==' ')
		{
			value = true;
		}
        
		if(name == ';' ||name == '.' ||name == ',')
		{
			printf("\n");
			n++;
            value = true;
            continue;
        } 
          printf("%c",name);  
	    }
	return 0;
}