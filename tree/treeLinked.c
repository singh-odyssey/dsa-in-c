// creating a tree using linked .
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main()
{
    // initializing nodes
    struct node *r1 = createNode(1);
    struct node *r2 = createNode(2);
    struct node *r3 = createNode(3);
    struct node *r4 = createNode(4);
    struct node *r5 = createNode(5);
    struct node *r6 = createNode(6);
    struct node *r7 = createNode(7);

    // linking nodes to form a tree structure
    r1->left = r2;
    r1->right = r3;
    r2->left = r4;
    r2->right = r5;
    r3->left = r6;
    r3->right = r7;

    
    printf("\nTree Structure:\n");
    printf("        %d\n", r1->data);
    printf("       / \\\n");
    printf("      %d   %d\n", r2->data, r3->data);
    printf("     / \\   / \\\n");
    printf("    %d   %d %d   %d\n", r4->data, r5->data, r6->data, r7->data);

    return 0;
}
