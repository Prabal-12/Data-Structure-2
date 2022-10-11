// The code prints the first of the list without length of the list 

#include <stdio.h>  //standard library for input/ Output operations
#include <stdlib.h> //standard library for memory allocation


//********************************************************
//defining node structure
struct nodeType{   
int val; //value of the node
struct nodeType * next; //pointer to the next node
};
typedef struct nodeType NodeAddress; // NodeAddress is a pointer to a node
//********************************************************

//Output linked list
void Output_linked_list(NodeAddress * head){  //Function for making linked list
    NodeAddress * current = head;             //current is a pointer to a node
    while(current!=NULL){                     //while current is not NULL

        if (current->next==NULL){             //if current is the last node
            printf("%d",current->val);        //print the value of the node
        }

        else{                                 //If current is not the last node
            printf("%d->",current->val);      //print the value of the node
        }

        current = current->next;              //move to the next node
    }

    printf("\n");                             //Give a break after printing the list
}

//********************************************************

//given an array, make a linked list and print it
NodeAddress * Array_to_linkedlist(int * a, int n){ //Function for making linked list
    NodeAddress * head = NULL;                     //head is a pointer to a node
    NodeAddress * current = NULL;                  //current is a pointer to a node

    for(int i=0;i<n;i++){                          //for loop to traverse the array
        NodeAddress * temp = malloc(sizeof(NodeAddress)); //temp is a pointer to a node
        temp->val = a[i];                          // assigning the value of the node
        temp->next = NULL;                         //assigning the next pointer to NULL

        if (i==0){                                 //   if it is the first node
            head = temp;                           //   assign head to temp
            current = temp;                        //   assign current to temp
        }

        else{                                       //if it is not the first node
            current->next = temp;                  //assign the next pointer of current to temp
            current = temp;                        //assign current to temp
        }
    }
    return head;                                   //return the head of the linked list
}

//********************************************************

//Create random array                              //Create random array
int * create_random_array(int n){                  //Function for creating random array
    int * a = (int *)malloc(n*sizeof(int));        //allocate memory for the array

    for(int i=0;i<n;i++){                           //for loop to traverse the array
        a[i] = rand()%200 - 100;    //generate random numbers between 100 and 100
    }
    return a;                       //return the array
}

//********************************************************

// Using hare and tortoise algorithm to find the middle of the list
// Give will give the second half of the list

//********************************************************


void secondHalfList(NodeAddress * head){ //Function for making linked list
    NodeAddress * slow = head;           //slow is a pointer to a node
    NodeAddress * fast = head;           //fast is a pointer to a node
    while(fast!=NULL && fast->next!=NULL){ //while fast is not NULL
        slow = slow->next;                 //move slow to the next node
        fast = fast->next->next;           //move fast to the next node
    }
    Output_linked_list(slow);              //print the second half of the list
}

//********************************************************

// Using hare and tortoise algorithm to find the first half of the list

//********************************************************

void firstHalfList(NodeAddress * head){      //Function for making linked list
    NodeAddress * slow = head;               //slow is a pointer to a node
    NodeAddress * fast = head;               //fast is a pointer to a node
    printf("%d ",slow->val);                 //print the first node

    while(fast!=NULL && fast->next!=NULL){   //while fast is not NULL
        fast = fast->next->next;             // move fast to the next node

        if (fast!=NULL && fast->next!=NULL){ //if fast is not NULL
            slow = slow->next;               //move slow to the next node
            printf("%d ",slow->val);          //print the value of the node
        }
    }
    printf("\n");                            //Give a break after printing the list
}

//********************************************************

// Runing the code to check the functions

int main(){
    int n = rand()%30 + 1;    //generate random numbers
    int * a = create_random_array(n); //create random array

    NodeAddress * head = Array_to_linkedlist(a,n);  //create linked list

    printf("Intial linked list \n");  //print the initial linked list
    Output_linked_list(head);         //print the linked list

    printf("first half linked list is \n");
    firstHalfList(head);                  //print the first half of the list

    printf("second half linked list is \n");
    secondHalfList(head);                 //print the second half of the list

    return 0;
}

//********************************************************

// The END

//********************************************************