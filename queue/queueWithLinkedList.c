// implementation of queue using linked list .

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;
int Fcount = -1;
int Rcount = -1;

void menu();
void enqueue();
void dequeue();
void traverse();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int response;
    while (1)
    {
        printf("\nchoose one of the following \n");
        printf("1->enqueue\n");
        printf("2->dequeue\n");
        scanf("%d", &response);

        switch (response)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        default:
            printf("invalid input \n");
            break;
        }
    }
}

void enqueue()
{
    int input;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("enter your data :\n");
    if (scanf("%d", &input) != 1)
    {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n')
            ; // clear the input buffer
        free(temp);
        return;
    }
    if (front == NULL)
    {
        temp->data = input;
        front = temp;
        rear = temp;
        front->next = NULL;
        rear->next = NULL;
        Fcount++;
        Rcount++;
    }
    else
    {
        temp->data = input;
        rear->next = temp;
        temp->next = NULL;
        rear = rear->next;
        Rcount++;
    }
    traverse();
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    struct node *temp = front;
    int value = front->data;
    front = front->next;
    free(temp);
    Fcount++;
    printf("Element dequeued: %d\n", value);
    if (Fcount == Rcount + 1)
    {
        Fcount = -1;
        Rcount = -1;
    }

    traverse();
}

void traverse()
{
    printf("your queue is >>\n");
    struct node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    printf("front->%d\n", Fcount);
    printf("rear->%d\n", Rcount);
}
