// update an element in an array at a particular index .

#include<stdio.h>
#include<unistd.h>

int main (){

    int size , pos , element;
    printf("enter the size of an array :\n ");
        scanf("%d",&size);
    
    int arr[size];

    printf("enter the elements of an array :\n ");
        for (int i = 0; i < size; i++)
        {
            scanf("%d",&arr[i]);
        }
        
    printf("your array is :\n ");
        for (int i = 0; i < size; i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");

    printf("Enter the position at which you want to update element :\n ");
        scanf("%d",&pos);

    printf("Enter the Updated Value :\n ");
        scanf("%d",&element);

    printf("array updation has started .....\n");

         arr[pos-1]=element;

        sleep(2);
        
    printf("array updation has Completed  .....\n your new array is \n");
        for (int i = 0; i < size; i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");

    return 0;
}