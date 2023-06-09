#include<stdio.h>
#include<stdlib.h>
# define Maxsize 10
int top1=-1;
int top2=-1;
int stack1[Maxsize];
int stack2[Maxsize];
void push(int Data, int stackno){
    if(stackno==1){
        if(top1==Maxsize-1)
            printf("\nStack overflow");
        else
            stack1[++top1]=Data;}
    else{
        if(top2==Maxsize-1)
            printf("\nStack overflow");
        else
            stack2[++top2]=Data;}
}
void Enqueue(int Data, int stackno){
    if(stackno==1){
        push(Data,1);
    }
    else{
        push(Data,2);
    }
}
int pop(int stackno){
    if(stackno==1){
        if(top1<0)
            printf("Stack underflow:");
        else
            return stack1[top1--];}
    else{
        if(top2<0)
            printf("Stack underflow");
        else
            return stack2[top2--]; }
}
void Dequeue(){
    while(top1>0){
        push(pop(1),2);
    }
    if(top1<0)
        printf("Queue undeflow:");
    else
        printf("Dequeued front element:%d",pop(1));
    while(top2>=0){
        push(pop(2),1);
    }
}
void Display()
{
    int i=0;
    while(i<=top1)
        printf("%d ",stack1[i++]);
    printf("\n");
}
int main()
{
    int choice,Data;
    
    do{
        printf("\n1.Enqueue 2.Dequeue 3.display 4.exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter data into queue:");
            scanf("%d",&Data);
            Enqueue(Data,1);
            break;
        case 2:
            Dequeue();
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