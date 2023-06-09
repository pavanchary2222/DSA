#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
struct node* tail=NULL;
void createnodes(int n)
{
    for( int i=0;i<n;i++)
    {
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        printf("newnode->data=");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
}
void Reversenodes()
{
    struct node* current=head;
    struct node* nextnode=head;
    struct node* prev=NULL;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        current->next=prev;
        prev=current;
        current=nextnode;
    }
    head=prev;
}
void display()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    createnodes(5);
    display();
    Reversenodes();
    display();
}