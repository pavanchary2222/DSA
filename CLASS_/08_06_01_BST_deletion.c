
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node *left;
    int data;
    struct node* right;
};
//inorder traversal
void inorder(struct node* temp)
{
    if(temp==NULL)
        return;
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}
//Postorder Traversal
void postorder(struct node* temp)
{
    if(temp==NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    printf("%d ",temp->data);
}
// Pre order traversal
void preorder(struct node* temp)
{
    if(temp==NULL)
        return;
    printf("%d ",temp->data);
    preorder(temp->left);
    preorder(temp->right);
}

struct node* create(int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct node* inordersuc(struct node* root)
{
    root=root->right;
    while(root->left!=NULL)
        root=root->left;
    return root;
}
void swap(int *p,int *q)
{
    int data=*p;
    *p=*q;
    *q=data;
}

struct node* insert(struct node* temp,int key)
{
    if(temp==NULL)
        return create(key);
    if(key<temp->data)
        temp->left=insert(temp->left,key);
    else
        temp->right=insert(temp->right,key);
    return temp;
}

struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = inordersuc(root);
 
        // Copy the inorder
        // successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int Height(struct node* root)
{
    int x;
    if(root==NULL)
        return 0;
    int leftmax=Height(root->left);
    int rightmax=Height(root->right);
    return 1+(x=leftmax<=rightmax?rightmax:leftmax);
}

int Depth(struct node* root)
{
    int x;
    if(root==NULL)
        return 0;
    int leftmax=Depth(root->left);
    int rightmax=Depth(root->right);
    return 1+(x=leftmax<=rightmax?rightmax:leftmax);
}
void Display(struct node* root)
{
    int choose;
    printf("1.Inorder 2.Preorder 3.Postorder 4->0 to exit\n");
    do{
        printf("Enter your choice:");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:
                inorder(root);
                printf("\n");
                break;
            case 2:
                postorder(root);
                printf("\n");
                break;
            case 3:
                preorder(root);
                printf("\n");
                break;
        }
    }while(choose);
}
int search(struct node* root,int key)
{
    if(root==NULL)
        return 0;
    if(key==root->data)
        return 1;
    else{
    if(key<root->data)
        search(root->left,key);
    else if(key>root->data)
        search(root->right,key);
    }
}
int main()
{
    struct node* root=NULL;
    int x,choice,Data,h,d;
    do{
    printf("\n1.create: 2.Delete: 3.Display: 4.Height 5.Depth 6.Search 0.exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter node data:");
                scanf("%d",&Data);
                root=insert(root,Data);
                break;
            case 2:
                printf("Enter Data to be deleted:");
                scanf("%d",&Data);
                root=deleteNode(root,Data);
                inorder(root);
                printf("\n");
                break;
            case 3:
                Display(root);
                printf("\n");
                break;
            case 4:
                h=Height(root);
                printf("Height of the tree is:%d",h);
                break;
            case 5:
                d=Depth(root);
                printf("Depth of a root is:%d",d);
                break;
            case 6:
                printf("enter Data to search:");
                scanf("%d",&Data);
                (x=search(root,Data))?printf("Element found"):printf("Element not found");
                break;
            case 0:
                exit(EXIT_FAILURE);
        }
    }while(choice!=0);
}
