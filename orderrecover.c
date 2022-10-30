#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

void recovering_order(char , char *);

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"};

int main(void)
{
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}

void recovering_order(char *order, char **result)
{
    *result = malloc(100000);
    int temp = 0, length = 0, compare = 0, position = 100, first = 1, first_result = 1;
    char name[100][100], temporary[100] = "dawdaddadadadadadadawdawdawda";
    char a[1000];
    for (int i = 0; i < strlen(order); i++)
    {
        if (order[i] == ':')
        {
            temp++;
            length = 0;
        }
        else
        {
            name[temp][length] = order[i];
            length++;
        }
    }
    for (int j = 0; j <= temp; j++)
    {
        position = 100;
        for (int i = 0; i < 120; i++)
        {
            length = 0;
            first = 1;
            compare = 0;
            for (int k = 0; k < strlen(names[i]); k++)
            {
                if (name[j][compare] == names[i][k])
                {
                    if (first == 1)
                    {
                        length = k;
                        first = 0;
                    }
                    compare++;
                }
                else if (compare != strlen(name[j]))
                {
                    compare = 0;
                    first = 1;
                    length = 100;
                }
            }
            if (compare == strlen(name[j]))
            {
                if (length < position)
                {
                    strcpy(temporary, "");
                    strcpy(temporary, names[i]);
                    position = length;
                }
                else if (length == position)
                {
                    if (strlen(temporary) > strlen(names[i]))
                    {
                        strcpy(temporary, "");
                        strcpy(temporary, names[i]);
                        position = length;
                    }
                    else if (strlen(temporary) == strlen(names[i]))
                    {
                        for (int u = 0; u < strlen(temporary); u++)
                        {
                            if (temporary[u] > names[i][u])
                            {
                                strcpy(temporary, "");
                                strcpy(temporary, names[i]);
                                position = length;
                                ;
                            }
                        }
                    }
                }
                compare = 0;
            }
        }
        if (first_result == 1)
        {
            strcpy(a, temporary);
            first_result = 0;
        }
        else
        {
            strcat(a, "+");
            strcat(a, temporary);
        }
        // *result += *temporary;
        // for (int u = 0; u < strlen(temporary); u++)
        // {
        //     *(result + u) = temporary[u];
        // }
        // printf("%s test %s\n", a, *result);
    }
    strcpy(*result, a);
    return;
}