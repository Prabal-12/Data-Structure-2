#include <stdio.h>

 void heapify(int a[],int n,int i)  //heapify function
 {
    int max = i; // Initialize max as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2
    int temp=0;   //temp variable for swapping
      
    if (left < n && a[left] > a[max]) // If left child is larger than root 
    {
        max = left;
    }
    if (right < n && a[right] > a[max]) //if the right child is larger than root
    {
        max = right; //then make the right child as the root
    }
    if (max != i)
    {
        temp = a[i]; //swap the root with the largest child
        a[i] = a[max]; //swap the root with the largest child
        a[max] = temp;  //  swap the root with the largest child
        
        heapify(a,n,max);
    }
}
  
void heapSort(int a[], int n) //heap sort function 
{
    int temp=0; //temp variable for swapping
    
    for (int i = n/2-1;i >= 0;i--) // Build heap (rearrange array)
    {
        heapify(a,n,i);
    }
        
    for (int i = n - 1; i >= 0; i--) // One by one extract an element from heap
    {
        temp = a[0]; //swap the root with the largest child
        a[0] = a[i]; //swap the root with the largest child
        a[i] = temp; //swap the root with the largest child
        
        heapify(a,i,0); // call max heapify on the reduced heap
    }
}

void thirdLargestNum(int *maxHeap, int n) // Function to find the third largest number in the heap
{
    heapSort(maxHeap,n); //sort the array using heap sort
    printf("\n Third Largest value of the Heap: %d", maxHeap[n-3]);//printing the third largest number
}

int main() 
{
    int a[] = {957, 671, 541, 824, 467, 357, 498, 786, 482, 213}; // Setting the elements of the heap to the values in the array
    int n = sizeof(a)/sizeof(a[0]); // Setting the nth element of the heap to the size of the array divided by the size of the array at the first index
  
    heapSort(a, n); // Calling the heapSort function
  
    printf("Max Heap: "); // Printing the max heap
    
    for(int i=0;i<n;i++) // Looping through the array and printing the values 
    {
        printf("%d ",a[i]); // Printing the values of the array
    }
    
    int maxHeap[n]; // Setting the max heap to the size of the array
    
    for(int i=0;i<n;i++) // Looping through the array and incrementing by 1 for all cases where i is less than n
    {
        maxHeap[i] = a[i]; // Setting the max heap to the values of the array
    }
    
    thirdLargestNum(maxHeap, n); // Calling the thirdLargestNum function
    
    return 0;
}