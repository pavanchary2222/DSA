#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void printlist(struct node* head)
{
    struct node* n=head;
    while(n->next!=head)
    {
        printf("%d\n",n->data);
        n=n->next;
    }
    printf("%d",n->data);
}
int main()
{
    struct node* first=(struct node*)malloc(sizeof(struct node));//assinging and allocating memory using malloc done at once
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));//malloc allocates a single block of memory 

    first->data=10;
    first->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=first;

    printlist(first);
}