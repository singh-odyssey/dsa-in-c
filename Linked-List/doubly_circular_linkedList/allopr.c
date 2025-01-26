#include <stdio.h>
#include <stdlib.h>

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
