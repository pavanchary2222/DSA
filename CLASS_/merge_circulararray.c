//merging two circular linked list using dual pointers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
};
struct node * head1=NULL;
struct node* tail1=NULL;
struct node* head2=NULL;
struct node* tail2=NULL;
void createnode1(int n)
{
    for(int i=0;i<n;i++)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&ptr->data);
        if(head1==NULL)
        {
            head1=tail1=ptr;
        }
        else
        {
            tail1->next=ptr;
            tail1=ptr;
        }
        ptr->next=head1;
    }
}
void createnode2(int n)
{
    for(int i=0;i<n;i++)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&ptr->data);
        if(head2==NULL)
        {
            head2=tail2=ptr;
        }
        else
        {
            tail2->next=ptr;
            tail2=ptr;
        }
        ptr->next=head2;
    }
}
void merge()
{
    tail1->next=head2;
    tail2->next=head1;
}
void viewlist()
{
    struct node* temp=head1;
    while(temp->next!=head1)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}
int main()
{
    int n1,n2;
    printf("Enter size of list1:");
    scanf("%d",&n1);
    createnode1(n1);
    printf("Enter size of list2:");
    scanf("%d",&n2);
    createnode2(n2);
    printf("Merging two lists:");
    merge();
    viewlist();
}