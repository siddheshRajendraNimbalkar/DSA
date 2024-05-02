#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    else if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void freeBST(struct node *root)
{
    if (root != NULL)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
        printf("Dynamic Memory Allocated has been freed \n");
    }
}

struct node *search(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
    }
    return -1;
}

int leafCount(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return leafCount(root->left) + leafCount(root->right);
    }
}

int nonLeafCount(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->right == NULL && root->left == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + nonLeafCount(root->left) + nonLeafCount(root->right);
    }
}

int total(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + total(root->left) + total(root->right);
}

int search(struct node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return 1;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return 0;
}

int main()
{
    struct node *root = NULL;
    int choise, data, key, sea;
    printf("\nBinary Search Tree Operations\n");
    printf("1. Insert Node\n");
    printf("2. Preorder Traversal\n");
    printf("3. Search For The Element\n");
    printf("4. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            printf("Enter the data to insert: ");
            printf("\t");
            scanf("%d", &data);
            root = insert(root, data);
            printf("Node inserted successfully.\n");
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
            }
            break;
        case 3:
            printf("\n Enter the data to Search:");
            scanf("%d", &key);
            sea = search(root, key);
            if (sea)
            {
                printf("Data found \n");
            }
            break;
        case 10:
            freeBST(root);
            exit(0);
            break;
        case 3:
            printf("Total number of leaf nodes: %d\n", leafCount(root));
            break;
        case 4:
            printf("Total number of non-leaf nodes: %d\n", nonLeafCount(root));
            break;
        case 5:
            printf("Total number of nodes: %d\n", total(root));
            break;
        case 6:
            printf("Enter the data to be searched: ");
            scanf("%d", &data);
            if (search(root, data))
                printf("Data found\n");
            else
                printf("Data not found\n");
            break;
        default:
        default:
            printf("check the option");
            break;
        }
    }
    return 0;
}