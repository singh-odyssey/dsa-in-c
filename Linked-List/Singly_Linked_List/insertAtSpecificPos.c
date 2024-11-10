//inserting a new node after specific node defined by user .
//in a pre-Defined nodeList .

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void preDefineList();
void insertAtPos();
void traverse();

struct node *head;
struct node *node2;
struct node *node3;
struct node *node4;
struct node *node5;

int main(){

    printf("your pre defined node list is : \n");
      preDefineList();
      traverse();
    insertAtPos();


    return 0;
}

void preDefineList(){

    head=(struct node *)malloc(sizeof(struct node));
    head->data=10;
    head->next=NULL;

    node2=(struct node *)malloc(sizeof(struct node));
    node2->data=20;
    node2->next=NULL;

    node3=(struct node *)malloc(sizeof(struct node));
    node3->data=30;
    node3->next=NULL;

    node4=(struct node *)malloc(sizeof(struct node));
    node4->data=40;
    node4->next=NULL;

    node5=(struct node *)malloc(sizeof(struct node));
    node5->data=50;
    node5->next=NULL;

    //linking all the nodes
    head->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;
    node5->next=NULL;
}

void insertAtPos(){
    int pos,data,count=0;
    struct node *newNode;
    struct node *ptr=head;
    newNode=(struct node *)malloc(sizeof(struct node));

    printf("Enter the Position where you want to insert the node (between 0 and 6) : \n");
        scanf("%d",&pos);
        if (pos<1 || pos>6)
        {
            printf("invalid Positon is entered \n code execution has stopped !!! \n");
            return;
        }
        
    printf("Enter the data for new Node : \n");
        scanf("%d",&data);

    newNode->data=data;

    while (ptr!=NULL)
    {
        if (pos==1)
        {
            newNode->next=head;
            head=newNode;
            traverse();
            return;
        }
        
        else if (count==pos-2) // to check if ptr is one position behind than the pos where node has to be inserted
        {
            newNode->next=ptr->next;
            ptr->next=newNode;
            traverse();
            return;
        }   
        ptr=ptr->next;
        count++;
    }
}

void traverse(){
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
