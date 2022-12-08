#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_LEN 1024
#define LINE_LEN 128

void convert(char *arr[], int count);
int main()
{
    char line[BUFFER_LEN];
    char buffer[LINE_LEN][BUFFER_LEN];
    char *arr[LINE_LEN];

    // {a, hole, in, the, world}
    int count = 0;
    while (fgets(line, BUFFER_LEN - 1, stdin) != NULL)
    {
        arr[count] = buffer[count];
        strncpy(buffer[count++], line, BUFFER_LEN - 1);
    }
    convert(arr, count);
}

void convert(char *arr[], int count)
{
    char *dict[] = {"2", "22", "222", "3", "33", "333", "4",
                    "44", "444", "5", "55", "555", "6", "66",
                    "666", "7", "77", "777", "7777", "8", "88",
                    "888", "9", "99", "999", "9999"};

    // iterating over the array of strings
    for (int i = 0; i < count; i++)
    {
        // getting length of the string
        int len = strlen(arr[i]);
        // iterating over each characater of the string
        for (int j = 0; j < len; j++)
        {
            // getting the character
            char curr_character = arr[i][j];

            // if charactor is space print ' '
            if (curr_character == ' ')
            {
                printf(" ");
            }
            else if (curr_character >= 'a' && curr_character <= 'z')
            {
                // print the number key and number of times it need to presses
                printf("(%c)%d", dict[curr_character - 'a'][0], strlen(dict[curr_character - 'a']));
            }
            else
            {
                printf("\n");
            }
        }
    }
}