#include<stdio.h>
#include<stdlib.h>
# define Maxsize 10
int front1=-1;
int rear1=-1;
int front2=-1;
int rear2=-1;
int Queue1[Maxsize];
int Queue2[Maxsize];

void Enqueue(int Data, int Queueno)
{
    if(Queueno==1){ 
        if(rear1==Maxsize-1)
            printf("Stack Overflow1\n");
        else{
            front1=0;
            Queue1[++rear1]=Data;
        }
    }
    else{
        if(rear2==Maxsize-1)
            printf("Stack Overflow2\n");
        else{
            front2=0;
            Queue2[++rear2]=Data;
        }
    }
}
int Dequeue(int Queueno)
{ 
    if(Queueno==1){
        if(front1>rear1||front1==-1)
            printf("Stack Underflow1\n");
        else
            return Queue1[front1++];
    }
    else{
        if(front2>rear2||front2==-1)
            printf("Stack Underflow2\n");
        else
            return Queue2[front2++];
    }
}
void push(int Data, int Queueno){
    if(Queueno==1)
        Enqueue(Data,1);
    else
        Enqueue(Data,2);
}
void pop(){
    if(front1!=rear1){//if more than one elements are there in the Queue
        while(front1<rear1){
            Enqueue(Dequeue(1),2);}
        printf("popped out element:%d\n",Dequeue(1));
        front1=rear1=-1;
        while(front2<=rear2){
        Enqueue(Dequeue(2),1);    
    }
    front2=rear2=-1;
    }
    else{
        if(front1==rear1==-1){
        printf("popped out element:%d\n",Dequeue(1));
        front1=rear1=-1;
        }
        else{
        printf("popped out element:%d\n",Dequeue(1));
        front1=rear1=-1;
        }
    }
}
void Display()
{
    int i=rear1;
    while(i)
        printf("%d ",Queue1[i--]);
    printf("%d",Queue1[i]);
    printf("\n");
}
int main(){
    int choice,Data;
    do{
        printf("1.push 2.pop 3.Display 4.Exit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data into the queue:");
            scanf("%d",&Data);
            push(Data,1);
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        default:
            exit(EXIT_FAILURE);
            break;
        }
    }while(choice);
}