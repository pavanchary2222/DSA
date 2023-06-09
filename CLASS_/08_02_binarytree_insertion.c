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
void Traversal(struct node* temp)
{
    if(temp!=NULL)
    {
        printf("%d ",temp->data);
        Traversal(temp->left);
        Traversal(temp->right);
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
int main()
{
    insert(root,create(11));
    insert(root,create(10));
    insert(root,create(12));
    insert(root,create(9));
    insert(root,create(15));
    insert(root,create(8));
    insert(root,create(17));
    insert(root,create(7));
    insert(root,create(13));

    //printnodes(root);
    Traversal(root);
}