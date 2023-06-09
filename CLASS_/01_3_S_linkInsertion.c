#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
/*This function prints all the 
    contents of the list*/
    void Traversal(struct node* n)
    {
        while(n!=NULL)
        {
            printf("%d\n",n->data);
            n=n->next;
        }
    }

    struct node* InsertNOdeFirst(struct node* n,int Data)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        ptr->next=n;
        ptr->data=Data;
        printf("\nSuccessfully Inserted node at first!\n");
        return ptr;
    }

    struct node* InsertAtIndex(struct node* head,int Data,int index)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        struct node* p=head;
        int i=0;
        while(i!=index-1)
        {
           p=p->next;
            i++;
        }
        ptr->data=Data;
        ptr->next=p->next;
        p->next=ptr;  
        printf("\nSuccessfully Inserted node at Index\n");
        return head;
    }
//case: This function prints list in reverse order
    void reverse_list(struct node* p)
    {
        if(p!=NULL)
        {
            reverse_list(p->next);
            printf("%d ",p->data);
        }
        else
            return;
    }

    struct node* InsertAtend(struct node* head,int Data)
    {
        struct node* ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=Data;
        struct node* p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=ptr;
        ptr->next=NULL;
        printf("\nSuccessfully Inserted node at end!\n");
        return head;
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
    head->data=11;//assing data in first node;
    head->next=second;//link first node with second;

    second->data=22;//assign data in second node;
    second->next=third;//link second node to third;

    third->data=33;//assign data in third node;
    third->next=NULL;//pointer point to nothing and store null or making a null pointer;

    int n;
    do{
        printf("\nEnter to edit accordingly\n");
    printf("\nEnter 1 to view data:");
    printf("\nEnter 2 to insert node at first:");
    printf("\nEnter 3 to insert node at index:");
    printf("\nEnter 4 to insert node at end:");
    printf("\nEnter 0 to exit:\n");
    scanf("%d",&n);
    int index;
    switch(n)
    {
        case 1:
            Traversal(head);
            break;
        case 2:
            head=InsertNOdeFirst(head,10);
            break;
        case 3:
            head=InsertAtIndex(head,55,2);
            break;
        case 4:
            head=InsertAtend(head,66);
            break;
        case 5:
            reverse_list(head);
        default:
            exit(EXIT_FAILURE);
    }
    }while(n!=0);

}
