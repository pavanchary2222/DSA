#include <stdio.h>
#include <stdlib.h>
struct Edge{
    int data;
    struct Edge *next;
};
struct Vertex{
    int data;
    struct Edge *dataAdress;
    struct Vertex *next;
};
struct Vertex *head,*tail;
struct Edge *createEdge(int data){
    struct Edge *nn=(struct Edge*)malloc(sizeof(struct Edge));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
struct Vertex *createVertex(int data){
    struct Vertex *nn=(struct Vertex*)malloc(sizeof(struct Vertex));
    nn->data=data;
    nn->dataAdress=NULL;
    nn->next=NULL;
    return nn;
}
struct Edge *addVertex(int data){
    struct Vertex *nn=createVertex(data);
    if(head==NULL)
        head=tail=nn;
    else{
        tail->next=nn;
        tail=nn;
    }
    return nn->dataAdress;
}
struct Edge *address(int data){
    struct Vertex *temp=head;
    while(temp!=NULL){
        if(temp->data==data)
            return temp->dataAdress;
        temp=temp->next;
    }
    return addVertex(data);
}
void modifyAddress(int data,struct Edge *nn){
    struct Vertex *temp=head;
    while(temp!=NULL){
        if(temp->data==data){
            temp->dataAdress=nn;
            break;
        }
        temp=temp->next;
    }
}
void insertVertex(struct Edge *head,int startVertex,int endVertex){
    struct Edge *temp=head,*nn=createEdge(endVertex);
    if(head==NULL)
        modifyAddress(startVertex,nn);
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=nn;
    }
}
void addEdge(){
    int startVertex,endVertex;
    printf("enter pair: ");
    scanf("%d%d",&startVertex,&endVertex);
    struct Edge *sVertex=address(startVertex),*eVertex=address(endVertex);
    insertVertex(sVertex,startVertex,endVertex);
    insertVertex(eVertex,endVertex,startVertex);
}
int searchPair(int startVertex,int endVertex){
    struct Edge *temp=address(startVertex);
    while(temp!=NULL){
        if(temp->data==endVertex)
            return 1;
        temp=temp->next;
    }
    return 0;
}
void adjacentMatrix(){
    struct Vertex *temp,*np,*temp1;
    printf("   ");
    for(temp=head;temp!=NULL;temp=temp->next)
        printf("%3d",temp->data);
    printf("\n");
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%3d",temp->data);
        for(np=temp,temp1=head;temp1!=NULL;temp1=temp1->next)
            printf("%3d",searchPair(np->data,temp1->data));
        printf("\n");
    }
}
void adjacentList(){
    struct Vertex *temp;
    for(temp=head;temp!=NULL;temp=temp->next){
        printf("%d ",temp->data);
        for(struct Edge *np=address(temp->data);np!=NULL;np=np->next)
            printf("%d ",np->data);
        printf("\n");
    }
}
void removeEdge(int startVertex,int endVertex){
    struct Edge *temp=address(startVertex),*np;
    if(temp->data==endVertex)
        modifyAddress(startVertex,temp->next);
    else{
        while(temp!=NULL&&temp->data!=endVertex){
            np=temp;
            temp=temp->next;
        }
        if(temp!=NULL){
            np->next=temp->next;
            free(temp);
        }
    }
}
void removeVertex(){
    int vertex;
    printf("enter vertex: ");
    scanf("%d",&vertex);
    struct Vertex *temp=head,*np;
    if(temp->data==vertex)
        head=temp->next;
    else{
        while(temp->data!=vertex){
            np=temp;
            temp=temp->next;
        }
        np->next=temp->next;
    }
    free(temp);
    for(temp=head;temp!=NULL;temp=temp->next){
        removeEdge(temp->data,vertex);
    }
    temp=np=head;
    if(temp->dataAdress==NULL)
        head=temp->next;
    else{
        temp=temp->next;
        while(temp!=NULL){
            if(temp->dataAdress==NULL)
                np->next=temp->next;
            else
                np=temp;
            temp=temp->next;
        }
    }
}
int count(){
    struct Vertex *temp;
    int count=0;
    for(temp=head;temp!=NULL;temp=temp->next)
        count++;
    return count;
}
int check(int arr[],int data,int end){
    for(int i=0;i<=end;i++)
        if(arr[i]==data)
            return 0;
    return 1;
}
void breadthFirstSearch(){
    int queue[count()],i=0,j=0;
    queue[i++]=head->data;
    while(j<count()){
        struct Edge *temp=address(queue[j]);
        while(temp!=NULL){
            if(check(queue,temp->data,i)==1)
                queue[i++]=temp->data;
            temp=temp->next;
        }
        j++;
    }
    for(j=0;j<count();j++)
        printf("%d ",queue[j]);
    printf("\n");
}
void depthFirstSearch(){
    int stack[count()],i=0,j=0;
    stack[i++]=head->data;
    while(i<count()){
        struct Edge *temp=address(stack[j]);
        while(temp!=NULL&&check(stack,temp->data,i)!=1)
            temp=temp->next;
        if(temp!=NULL){
            stack[i++]=temp->data;
            j++;
        }
        else
            j--;
    }
    for(j=0;j<count();j++)
        printf("%d ",stack[j]);
    printf("\n");
}
void display(){
    int n;
    printf("1.Breadth First Search 2.Depth First Search: ");
    scanf("%d",&n);
    switch(n){
        case 1:
            breadthFirstSearch();break;
        case 2:
            depthFirstSearch();break;
        default:
            printf("you entered the wrong number!!!!\n");
    }
}
void main(){
    while(1){
        int n,x,y;
        printf("1.Add Edge 2.Adjacent Matrix 3.Adjacent List 4.Remove Vertex 5.Remove Edge 6.Search Element 7.Display 8.Exit: ");
        scanf("%d",&n);
        if(n==5||n==6){
            printf("enter pair: ");
            scanf("%d%d",&x,&y);
        }
        switch(n){
            case 1:
                addEdge();break;
            case 2:
                adjacentMatrix();break;
            case 3:
                adjacentList();break;
            case 4:
                removeVertex();break;
            case 5:
                removeEdge(x,y),removeEdge(y,x);break;
            case 6:
                searchPair(x,y)==1?printf("element found\n"):printf("element not found\n");break;
            case 7:
                display();break;
            case 8:
                exit(0);
            default:
                printf("you entered the wrong number!!!!\n");
        }
    }
}