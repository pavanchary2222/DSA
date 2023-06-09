#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* Traversal(struct node* n)
{
    while(n!=NULL)
    {
        printf("%d\n",n->data);
        n=n->next;
    }
}
//case 1: deletnig the index at first from the given list
struct node* deleteAtFirst(struct node* head)
{
    struct node* p=head;
    head=head->next;
    free(p);
    return head;
}
//case 2: deleting the eleent at given index from the given list
struct node* deleteAtIndex(struct node* head,int index)
{
    struct node* p=head;
    struct node* q=p->next;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);
    return head;
}
//case 3: deleting node at end
struct node* deleteAtEnd(struct node* head)
{
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
//case 4: Deleting the node with index and given value;
struct node* deletewithvalue(struct node* head,int value)
{
    struct node* p=head;
    struct node* q=p->next;
    while(q->next!=NULL && q->data!=value)
    {
        p=p->next;
        q=q->next;
    }
   if(q->data==value)
   {
       p->next=q->next;
       free(q);
   }
    return head;
}
int main()
{
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    struct node* four=NULL;


    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    four=(struct node*)malloc(sizeof(struct node));

    head->data=11;
    head->next=second;

    second->data=22;
    second->next=third;

    third->data=33;
    third->next=NULL;

    four->data=44;
    four->next=NULL;
    //head=deleteAtFirst(head);//deletion at first;
    //head=deleteAtIndex(head,1);//deletion i between;
    //head=deleteAtEnd(head);
    head=deletewithvalue(head,11);
    Traversal(head);
}