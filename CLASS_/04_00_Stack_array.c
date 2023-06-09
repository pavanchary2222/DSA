#include<stdio.h>
#include<stdlib.h>
int MAXSIZE=8;
int Stack[8];
int top =-1;

int isfull()
{
    if(top==MAXSIZE)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int push(int data)
{
    if(!isfull())
    {
        top=top+1;
        Stack[top]=data;
        printf("\nSuccess\n");
    }
    else
    {
        printf("\nError!!\n");
    }
}

int pop()
{
    int Data;
    if(!isempty())
    {
        Data=Stack[top];
        top=top-1;
        return Data;
    }
    else
        printf("\nERROR!! Retreiving data:\n");
}
int peek()
{
    printf("Top element:%d\n",Stack[top]);
}
int viewlist()
{
    while(!isempty())
    {
        int data;
        data=pop();
        printf("%d\t",data);
    }
}

int main()
{
    int choice;
    do
    {
        printf("\nSelect  Accordingly\n");
        printf("Enter 1 insert top:\n");
        printf("Enter 2 to pop top element:\n");
        printf("Enter 3 to peek top element:\n");
        printf("Enter 4 to view the list:\n");
        printf("Enter 0 to exit\n");
        int Data;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("Enter Data:");
                scanf("%d",&Data);
                push(Data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                viewlist();
                break;
            default:
                printf("\t\t****CASE ERROR Choose correct option!!****");
        }
    }while(choice!=0);
}