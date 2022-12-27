#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void returnSmallestNum(int* maximumHeap , int n) { // Function to return the smallest number in the max heap
    int minimunElement = INT_MAX; // Setting the minimum element to the maximum value of an integer
    for(int i=n/2; i<n; i++) { // Looping through the array and incrementing by 1 for all cases where i is less than n
        minimunElement = minimunElement < maximumHeap [i] ? minimunElement : maximumHeap [i]; // If the minimum element is less than the value of the array at i, set the minimum element to the minimum element, otherwise set the minimum element to the value of the array at i
    }
    printf("The minimum element is: %d\n", minimunElement); // Printing the minimum element
}



void insertHeapify(int* maximumHeap , int n, int i) {  //Function to  insert value in Heapify 
    int parent = (i-1)/2; // Setting the parent to the value of i minus 1 divided by 2

    while(i > 0) {
        if (maximumHeap [parent] < maximumHeap [i]) {  //swap the valuess of the array at the parent and the array at i
            
            int temp = maximumHeap [parent];         //swap the valuess of the array at the parent and the array at i
            maximumHeap [parent] = maximumHeap [i];
            maximumHeap [i] = temp;
        }
        i = parent;    
        if (maximumHeap [parent] < maximumHeap [i]) { //swap the values of the array at the parent and the array at i
            
            int temp = maximumHeap [parent];
            maximumHeap [parent] = maximumHeap [i]; //swap the values of the array at the parent and the array at i
            maximumHeap [i] = temp;
        }
        parent = (i-1)/2; // Setting the parent to the value of i minus 1 divided by 2
    }
}


//insert element into heap
void insert(int* heap, int* n, int x) { // Function to insert an element into the heap
    int i; // Setting i to an integer
    if(*n==5000) { // If the value of n is equal to 5000
        printf("\nHeap is full"); //    print heap is full
        return; // return
    }
    
    (*n)++; // Increment the value of n by 1

    heap[(*n)-1] = x; // Setting the value of the array at the value of n minus 1 to x

    insertHeapify(heap, *n, (*n)-1); // Calling the insertHeapify function
}

int main() // Running the code 
{
    int heap[5000],n=0; // Setting the heap to have a size of 5000 and setting n to 0

   
    int elementofHeap[] = {957, 671, 541, 824, 467, 357, 498, 786, 482, 213}; // Setting the elements of the heap to the values in the array

    int nth_elementofHeap  = sizeof(elementofHeap)/sizeof(elementofHeap[0]);// Setting the nth element of the heap to the size of the array divided by the size of the array at the first index

    for(int i=0; i<nth_elementofHeap ; i++) { // Looping through the array and incrementing by 1 for all cases where i is less than n
        insert(heap, &n, elementofHeap[i]); // Inserting the elements of the array into the heap
    }

    printf("Max Heap: ");
    for(int i=0; i<n; i++) { // Looping through the array and printing the values
        printf("%d ", heap[i]); // Printing the values of the array
    }
    printf("\n");

    
    returnSmallestNum(heap, n); //printing the smallest element in the maximumHeap 

    return 0;
}