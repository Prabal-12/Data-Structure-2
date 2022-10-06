//Code to find the address of the max element in an array

#include <stdio.h>  // standard input output library
#include <stdlib.h> // standard library for memory allocation
#include <time.h>   // for random number generation


//*****************************************************************

int create_Array(int n){ //function to create an array of n elements
    int *t = malloc (n*sizeof(int));  //malloc = memory allocation
    if(t) { //if the memory allocation is successful
        for (int i = 0; i < n; i++){ t[i] = rand()%1000;} //generating a number between 0-999
    }
    return t; //return the address of the array
}

//*****************************************************************

void output_Array(int *a, int n){ //function to output the array
    printf("Array is  = "); //output the array
    for (int i = 0; i < n; i++){ //output the array
        printf(i?", %d":"%d", a[i]);  //output the array
    }
    printf("\n");  //output the array
}
//*****************************************************************

int findIndexofMax(int *a, int n){  //function to find the index of the max element in the array
    //error case - there is no element in the array
    if (n<1) {return -1;} //return -1 if there is no element in the array

    int imax = 0;   //index of max element = 0 initially
    for (int i = 1; i < n; i++){ //loop through the array
        if (a[i] > a[imax]) imax = i; //if the current element is greater than the max element, then update the index of max element
    }
    return imax;
}

//*****************************************************************

int findAddressofMax(int *a, int n){ //function to find the address of the max element in the array
    int *amax = NULL;                //address of max element = NULL initially
    if (n>=1) {                      //error case - there is no element in the array
        amax = a; //initially, the address of max element = address of first element
        for (int i = 1; i < n; i++){ //loop through the array
            if (*(a+i) > *(a + amax)) { //if the current element is greater than the max element, then update the address of max element
                amax = i; //update the address of max element
            }
        }
    }
    return amax;    //return the address of the max element
}

//*****************************************************************

//Code to test the code 

int main(){ // main function running the program
    int *a; // pointer to the array
    int n = 15; // number of elements in the array
    srand(time(NULL));    //for random number generation

    a = create_Array(n);  //create an array of n elements

    output_Array(a,n);    //output the array
    printf("Address of the maximum element is = %d , the value of the item at that place is = %d \n", findAddressofMax(a,n), *(findAddressofMax(a,n)));

    free(a); //make sure to do it after malloc - to free the RAM
    
    return 0; //    return 0; //return 0 to the operating system
}

//*****************************************************************