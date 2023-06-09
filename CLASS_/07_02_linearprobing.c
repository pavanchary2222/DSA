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
    if(arr[key]==NULL)
    {
        arr[key]=x;
        printf("Element %d inserted at index:%d\n",x,key);
        flag=1;
    }
    else
    {
        int j=1;
        int hashkey=(key+j)%max;
        while(arr[hashkey]!=NULL)
        {
            j++;
            hashkey=(key+j)%max;
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
        int hashkey=(key+j)%max;
        while(arr[hashkey]!=NULL)
        {
            if(arr[hashkey]==x)
            {
                flag=1;
                linearindex=hashkey;
                break;
            }
            else{
            j++;
            hashkey=(key+j)%max;
            }
        }
    }
    if(flag==1){
        printf("Elemnt %d found at index %d:\n",x,linearindex);
        return linearindex;
    }
    else{
        printf("Element %d not found:\n",x);
        return 0;
    }
}
void delete(int x)
{
    int key=search(x);
    if(key)
    {
        arr[key]=NULL;
        printf("Element %d deleted\n",x);
    }
    else
        printf("Element %d not found to delete:",x);
}

int main()
{
    for(int i=0;i<max;i++)
    {
        arr[i]=NULL;
    }
    insert(2);
    insert(5);
    insert(3);
    insert(33);
    insert(44);
    insert(55);

    printlist();

    search(0);
    search(33);
    search(3);
    search(55);

    delete(55);
    delete(6);
}