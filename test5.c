#include <stdlib.h>
#include <string.h>

#define URL_MAX 2048
#define KEY_MAX 100

typedef struct search_s {
    char *key;
    char *value;
} search_t;

search_t *get_param_by_key(char *url, char *key) 
{
    search_t *param = NULL;
    char *search = strstr(url, "?");  // find the start of the search part
    if (search != NULL) 
    {
        search++;  // move past the '?' character
        char *end = strstr(search, "#");  // find the end of the search part
        if (end != NULL) 
        {
            *end = '\0';  // terminate the search string
        }
        char *token = strtok(search, "&");  // get the first token
        while (token != NULL) 
        {
            char *delim = strchr(token, '=');  // find the delimiter between key and value
            if (delim != NULL) {
                *delim = '\0';  // terminate the key
                char *key_copy = strdup(token);  // make a copy of the key
                char *value = delim + 1;  // get the value
                if (strcmp(key_copy, key) == 0) 
                {  // check if the key matches the search key
                    param = malloc(sizeof(search_t));  // allocate memory for the result
                    param->key = key_copy;
                    param->value = value;
                    break;
                }
                free(key_copy);  // free the key copy if it doesn't match
            }
            token = strtok(NULL, "&");  // get the next token
        }
    }
    return param;
}
