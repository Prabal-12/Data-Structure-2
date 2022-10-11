//Code will reverse a linked list elements 

#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library for malloc, free, etc.


//*******************************************
struct nodeType{            //defining node structure
int val;                    //value of the node
struct nodeType * next;     //pointer to the next node
};

typedef struct nodeType NodeAddress;  //defining node type

//*******************************************


//Outputlinked list

void output_linked_list(NodeAddress * head){   //function to output linked list
    NodeAddress * current = head;              //current node
    while(current!=NULL){                      //loop through the linked list

        if (current->next==NULL){              //if it is the last node
            printf("%d",current->val);         //print the value
        }

        else{                                   //if it is not the last node
            printf("%d->",current->val);        //print the value and arrow
        }
        current = current->next;                //move to the next node
    }
    printf("\n");                               //print new line
}

//*******************************************

//Convert an array in a linked list

NodeAddress * arrayToList(int * a, int n){     //function to convert array to linked list
    NodeAddress * head = NULL;                 //head of the linked list
    NodeAddress * current = NULL;              //current node

    for(int i=0;i<n;i++){                      //loop through the array

        NodeAddress * temp = malloc(sizeof(NodeAddress)); //allocate memory for the node
        temp->val = a[i];                                 //assign value to the node
        temp->next = NULL;                                //assign next to NULL

        if (i==0){                                         //if it is the first node
            head = temp;                                   //assign head to the node
            current = temp;                                //assign current to the node
        }
        else{                                               //if it is not the first node
            current->next = temp;                           //assign next to the node
            current = temp;                                 //assign current to the node
        }
    }
    return head;                                            //return head of the linked list
}


//*******************************************

//generate random array
int * create_random_array(int n){            //function to generate random array
    int * a = (int *)malloc(n*sizeof(int));  //allocate memory for the array
    for(int i=0;i<n;i++){                    //loop through the array
        a[i] = rand()%200 - 100;    //generate random numbers between -100 and 100
    }
    return a;
}
//*******************************************

//reversing linked list

//*******************************************

NodeAddress * reverseList(NodeAddress * head){
    NodeAddress * current = head;
    NodeAddress * prev = NULL;
    NodeAddress * next = NULL;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

//*******************************************

//Runing the program to check the output of the code
int main( ){
    int n = rand()%30 + 1;    //generate random numbers
    int * a = create_random_array(n);  //creating random array

    //print linked list
    printf("linked list is \n");             //print linked list
    NodeAddress * head = arrayToList(a,n);   //convert array to linked list
    output_linked_list(head);                //output linked list

    //reverse linked list
    printf("The reversed linked list is: \n"); //print reversed linked list
    head = reverseList(head);                  //reverse linked list
    output_linked_list(head);                  //output linked list
    
    return 0;
}

//*******************************************

// The END

//*******************************************