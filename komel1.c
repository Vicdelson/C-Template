#include <stdio.h>
#include <stdbool.h>

int main()
{
    int name_no, name_index = 0;
    char name_letter;
    bool capitalize_letter = true;
    scanf("%d\n", &name_no);
    while(name_index != name_no){
        
        scanf("%c", &name_letter);
        
        //If the scanf encounters a ';' character
        if(name_letter == ';' || name_letter == '.' ||name_letter == ','){
            printf("\n");
            capitalize_letter = true;
            name_index++;
            continue;
        } else if(name_letter == ' '){
            capitalize_letter = true;
        }
        
        //Capitalize letter after the whitespace
        if(capitalize_letter == true){
            if(name_letter <= 122 && name_letter >= 97){
                name_letter -= 32;
                capitalize_letter = false;
            } else if(name_letter >=65 && name_letter <=90){ //If character is already uppercase, make the uppercase boolean false
                capitalize_letter = false;
            }
        } else{  //If not capitalize letter, detect if character is uppercase and lowercase it
            if(name_letter >= 65 && name_letter <= 90){
                name_letter += 32;
            }
        }        
        
        printf("%c", name_letter);
        
    } 
    return 0;
}