
// Code for stress testing loops

#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv){

    float i;                          // i is the variable that will be incremented
    float increment = 0.000000001;    // increment is the amount that i will be incremented by
    float x = 0.00000001;               // x is the number that i will be incremented up to as can be seen from the for loop conditon 
    int Counter = 1;

    for (i=0.0; i<x; i+=increment) {      // for loop that will increment i by the amount of increment until i is equal to x
        printf(" Number of the loop is  %d\n", Counter);   // prints the number of the loop
        Counter++;                                // increments the counter by 1
    }

    return 0;
}


// End 