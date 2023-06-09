#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Size 5
int front=-1; 
int rear=-1;
int queue[Size];

bool isfull()
{
    if((rear+1)%Size==front)
        return true;
    return false;
}

bool isempty()
{
    if(front==rear==-1)
        return true;
    return false;
}

int enqueue(int value)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=value;
		printf("Element inserted:%d\n",value);
	}
    else if(!isfull())
    {
        rear=(rear+1)%Size;
        queue[rear]=value;
        printf("Element inserted:%d\n",value);
    }
    else{
        printf("\nQueue Full\n");
    }
}

int dequeue()
{
    int Data;
    if(isempty())
    {
        printf("\n Queue is empty \n");
    }
    else if(front==rear)
    {
        int Data=queue[front];
        front=rear=-1;
        return Data;
    }
    else{
        Data=queue[front];
        front=(front+1)%Size;
        return Data;
    }
}

int Traversal()
{
    if(front==rear==-1)
        printf("Queue is empty:");
    else{
        printf("Queue is:");
        int i=front;
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%Size;
        }
        printf("%d",queue[rear]);
    }
}

int main()
{
     printf("\nEnter Accordingly and the size of queue is %d:\n",Size);
    printf("Enter 1.push 2.pop 3.isfull 4.isempty 5.Traversal:\n");

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
            Data=isfull();
            Data==1?printf("\n!!overflow!!\n"):printf("\n!!Not Yet!!\n");
            break;
        case 4:
            Data=isempty();
            Data==1?printf("\n!!Underflow!!\n"):printf("\n!!Not Yet!!\n");
            break;
        case 5:
            Traversal();
            break;
        default:
            printf("\n!!Error Choose correct option!!\n");
            break;
        }
    }while(choice);
}
