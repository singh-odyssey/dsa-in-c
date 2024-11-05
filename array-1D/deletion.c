//deleting an element in an array .

#include<stdio.h>
#include<unistd.h>

int main (){

    int size , pos;

    printf("enter the size of array :\n");
        scanf("%d",&size);

    int arr[size];

    printf("enter the element of array :\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d",&arr[i]);
        }
    
    printf("your  array is :\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\t",arr[i]);
        }

    
    printf("\n Enter the position where you want to Delete :\n");
        scanf("%d",&pos);
            if (pos<0 || pos>size)
            {
                printf("\n No Such Location Found ....\n Enter Valid Position \n");
                 return 1;
            }

    printf("Deleting .... :\n");
        sleep(2);

    for (int i = pos; i <= size; i++)
    {
        arr[i-1]=arr[i];
    }
    
    printf("Element Deleted successfully .... :\n");

    printf("New array :\n");
        for (int i = 0; i < size-1; i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");

    
 return 0;   
}