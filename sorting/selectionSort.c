#include <stdio.h>

void selectionSort(int arr[], int size);

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

    selectionSort(arr, size_of_arr);

    printf("your arr after sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void selectionSort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        int min = arr[i];
        int loc = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                loc = j;
            }
        }
        if (loc != i)
        {
            temp = arr[i];
            arr[i] = arr[loc];
            arr[loc] = temp;
        }
    }
}