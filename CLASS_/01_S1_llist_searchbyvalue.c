#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
//case 1: Searching the node with a given value;
struct node* SearchbyValue(struct node* head,int value)
{
    struct node *ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        if(ptr->data==value)
        {
            printf("Value found at node:%d",count);
            exit(0);
        }
        ptr=ptr->next;
    }
}
int main()
{
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    struct node* fourth=NULL;


    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=11;
    head->next=second;

    second->data=22;
    second->next=third;

    third->data=33;
    third->next=fourth;

    fourth->data=44;
    fourth->next=NULL;
    head=SearchbyValue(head,11);
}