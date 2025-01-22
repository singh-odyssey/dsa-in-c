// taking ideal case of hashing where no collision will exist and time complexity is O(1).
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initHashTable()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1; // -1 indicates an empty slot
    }
}

int hash(int key)
{
    return key % TABLE_SIZE;
}

void insert(int key)
{
    int index = hash(key);
    if (hashTable[index] == -1)
    {
        hashTable[index] = key;
    }
    else
    {
        printf("Collision detected! This example assumes no collisions.\n");
    }
}

int search(int key)
{
    int index = hash(key);
    if (hashTable[index] == key)
    {
        return index;
    }
    else
    {
        return -1; // Key not found
    }
}

void menu()
{
    int input, number, key;
    printf("\nChoose from the following ----\n");
    printf("\n1 -> Enter a Number \n");
    printf("2 -> Search a Number \n");
    scanf("%d", &input);

    if (input == 1)
    {
        printf("Enter number to insert: ");
        scanf("%d", &number);
        if (number >= TABLE_SIZE)
        {
            printf("Max number you can enter is up to %d\n", TABLE_SIZE - 1);
        }
        else
        {
            insert(number);
        }
    }
    else if (input == 2)
    {
        printf("Enter number to search: ");
        scanf("%d", &key);
        int result = search(key);
        if (result != -1)
        {
            printf("Number found at index %d\n", result);
        }
        else
        {
            printf("Number not found\n");
        }
    }
    else
    {
        printf("Invalid option\n");
    }
}

int main()
{
    initHashTable();
    while (1)
    {
        menu();
    }
    return 0;
}