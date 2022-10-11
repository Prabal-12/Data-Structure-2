// Code to reverse a linked list in chunks of size k from the list given in n number list

#include <stdio.h> //standard library for input/ Output operations
#include <stdlib.h> //standard library for memory allocation

struct nodeType{   //defining node structure
int val;           //value of the node
struct nodeType * next;   //pointer to the next node
};                        //end of node structure

typedef struct nodeType NodeAddress;   //NodeAddress is a pointer to a node

//NodeAddress * head is equivalent to NodeAddress head

//****************************************************
//Output linked list

void Output_linked_list(NodeAddress * head){ //Function for making linked list
    NodeAddress * current = head;            //current is a pointer to a node
    while(current!=NULL){                    //while current is not NULL
        if (current->next==NULL){            //if current is the last node
            printf("%d",current->val);       //print the value of the node
        }
        else{                                //If current is not the last node
            printf("%d->",current->val);     //print the value of the node
        }
        current = current->next;              //move to the next node
    }
    printf("\n");                             //Give a break after printing the list
}

//****************************************************

//Converting an array into a linked list using a function
NodeAddress * Array_linked_list(int * a, int n){ //Function for making linked list
    NodeAddress * head = NULL;                   //head is a pointer to a node
    NodeAddress * current = NULL;                //current is a pointer to a node

    for(int i=0;i<n;i++){                        //for loop to traverse the array
        NodeAddress * temp = malloc(sizeof(NodeAddress)); //temp is a pointer to a node
        temp->val = a[i];                                // assigning the value of the node
        temp->next = NULL;                                //assigning the next pointer to NULL

        if (i==0){                                      //if it is the first node
            head = temp;                                //assign head to temp
            current = temp;                             //assign current to temp
        }
        else{                                           //if it is not the first node
            current->next = temp;                       //assign the next pointer of current to temp
            current = temp;                             //assign current to temp
        }
    }
    return head;                                         //return the head of the linked list
}

//****************************************************

//Create random array
int * create_array_Array(int n){
    int * a = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        a[i] = rand()%500 - 50;    //generate random numbers between -50 and 450
    }
    return a;
}

//****************************************************
//chunk reverse linked list
//****************************************************

NodeAddress * chunkReverse(NodeAddress * head, int k){       //Function for making linked list
    NodeAddress * current = head;                            //current is a pointer to a node
    NodeAddress * prev = NULL;                               //prev is a pointer to a node
    NodeAddress * next = NULL;                               //next is a pointer to a node

    int count = 0;                                            //count is a variable to count the number of nodes

    while(current!=NULL && count<k){                         //while current is not NULL and count is less than k
        next = current->next;                                 //assign next to the next pointer of current
        current->next = prev;                                 //assign the next pointer of current to prev
        prev = current;                                        //assign prev to current
        current = next;                                        //assign current to next
        count++;                                                //increment count
    }

    if (next!=NULL){                                           //if next is not NULL
        head->next = chunkReverse(next,k);                     //assign the next pointer of head to the next chunk
    }
    return prev;                                                //return prev
}

//****************************************************

// Running the code to check the final output
int main( ){
    int n = rand()%30 + 1;    //generate random numbers between 1 and 30
    int * a = create_array_Array(n); //create an array of size n

    //Output linked list            
    printf(" The linked list is  \n"); //print the list
    NodeAddress * head = Array_linked_list(a,n);     //create a linked list
    Output_linked_list(head);                        //print the list head

    int k = 3; //chunk size of each repeat is 3
    printf("Chunch reverse linked list is \n",k);  //print the list
    head = chunkReverse(head,k);                   //reverse the linked list in chunks of size k
    Output_linked_list(head);                      //print the list head
    
    return 0;
}

//****************************************************

// END OF CODE

//****************************************************