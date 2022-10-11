// Code to convert an array to a linked list

#include <stdio.h> //standard library for input/ Output operations
#include <stdlib.h> //standard library for memory allocation

struct nodeType{ //defining node structure
int val;         //value of the node
struct nodeType * next; //pointer to the next node
};                      

typedef struct nodeType NodeAddress;  //NodeAddress is a pointer to a node

//NodeAddress * head is equivalent to NodeAddress head

//****************************************************

//print linked list from the data given above :- 

void OutputLinkedlist(NodeAddress * head){ //Function for making linked list
    NodeAddress * current = head; //current is a pointer to a node
    while(current!=NULL){         //while current is not NULL
        if (current->next==NULL){  //if current is the last node
            printf("%d",current->val); //print the value of the node
        }
        else{                           //If current is not the last node
            printf("%d->",current->val); //print the value of the node
        }
        current = current->next; //move to the next node
    }
    printf("\n");                 //print a new line
}

//****************************************************


//given an array, make a linked list and print it

NodeAddress * Array_List(int * a, int n){ //Function for making linked list
    NodeAddress * head = NULL;  //head is a pointer to a node
    NodeAddress * current = NULL;  //current is a pointer to a node
    for(int i=0;i<n;i++){            //for loop to traverse the array till the end is not reached

        NodeAddress * temp = malloc(sizeof(NodeAddress)); //temp is a pointer to a node
        temp->val = a[i];                                 //assign the value of the node
        temp->next = NULL;                                //assign the next pointer to NULL
        if (i==0){                                        //if it is the first node
            head = temp;                                  //assign head to temp
            current = temp;                               //assign current to temp
        }
        else{                                              //if it is not the first node
            current->next = temp;                          //assign the next pointer of current to temp
            current = temp;                                //assign current to temp
        }
    }
    return head;
}

//****************************************************

//Creating a random array of length n

int * Create_randon_Array(int n){           //Function for creating a random array
    int * a = (int *)malloc(n*sizeof(int)); //allocate memory for the array
    for(int i=0;i<n;i++){                   //for loop to traverse the array till the end is not reached
        a[i] = rand()%200 - 100;             //generate random numbers between -100 and 100
    }
    return a;                              //return the array
}

//****************************************************

//Running the functions 
int main( ){ 
    int n = rand()%30 + 1;    //generate random numbers between 1 and 30
    int * a = Create_randon_Array(n);    //create a random array of length n

    printf("The original array was %d \n", n); //print the the intial array
    for(int i=0;i<n;i++){                      //for loop to traverse the array till the end is not reached
        printf("%d ",a[i]);                    //print the value of the node
    }

    printf("\n"); //print a new line

    printf(" The final linkedlist is \n"); //print the the intial array
    NodeAddress * head = Array_List(a,n);            //create a linked list from the array
    OutputLinkedlist(head);                          //print the linked list

    return 0;
}

//****************************************************