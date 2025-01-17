#include <stdio.h>

void insertionSort(int arr[], int size);

int main()
{
    int arr[] = {12, 312, 42312, 1234, 1, 123, 3123};
    int size_of_arr = (sizeof(arr) / sizeof(arr[0]));
    printf("your arr before sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, size_of_arr);

    printf("your arr after sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void insertionSort(int arr[], int size)
{
    int temp,j;
    for (int i = 0; i < size; i++)
    {
        temp=arr[i];
        j=i-1;
        while ((temp<arr[j])&&j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
