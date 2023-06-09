#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
/*This function prints all the 
    contents of the list*/
    void view(struct node* n)
    {
        while(n!=NULL)
        {
            printf("%d\n",n->data);
            n=n->next;
        }
    }

    void insert(struct node* n)
    {
        while(n!=NULL)
        {
            printf("Enter %u data:",n);
            scanf("%d",&n->data);
            n=n->next;
        }
    }

    void DLet(struct node* n)
    {
        int Node;
        printf("\nEnter node to delete:");
        scanf("%d",&Node);
        while(n==Node)
        {
            n->data=0;
            n->next=NULL;
            (n-(sizeof(struct node)))->next=NULL;
            break;
        }
    }

    int InsertNOdeFirst(struct node* n,int Data)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        ptr->next=n;
        ptr->data=Data;
        return ptr;
    }

    int InsertAtIndex(struct node* n,int Data,int Index)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node*));
        struct node *p=n;
        int i=0;
        while(i!=Index-1)
        {
            p=p+(i+1);
            i++;
        }
            ptr->next=p->next;
            p->next=ptr;
            ptr->data=Data;
    }
int main()
{
    //step-1-> creating struture pointers and assigning null; allocates memory in heap
    struct node* head=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    //step 2-> allcating memory for the null pointers dynamically using malloc;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    //when malloc is used it allocates a sinlge block of memory that returns void pointer;
    head->data=0;//assing data in first node;
    head->next=second;//link first node with second;

    second->data=0;//assign data in second node;
    second->next=third;//link second node to third;

    third->data=0;//assign data in third node;
    third->next=NULL;//pointer point to nothing and store null or making a null pointer;

    int n;
    do{
        printf("\nTO manupulate press accordingly:\n");
    printf("\nEnter 1 to insert data");
    printf("\nEnter 2 to delte data");
    printf("\nEnter 3 to view the data:");
    printf("\nEnter 4 to Insert a Node at first:");
    printf("\nEnter 5 to insert a Node in between:");
    printf("\nEnter 0 to exit:\t");
    scanf("%d",&n);
    int Data,Index;
    switch(n)
    {
        case 1:
            insert(head);
            break;
        case 2:
            DLet(head);
            break;
        case 3:
            view(head);
            break;
        case 4:
            printf("\nEnter first node data:");
            scanf("%d",&Data);
            head=InsertNOdeFirst(head, Data);
            break;
        case 5:
            printf("Enter data at Index Node:");
            scanf("%d",&Data);
            InsertAtIndex(head,Data,Index);
            break;
    }
    }while(n!=0);
    return 0;
}