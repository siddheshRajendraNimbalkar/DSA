#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node *createNode(int data){
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert(struct node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    else if(root->data > data){
        root->left = insert(root->left, data);
    }
    else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

void preorder(struct node *root){
    if(root != NULL){
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void freeBST(struct node *root){
    if(root != NULL){
        freeBST(root->left);
        freeBST(root->right);
        free(root);
        printf("Dynamic Memory Allocated has been freed \n");
    }

}

struct node *search(struct node *root, int key){
  while(root != NULL){
    if(root->data == key){
      return root;
    }
    else if(root->data < key){
      root = root->right;
    }
    else if(root->data>key){
      root = root->left;
    }
  }
}

int main(){
    struct node *root = NULL;
    int choise,data,key,sea;
    printf("\nBinary Search Tree Operations\n");
        printf("1. Insert Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Search For The Element\n");
        printf("4. Exit\n");
    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choise);
        switch(choise){
            case 1:printf("Enter the data to insert: ");
            printf("\t");
            scanf("%d", &data);
            root = insert(root,data);
            printf("Node inserted successfully.\n");
            break;
        case 2:
            if(root == NULL){
                printf("Tree is empty.\n");
            }
            else{
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
            }
            break;
          case 3:

            printf("\n Enter the data to Search:");
            scanf("%d",&key);
            sea = search(root,key);
            if(sea){
              printf("Data found \n");
            }
          break;
        case 4:
            freeBST(root);
            exit(0);
        default:
            printf("check the option");
            break;
        }
    }
    return 0;
}