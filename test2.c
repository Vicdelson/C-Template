#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 15

void convert (char *last, char *first);

int main()
{
    char last_name[MAX_LEN + 2];
    char first_name[MAX_LEN + 2];
    
    // Enter last name
    fgets(last_name, MAX_LEN*2 , stdin);
    if(last_name[strlen(last_name) - 1] == '\n')
        last_name[strlen(last_name) - 1] = '\0';
    
    // Enter first name
    fgets(first_name, MAX_LEN*2, stdin);
    if(first_name[strlen(first_name) - 1] == '\n')
        first_name[strlen(first_name) - 1] = '\0';
    
    // Convert and print the name by using the function convert
    convert(last_name, first_name);
    
    return 0;
}
#define MAX_NAME_LEN 15

void convert(char *last, char *first) 
{
    char ch;
    // for replacing space to dash
    ch = '-';  
    //  check the lenght of first name and last name not greater than 15 characters
    if (strlen(last) > MAX_NAME_LEN || strlen(first) > MAX_NAME_LEN)
    {
        printf("illegal\n");
        return;
    }
    // Convert last name to uppercase
    for (int i = 0; i < strlen(last); i++)  
    {
        last[i] = toupper(last[i]);
    }
    // conver the first name to uppercase
    for (int i = 0; i < strlen(first); i++) 
    {
       
        first[i] = toupper(first[i]);
    }
    // Replacing the space by dash
    for(int i = 0; i < strlen(first); i++)
    {  
        if(first[i] == ' ')  
            first[i] = ch;  
    }  
    // PRINTING THE RESULT
printf("%s, %s",last,first);
}