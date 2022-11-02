//Code for insertation sort for linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//***************************************
struct node{ //node is a struct
    int val; //value of the node
    struct node *next;//pointer to the next node
};

typedef struct node *NodeAddress; //pointer to the node

//***************************************

//insertation sort for linkedlist

//***************************************
void insertation_sort_for_linkedlist(NodeAddress head){ //insertation sort for linked list
    NodeAddress i, j, key; //i, j, key are pointers to the node
    for (i = head->next; i != NULL; i = i->next){ //loop through the linked list
        key = i;      //set key to the current node
        j = i->next;  //set j to the next node
        while (j != NULL && j->val < key->val){ //loop through the rest of the linked list
            key->val = j->val;                  //swap the values of the node and the key node
            j->val = key->val;               
            j = j->next;
        }
    }
}

//***************************************


int Create_Array(int n){ //create an array of size n
    int *sample_array = malloc (n*sizeof(int)); //allocate memory for the array
    if(sample_array) {
        for (int i = 0; i < n; i++){ sample_array[i] = rand()%1000;} //generate a random number between 0-999
       
    }
    return sample_array; //return the array
}

//***************************************

NodeAddress Convert_Array_to_linkedlist(int *a, int n){ //create a linked list from an array
    NodeAddress head = NULL;  //head of the linked list
    NodeAddress temp = NULL;   //temporary holder for the linked list
    
    // Considering corner condition
    if(n>0){                 //if the array is not empty
        head = malloc(sizeof(struct node)); //allocate memory for the head of the linked list
        head->val = a[0];   //set the value of the head of the linked list to the first element of the array
        head->next = NULL;  //set the next pointer of the head of the linked list to NULL
        temp = head;        //set the temporary pointer to the head of the linked list
    }

    for (int i = 1; i < n; i++){ //loop through the rest of the array
        temp ->next = malloc(sizeof(struct node)); //allocate memory for the next node
        temp = temp->next;//move the temporary pointer to the next node
        temp->val = a[i]; //set the value of the node to the value of the array (SWAP)
        temp->next = NULL; //set the next pointer of the node to NULL
        
    }
    return head; //return the head of the linked list
}

//***************************************

void free_prev_Linked_List(NodeAddress head){ //free the linked list
  

    NodeAddress prev;  //previous node
    while (head){      //loop through the linked list
        prev = head;   //set the previous node to the current node
        head = head->next; //move the head to the next node
        free(prev);        //free the previous node
    }
}
//***************************************

void output_linked_List(NodeAddress head){ //output the linked list
    NodeAddress c; //current node
    for (c = head; c!=NULL; c = c->next){ //loop through the linked list
        printf(c==head?"%d":", %d", c->val); //print the value of the node
    }
    printf("\n"); //print a new line
}

//***************************************

//Running code to check insertation sort for linked list work properly

//***************************************

int main(){
    int *a; //array
    int n = 10; //size of the array
    NodeAddress list; //linked list
    srand(time(NULL)); //   seed for the random number generator

    a = Create_Array(n);  //create an array of size n
    list = Convert_Array_to_linkedlist(a,n); //create a linked list from the array
    
    output_linked_List(list); //output the linked list
    insertation_sort_for_linkedlist(list); //insertation sort for linked list
    output_linked_List(list); //output the linked list after the sorting

    free(a);  //free the array
    free_prev_Linked_List(list); //free the linked list
    
    return 0; //return 0
}

//***************************************

//Code Ends

//***************************************