#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main()
{
    int arr[] = {1212, 23214, 3453,22,554, 567, 897};
    int size_of_arr = (sizeof(arr) / sizeof(arr[0]));
    printf("your arr before sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, size_of_arr - 1);

    printf("your arr after sorting \n");
    for (int i = 0; i < size_of_arr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}