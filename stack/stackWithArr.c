#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 7

int top = -1;
int stack[MAX_SIZE];

// void predefinedStack();
void push();
void pop();
void kill();
void traverse();

int main()
{

    printf("your max size is %d\n", MAX_SIZE);
    // predefinedStack();
    // traverse();

    int choice;
    printf("Choose one of the following :\n");
    printf("1->push in stack\n");
    printf("2->pop from  stack\n");
    printf("3-> exit\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        kill();
        break;

    default:
        break;
    }

    return 0;
}

// void predefinedStack(){
//     for (int  i = 1; i <= MAX_SIZE; i++)
//     {
//         top=top+1;
//         stack[top]=i*21;//21 is for some random number.
//     }
// }

void push()
{
    int item;
    printf("enter the element to push\n ");
    scanf("%d", &item);
    if (top == MAX_SIZE)
    {
        printf("stack is full \n");
        return;
    }
    top = top + 1;
    stack[top] = item;
    printf("element %d pushed to stack successfully\n", item);
    traverse();
    main();
}

void pop()
{
    int item;
    if (top == -1)
    {
        printf("\nstack is empty \n\n");
        main();
    }
    item = stack[top];
    top--;
    printf("element removed from  stack successfully\n");
    traverse();
    main();
}

void traverse()
{
    printf("your stack elements are : \n");
    for (int i = top; i >= 0; i--)
    {
        printf("[%d] -> %d\n", i, stack[i]);
    }
    printf(" \n");
}

void kill()
{

    printf("code excecution completed Successfully\n");

    return;
}