// performing all the operations in doubly linked list -> insertionAtbegin ,end,afterSpecific node and searching.
// same goes for deletion .
// every time a new node list will be created as it is generated randomly .

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *prev;
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
void searching();
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
    printf("7->PERFORM SEARCHING \n\n");
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

    case 7:
        searching();
        break;

    default:
        printf("invalid input \n");
        break;
    }

    return 0;
}

void preDefinedList()
{

    struct node *ptr, *temp;
    srand(time(NULL)); // for random number

    for (int i = 1; i <= 10; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        int random_number = rand() % 1000 + 1; // generating random number between 1 and 1000
        temp->data = random_number;
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
}

void insertAtBegin()
{
    int data;
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    printf("enter data of new Node \n");
    scanf("%d", &data);

    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;

    printf("Node inserted successfully at begin \n");
    traverse();
}

void insertAtEnd()
{
    int data;
    struct node *ptr = head;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of new node \n");
    scanf("%d", &data);
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->data = data;
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = NULL;

    printf("Node inserted successfully \n");
    traverse();
}

void insertAtSpecificNode()
{
    int pos, data;

    struct node *ptr = head;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Enter the position where you want to add a new node \n");
    scanf("%d", &pos);

    if (pos < 1 || pos > 10)
    {
        printf("Invalid position  \n Nothing changed in the list \n");
        return;
    }
    printf("Enter data of new node \n");
    scanf("%d", &data);
    if (pos == 1)
    {
        temp->data = data;
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
        printf("Node inserted successfully \n");
        traverse();
        return;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        temp->data = data;
        temp->next = ptr->next;
        temp->prev = ptr;
        ptr->next = temp;

        printf("Node inserted successfully \n");
        traverse();
        return;
    }
}

void deleteAtBegin()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(ptr);
    printf("Node deleted successfully \n");
    traverse();
}

void deleteAtEnd()
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    free(ptr);
    printf("Node deleted successfully \n");
    traverse();
}

void deleteAtSpecificNode()
{
    int pos;
    struct node *ptr = head;
    printf("Enter position of Node which you want to delete\n");
    scanf("%d", &pos);
    if (pos < 1 || pos > 10)
    {
        printf("Invalid Position \n Nothing changed in the list \n");
        return;
    }

    if (pos == 1)
    {
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("Node deleted successfully \n");
        traverse();
        return;
    }

    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;
    free(ptr);
    printf("Node deleted successfully \n");
    traverse();
}

void searching()
{
    int data;
    struct node *ptr = head;
    int found = 0;
    printf("Enter the number you want to find -> ");
    scanf("%d", &data);
    while (ptr != NULL)
    {
        if (ptr->data == data)
        {
            printf("Data found in the List\n");
            found = 1;
            break;
        }

        ptr = ptr->next;
    }
    if (!found)
    {
        printf("Data not found in the List\n");
    }
}

void traverse()
{

    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
