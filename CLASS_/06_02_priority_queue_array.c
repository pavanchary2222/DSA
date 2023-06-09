#include <stdio.h>
#include<stdlib.h>
#include<conio.h>

// Structure for the elements in the
// priority queue
struct pqueue {
	int value;
	int priority;
};

// Store the element of a priority queue
struct pqueue pq[100000];

// Pointer to the last index
int size = -1;

// Function to insert a new element
// into priority queue
void penqueue(int value, int priority)
{
	// Increase the size
	size++;

	// Insert the element
	pq[size].value = value;
	pq[size].priority = priority;
}

// Function to check the top element
int peek()
{
	int highestPriority = 0;
	int ind = -1;

	// Check for the element with
	// highest priority
	for (int i = 0; i <= size; i++) {

		// If priority is same choose
		// the element with the
		// highest value
		if (highestPriority == pq[i].priority && ind > -1 && pq[ind].value< pq[i].value) 
		{
			highestPriority = pq[i].priority;
			ind = i;
		}
		else if (highestPriority> pq[i].priority) 
		{
			highestPriority = pq[i].priority;
			ind = i;
		}
	}

	// Return position of the element
	return ind;
}

// Function to remove the element with
// the highest priority
void pdequeue()
{
	// Find the position of the element
	// with highest priority
	int ind = peek();

	// Shift the element one index before
	// from the position of the element
	// with highest priority is found
	for (int i = ind; i < size; i++) {
		pq[i] = pq[i + 1];
	}

	// Decrease the size of the
	// priority queue by one
	size--;
}

// Driver Code
int main()
{
	// Function Call to insert elements
	// as per the priority
	penqueue(10, 2);
	penqueue(14, 4);
	penqueue(16, 4);
	penqueue(12, 3);

	// Stores the top element
	// at the moment
	int ind = peek();

	printf("%d\n",pq[ind].value);

	// Dequeue the top element
	pdequeue();

	// Check the top element
	ind = peek();
	printf("%d\n",pq[ind].value);

	// Dequeue the top element
	pdequeue();

	// Check the top element
	ind = peek();
	printf("%d\n",pq[ind].value);
	return 0;
}
// int main()
// {
//      printf("\nEnter Accordingly:\n");
//     printf("Enter 1 to push element:\n");
//     printf("Enter 2 to pop element:\n");
// 	printf("Enter 3 to peek:\n");
//     printf("Enter 0 to Exit:\n");
//     int choice,Data,prior;
//     do{
//         printf("\nChoose option:");
//         scanf("%d",&choice);
//         switch (choice)
//         {
//         case 1:
//             printf("Enter Data,priority:");
//             scanf("%d %d",&Data,&prior);
//             penqueue(Data,prior);
//             break;
//         case 2:
//             pdequeue();
//             break;
// 		case 3:
// 			Data=peek();
// 			printf("%d\n",pq[Data].value);
// 			break;
//         default:
//             printf("\n!!Error Choose correct option!!\n");
//             break;
//         }
//     }while(choice);
// }