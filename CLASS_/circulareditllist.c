#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

void Traversal(struct node* head)
{
    struct node* n=head;
    while(n->next!=head)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
    printf("%d\t",n->data);
}
struct node* InsertAtFirst(struct node* head)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=10;
    ptr->next=head;
    return ptr;
}
struct node* InsertAtEnd(struct node * n)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=50;
    struct node* head=n;
    while(n->next!=head)
    {
        n=n->next;
    }
    n->next=ptr;
    ptr->next=head;
    return head;
}
int main()
{
    struct node* first=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=first;

    printf("List before insertion at first\n");
    Traversal(first);
    // printf("List After insertion at first\n");
    // first=InsertAtFirst(first);
    // Traversal(first);
    // printf("List After insertion at Last\n");
    // first=InsertAtEnd(first);
    // Traversal(first);
}