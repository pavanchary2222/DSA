#include<stdio.h>
#include<stdlib.h>
int Maxsize=100;
int front=-1;
int back=-1;
int arr[100];
int isfull()
{
    if(back==Maxsize-1)
        return 1;
    return 0;
}

int isempty()
{
    if(front==-1|| front >= back)
        return 1;
    else
        return 0;
}

int enqueue(int value)
{
    if(!isfull())
    {
        back++;
        arr[back]=value;
        printf("pushed element:%d\n",value);
    }
    else
    {
        printf("\n!!Queue Overflow!!\n");
    }
}
int dequeue()
{
    if(!isempty())
    {
        front++;
        return arr[front];
    }
    printf("\n!!Queue Underflow!!\n");
}

int peek()
{
    if(!isempty())
        printf("Top Element:%d\n",arr[front+1]);
    else
        printf("\n!!queue empty!!\n");
}
void viewlist()
{
    while(!isempty())
    {
        printf("%d ",dequeue());
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
            Data=dequeue();
            printf("Poped out element:%d\n",Data);
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