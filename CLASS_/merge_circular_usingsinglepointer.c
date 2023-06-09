//merging two circular linked list using single pointer 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
};
struct node* tail1=NULL;
struct node* tail2=NULL;
void createnode1(int n)
{
    for(int i=0;i<n;i++)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&ptr->data);
        if(tail1==NULL)
        {
            tail1=ptr;
            tail1->next=ptr;
        }
        else
        {
            ptr->next=tail1->next;
            tail1->next=ptr;
            tail1=ptr;
        }
    }
}
void createnode2(int n)
{
    for(int i=0;i<n;i++)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        printf("Enter node data:");
        scanf("%d",&ptr->data);
        if(tail2==NULL)
        {
            tail2=ptr;
            tail2->next=ptr;
        }
        else
        {
            ptr->next=tail2->next;
            tail2->next=ptr;
            tail2=ptr;
        }
    }
}
void merge()
{
    struct node* temp1=tail1->next;
    tail1->next=tail2->next;
    tail2->next=temp1;
}
void viewlist()
{
    struct node* head=tail2->next;
    do
    {
        printf("%d ",head->data);
        head=head->next;
    }while(head->next!=tail2->next);
    printf("%d\n",head->data);
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
