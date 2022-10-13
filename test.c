#include <stdio.h>
#include <stdbool.h>

int main()
{
	
	char str;	
	int numbers,amount=0;
	scanf("%d\n", &numbers);
	
	while(amount != numbers)
	{
		scanf("%c",&str);
		if(str == ';'|| str == ','|| str == '.')
		{
			printf("\n");
			amount++;
			continue;
		}
		for(int i=0; str!='\0'; i++)
		{
		if(i==0)
		{
			if((str>='a' && str<='z'))
				str=str-32;
			continue;
		}
		if(str==' ')
		{
			++i;
			if(str>='a' && str<='z')
			{
				str=str-32;
				continue;
			}
		}
		else
		{
			if(str>='A' && str<='Z')
				str=str+32;
		}
	}
	}
	printf("%s\n",str);
	return 0;
}