#include <string.h>

/*char *gettoken(char *str, const char *sep) 
{
    static char *p;
    char *token;
    if (str != NULL) 
    {
        p = str;
    }
    if (p == NULL) 
    {
        return NULL;
    }
    token = p;
    p = strpbrk(p, sep);
    if (p != NULL) 
    {
        *p = '\0';
        p++;
    }
return token;
}*/
/*
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
}*/
char *gettoken(char *str, const char *sep) 
{
    static char *next = NULL; // next position to continue from
    if (str != NULL) 
    {
        next = str;
    }
    if (next == NULL || *next == '\0') 
    {
        return NULL;
    }
    char *current = next;
    // Find the end of the current token
    next = strpbrk(current, sep);
    if (next != NULL) 
    {
    // Terminate the current token and move the pointer to the next one
    *next = '\0';
    next += 1;
    }
    return current;
}
