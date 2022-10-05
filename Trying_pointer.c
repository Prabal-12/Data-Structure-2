// Code to check and use the pointers 


#include <stdio.h>  //standard input output library



int main (int argc, char **argv){ //main function running the program

	const int x = 36;  //constant integer x = 36
	int *p = &x;       //pointer p points to the address of x
	*p = 37;           //dereference p and assign 37 to x


	printf("x = %d \n", x);       //output x
	printf("*p = %d \n", *p);     //output the value of x


	return 0;                    

}