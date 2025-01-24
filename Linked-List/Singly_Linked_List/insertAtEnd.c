// inserting a node at the end of node list defined by user.
// here list is created by user and then an additional node is inserted at the end of that list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void nodeListCreate(int);
void traverse();
void insertNode();

struct node *head = NULL;

int main()
{
    int length;
    printf("enter the number of data :\n");
    scanf("%d", &length);
    if (length < 1)
    {
        printf("Invalid Input\n");
        return 0;
    }

    nodeListCreate(length);

    printf("your node is :\n");
    traverse();

    char boolean;
    printf("Do you want to insert another node at end (y/n): \n");
    scanf(" %c", &boolean);
    if (boolean == 'y')
    {
        insertNode();
    }
    else if (boolean == 'n')
    {
        printf("code execution complete \n");
        exit(0);
    }
    else
    {
        printf("Invalid input\n");
        return 0;
    }

    return 0;
}

void nodeListCreate(int length)
{
    int input;
    for (int i = 0; i < length; i++)
    {
        printf("enter data for node %d :\n", i + 1);
        struct node *ptr, *temp;
        scanf("%d", &input);

        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = input;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            ptr = head;
        }
        else
        {
            ptr->next = temp; // how?
            ptr = ptr->next;  // where is it storing the link
        }
    }
}

void traverse()
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        printf("The list is empty.\n");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void insertNode()
{
    int addData;
    struct node *ptr, *newNode;
    ptr = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("enter your data \n");
    scanf("%d", &addData);
    while (1)
    {
        if (ptr->next == NULL)
        {
            newNode->data = addData;
            ptr->next = newNode;
            newNode->next = NULL;
            printf("Updated list is \n");
            traverse(head);
            break;
        }
        ptr = ptr->next;
    }
}