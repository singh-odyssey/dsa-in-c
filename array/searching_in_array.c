//searching a particular number in an array by linear searching .

#include<stdio.h>

int main(){

    int size , num;

    printf("enter the size of your array :\n");
        scanf("%d",&size);

    int arr[size];

    printf("enter the elements of your array :\n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d",&arr[i]);
        }
    
    printf("enter the number to find :\n");
        scanf("%d",&num);

    for (int i = 1; i <= size; i++)
    {
        if (num==arr[i])
        {
            printf("Your number is found in array ---\n");
            printf("Code Execution Completed Successfully ---\n");
            break ;
        }
        else if (i==size)
        {
            printf("No such Number Found ---\n");
            printf("Code Execution Completed Successfully ---\n");
            break ;
        }
        
    }
    
    return 0;
}
