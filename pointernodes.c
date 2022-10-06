//Code to make and use pointers for nodes 

#include <stdio.h> // standard input output library 
#include <stdlib.h> // standard library for memory allocation

struct nodeType{     //structure for a node
int val;             //value of the node
struct nodeType * next; //pointer to the next node
};

typedef struct nodeType Node;   //define Node as a structure of type nodeType

//*********************************************************

//make a node, set its value to val, and return it
Node * makeNode(int val){ //function to make a node
	Node * temp; //pointer to the node
	temp = malloc(sizeof(Node)); //allocate memory for the node
	temp->val = val; //set the value of the node
	temp->next = NULL; //set the next pointer to NULL
	return temp;  //return the address of the node
}

//*********************************************************

//trying the code 

//make a node, set its value to val, and return it
int main(){
	printf(" Element at that node %d\n",*makeNode(5));
	printf("Node Address %p",makeNode(5));
	
	return 0;

}

//*********************************************************