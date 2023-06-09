#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    //char *name;
    struct node* next;
};
//case: This function prints list in reverse order
    void reverse_list(struct node* p)
    {
        if(p!=NULL)
        {
            reverse_list(p->next);
            printf("%d ",p->data);
            //printf("%s;",p->name);
        }
        else
            return;
    }
int main()
{

    //step-1-> creating struture pointers and assigning null; allocates memory in heap
    struct node* first=NULL;
    struct node* second=NULL;
    struct node* third=NULL;
    //step 2-> allcating memory for the null pointers dynamically using malloc;
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    //when malloc is used it allocates a sinlge block of memory that returns void pointer;
    first->data=1;//assing data in first node;
    //strcpy(first->name,"Chotabheem");
    first->next=second;//link first node with second;

    second->data=2;//assign data in second node;
    //strcpy(second->name,"chutki");
    second->next=third;//link second node to third;

    third->data=3;//assign data in third node;
    //strcpy(third->name,"raju");
    third->next=NULL;//pointer,point to nothing and store null;
    reverse_list(first);
    return 0;
}
