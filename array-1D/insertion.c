//inserting an element at given index in an array .

#include<stdio.h>

int main (){

    int size , element , pos;

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
        
    printf("\nenter the element you want to insert :\n");
        scanf("%d",&element);
    
    printf("enter the position where you want to insert :\n");
        scanf("%d",&pos);
    
    for (int i = size+1; i >pos; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[pos]=element;

    printf("the array has updated ...\n");
    printf("New array is  \n");
        for (int i = 0; i < size+1; i++)
        {
            printf("%d\t",arr[i]);
        }
        printf("\n");
        
  return 0;
}