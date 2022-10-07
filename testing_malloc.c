// Code to try operation of malloc and how to use it 

#include <stdio.h> // standard input output
#include <stdlib.h> // standard library for memory allocation

//*********************************************************

void main(){ // main function running the program
int *a; // pointer to the array
int x; // number of elements in the array
a = malloc(1000 * sizeof(x)); //malloc = memory allocation

printf("%p \n", a); //print the address of the array

x = *(a+1);//assign the value of the second element of the array to x
printf("%d \n", x); //print the value of x

free(a); //make sure to do it after malloc - to free the RAM
}

//*********************************************************