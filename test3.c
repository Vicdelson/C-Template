#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strtok(char *s, const char *sep) {
  printf("strtok banned\n");
  exit(1);
}
char *strtok_r(char *str, const char *sep, char **lasts) {
  printf("strtok_r banned\n");
  exit(1);
}

char *strsep(char **stringp, const char *delim) {
  printf("strsep banned\n");
  exit(1);
}
char *gettoken(char *str, const char *sep);
int main() {
  char buffer[4096];
  char *sep = " \t\n;,.?!";
  char *word;
  int N;
  scanf("%d\n", &N);
  for (int i = 0; i < N; i++) {
    fgets(buffer, 4095, stdin);
    for (word = gettoken(buffer, sep); word != NULL;
         word = gettoken(NULL, sep)) {
      printf("%s\n", word);
    }
  }
}
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

