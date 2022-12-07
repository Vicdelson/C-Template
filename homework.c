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

#include <stdbool.h>

int sign;
char *result;
char *token;
char *temp;
char word[MAX_LEN + 1];
char remake[MAX_LEN + 1];
unsigned long len;
bool flag;

void recovery(char *homework) 
{
    strcpy(word, homework);
    
    token = strtok(word, " \n");

    while(token != NULL)
    {
        flag = true;
        len = strlen(token);

        //Check if back is punctuated or not
        if((token[length - 1] == '.' || token[length - 1] == ',' || token[length - 1] == '!' || token[length - 1] == '?') && length > 1)
        {
            flag = true;
        } 
        else if(!isalpha(token[length-1]))
        { //If not Check if last is any non-alphabetic char
            flag = false;
        } 
        else if((token[length - 1] == '.' || token[length - 1] == ',' || token[length - 1] == '!' || token[length - 1] == '?') && length == 1)
        {
            flag = false;
        }
        // //Check if word contains alphabets only
        for(int i = 0; i < len - 1; i++)
        {
            if(isalpha(token[i]))
            {
                continue;
            } 
            else
            {
                cat = false;
            }
        }

        //Check length
        if(length < 1 || length > 21){
            cat = false;
        }

        if(cat){
            strcat(final, token);
            strcat(final, " ");
        }

        
        token = strtok(NULL, " \n");
    }
    strcpy(homework, final);
}