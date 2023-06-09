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

struct node* root=NULL;
struct node *arr[max];
int front=-1;
int rear=-1;

int isfull()
{
    if(rear==max-1)
        return 1;
    return 0;
}
int isempty()
{
    if(front=-1|| front>rear)
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
    }
}

void inorder(struct node* temp)
{
    if(temp==NULL)
        return;
    else{
        inorder(temp->left);
        printf("%d ",temp->data);
        inorder(temp->right);
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

struct node* insert(int data)
{
    if(root==NULL){
         root=create(data);
         Q_insert(root);
    }
    else{
            struct node* temp=arr[front];
            if(temp->left==NULL){
                temp->left=create(data);
                Q_insert(temp->left);
            }
            else{
                temp->right=create(data);
                Q_insert(temp->right);
                Q_delete();
            }
    }
}
int main()
{
        
    int choice,Data;
    
    do{
        printf("\n1.create: 2.inorderdisplay: 0.exit:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter node data:");
                scanf("%d",&Data);
                insert(Data);
                break;
            case 2:
                printf("The inorder traversal of list:");
                inorder(root);
                break;
            case 0:
                printf("\nExit\n");
        }
    }while(choice!=0);
}