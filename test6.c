#include <stdio.h>
#include <string.h>
char *gettoken(char *str, const char *sep) 
{
    static char *temp; // needs to be static
    if (str != NULL) 
    {
        temp = str;
    }
    if (temp == NULL) 
    {
        return NULL;
    }
    // find the first occurrence of the separator
    char *token = temp;
    int found = 0;
    while (*temp) 
    {
        if (strchr(sep, *temp) != NULL) 
        {
            found = 1;
            *temp = '\0';
            temp++;
            break;
        }
        temp++;
    }
    if (!found) 
    {
        temp = NULL;
    }
    return token;
}