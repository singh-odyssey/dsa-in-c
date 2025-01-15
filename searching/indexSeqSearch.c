#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int arr[], int size);
int indexSeqSearch(int arr[], int size, int target);

int main()
{
    int size;

    printf("enter the size of array : ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("enter the elements of array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, size);
    int target;
    printf("enter the element to find \n");
    scanf("%d", &target);

    int result = indexSeqSearch(arr, size, target);
    if (result != -1)
    {
        printf("ELEMENT FOUND \n LOCATION ->%d \n", result);
    }
    else
    {
        printf("NOT FOUND\n");
    }

    return 0;
}

// bubble sort
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

int indexSeqSearch(int arr[], int size, int target)
{
    int blockSize = sqrt(size);
    int index[blockSize + 1];
    for (int i = 0; i <= blockSize; i++)
    {
        index[i] = i * blockSize;
    }

    int beg = 0, end = 0;

    for (int i = 1; i <= blockSize; i++)
    {
        if (target <= arr[index[i]])
        {
            beg = index[i - 1];
            end = index[i];
            break;
        }
    }

    for (int i = beg; i < end && i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}