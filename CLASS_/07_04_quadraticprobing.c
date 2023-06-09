//Linear probing in hashing
#include<stdio.h>
#include<string.h>
#define max 10
int arr[max];
void printlist()
{
    for(int i=1;i<=max;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insert(int x)
{
    int key=x%max,flag=0;
    if(arr[key]=='\0')
    {
        arr[key]=x;
        printf("Element %d inserted at index:%d\n",x,key);
        flag=1;
    }
    else
    {
        int j=1;
        int hashkey=(key+j*j)%max;
        while(arr[hashkey]!='\0')
        {
            j++;
            hashkey=(key+j*j)%max;
        }
        arr[hashkey]=x;
        printf("Element %d inserted at index:%d\n",x,hashkey);
    }
}
int search(int x)
{
    int key=x%max,flag=0,linearindex=0;
    if(arr[key]==x)
    {
        linearindex=key;
        flag=1;
    }
    else
    {
        int j=1;
        int hashkey=(key+j*j)%max;
        while(arr[hashkey]!='\0')
        {
            if(arr[hashkey]==x)
            {
                flag=1;
                linearindex=hashkey;
                break;
            }
            else{
            j++;
            hashkey=(key+j*j)%max;
            }
        }
    }
    if(flag==1){
        printf("Elemnt %d found at index %d:\n",x,linearindex);
        return linearindex;
    }
    else{ 
        printf("Elemnt not found:\n");
        return 0;
    }
}
void delete(int x)
{
    int key=search(x);
    if(key)
    {
        int data=arr[key];
        arr[key]='\0';
        printf("Element %d deleted\n",data);
    }
    else
        printf("Element not found to delete:");
}

int main()
{
    for(int i=0;i<max;i++)
    {
        arr[i]='\0';
    }
    insert(2);
    insert(5);
    insert(3);
    insert(33);
    insert(44);
    insert(55);

    printlist();

    search(5);
    search(33);
    search(3);
    search(55);

    delete(55);

    printlist();
}