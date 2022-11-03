//selection sort for linked list

#include <stdio.h> //standard input output library
#include <stdlib.h> //standard library for malloc
#include <time.h> //time library for time(NULL)

//***************************************

struct node{ //structure for linked list
    int val; //value of the node
    struct node *next; //pointer to the next node
};

typedef struct node *NodeAddress;//pointer to the node

//***************************************

//selection sort for linked list

//***************************************

void selection_sort_linkedlist(NodeAddress head){ //selection sort for linked list
    NodeAddress i, j, minimum_V, temp_holder;  //i, j, minimum_V, temp_holder are pointers to the node

    for (i = head; i->next != NULL; i = i->next){ // loop through the linked list
        minimum_V = i;//set minimum_V to the first node

        for (j = i->next; j != NULL; j = j->next){ //loop through the rest of the linked list
            if (j->val < minimum_V->val){ //if the value of the node is less than the value of the minimum_V node
                minimum_V = j;  //set minimum_V to the node
            }
        }
        temp_holder = i->val;         //swap the values of the node and the minimum_V node
        i->val = minimum_V->val;     
        minimum_V->val = temp_holder;
    }
}
//***************************************


int Create_Array(int n){ //create an array of size n
    int *Sample_Array = malloc (n*sizeof(int)); //allocate memory for the array

    if(Sample_Array) {     //if the array is not empty
        for (int i = 0; i < n; i++){ Sample_Array[i] = rand()%1000;} //generate a random number between 0-999
    }
    return Sample_Array; 
}


NodeAddress Convert_array_to_Linkedlist(int *a, int n){ //create a linked list from an array
    NodeAddress head = NULL; //head of the linked list
    NodeAddress temp_holder = NULL; //temporary holder for the linked list
    
    // Considering corner condition 
    if(n>0){               //if the array is not empty
        head = malloc(sizeof(struct node)); //allocate memory for the head of the linked list
        head->val = a[0];    //set the value of the head of the linked list to the first element of the array
        head->next = NULL;   //set the next pointer of the head of the linked list to NULL
        temp_holder = head;  //set the temporary holder to the head of the linked list
    }

    for (int i = 1; i < n; i++){   //loop through the rest of the array
        temp_holder ->next = malloc(sizeof(struct node));//allocate memory for the next node
        temp_holder = temp_holder->next; //set the temporary holder to the next node
        temp_holder->val = a[i]; // set the value of the next node to the next element of the array
        temp_holder->next = NULL;//set the next pointer of the next node to NULL
        
    }
    return head; //return the head of the linked list
}

//***************************************

void free_prev_linkedlist_addresses (NodeAddress head){ //free the linked list

    NodeAddress prev; //pointer to the previous node
    while (head){    //loop through the linked list
        prev = head;  //set the previous node to the head of the linked list
        head = head->next;//set the head of the linked list to the next node
        free(prev);       //free the previous node
    }
}

//***************************************

void Output_linkedlist(NodeAddress head){ //output the linked list
    NodeAddress c;                        //pointer to the node
    printf("Linked List = ");             //output the linked list
    for (c = head; c!=NULL; c = c->next){ //loop through the linked list
        printf(c==head?"%d":", %d", c->val);//output the value of the node
    }
    printf("\n"); //new line
}

//***************************************

// Runing the program to test the functions if selection sort for linked list works correctly

int main(){
    int *a; //pointer to the array
    int n = 8; //size of the array
    NodeAddress list; //pointer to the head of the linked list
    srand(time(NULL)); //seed the random number generator

    a = Create_Array(n); //create an array of size n
    list = Convert_array_to_Linkedlist(a,n); //create a linked list from the array
    
    Output_linkedlist(list); //output the linked list
    selection_sort_linkedlist(list); //selection sort for linked list
    Output_linkedlist(list);  //output the linked list

    free(a); //free the array
    free_prev_linkedlist_addresses(list); //free the linked list
    
    return 0; 
}

//***************************************

// Code END

//***************************************