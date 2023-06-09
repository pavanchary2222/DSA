#include<stdio.h>
void swap(int *a, int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void printarray(int arr[], int n){
 int i=0;
for(i=0;i<n;i++){
printf("%d ",arr[i]);}
}
void maxheap(int arr[],int n, int i)// maxheap==heapify method
{
int largest=i;
int l=2*i+1;
int r=2*i+2;
while(l<n && arr[largest]<arr[l])
	largest=l;
while(r<n && arr[largest]<arr[r])
	largest=r;
if(largest!=i)//changed
{
	swap(&arr[largest],&arr[i]);
	maxheap(arr,n,largest);
}
}

void heapsort(int arr[],int n)
{
	int i;
	for(i=n/2-1;i>0;i--)
		maxheap(arr,n,i);
	for(i=n-1;i>0;i--)
 	{
		swap(&arr[0],&arr[i]);
		
		maxheap(arr,i,0);		
	}
}
int main()
{
	int arr[]={13,11,12,5,6,7};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	heapsort(arr,size);
	
	printarray(arr,size);
}


