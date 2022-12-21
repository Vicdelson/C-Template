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
void MoveToTail(struct node **head, struct node **tail) {
    // Initialize the maximum value to the head of the list
    struct node *max = *head;

    // Traverse the list to find the maximum value
    for (struct node *cur = *head; cur != NULL && cur->val < 100000; cur = cur->next) {
        if (cur->val > max->val) {
            max = cur;
        }
    }

    // If the maximum value is already at the tail, return
    if (max == *tail) {
        return;
    }

    // Remove the maximum value from the list
    if (max == *head) {
        *head = max->next;
    } else {
        // Find the node before the maximum value
        struct node *prev = *head;
        while (prev->next != max) {
            prev = prev->next;
        }
        prev->next = max->next;
    }

    // Append the maximum value to the tail of the list
    (*tail)->next = max;
    max->next = NULL;
    *tail = max;
}