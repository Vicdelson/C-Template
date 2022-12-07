#include<stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}
void recovery(char *homework){
    char *result;
    char *token;
    char *temp;
   bool flag = false;
   /* get the first token */
   token = strtok(temp, " ");
    while( token != NULL ) 
    {
      if((!(*token>='a' && *token<='z') || !(*token>='A' && *token<='Z')) && flag==false )
      {
        flag = true;  
      }
      else
      {
        for(char *c = token;*token!='\0';token++)
        {
            result+=*c;
        }
      }
      result+=' ';
      token = strtok(NULL, " ");
   }
   homework = result;
}