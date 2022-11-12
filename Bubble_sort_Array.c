// C program for implementation of Bubble sort
#include <stdio.h>

void swap(int* xp, int* yp) \\ Function to swap the content of two integers
{
    int temp = *xp;       \\ Store the value pointed by xp in temp
    *xp = *yp;             \\ Copy the value pointed by yp to xp
    *yp = temp;             \\ Copy the value stored in temp to yp
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n) \\ Function to sort an array of integers of size n
{
    int i, j;
    for (i = 0; i < n-1; i++) \\ Loop for n-1 passes

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) \\ Loop for n-i-1 passes
            if (arr[j] > arr[j+1]) \\ If the element at j is greater than the element at j+1
                swap(&arr[j], &arr[j+1]); \\ Swap the elements
}

/* Function to print an array */
void printArray(int arr[], int size) \\ Function to print an array of integers of size n
{
    int i;
    for (i=0; i < size; i++) \\ Loop for size passes
        printf("%d ", arr[i]); \\ Print the element at i
    printf("n");
}


// Driver program to test above functions
int main() \\ Main function
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; \\ Array of integers
    int n = sizeof(arr)/sizeof(arr[0]); \\ Size of the array
    bubbleSort(arr, n); \\ Call the bubbleSort function
    printf("Sorted array: n"); \\ Print the sorted array
    printArray(arr, n); \\ Call the printArray function
    return 0; \\ Return 0
}
