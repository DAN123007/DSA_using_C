#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    struct node *root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the nodes:\n");
    while(n--)
    {
        int temp;
        scanf("%d", &temp);
        root = insert(root, temp);
    }

    printf("\n\\Inorder traversal:\n");
    inorder(root);
    printf("\n\\Preorder traversal:\n");
    preorder(root);
    printf("\n\\Postorder traversal:\n");
    postorder(root);

    return 0;
}