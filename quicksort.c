#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaring struct
struct ESPer
{
    char name[64];
    int level;
};

// comparator function
int cmp(const void *a, const void *b)
{
    struct ESPer *x = (struct ESPer *)a;
    struct ESPer *y = (struct ESPer *)b;
    return x->level - y->level;
}

// sort function
void sort_level(struct ESPer *arr, int length)
{
    qsort(arr, length, sizeof(struct ESPer), cmp);
}

// main function
int main()
{
    int n;
    // declaring array of struct
    struct ESPer tokiwadai[100];

    // taking number of elements as input
    scanf("%d", &n);

    // looping through the array and storing the values
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    // sorting the array
    sort_level(tokiwadai, n);

    // printing the sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%d %s", tokiwadai[i].level, tokiwadai[i].name);
        printf("\n");
    }

    return 0;
}