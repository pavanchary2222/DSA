#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct priorQueue
{
    int data; //Self Referentail structures
    int priority;
    struct priorQueue* next;
};
struct priorQueue* Front=NULL;//Head pointer to the node...

bool isfull()
{
    struct priorQueue* node=(struct priorQueue*)malloc(sizeof(struct priorQueue));
    if(node==NULL)
        return true;
    return false;
}

bool isempty()
{
    if(Front==NULL)
        return true;
    return false;
}

struct priorQueue* createnode(int Data,int prior)
{
    struct priorQueue* nn=(struct priorQueue*)malloc(sizeof(struct priorQueue));
    if(nn==NULL)
        printf("Queue Full!\n");
    else{
            nn->data=Data;
            nn->priority=prior;
            nn->next=NULL;
            return nn;
    }
}

void penqueue(int Data,int prior)
{
    struct priorQueue* nn=createnode(Data,prior);
    if(Front==NULL || prior<Front->priority)
    {
        nn->next=Front;
        Front=nn;
    }
    else
    {
        struct priorQueue* temp=Front;
        while(temp->next!=NULL&& prior>=(temp->next)->priority)
        {
            temp=temp->next;
        }
        nn->next=temp->next;
        temp->next=nn;
    }
}

int pdequeue()
{
    int Data;
    struct priorQueue* p=Front;
    Front=Front->next;
    Data=p->data;
    free(p);
    return Data;
}
int Traversal()
{
    struct priorQueue* p=Front;
    while(p!=NULL)
    {
        printf("priority=%d Data=%d\n",p->priority,p->data);
        p=p->next;
    }
}
int main()
{
     printf("\nEnter Accordingly:\n");
    printf("Enter 1 to push element:\n");
    printf("Enter 2 to pop element:\n");
    printf("Enter 3 to check if Queue overflown:\n");
    printf("Enter 4 to check if Queue underflown:\n");
    printf("Enter 5 to viewlist:\n");
    printf("Enter 0 to Exit:\n");
    int choice,Data,prior;
    do{
        printf("\nChoose option:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter Data,priority:");
            scanf("%d %d",&Data,&prior);
            penqueue(Data,prior);
            break;
        case 2:
            Data=pdequeue();
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