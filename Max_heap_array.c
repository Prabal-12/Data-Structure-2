//Code for array implementation of max heap

#include <stdio.h>
#include <stdlib.h>

//************************************************
//heapify function to heapify the tree
void heapify(int *a, int n, int Index){
    //initialise largest as root
    int largest = Index; //largest is the index of the current Index
    int left = 2*Index+1; //left child index = 2*Index+1
    int right = 2*Index+2; //right child index = 2*Index+2

    //checkig of the left child node is larger than root index value, if true then set largest to left
    if(left < n && a[left] < a[largest]){ //if left child is smaller than root, set largest to left
        largest = left; //largest is the index of the left child
    }

    //check if the right child node is larger than root index value, if true then set largest to right
    if(right < n && a[right] < a[largest]){ 
        largest = right; //largest is the index of the right child
    }

 
    if(largest != Index){ //if largest is not the root, swap and heapify
        int temp_holder = a[Index]; //swap the root with the largest
        a[Index] = a[largest]; //swap the root with the largest
        a[largest] = temp_holder; //swap the root with the largest
        heapify(a, n, largest); //heapify the subtree
    }
}

//************************************************
void Max_heap(int *a, int n){ //n is the size of the array
    for(int i = n/2-1; i>=0; i--){ //start with the first non-leaf node and work up
        heapify(a, n, i); //heapify the tree
    }

    for(int i = 0; i<n; i++){ //print the heap
        printf("%d ", a[i]); // print the heap
    }
}

//************************************************


// Runing the program to check if the Max heaps  works correctly
int main(){ 
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; //array to be sorted
    int n = sizeof(a)/sizeof(a[0]); //size of the array
    Max_heap(a, n);   //build the max heap
    return 0; 
}

//************************************************

// Code Ends

//************************************************


