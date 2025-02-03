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
    newNode->left = newNode->right = NULL;
    return newNode;
}

// note --- all comment out code is  logic for user input  .

// struct node *insertNode(struct node *root, int data)
// {
//     if (root == NULL)
//     {
//         return createNode(data);
//     }
//     if (data < root->data)
//     {
//         root->left = insertNode(root->left, data);
//     }
//     else if (data > root->data)
//     {
//         root->right = insertNode(root->right, data);
//     }
//     return root;
// }

void inOrder(struct node *root, int *arr, int *index)
{
    if (root != NULL)
    {
        inOrder(root->left, arr, index);
        arr[(*index)++] = root->data;
        inOrder(root->right, arr, index);
    }
}

int main()
{
    int n=5; 

    struct node *root = createNode(10);
    root->left = createNode(3);
    root->right = createNode(80);
    root->left->left = createNode(1);
    root->left->right = createNode(4);

    // int data;


    // printf("Enter the number of nodes: ");
    // scanf("%d", &n);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter node value: ");
    //     scanf("%d", &data);
    //     root = insertNode(root, data);
    // }

    int arr[n];
    int index = 0;
    inOrder(root, arr, &index);

    printf("inoder: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int isBST = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] >= arr[i + 1])
        {
            isBST = 0;
        }
    }

    if (isBST)
    {
        printf("The tree is a Binary Search Tree.\n");
    }
    else
    {
        printf("The tree is not a Binary Search Tree.\n");
    }

    return 0;
}
