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
//case 1: Delete node at first
struct node* DeleteAtFirst(struct node* head)
{
    struct node* p=head;
    head=head->next;
    head->prev=NULL;
    free(p);
    return head;
}
//case 2:Delete node at index
struct node* DeleteAtIndex(struct node* head,int index)
{
    struct node* p=head;
    struct node* q=head->next;
    int i=1;
    while(i!=index-1)
    {
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    (q->next)->prev=p;
    free(q);
    return head;
}
//case 3: Delete node at End;
struct node* DeleteAtEnd(struct node* head)
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
        printf("\n\t\t\tEnter to Delete accordingly\t\t\t\n");
    printf("\nEnter 1 to view data:");
    printf("\nEnter 2 to Delete node at first:");
    printf("\nEnter 3 to delete node at index:");
    printf("\nEnter 4 to delete node at end:");
    printf("\nEnter 5 to delete node with given value:");
    printf("\nEnter 0 to exit:\n");
    scanf("%d",&n);
    int index;
    switch(n)
    {
        case 1:
            Traversal(first);//Link Traversal
            break;
        case 2:
            first=DeleteAtFirst(first);//This function deletes node before head node;
            break;
        case 3:
            first=DeleteAtIndex(first,2);//This function deletes node after a specified index;
            break;
        case 4:
            first=DeleteAtEnd(first);//This function deletes node at end;
        /*case 5:
            first=Deletewithvalue(first);//This function deletes the node with a given value;*/
    }
    }while(n!=0);
}
