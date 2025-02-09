#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};

struct node *createNode(int data)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct node *root=NULL;
    int data, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter node value: ");
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    printf("Inorder Traversal -> : ");

    inorderTraversal(root);

    return 0;
}