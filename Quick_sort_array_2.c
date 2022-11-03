// Code to perform QUICK SORT ON AN ARRAY

#include <stdio.h> 
#include <stdlib.h>


//*****************************************
int partition(int *Main_array, int start, int end){ // Function to partition the array  
    int pivot = Main_array[end]; // Taking the last element as pivot
    int partition_position_index = start; // Setting the pivot index to the start of the array
    for (int counter = start; counter < end; counter++){ // Looping through the array
        if(Main_array[counter] <= pivot){ // If the element is less than the pivot
            int temp = Main_array[counter]; // Swapping the element with the pivot index
            Main_array[counter] = Main_array[partition_position_index]; 
            Main_array[partition_position_index] = temp; 
            partition_position_index++; // incrementing the pivot index
        }
    }
    int temp = Main_array[partition_position_index]; // Swapping the pivot with the pivot index
    Main_array[partition_position_index] = Main_array[end];
    Main_array[end] = temp;

    return partition_position_index; // Returning the pivot index
}

//*****************************************

//Quicksort for an array 

//*****************************************
void quickSort(int *Main_array, int start, int end){ // Function to perform quick sort
    if(Main_array && start < end){                   // If the array is not empty and the start is less than the end
        int partition_position_index = partition(Main_array, start, end); // Partitioning the array
        quickSort(Main_array, start, partition_position_index-1);         // Recursively calling the quick sort function for first half
        quickSort(Main_array, partition_position_index+1, end);           // Recursively calling the quick sort function for second half
    }
}

//*****************************************

// Runnig the function to check if quick sort is working on a sample array
void main(){
    int Main_array[] = {53,35, 24, 67, 45, 35, 86, 34}; //  Array to be sorted
    int n = sizeof(Main_array)/sizeof(Main_array[0]); // Finding the size of the array
    quickSort(Main_array, 0, n-1);         // Calling the quick sort function
    for (int counter = 0; counter < n; counter++){ // Printing the sorted array
        printf("%d ", Main_array[counter]); // Printing the sorted array
    }
}


//***********************************************

// Code END

//***********************************************