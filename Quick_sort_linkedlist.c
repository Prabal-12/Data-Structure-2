// Code for quick sort on linked list

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//*****************************************
struct node{ // Structure for the linked list
    int val; // Value of the node
    struct node *next;// Pointer to the next node
};

typedef struct node *NodeAddress;// Defining a new data type for the node address

//*****************************************

//Quick sort function

//*****************************************

void quick_Sort_for_LinkedList(NodeAddress head, NodeAddress tail){ // Function to perform quick sort on a linked list
    NodeAddress i, j, pivot, temp; // Defining the pointers
    if (head != tail){   // If the head is not equal to the tail
        pivot = head;    // Taking the head as the pivot
        i = head;        // Setting the pivot index to the head
        j = head->next;   // Setting the counter to the next element of the head

        while (j != tail){ // Looping through the linked list
            if (j->val < pivot->val){ // If the element is less than the pivot
                i = i->next;          // Increment the pivot index
                temp = i->val;        // Swap the values
                i->val = j->val;
                j->val = temp;
            }
            j = j->next;              // Increment the counter
        }
        temp = i->val;                // Swap the values
        i->val = pivot->val;
        pivot->val = temp;
        quick_Sort_for_LinkedList(head, i); // Recursively call the function
        quick_Sort_for_LinkedList(i->next, tail); // Recursively call the function
    }
}

//*****************************************

int create_Array(int n){  // Function to generate an array of random numbers
    int *Sample_Array = malloc (n*sizeof(int)); // Allocate memory for the array

    if(Sample_Array) { // If the array is not empty
        for (int i = 0; i < n; i++){ Sample_Array[i] = rand()%1000;} //generate a random number between 0-999
        
    }
    return Sample_Array; // Return the array
}

//*****************************************

NodeAddress Convert_array_to_linkedlist(int *a, int n){ // Function to convert an array to a linked list
    NodeAddress head = NULL;  // Defining the head of the linked list
    NodeAddress temp = NULL;  // Defining the temporary pointer
    
    // Consider corner cases

    if(n>0){                            // If the array is not empty
        head = malloc(sizeof(struct node)); // Allocate memory for the head
        head->val = a[0];                   // Assign the value of the head
        head->next = NULL;                  // Assign the next pointer of the head to NULL
        temp = head;                        // Assign the temporary pointer to the head
    }

    for (int i = 1; i < n; i++){            // Loop through the array
        temp ->next = malloc(sizeof(struct node)); // Allocate memory for the next node
        temp = temp->next;                         // Assign the temporary pointer to the next node
        temp->val = a[i];                          // Assign the value of the next node
        temp->next = NULL;                         // Assign the next pointer of the next node to NULL
        
    }
    return head; // Return the head of the linked list
}

//*****************************************

void clear_prev_linked_list(NodeAddress head){ // Function to clear the linked list

    NodeAddress prev;  // Defining the previous pointer
    while (head){      // Loop through the linked list
        prev = head;   // Assign the previous pointer to the head
        head = head->next; // Assign the head to the next node
        free(prev);        // Free the previous node
    }
}

//*****************************************

void output_linkedlist(NodeAddress head){ // Function to output the linked list
    NodeAddress c; // Defining the pointer
    for (c = head; c!=NULL; c = c->next){ // Loop through the linked list
        printf(c==head?"%d":", %d", c->val); // Print the value of the node
    }
}
//*****************************************

// Runing code for the quick sort on linked list
int main(){
    int *a; // Defining the array
    int n = 8; // Defining the size of the array
    NodeAddress list; // Defining the head of the linked list
    srand(time(NULL)); // Seed the random number generator

    a = create_Array(n); // Create an array of random numbers
    list = Convert_array_to_linkedlist(a,n); // Convert the array to a linked list
    
    output_linkedlist(list);                 // Output the linked list
    quick_Sort_for_LinkedList(list, NULL);   // Perform quick sort on the linked list
    output_linkedlist(list);                 // Output the linked list after sorting

    free(a);                      // Free the array
    freeLinkedList(list);         // Free the linked list
    
    return 0;

}
//*****************************************

//Code END

//*****************************************