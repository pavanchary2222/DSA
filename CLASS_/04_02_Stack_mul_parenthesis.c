#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    char *arr;
    int size;
};

int isempty(struct stack* ptr)
{
    if(ptr->top==-1)
        return 1;
    return 0;
}

int isfull(struct stack* ptr)
{
    if(ptr->top==ptr->size-1)
        return 1;
    return 0;
}

void push(struct stack* ptr,char val)
{
    if(!isfull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top]==val;
        printf("pushed:%c\n",val);
    }
    else{
        printf("Stack Overflow!! Cannot push the element:");
    }
}
int pop(struct stack * ptr)
{
    char val;
    if(!isempty(ptr))
    {
        return ptr->arr[ptr->top--];
    }
    else 
        printf("can't pop\n");
}
int ismatched(char a,char b)
{
    if(a=='(' && b==')')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='[' && b==']')
        return 1;
}
int parenthesis_match(char *exp)
{
    struct stack* sp;
    sp->top=-1;
    sp->size=strlen(exp);
    sp->arr=(char*)malloc(sizeof(char)*sp->size);

    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(sp,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(isempty(sp)){
                return 0;
            }
            if(!ismatched(pop(sp),exp[i]))
            {
                return 0;
            }
        }
    }
    if(isempty(sp)){
        return 1;
    }
    else{
    return 0;
    }
}
int main()
{
    char *exp="((8)[{(9-8)})";
    if(parenthesis_match(exp))
        printf("Parenthesis is balanced:\n");
    else
        printf("Parenthesis is not balanced:\n");
}