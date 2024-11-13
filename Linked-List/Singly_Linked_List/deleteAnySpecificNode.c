//delete a node at anyspecific point from a predefined list .

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void createNodeList(int);
void traverse();
void deleteSpecificNode();

struct node *head = NULL;

int main()
{
    char y;
    for (int i = 1; i <= 11; i++)
    {
        createNodeList(i);
    }
    printf("your node list is :\n");
    traverse();

    printf("To delete any specific node from the list enter 'y' :\n");
    scanf(" %c", &y);
    if (y == 'y')
    {
        deleteSpecificNode();
    }else
    {
        printf("Nothing changed in node \n");
    }
    
    return 0;
}

void createNodeList(int value)
{
    struct node *ptr = head;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        head = (struct node *)malloc(sizeof(struct node));
        head->data = value;
        head->next = NULL;
        ptr = head;
    }
    else
    {
        temp->data = value;
        temp->next = NULL;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void traverse()
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void deleteSpecificNode()
{
    int pos;
    struct node *ptr=head;
    struct node *prev;
    printf("enter position of node to delete :\n");
    scanf("%d",&pos);
    if (pos==1)
    {
     head=ptr->next;
     free(ptr);
     traverse();
     return;
    }else if (pos<1||pos>10)
    {
        printf("invalid position \n Nothing changed in node \n");
        return;
    }
    
    for (int i = 1; i < pos; i++)
    {
        prev=ptr;
        ptr=ptr->next;        
    }
    prev->next=ptr->next;
    free(ptr);
    printf("\nyour new node list is \n");
    traverse();
}
