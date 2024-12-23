// inserting and deleting elements from a queue .

#include <stdio.h>
#define MAX_SIZE 5 // size of queue

int arr[MAX_SIZE]; // initialize the queue
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void traverse();
void menu();

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
        printf("\n****Choose one of the following :****\n");
        printf("1 -> Insert in queue\n");
        printf("2 -> Delete from queue\n");
        printf("3 -> Exit\n");
        scanf("%d", &response);

        if (response == 1)
        {
            enqueue();
        }
        else if (response == 2)
        {
            dequeue();
        }
        else if (response == 3)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid input\n");
        }
    }
}

void enqueue()
{
    int input;
    if (rear == MAX_SIZE - 1)
    {
        printf("queue overflow\n");
        return;
    }
    printf("enter the element :\n");
    scanf("%d", &input);
    if (front == -1)
    {
        front++;
        rear++;
        arr[rear] = input;
    }
    else
    {
        rear++;
        arr[rear] = input;
    }
    traverse();
}

void dequeue()
{
    int empty;
    if (front == -1)
    {
        printf("queue is underflow\n");
    }
    if (front == rear)
    {
        arr[front] = empty;
        front = -1;
        rear = -1;
        printf("queue is empty\n");
        printf("front=%d\n", front);
        printf("rear=%d\n", rear);
    }
    else
    {
        arr[front] = empty;
        front++;
        traverse();
    }
}

void traverse()
{
    printf("your queue is \n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d->", arr[i]);
    }
    printf("\n");
    printf("front=%d\n", front);
    printf("rear=%d\n", rear);
}