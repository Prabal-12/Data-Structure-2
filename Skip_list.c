//Code for data structure skip list

#include <stdio.h>
#include <stdlib.h>

//*******************************************

//define the node type
struct nodeType{ //
int val; //value of the node
struct nodeType * next; //pointer to the next node
struct nodeType * next5; //pointer to the next node
struct nodeType * next10; //pointer to the next node
};

typedef struct nodeType NodeAddress; //define NodeAddress as Sample_array type

//*******************************************

//NodeAddress * head is equivalent to NodeAddress head

// Output linked list
void output_linked_list(NodeAddress * head){ //head is the pointer to the first node

    NodeAddress * current = head;            //current is the pointer to the current node
    while(current!=NULL){                    //while current is not NULL
        if (current->next==NULL){            //if current is the last node
            printf("%d",current->val);       //print the value of the last node
        }
        else{                                //if current is not the last node
            printf("%d->",current->val);     //print the value of the current node
        }
        current = current->next;             //move current to the next node
    }
    printf("\n");
}

//*******************************************

//print linked list with next5
void output_linked_list5(NodeAddress * head){ //head is the pointer to the first node
    printf("%d ",head->val); // print the value of the first node
    NodeAddress * current = head; //current is the pointer to the current node
    while(current!=NULL){ //while current is not NULL
        if (current->next5!=NULL){ //if current is the last node
            printf("%d ",current->next->val); //print the value of the last node
        }
        current = current->next; //move current to the next node
    }
    printf("\n");
}

//*******************************************
//print linked list with next10
void output_linked_list10(NodeAddress * head){ //head is the pointer to the first node
    printf("%d ",head->val);          // print the value of the first node
    NodeAddress * current = head;     //current is the pointer to the current node
    while(current!=NULL){             //while current is not NULL
        if (current->next10!=NULL){   //if current is the last node
            printf("%d ",current->next->val); //print the value of the last node
        }          
        current = current->next;    //move current to the next node
    }
    printf("\n");
}

//*******************************************

NodeAddress * Convert_array_to_skiplist(int * Sample_array, int n){ //convert array to skip list
    NodeAddress * head = (NodeAddress *)malloc(sizeof(NodeAddress)); //allocate memory for the first node
    head->val = Sample_array[0]; //assign the value of the first node
    head->next = NULL; //assign NULL to the next pointer of the first node
    head->next5 = NULL; //assign NULL to the next5 pointer of the first node
    head->next10 = NULL;  //assign NULL to the next10 pointer of the first node

    NodeAddress * current = head; //current is the pointer to the current node
    for(int i=1;i<n;i++){ //for loop to create the rest of the nodes
        NodeAddress * newNode = (NodeAddress *)malloc(sizeof(NodeAddress)); //allocate memory for the new node
        newNode->val = Sample_array[i]; //assign the value of the new node
        newNode->next = NULL; //assign NULL to the next pointer of the new node
        newNode->next5 = NULL; //assign NULL to the next5 pointer of the new node
        newNode->next10 = NULL; //assign NULL to the next10 pointer of the new node

        current->next = newNode; //assign the new node to the next pointer of the current node
        current = current->next;    //move current to the next node
    }
//*******************************************
    //add next5 and next10
    current = head;
    int count = 0;
    while(current!=NULL){
        count++;
        if (count%5==0){
            current->next5 = current->next;
        }
        if (count%10==0){
            current->next10 = current->next;
        }
        current = current->next;
    }

    return head;
}

//*******************************************

//Create an array of random array

int * Convert_array(int n){ //generate an array of random numbers
    int * Sample_array = (int *)malloc(n*sizeof(int)); //allocate memory for the array
    for(int i=0;i<n;i++){            //for loop to generate random numbers
        Sample_array[i] = rand()%200 - 100;    //generate random numbers between 100 and 100
    }
    return Sample_array; 
}

//*******************************************

//Runing the code to check whether skip list works

int main( ){
    int n = 27;    
    int * Sample_array = Convert_array(n); //generate an array of random numbers

    printf("Original array %d\n", n); //print the original array
    for(int i=0;i<n;i++){   //for loop to print the original array
        printf("%d ",Sample_array[i]); //print the original array
    }

    printf("Skip list \n"); //print the skip list
    NodeAddress * head = Convert_array_to_skiplist(Sample_array,n); //convert array to skip list
    output_linked_list(head); //print the skip list
    output_linked_list5(head); //print the skip list with next5
    output_linked_list10(head); //print the skip list with next10

    return 0;
}

//*******************************************

// Code Ends

//*******************************************
