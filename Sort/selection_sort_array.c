// Performing selection sort in array
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// function for generating an array for n elements
int * generateArray(int n){
    int *array = malloc(n*sizeof(int)); // allocate memory for array
    for(int i=0; i<n; i++){ // loop for n times
        array[i] = rand()%100; // assign random data to array[i]
    }
    return array; // return array
}
// function for printing an array
void printArray(int *array, int n){ // array and size of the array
    for(int i=0; i<n; i++){ // loop for n times
        printf("%d ", array[i]); // print array[i]
    }
}

// function for selection sort
void selectionSort(int *array, int n){ // array and size of the array
    int lower, tempholder; // declare lower and tempholder
    for(int i=0; i<n-1; i++){ // loop for n-1 times
        lower = i; // assign i to lower
        for(int j=i+1; j<n; j++){ // loop for n-i-1 times
            if(array[j]<array[lower]){ // if array[j] is less than array[lower]
                lower = j; // assign j to lower
            }
        }
        tempholder = array[i]; // assign array[i] to tempholder
        array[i] = array[lower]; // assign array[lower] to array[i]
        array[lower] = tempholder; // assign tempholder to array[lower]
    }
}
int main(int argc, char const *argv[])
{
    int n; // number of elements
    printf("What are the number of elements? ");
    scanf("%d", &n); // read the number of elements
    srand(time(60)); // seed for random number generator
    int *array; // declare an array
    array = generateArray(n); // generate an array
    outputArray(array, n); // print the array
    selectionSort(array, n); // sort the array
    printArray(array, n); // print the array
    free(array); // delete the array
    return 0;
}
