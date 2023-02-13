#include <stdio.h>
#include <stdlib.h>

struct node {
    long long int val;
    struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
void MoveToTail();

int main(void) {
    long long int n;
    scanf("%lld", &n);
    for (long long int i = 1; i <= n && i <= 1000 && 5 <= n && n <= 1000; ++i) {
        struct node *tmp = malloc(sizeof(struct node));
        long long int val;
        scanf("%lld", &val);
        if (val < 100000) 
        {
            tmp->val = val;
        } else {
            printf("Error: Element value is not strictly less than 100000.\n");
            return 1;
        }
        tmp->next = NULL;
        if (i == 1) {
           head = tmp;
        } else {
           tail->next = tmp;
        }
           tail = tmp;
        }
        MoveToTail(&head, &tail);
        for (struct node *cur = head; cur != NULL; cur = cur->next) {
            printf("%lld ", cur->val);
        }
        return 0;
}
// Function to move the maximum value to the tail of the linked list
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