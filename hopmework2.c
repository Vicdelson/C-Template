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
void recovery(char *homework) {

    char temp[MAX_LEN + 1], final[MAX_LEN + 1];
    char *token;

    strcpy(temp, homework);
    
    token = strtok(temp, " \n");

    while(token != NULL){
        bool cat = true;
        unsigned length = strlen(token);

        //Check if back is punctuated or not
        if((token[length - 1] == '.' || token[length - 1] == ',' || token[length - 1] == '!' || token[length - 1] == '?') && length > 1){
            cat = true;
        } else if(!isalpha(token[length-1])){ //If not Check if last is any non-alphabetic char
            cat = false;
        } else if((token[length - 1] == '.' || token[length - 1] == ',' || token[length - 1] == '!' || token[length - 1] == '?') && length == 1){
            cat = false;
        }

        // //Check if word contains alphabets only
        for(int i = 0; i < length - 1; i++){
            if(isalpha(token[i])){
                continue;
            } else{
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