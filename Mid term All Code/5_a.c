#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

int* sortEveryThirdElement(int* a, int n) { // Setting the function to sort every third element by taking array a and number n 
    for(int i=2; i<n; i+=3) { // Looping through the array and incrementing by 3 for all cases where i is less than n
        int smallest = a[i]; // Setting the smallest value to the first element in the array
        int smallestValue = i; 
        
        for(int j=i+3; j < n; j += 3) { // Looping through the array and incrementing by 3 for all cases where j is less than n
            if(a[j] < smallest) {      // If the value of the array at j is less than the smallest value
                smallest = a[j];       // Set the smallest value to the value of the array at j
                smallestValue = j;       
            }
        }

        //swap smallest
        if (smallestValue != i) { // Function to swap the smallest value with the first element in the array
            int temp = a[smallestValue]; // Setting a temporary variable to the value of the array at the smallest index
            a[smallestValue] = a[i];     // Setting the value of the array at the smallest index to the value of the array at the first index
            a[i] = temp;

        }
    }

    return a;
}

int main(void) {
    //unsorted array initialization
    int a[] = {6,5,7,8,9,3,4,2,10,12,11};
    int n = sizeof(a)/sizeof(a[0]);

    
    printf("Unsorted array at the start  ");  //printing inital 
    for(int i=0; i<n; i++) { // Looping through the array and printing the values
        printf("%d ", a[i]); // Printing the values of the array
    }
    printf("\n");
    sortEveryThirdElement(a, n);

   
    printf("\nSorted array after the process: "); //printing the sorted array after the process
    for(int i=0; i<n; i++) { // Looping through the array and printing the values
        printf("%d ", a[i]); // Printing the values of the array
    }
    
    printf("\n");
}