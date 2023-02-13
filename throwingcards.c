#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

int del;

void reverseList()
{
    struct node *c0, *c1;
    if(tail != NULL)
    {
        c0 = tail;
        c1 = tail->next;
        tail = tail->next;
        c0->next = NULL;
        while(tail != NULL)
        {
            tail = tail->next;
            c1->next = c0;
            c0 = c1;
            c1 = tail;
        }
        tail = c0;
    }
}
void MoveToTail(struct node **head)
{
    struct node *first = *head;
    struct node *last = *head;
    if(*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    *head = first->next;
    first->next = NULL;
    last->next = first;
}
void Listing(struct node *head)
{
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
void Sieve(struct node **head, int value)
{
    struct node *graph = NULL;
    graph = (struct node *)malloc(sizeof(struct node));
    graph->val = value;
    graph->next = *head;
    *head = graph;
}
void *Mapping(struct node **head)
{
    struct node *cards;

    cards = *head;

    *head = (*head)->next;
    del = cards->val;
    free(cards);
}
int main()
{
    int cards, throw;
    scanf("%d %d", &cards, &throw);

    for(int i = cards;i >= 1;i--)
    {
        Sieve(&head, i);
    }

    for(int i = 0;i < throw;i++)
    {
        Mapping(&head);
        MoveToTail(&head);
        Sieve(&tail, del);
    }
    reverseList();
    Listing(tail);
}