#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int max;
    int *arr;
};
int isempty(struct stack *s1)
{
    if(s1->top==-1)
        return 1;
    else    
        return 0;
} 

int isfull(struct stack *s1)
{
    if(s1->top==s1->max-1)
        return 1;
    else
        return 0;
}
int push(struct stack *s1,int Data)
{
    if(!isfull(s1))
    {
        s1->top++;
        s1->arr[s1->top]=Data;
        printf("\nSuccess\n");
    }
    else
    {
        printf("\nStack ERROR\n");
    }
}

int pop(struct stack *s1)
{
    int Data;
    if(!isempty(s1))
    {
        Data=s1->arr[s1->top];
        s1->top--;
        return Data;
    }
    else
    {
        printf("\nStack Empty\n");
    }
}
int peek(struct stack *s1)
{
    printf("\nTop Element is %d",s1->arr[s1->top]);
}
int viewlist(struct stack *s1)
{
    while(!isempty(s1))
    {
        int Data;
        Data=pop(s1);
        printf("%d\t",Data);
    }
}
int main()
{
    struct stack *s1 =(struct stack*)malloc(sizeof(struct stack));
    s1->top=-1;
    s1->max=5;
    s1->arr=(int *)malloc(s1->max *sizeof(int));

    push(s1,10);
    push(s1,20);
    push(s1,30);
    push(s1,40);
    peek(s1);
    printf("\n");
    viewlist(s1); 
}