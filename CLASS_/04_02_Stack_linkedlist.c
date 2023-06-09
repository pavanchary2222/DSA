#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
int isfull()
{
    struct stack *n=(struct stack*)malloc(sizeof(struct stack));
    if(n==NULL)
        return 1;
    else
        return 0;
}
int isempty(struct stack *tp)
{
    if(tp==NULL)
        return 1;
    else
        return 0;
}

struct stack* push(int Data)
{
    if(!isfull())
    {
        struct stack* ptr=(struct stack*)malloc(sizeof(struct stack));
        ptr->next=top;
        ptr->data=Data;
        top=ptr;
        printf("Element pushed:%d\n",Data);
    }
    else
        printf("\nStack Overflow\n");
}
struct stack* pop(struct stack *tp)
{
    int Data;
    if(!isempty(tp))
    {
        struct stack* n=tp;
        Data=tp->data;
        top=tp->next;
        free(n);
        printf("\nELement poped:%d\n",Data);
    }
    else
        printf("\nUnderflow\n");
}
struct stack* Traversal(struct stack* n)
{
    while(n!=NULL)
    {
        printf("%d\t",n->data);
        n=n->next;
    }
}
int peek(int pos)
{
    struct stack *tp=top;
    for(int i=0;(i<pos-1 && tp!=NULL);i++)
    {
        tp=tp->next;
    }
    printf("\nElement at positon %d is %d\n",pos,tp->data);
}
int main()
{
    push(10);
    push(20);
    push(30);
    printf("\nList After pushing:");
    Traversal(top);
    peek(3);
    pop(top);
    pop(top);
    printf("\nList After Poping:");
    Traversal(top);
}