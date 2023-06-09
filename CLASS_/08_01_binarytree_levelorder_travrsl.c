#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100

struct node
{
    struct node *left;
    int data;
    struct node* right;
};

struct node *arr[max];
int front=-1;
int rear=-1;

struct node* root=NULL;
int isfull()
{
    if(rear==max-1)
        return 1;
    return 0;
}
int isempty()
{
    if(front>rear)
        return 1;
    return 0;
}
void Q_insert(struct node* x)
{
    if(!isfull()) 
    {
        if(front==-1)
        {
            front=rear=0;
            arr[rear]=x;
        }
        else{
            rear++;
            arr[rear]=x;
        }
    }
}
void Q_delete()
{
    if(!isempty()){
        struct node* temp=arr[front];
        front++;
        printf("%d ",temp->data);
    }
}

void levelorder(struct node* temp)
{
    if(temp==NULL)
        return;
    Q_insert(temp);
    while(!isempty())
    {
        struct node* temp1=arr[front];
        if(temp1->left!=NULL)
            Q_insert(temp1->left);
        if(temp1->right!=NULL)
            Q_insert(temp1->right);
        Q_delete();
    }
}

struct node* create(int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct node* insert(struct node* root,int Data)
{
    if(root==NULL)
        return create(Data);
    if(Data<root->data)
        root->left=insert(root->left,Data);
    else
        root->right=insert(root->right,Data);
    return root;
}
int main()
{
    struct node* root=NULL;
    int choice,Data;
    printf("\nEnter 1 to create a node:\nEnter 2 to print level order leaves:\nEnter 0 to exit:\n");
    do{
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
                levelorder(root);
                break;
            case 0:
                printf("\nExit\n");
        }
    }while(choice!=0);
}