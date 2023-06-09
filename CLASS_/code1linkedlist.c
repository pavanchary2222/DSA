#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node*next;
}*head,*tail;
int len;
struct node* createnode(int n)
{
    int i=0;
    while(n--){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL;
    printf("Enter data for node%d:",i+1);
    scanf("%d",&newnode->data);
    
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    len++;
    }
}

void InsertAtFirst()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL;
    printf("Enter data for node:");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else{
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    len++;
}
void InsertAtEnd()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->next=NULL;
    printf("Enter data:");
    scanf("%d",&newnode->data);
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    len++;
}
void InsertAtPostion()
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* pass1=head;
    struct node* pass2=tail;
    newnode->prev=NULL;
    newnode->next=NULL;
    printf("Enter data:");
    scanf("%d",&newnode->data);
    int i=1,pos;
    printf("Enter position:");
    scanf("%d",&pos);
    if(pos==1)
    {
        InsertAtFirst();
    }
    else if(pos==len)
    {
        InsertAtEnd();
    }
    else if(pos<=len/2)
    {
        while(pass1->next!=NULL && i!=pos-1)
        {
            pass1=pass1->next;
            i++;
        }
        newnode->next=pass1->next;
        pass1->next->prev=newnode;
        pass1->next=newnode;
        newnode->prev=pass1;
        len++;
    }
    else{
        while(pass2->prev!=NULL && i!=(len-pos)+1)
        {
            pass2=pass2->prev;
            i++;
        }
        pass2->prev->next=newnode;
        newnode->prev=pass2->prev;
        newnode->next=pass2;
        pass2->prev=newnode;
        len++;
    }
}
void Traversal()
{struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    printf("\t\t\tChoose your choice\n");
    printf("Enter 1 to create nodes:\n");
    printf("Enter 2 to insert at first:\n");
    printf("Enter 3 to insert at position:\n");
    printf("Enter 4 to insert at end:\n");
    int choice,n;
    do{
        printf("enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter no of nodes:");
            scanf("%d",&n);
            createnode(n);
            break;
        case 2:
            InsertAtFirst();
            Traversal();
            break;
        case 3:
            InsertAtPostion();
            Traversal();
            break;
        case 4:
            InsertAtEnd();
            Traversal();
            break;
        default:
            break;
        }
    }while(choice);
}
