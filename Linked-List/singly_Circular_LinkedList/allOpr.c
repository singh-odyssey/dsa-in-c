#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void preDefinedList();
void insertAtBegin();
void insertAtEnd();
void insertAtSpecificNode();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtSpecificNode();
void traverse();

int main()
{

    int input;
    preDefinedList();
    printf("\n\nYour predefined list is :\n");
    traverse();
    printf("\n*************************************************\n\n");
    printf("Select one of the following number to perform that task on linkedList :");
    printf("\n\n*************************************************\n\n");
    printf("1->INSERT AT BEGIN\n");
    printf("2->INSERT AT END\n");
    printf("3->INSERT AT SPECIFIC NODE\n");
    printf("4->DELETE AT BEGIN\n");
    printf("5->DELETE AT END\n");
    printf("6->DELETE AT SPECIFIC NODE\n");
    printf("YOUR INPUT -> ");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
        insertAtBegin();
        break;

    case 2:
        insertAtEnd();
        break;

    case 3:
        insertAtSpecificNode();
        break;

    case 4:
        deleteAtBegin();
        break;

    case 5:
        deleteAtEnd();
        break;

    case 6:
        deleteAtSpecificNode();
        break;

    default:
        printf("invalid input \n");
        break;
    }

    return 0;
}

void preDefinedList()
{
    int length;
    struct node *temp, *ptr;
    srand(time(NULL));
    printf("enter the size of your linked list :\n");
    scanf("%d", &length);
    if (length == 0)
    {
        printf("You just created a NULL linkedlist \n Code execution terminated");
    }
    else
    {
        for (int i = 1; i <= length; i++)
        {
            int random_number = rand() % 1000 + 1;
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = random_number;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
                ptr = head;
            }
            else
            {
                ptr->next = temp;
                ptr = ptr->next;
            }
            if (i == length)
            {
                ptr->next = head;
            }
        }
    }
}

void insertAtBegin()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data for new node :\n");
    scanf("%d", &data);
    temp->data = data;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head;
    head = temp;

    printf("Node inserted successfully :\n");
    traverse();
    printf("\n");
}

void insertAtEnd()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    int data;
    printf("Enter data for new node :\n");
    scanf("%d", &data);
    temp->data = data;
    ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = head;

    printf("Node inserted successfully :\n");
    traverse();
    printf("\n");
}

void insertAtSpecificNode()
{
    struct node *temp, *ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    int data, pos;
    printf("Enter Position of new node :\n");
    scanf("%d", &pos);
    printf("Enter data for new node :\n");
    scanf("%d", &data);
    temp->data = data;
    if (pos == 1)
    {
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
        head = temp;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }

    printf("Node inserted successfully :\n");
    traverse();
    printf("\n");
}

void deleteAtBegin()
{
    struct node *ptr1 = head;
    struct node *ptr2 = head;
    while (ptr2->next != head)
    {
        ptr2 = ptr2->next;
    }
    ptr2->next = ptr1->next;
    head = ptr2->next;
    free(ptr1);
    printf("Node deleted successfully :\n");
    traverse();
    printf("\n");
}

void deleteAtEnd()
{
    struct node *ptr = head, *prev;
    while (ptr->next != head)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    printf("Node deleted successfully :\n");
    traverse();
    printf("\n");
}

void deleteAtSpecificNode()
{
    struct node *ptr = head;
    struct node *prev = head;
    int pos;
    printf("Enter Position to delete node :\n");
    scanf("%d", &pos);
    for (int i = 1; i < pos; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = ptr->next;
    free(ptr);
    printf("Node deleted successfully :\n");
    traverse();
    printf("\n");
}

void traverse()
{
    struct node *ptr = head;
    do
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    printf("NULL");
}