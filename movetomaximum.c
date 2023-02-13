#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void) { 
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        scanf("%d", &tmp->val);
        tmp->next = NULL;
        if(i == 1)
            head = tmp;
        else
            tail->next = tmp;
        tail = tmp;
    }
    MoveToTail();
    for(struct node *cur = head; cur != NULL; cur = cur->next) {
        printf("%d ", cur->val);
    }
    return 0;
}

struct node *find(int key);
struct node *max = NULL;

// Function to move the maximum value to the tail of the linked list
void MoveToTail() 
{
     // Initialize the maximum value to the head of the list
    int first = search();
    struct node *start = find(first);

    if(tail->val == start->val)
    {
    } 
    else{
        int indicator;
        struct node *max = start;
        int test = 0;
        while(1)
        {
            if(max->next == tail){
                indicator = max->val;
                max->val = tail->val;
                tail->val = indicator;
                break;
            } else{
                indicator = max->val;
                max->val = max->next->val;
                max->next->val = indicator;
                max = max->next;
            }        
        }   
    }
}
int search(){
    int first = head->val;
    struct node *max = head->next;

    while(max != NULL){
        if(max->val > first){
            first = max->val;
        }
        max = max->next;
    }
    return first;
}

struct node *find(int key)
{
    struct node *max = head;
    while(max != NULL){
        if(max->val == key){
            return max;
        }
        max = max->next;
    }

    return NULL;
}