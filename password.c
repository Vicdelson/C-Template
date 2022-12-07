#include <stdio.h>
#include <string.h>

#define SIZE 25

// function prototypes
int length(char pwd1[], char pwd2[]);

int compare(char pwd1[], char pwd2[]);

int content(char pwd1[]);

// driver code
int main()
{
    // strings of length 25 for storing password
    char password1[SIZE];
    char password2[SIZE];

    // Enter the password
    scanf("%s", password1);
    // Enter the password again
    scanf("%s", password2);

    // Check Password
    // First: Check length
    if (length(password1, password2) == 1)
    {
        printf("Length does not match the requirements");
    }
    else
    {
        // Second: Check for consistency
        if (compare(password1, password2) == 1)
        {
            printf("Not the same password");
        }
        else
        {
            // Third: Check for compliance
            if (content(password1) == 1)
            {
                printf("Do not satisfy the conditions");
            }
            else
            {
                printf("Everything is good");
            }
        }
    }

    return 0;
}

int n, m, x, result,upper,lower,digit;

// length() return 0 if lengths are same
int length(char pwd1[], char pwd2[])
 {

    for(n = 0; pwd1[n] != '\0'; n++)
    {
        
    }
    for(m = 0; pwd2[m] != '\0'; m++)
    {
        
    }
        if((n < 6) || (n > 16) || (m < 6) || (m > 16))
        {
            return 1;
        } 
        else
        {
            return 0;
        }
}
/*// use strlen for length
    int n = strlen(pwd1);
    int m = strlen(pwd2);
    // return 0 for n == m else return 1
    if (n == m)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}*/

// compare() return 0 for same password else return 1
int compare(char pwd1[], char pwd2[])
{
    // call to strcmp which compare two string
    result = strcmp(pwd1, pwd2);
    // result is 0 for same strings
    // return 0 else return 1
    if (result == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// content() that return 0 for all satisfied conditions
// else return 1
int content(char pwd1[])
{
    // set upper lower and digit count 0
    upper = 0, lower = 0, digit = 0;
    // length of string
    x = strlen(pwd1);
    // for each char
    for (int i = 0; i < x; i++)
    {
        // if char is upper case increment upper
        if ('A' <= pwd1[i] && pwd1[i] <= 'Z')
        {
            upper++;
        }
        // if char is lower case increment lower
        if ('a' <= pwd1[i] && pwd1[i] <= 'z')
        {
            lower++;
        }
        // if char is digit then increment digit
        if ('0' <= pwd1[i] && pwd1[i] < '9')
        {
            digit++;
        }
    }
    // if upper lower digit all are greater than 0 return 0 else return 1
    if (upper > 0 && lower > 0 && digit > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}