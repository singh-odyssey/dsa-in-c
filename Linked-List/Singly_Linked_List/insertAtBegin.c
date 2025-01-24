// inserting a node in a beginning of a node list .

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *first;
struct node *second;
struct node *third;

void preDefinedNode();
void traverseTheList(struct node *ptr);
void insertNode();

int main()
{

    preDefinedNode();
    traverseTheList(first);
    insertNode();

    return 0;
}

void preDefinedNode()
{

    first = (struct node *)malloc(sizeof(struct node));
    first->data = 1;
    first->next = NULL;

    second = (struct node *)malloc(sizeof(struct node));
    second->data = 2;
    second->next = NULL;

    third = (struct node *)malloc(sizeof(struct node));
    third->data = 3;
    third->next = NULL;

    first->next = second;
    second->next = third;
}

void traverseTheList(struct node *ptr)
{

    printf("your list is :\n");

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertNode()
{
    int newData;
    printf("enter the data you want to insert :\n");
    scanf("%d", &newData);

    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next = first;
    first = newNode;

    traverseTheList(first);
}