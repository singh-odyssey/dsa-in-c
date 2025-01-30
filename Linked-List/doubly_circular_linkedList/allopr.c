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
void traverse();

int main()
{
    while (1)
    {
        int input;
        preDefinedList();
        printf("\n\nYour Linked list is :\n");
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
    }
    return 0;
}

void preDefinedList()
{
    struct node *ptr, *temp;
    srand(time(NULL)); // for random number
    for (int i = 0; i < 10; i++)
    {
        int random_number = rand() % 1000 + 1; // generating random number between 1 and 1000
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = random_number;
        if (head == NULL)
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
            ptr = head;
        }
        else
        {
            temp->next = head;
            temp->prev = ptr;
            ptr->next = temp;
            head->prev = temp;
            ptr = temp;
        }
    }
}

void insertAtBegin()
{
    int input;
    struct node *temp, *ptr = head;
    printf("Enter the data to insert \n");
    scanf("%d", &input);
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = input;
    head->prev->next = temp;
    temp->prev = head->prev;
    temp->next = head;
    head->prev = temp;
    head = temp;
    printf("\nDATA INSERTED");
}

void insertAtEnd()
{
}

void insertAtSpecificNode()
{
}

void deleteAtBegin()
{
}

void deleteAtEnd()
{
}

void deleteAtSpecificNode()
{
}

void traverse()
{
    struct node *ptr;
    ptr = head;
    do
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;

    } while (ptr != head);
    printf("HEAD");
}
