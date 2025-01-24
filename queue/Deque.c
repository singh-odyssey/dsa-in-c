// doubly ended queue using  array .
#include <stdio.h>
#include <stdlib.h>

#define max_size 5
int arr[max_size];
int front = -1;
int rear = -1;

void menu();
void pushF(); // inserting from front
void pushR(); // inserting from rear
void popF();  // removing from front
void popR();  // removing from rear
void traverse();
int isFull();
int isEmpty();
void clear();

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
        printf("\n Choose one of the following ----\n");
        printf("1 -> insert from front\n");
        printf("2 -> insert from rear\n");
        printf("3 -> delete from front\n");
        printf("4 -> delete from rear\n");
        printf("5 -> clear terminal\n");
        scanf("%d", &response);

        switch (response)
        {
        case 1:
            pushF();
            break;

        case 2:
            pushR();
            break;

        case 3:
            popF();
            break;

        case 4:
            popR();
            break;

        case 5:
            clear();
            break;

        default:
            printf("***invalid input*** \n");
            break;
        }
    }
}

void pushF()
{

    int input;
    printf("enter element to insert \n");
    scanf("%d", &input);
    if (isFull())
    {
        printf("queue is full \n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = input;
        }
        else
        {
            front = (front - 1 + max_size) % max_size;
            arr[front] = input;
        }
    }

    traverse();
}

void pushR()
{

    int input;
    printf("enter element to insert \n");
    scanf("%d", &input);
    if (isFull())
    {
        printf("queue is full \n");
        return;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = input;
        }
        else
        {
            rear = (rear + 1) % max_size;
            arr[rear] = input;
        }
    }

    traverse();
}

void popF()
{
    int temp;
    if (isEmpty())
    {
        printf("queue is empty\n Nothing to remove\n");
        return;
    }
    else
    {
        if (front == rear)
        {
            temp = arr[front];
            front = -1;
            rear = -1;
        }
        else
        {
            temp = arr[front];
            front = (front + 1) % max_size;
        }
    }
    traverse();
}

void popR()
{
    int temp;
    if (isEmpty())
    {
        printf("queue is empty\n Nothing to remove\n");
        return;
    }
    else
    {
        if (front == rear)
        {
            temp = arr[rear];
            front = -1;
            rear = -1;
        }
        else
        {
            temp = arr[rear];
            rear = (rear - 1) % max_size;
        }
    }
    traverse();
}

void traverse()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Your queue is: ");
        int i = front;
        while (1)
        {
            printf("%d->", arr[i]);
            if (i == rear)
                break;
            i = (i + 1) % max_size;
        }
        printf("\n");
        printf("front = %d\n", front);
        printf("rear = %d\n", rear);
    }
}

int isFull()
{
    if ((front == 0 && rear == max_size - 1) || (front == rear + 1))
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

void clear()
{
    system("clear");
}