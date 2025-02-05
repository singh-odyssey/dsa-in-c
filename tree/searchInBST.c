#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(struct node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->data == key)
    {
        return 1;
    }
    else
    {
        if (key < root->data)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
        }
    }
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);

    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 10);
    insert(root, 3);
    insert(root, 80);
    insert(root, 1);
    insert(root, 4);

    int key;
    
    printf("Enter the element to search \n");
    scanf("%d", &key);
    int result = search(root, key);
    if (result == 1)
    {
        printf("Element found !!! \n");
    }
    if (result != 1)
    {
        printf("Element Not found !!! \n");
    }

    return 0;
}