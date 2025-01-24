// traversing in doubly linkedlist in both direction .
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

void createNodeList(int value);
void traverseForward();
void traverseBackward();

int main()
{
    int length;
    printf("Enter how many NodeList you want  :\n ");
    scanf("%d", &length);
    for (int i = 1; i <= length; i++)
    {
        createNodeList(i);
    }
    printf("your list in forward \n");
    traverseForward();
    printf("your list in backward \n");
    traverseBackward();
    return 0;
}

void createNodeList(int value)
{

    struct node *ptr;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        ptr = head;
    }
    else
    {
        ptr->next = temp;
        temp->prev = ptr;
        ptr = ptr->next;
    }
}

void traverseForward()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void traverseBackward()
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}