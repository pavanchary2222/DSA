//Doubly linked list 

#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* Traversal(struct node* n)
{

	while(n!=NULL)
	{
	printf("%d\n",n->data);
	n=n->next;
	}
}
//case 1: Deletes the node with specified value;
struct node* Deletewithvalue(struct node* head,int value)
{
	int i=0;
	struct node* p=head;
	struct node* q=head->next;
	if(p->data==value)
	{	q->prev=NULL;
		free(p);
		return q;
	}
	else{
	
		while(q->data!=value && q->next!=NULL)
		{
		p=p->next;
		q=q->next;
		}
		if(q->data==value)
		{
		p->next=q->next;
		free(q);
		}
	return head;
	}
}

//case 2: delete the last node;
struct node* DeleteAtEnd(struct node* head)
{
	struct node* p=head;
	struct node* q=head->next;
	while(q->next!=NULL)
	{
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return head;
}
	
int main()
{
	struct node* head=NULL;
	struct node* second=NULL;
	struct node* third=NULL;
	struct node* fourth=NULL;
	
	//allocating memery to the pointers;
	head=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	third=(struct node*)malloc(sizeof(struct node));
	fourth=(struct node*)malloc(sizeof(struct node));
	
	head->prev=NULL;
	head->data=10;
	head->next=second;
	
	second->prev=head;
	second->data=20;
	second->next=third;
	
	third->prev=second;
	third->data=30;
	third->next=fourth;
	
	fourth->prev=third;
	fourth->data=40;
	fourth->next=NULL;
	
	//head=Deletewithvalue(head,40);
	head=DeleteAtEnd(head);
	Traversal(head);//This function prints all the list in a linked list;
	
	
}
