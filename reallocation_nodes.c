// Code to try reacllocation of nodes

#include <stdio.h> // standard input output library
#include <stdlib.h> // standard library for memory allocation

//*****************************************************************

int main(int argc, char **argv){ //main function running the program
	int *a;                      //pointer to the array
	int i, n, val;               //counter, number of nodes, value of the node

	n = 5; //initializing the number of nodes
	a = (int *) malloc(n * sizeof(int)); //allocating memory for the array

	
	i = 0; //initializing the counter
	scanf("%d", &val); //Reading the first value
	while (val > 0){   //Looping over the nodes
		
		a[i] = val;    //Setting the value of the node
		i = i+1;       //Incrementing the counter

		if(i>=n){      //Checking if the array is full
		 n = n*2;      //Doubling the size of the array
		 a = realloc(a, n * sizeof(int)); //Reallocating the memory
 	}
		scanf("%d", &val);                //Reading the next value

	}

	n = i;
	a = realloc(a, n*sizeof(int));     //Reallocating the memory

//*************************************
// Outputting of the Data 
//*************************************
	for(i=0; i<n; i++){ //Going over the nodes to collect the data
	printf("%d", a[i]); //Outputting the data
	}

	free(a);
}

//*************************************