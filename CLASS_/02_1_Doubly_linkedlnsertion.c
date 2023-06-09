#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;//This is a head pointer;
    int data;
    struct node* next;//this is a tail pointer;
};

struct node* Traversal(struct node* head)
{
    struct node* p=head;
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
//case 1: Insert node at first
struct node* InsertAtFirst(struct node* head)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    head->prev=p;
    p->prev=NULL;
    p->data=11;
    p->next=head;
    return p;
}
//case 2:insert node at index
struct node* InsertAtIndex(struct node* head,int index)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->data=33;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->prev=p;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
//case 3: Insert node at End;
struct node* InsertAtEnd(struct node* head)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head;
    ptr->data=99;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->prev=p;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
int main()
{
    struct node* first=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));

    first->prev=NULL;
    first->data=10;
    first->next=second;

    second->prev=first;
    second->data=20;
    second->next=third;

    third->prev=second;
    third->data=30;
    third->next=fourth;

    fourth->prev=third;
    fourth->data=40;
    fourth->next=NULL;

    int n;
    do{
        printf("\nEnter to edit accordingly\n");
    printf("\nEnter 1 to view data:");
    printf("\nEnter 2 to insert node at first:");
    printf("\nEnter 3 to insert node at index:");
    printf("\nEnter 4 to insert node at end:");
    printf("\nEnter 0 to exit:\n");
    scanf("%d",&n);
    int index;
    switch(n)
    {
        case 1:
            Traversal(first);//Link Traversal
            break;
        case 2:
            first=InsertAtFirst(first);//This function inserts node before head node;
            break;
        case 3:
            first=InsertAtIndex(first,2);//This function inserts node after a specified index;
            break;
        case 4:
            first=InsertAtEnd(first);//This function inserts node at end ;
    }
    }while(n!=0);
}
