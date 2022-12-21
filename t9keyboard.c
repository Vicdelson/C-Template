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
    char dict[LINE_LEN][BUFFER_LEN];
     char *dict1[] = {"2", "22", "222",
                      "3", "33", "333", 
                      "4","44", "444", 
                      "5", "55", "555", 
                      "6", "66", "666",
                      "7", "77", "777", "7777", 
                      "8", "88", "888", 
                      "9", "99", "999", "9999"};
     char *dict2[] = {"a", "b", "c", 
                      "d", "e", "f", 
                      "g", "h", "i", 
                      "j", "k", "l", 
                      "m", "n", "o", 
                      "p", "q", "r", "s", 
                      "t", "u", "v", 
                      "w", "x", "y", "z"};

  strcat(dict['a'], "(2)1");
  strcat(dict['b'], "(2)2");
  strcat(dict['c'], "(2)3");

  strcat(dict['d'], "(3)1");
  strcat(dict['e'], "(3)2");
  strcat(dict['f'], "(3)3");

  strcat(dict['g'], "(4)1");
  strcat(dict['h'], "(4)2");
  strcat(dict['i'], "(4)3");
  
  strcat(dict['j'], "(5)1");
  strcat(dict['k'], "(5)2");
  strcat(dict['l'], "(5)3");

  strcat(dict['m'], "(6)1");
  strcat(dict['n'], "(6)2");
  strcat(dict['o'], "(6)3");

  strcat(dict['p'], "(7)1");
  strcat(dict['q'], "(7)2");
  strcat(dict['r'], "(7)3");
  strcat(dict['s'], "(7)4");

  strcat(dict['t'], "(8)1");
  strcat(dict['u'], "(8)2");
  strcat(dict['v'], "(8)3");

  strcat(dict['w'], "(9)1");
  strcat(dict['x'], "(9)2");
  strcat(dict['y'], "(9)3");
  strcat(dict['z'], "(9)4");
    
    // iterating over the array of strings
    for(int i = 0; i < count; i++)
    {
      char curr_char[BUFFER_LEN] = {};
      char *indicator;
      /*getting length of the string
        int len = strlen(arr[i]);*/
      indicator = strtok(arr[i], " ");
      while(indicator != NULL)
      {
        int len = strlen(indicator);
        if(indicator[len-1] == '\n')
        {
          len--;
        } 
        // iterating over each characater of the string
        for(int j = 0; j < len; j++)
        {
          //getting the character
            /*char curr_character = arr[i][j];

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
            }*/
          strcat(curr_char, dict[indicator[j]]);
        }

        indicator = strtok(NULL, " ");
        if(indicator != NULL)
        {
          strcat(curr_char, " ");
        } 
      }
      strcat(curr_char, "\n");
      strcpy(arr[i], curr_char);
    }
}