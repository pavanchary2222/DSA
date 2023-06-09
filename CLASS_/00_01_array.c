#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,k,size=5,arr[100];
    printf("Enter elements into the array:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("array data before insertion:\t");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }

    for(i=size;i>0;i--)
    {
        arr[size+1]=arr[i];
    }
    arr[0]=10;
    size++;
    printf("array data After insertion:\t");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}