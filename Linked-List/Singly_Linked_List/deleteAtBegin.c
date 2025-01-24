// deleting a node from starting in a predefine nodelist.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void deleteFromStart();
void traverse();
void predefinedNodelist();

struct node *head;
struct node *node2;
struct node *node3;
struct node *node4;
struct node *node5;

int main()
{
    printf("your predefined node list is :\n");
    predefinedNodelist();
    traverse();
    deleteFromStart();

    return 0;
}

void predefinedNodelist()
{
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 100;

    node2 = (struct node *)malloc(sizeof(struct node));
    node2->data = 200;

    node3 = (struct node *)malloc(sizeof(struct node));
    node3->data = 300;

    node4 = (struct node *)malloc(sizeof(struct node));
    node4->data = 400;

    node5 = (struct node *)malloc(sizeof(struct node));
    node5->data = 500;

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;
}

void traverse()
{
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

void deleteFromStart()
{
    char y;
    struct node *ptr;
    ptr = head;

    printf("\nenter y to delete starting node :\n");
    scanf("%c", &y);
    if (y == 'y')
    {
        head = ptr->next;
        free(ptr);
        printf("node successfully deleted :\n");
        printf("new node list is  :\n");
        traverse();
        printf("\n");
    }
    else
    {
        printf("code execution complete \n Nothing is changed \n.");
    }
}
