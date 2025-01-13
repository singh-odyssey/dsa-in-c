#include <stdio.h>

int main()
{
    int size;
    printf("enter the size of array :\n");
    scanf("%d", &size);
    int arr[size];
    printf("enter the elements of array :\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("elements of array is :\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    int find, loc;
    int found = 0;
    printf("\nenter the element to find in array :\n");
    scanf("%d", &find);
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == find)
        {
            loc = i + 1;
            printf("ELEMENT FOUND \n");
            printf("SEARCHED ELEMENT -> %d \nLOCATION -> %d \n", find, loc);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("ELEMENT NOT FOUND \nSEARCHING COMPLETE\n");
    }
    return 0;
}
