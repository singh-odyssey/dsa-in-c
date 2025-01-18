#include <stdio.h>

quickSort(int arr[], int size);

int main()
{
    int arr[] = {123, 234, 345, 567, 897};
    int size_of_arr = (sizeof(arr) / sizeof(arr[0]));
    printf("your arr before sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, size_of_arr);

    printf("your arr after sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

quickSort(int arr[], int size)
{
    
}