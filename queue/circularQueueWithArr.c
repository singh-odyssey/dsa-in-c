#include<stdio.h>
#define max_size 5
int front=-1;
int rear=-1;
int queue[max_size];

void menu();
void enqueue();
void dequeue();
int isFull();
int isEmpty();
void traverse();

int main (){

menu();

    return 0;
}

void menu(){

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

void enqueue(){
    int input;
    printf("enter the number \n");
    scanf("%d",&input);
    if (isFull())
    {
        printf("queue is overflow \n");
    }
    else
    {
        if (front==-1)
        {
            front++;
        }
        rear=(rear+1)%max_size;
        queue[rear]=input;
        traverse();
    }

}

void dequeue(){
    int value;

    if (isEmpty())
    {
        printf("queue underflow\n");
    }

    else
    {
        if (front==rear)
           {
                value=queue[front];
                front=-1;
                rear=-1;
           }
        else
        {
            value=queue[front];
            front=(front+1)%max_size;
        }
        traverse();
    }

}

int isFull(){

    if (( front==0 && rear==max_size-1) || (front==rear+1))
    {
        return 1;
    }
    return 0;
}

int isEmpty(){
    if (front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

void traverse(){
    printf("your queue is \n");

    if (rear < front)
    {
        for (int i = front; i < max_size; i++)
        {
            printf("%d->", queue[i]);
        }
        for (int i = 0; i <= rear; i++)
        {
            printf("%d->", queue[i]);
        }
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d->", queue[i]);
        }
    }
    printf("\n");
    printf("front=%d\n", front);
    printf("rear=%d\n", rear);
}