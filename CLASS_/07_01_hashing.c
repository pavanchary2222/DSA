#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
int arr[max];
void printlist()
{
    int length=strlen(arr);
    for(int i=1;i<=length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insert(int x)
{
    int key=x%max;
    arr[key]=x;
    printf("Inserted at index %d:\n",key);
}
int search(int x)
{
    int key=x%max;
    if(arr[key]==x)
    {
        printf("Element found at index:%d\n",key);
    }
    else
    {
        printf("Element not found:");
    }
}
int main()
{
    int key;
    insert(2);
    insert(5);
    insert(3);
    insert(4);
    insert(1);
    insert(8);
    insert(7);
    insert(6);

    printlist();


    search(5);
    search(6);
    search(7);
}