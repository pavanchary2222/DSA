#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    struct node *left;
    int data;
    struct node* right;
};

struct node* root=NULL;

void inorder(struct node* temp)
{
    if(temp==NULL)
        return;
    inorder(temp->left);
    printf("%d ",temp->data);
    inorder(temp->right);
}

struct node* create(int data)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}
struct node* inorderpre(struct node* root)
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

void insert(struct node* temp,struct node* newnode)
{
    if(root==NULL)
    {
        root=newnode;
        printf("root node:%d\n",root->data);
    }
    else if(newnode->data<=temp->data)
    {
        if(temp->left!=NULL)
        {
            insert(temp->left,newnode);
        }
        else
        {
            temp->left=newnode;
            printf("Node:%d\n",newnode->data);
        }
    }
    else
    {
        if(temp->right!=NULL)
        {
            insert(temp->right,newnode);
        }
        else
        {
            temp->right=newnode;
            printf("Node:%d\n",newnode->data);
        }
    }
}
struct node* Deletenode(struct node* temp,int data)
{
    if(temp==NULL)
        return NULL;
    else if(data<temp->data)
        temp->left=Deletenode(temp->left,data);
    else if(data>temp->data)
        temp->right=Deletenode(temp->right,data);
    else{
        if(temp->left==NULL && temp->right==NULL){
            free(temp);
            return NULL;
        }
        else if(temp->left==NULL)
        {
            struct node* s=temp->right;
            swap(&temp->data,&s->data);
            free(temp->right);
            return NULL;
        }    
        else if(temp->right==NULL)
        {
            struct node* s=temp->left;
            swap(&temp->data,&s->data);
            free(temp->left);
            return NULL;
        }    
        else{
            struct node* s=inorderpre(temp);
            swap(&s->data,&temp->data);
            free(s);
            Deletenode(s,data);
        }
    }
}
int main()
{int choice,Data;
    printf("\nEnter 1 to create a node:\nEnter 2 to Delete node:\nEnter 3 to print data:\nEnter 0 to exit:\n");
    do{
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter node data:");
                scanf("%d",&Data);
                insert(root,create(Data));
                break;
            case 2:
                printf("Enter Data to be deleted:");
                scanf("%d",&Data);
                Deletenode(root,Data);
                inorder(root);
                printf("\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 0:
                exit(EXIT_FAILURE);
        }
    }while(choice!=0);
}
