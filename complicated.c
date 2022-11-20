#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void add_member(char *name, char *race, int age);
bool remove_member(char *name);

typedef struct member_data MEMBER_DATA;

MEMBER_DATA *head_member = NULL;

struct member_data
{
    char *name;
    char *race;
    int age;
    MEMBER_DATA *next;
};

int main(void)
{
    char name[30] = {};
    char race[30] = {};
    char cmd[30] = {};
    int age = 0;
    MEMBER_DATA *p = NULL, *p_next = NULL;

    for(;;)
    {
        printf("To add a member to Kota Wibu, type 'add'. \n");
        printf("To remove a member from Kota Wibu, type 'remove'. \n");
        printf("To see a list of the members, type 'list'. \n");
        printf("If you are done creating the list, type 'done', \n");
        scanf("%s", cmd);

        if(!strcmp(cmd, "done"))
        {
            printf("The list of Kota Wibu is complete! The adventure can begin...\n");
            break;
        }
        else if(!strcmp(cmd,"list"))
        {
            int count = 0;
            if(head_member == NULL)
            {
                printf("\nThe list of Kota Wibu has not been formed yet. \n\n");
            }
            else
            {
                printf("\n");
                for(p = head_member;p;p = p -> next)
                {
                    printf("[%d] %s, %s, %d\n", ++count, p -> name, p -> race, p -> age);
                }
                printf("\n");
            }
        }
        else if(!strcmp(cmd, "remove"))
        {
            printf("\nWho is leaving Kota Wibu? ");
            scanf("%s", name);
            if(remove_member(name))
            {
                printf("\n%s has left Kota Wibu.\n\n", name);
            }
        }
        else if(!strcmp(cmd,"add"))
        {
            printf("Who is joining Kota Wibu? ");
            scanf("%s", name);
            printf("What race is %s? ", name);
            scanf("%s", race);
            printf("How old is %s? ", name);
            scanf("%d", &age);

            printf("\n%s (race %s, age %d) has joined NCKU!\n\n", name, race, age);
            add_member(name, race, age);
        }
        else
        {
            printf("\n%s is not a valid command. \n\n", cmd);
            continue;
        }
    }
    for(p = head_member; p; p = p_next)
    {
        p_next = p -> next;
        remove_member(p-> name);
    }
    return 0;
}

MEMBER_DATA *new_node()
{
    MEMBER_DATA *node = NULL,node_zero = {0};

    if((node =(MEMBER_DATA *)malloc(sizeof(MEMBER_DATA))) == NULL)
    {
        //ERROR MESSAGES
        return NULL;
    }
    *node = node_zero;
    return node;
}

void add_member(char *name, char *race, int age)
{
    MEMBER_DATA *newNode = NULL, *p = NULL;

    if((newNode = new_node()) == NULL)
    return;

    newNode ->name = strdup(name);
    newNode ->race = strdup(race);
    newNode ->age = age;

    if(head_member == NULL)
    {
        head_member = newNode;
    }
    else
    {
        //Add node to end of list
        for(p = head_member;p ; p = p -> next)
        {
            if(p -> next == NULL)
            {
                p -> next = newNode;
                break;
            }
        }
    }
}

bool remove_member(char *name)
{
    MEMBER_DATA *p = NULL, *temp = NULL;

    if(head_member == NULL)
    {
        printf("\nThere are no members to remove. \n\n");
        return false;
    }
    if(!strcmp(head_member -> name, name))
    {
        temp = head_member;
        head_member = head_member -> next;
        free(temp -> name);
        free(temp -> race);
        free(temp);
        temp = NULL;
        return true;
    }
    for(p = head_member;p ;p = p -> next)
    {
        if(p -> next = NULL)
        {
            if(strcmp(p -> next -> name, name))
            {
                temp = p -> next;
                p -> next = p -> next -> next;
                free(temp -> name);
                free(temp -> race);
                free(temp);
                temp = NULL;
                return true;
            }
        }
    }
    printf("\nThere is no member named %s. \n\n", name);
    return false;
}