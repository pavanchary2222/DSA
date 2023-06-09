#include<stdio.h>
#include<stdlib.h>
struct circular
{
    int data;
    struct circular* next;
};
struct circular* tail1=NULL;
struct circular* tail2=NULL;
void createnode(int n)
{
	int i;
    for(i=0;i<n;i++)
    {
        struct circular* ptr=(struct circular*)malloc(sizeof(struct circular));
        printf("Enter node data:");
        scanf("%d",&ptr->data);
        ptr->next=NULL;
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
struct circular* splitnode(int Data)
{
    struct circular* temp1=tail1->next;
    struct circular* temp2=temp1->next;
    while(temp1->next!=tail1->next && temp1->next->data!=Data)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    temp1->next=tail1->next;
    tail1->next=temp2;
    tail2=tail1;
    tail1=temp1;
}

void viewlist(struct circular* temp)
{
    struct circular* temp1=temp;
    while(temp1->next!=temp)
    {
        printf("%d ",temp1->data);
        temp1=temp1->next;
    }
    printf("%d",temp1->data);
    printf("\n");
}
  
int main()
{
    int n1,element;
    printf("Enter no of nodes to create:");
    scanf("%d",&n1);
    createnode(n1);
    printf("Enter data at split:");
    scanf("%d",&element);
    splitnode(element);
    printf("circular list no 1:");
    viewlist(tail1->next);
    printf("circular list no 2:");
    viewlist(tail2->next);
}
