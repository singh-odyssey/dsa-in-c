//deleting a node from end of a node list .
//here list is defined by user .

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node *next;
};

void createNodeList();
void traverse();
void deleteFromEnd();

struct node *head=NULL;

int main (){
    char y;
    createNodeList();
    printf("your node is :\n");
    traverse();

    printf("\nenter y to delete last node of the list:\n");
    
        scanf(" %c",&y); //space before %c to clear input buffer caused by \n .
         if (y=='y')
         {
             deleteFromEnd();
             printf("your new node is :\n");
             traverse();

         }else
         {
            printf("code execution complete \n Nothing is changed in NodeList \n");
         }
         
    

    return 0;
}

void createNodeList(){
    int length,val; 

    printf("enter the length of node list : \n");
    scanf("%d",&length);

    struct node *ptr,*temp;

    
    for (int i = 0; i < length; i++)
    {
        printf("enter data for node%d ->",i+1);
        scanf("%d",&val);
        
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=val;
        temp->next=NULL;

        if (head==NULL)
        {
            head=temp;
            ptr=head;
        }
        else
        {
            ptr->next=temp;
            ptr=ptr->next;            
        }
        
    }
        
}

void traverse(){
    struct node *ptr=head;

    while (ptr!=NULL)
    {
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

void deleteFromEnd(){
    struct node *ptr=head;
    struct node *prev=NULL;

    while (ptr->next != NULL) {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next=NULL;
    free(ptr);
}
