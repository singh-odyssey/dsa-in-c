#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size);
void traverse(int arr[], int size);

int main()
{
    int arr[] = {21, 43, 546, 2341, 4321, 34};
    int size = 6;
    printf("Array before sorting :  ");
    traverse(arr, size);
    sort(arr, size);
    printf("Array after sorting  :  ");
    traverse(arr, size);

    return 0;
}

void sort(int arr[], int size)
{
    // finding max element in array
    int maxElement;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            maxElement = arr[i];
            i++;
        }
        else
        {
            i++;
        }
    }

    // calculating no.of digits in max element which will become number of pass required .
    int pass = 0;
    while (maxElement != 0)
    {
        maxElement /= 10;
        pass++;
    }
    
    //main logic
    int exp = 1; 
    int output[size]; // output array to store sorted numbers temporarily

    // loop for each digit place (units, tens, hundreds, ...)
    for (int p = 0; p < pass; p++)
    {
        int count[10] = {0}; // count array to store count of occurrences of digits (0-9)

        // count occurrences of each digit in the current place value
        for (int i = 0; i < size; i++)
        {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // change count[i] so that it contains the actual position of this digit in output[]
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        // build the output array
        for (int i = size - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // copy the output array to arr[]
        for (int i = 0; i < size; i++)
        {
            arr[i] = output[i];
        }

        exp *= 10; // move to next digit place
    }

}

void traverse(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("]");
    printf("\n");
}