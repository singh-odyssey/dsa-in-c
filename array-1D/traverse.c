//storing and accessing elements in arr .

#include<stdio.h>

int main (){

    int    arr[10];
    printf("enter the element of array :\n");
        for (int i = 0; i < 10; i++)
        {
            scanf("%d",&arr[i]);
        }
    printf("your array is :\n");
        for (int  i = 0; i < 10; i++)
        {
            printf("%d ",arr[i]);
        }
        
        

    return 0;
}