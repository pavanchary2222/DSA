#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue* next;
};
struct queue* front=NULL;
struct queue* back=NULL;
int isfull()
{
    struct queue *ptr=(struct queue*)malloc(sizeof(struct queue));
    if(ptr==NULL)
        return 1;
    return 0;
}

int isempty()
{
    if(front==NULL||front>back)
        return 1;
    return 0;
}

int enqueue(int value)
{
    struct queue* ptr=(struct queue*)malloc(sizeof(struct queue));
    ptr->data=value;
    ptr->next=NULL;
    if(ptr==NULL)
        printf("!!Queue Full!!\n");
    else
        if(front==NULL)
        {
            front=back=ptr;
            printf("pushed Element:%d\n",ptr->data);
        }
        else   
        {
            back->next=ptr;
            back=ptr;
            printf("pushed Element:%d\n",ptr->data);
        }   
}

int dequeue()
{
    struct queue* p=front;
    int Data=-1;
     if(!isempty())
     {
         front=front->next;
         Data=p->data;
         free(p);
        return Data;
     }
     printf("Queue Underflow:\n");
}

int peek()
{
    printf("Top Element is:%d\n",front->data);
}
int viewlist()
{
    struct queue* p=front;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    printf("\nEnter Accordingly:\n");
    printf("Enter 1 to push element:\n");
    printf("Enter 2 to pop element:\n");
    printf("Enter 3 to peek top element:\n");
    printf("Enter 4 to check if stack overflown:\n");
    printf("Enter 5 to check if stack underflown:\n");
    printf("Enter 6 to viewlist:\n");
    printf("Enter 0 to Exit:\n");
    int choice,Data;
    do{
        printf("\nChoose option:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data:");
            scanf("%d",&Data);
            enqueue(Data);
            break;
        case 2:
            printf("Poped out element:%d\n",dequeue());
            break;
        case 3:
            peek();
            break;
        case 4:
            Data=isfull();
            Data==1?printf("\n!!overflow!!\n"):printf("\n!!Not Yet!!\n");
            break;
        case 5:
            Data=isempty();
            Data==1?printf("\n!!Underflow!!\n"):printf("\n!!Not Yet!!\n");
            break;
        case 6:
            viewlist();
            break;
        default:
            printf("\n!!Error Choose correct option!!\n");
            break;
        }
    }while(choice);
}