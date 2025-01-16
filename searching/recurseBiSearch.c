// binary search using recursion .
#include <stdio.h>

int search(int arr[], int size, int key, int low, int high);

int main()
{
    int key;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("enter number to find \n");
    scanf("%d", &key);
    int result = search(arr, size, key, 0, size - 1);

    if (result != -1)
    {
       printf("element found at location %d\n", result);
    }
    else if (result == -1)
    {
        printf("element not found \n");
    }

    return 0;
}

int search(int arr[], int size, int key, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (key == arr[mid])
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        return search(arr, size, key, low, mid - 1);
    }
    else
    {
        return search(arr, size, key, mid + 1, high);
    }
}