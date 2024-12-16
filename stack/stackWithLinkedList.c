#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=NULL;

void push();
void pop();
void traverse();
void kill();

int main (){

    int choice;
    printf("Choose one of the following :\n");
    printf("1->push in stack\n");
    printf("2->pop from  stack\n");
    printf("3-> exit\n");
    scanf("%d",&choice);

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

void push(){
    int value;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the value to push in stack: \n ");
    scanf("%d",&value);
    temp->data=value;
    temp->next=top;
    top=temp;
    traverse();
    main();
}
void pop(){
    traverse ();
    struct node *temp;
    temp=top;
    top=top->next;
    free(temp);
    printf("element pop successfully\n");
    traverse();
    main();
}
void traverse(){
    printf("your stack is :\n");
    struct node *ptr;
    ptr=top;
    while (ptr!=NULL)
    {
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n\n");

}
void kill(){
    printf("code execution complete \n");
    return ;
}