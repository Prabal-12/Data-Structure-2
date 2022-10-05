// Code to create an array of integers

#include <stdio.h> // standard input output library
#include <stdlib.h> // standard library for memory allocation

int create_Array(int n){ // function to create an array of integers
    int *t = malloc (n*sizeof(int)); // allocate memory for the array
    if(t) {
        for (int i = 0; i < n; i++){ t[i] = i;} //variable i is local to this function - variable scope thing
    }
    return t; // return the pointer to the array
}
void output_array(int *a, int n){ // function to output the array
    printf("Array = ");            // print the array
    for (int i = 0; i < n; i++){    // loop over the array
        printf(i?", %d":"%d", a[i]); // print the array
    }
    printf("\n");
}

void printArray1(int *a, int n){ // function to output the array
    for (int i = 0; i < n; i++){ // loop over the array
        printf("%d ", a[i]);      // print the array
    }
}

//*********************************************************

int main(int argc, char **argv){ // main function running the program
    int *a; // pointer to the array
    int n = 15; // number of elements in the array

    a = create_Array(n); // create the array
    output_array(a,n); // output the array
    free(a);  //    free the memory
    return 0;
}

//*********************************************************