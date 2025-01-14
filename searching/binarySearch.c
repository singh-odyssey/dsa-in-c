#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size);
int binarySearch(int arr[], int beg, int end, int toFind);

int main()
{
    int size;

    printf("enter the size of array : ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1; //
    }

    printf("enter the elements of array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, size);
    int beg = 0, end = size - 1, toFind;

    printf("enter the element to Find \n");
    scanf("%d", &toFind);

    int result = binarySearch(arr, beg, end, toFind);
    if (result != -1)
    {
        printf("ELEMENT FOUND \n LOCATION -> %d \n ELEMENT -> %d \n", result + 1, toFind);
    }
    else
    {
        printf("ELEMENT NOT FOUND \n");
    }

    return 0;
}

// using bubble sort
void sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int beg, int end, int toFind)
{
    int mid;

    while (beg <= end)
    {
        mid = (beg + end) / 2;

        if (arr[mid] == toFind)
        {
            return mid;
        }
        else if (arr[mid] < toFind)
        {
            beg = mid + 1;
        }
        else if (arr[mid] > toFind)
        {
            end = mid - 1;
        }
    }
    return -1;
}
