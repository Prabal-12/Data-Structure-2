#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// create a linked list
// declare a node structure for linked list
struct node {
    int data; // data of the node
    struct node *next; // pointer to the next node
};
typedef struct node * nodeAddress; // define a new type for node address pointer

// function for generating a linked list for n nodes
nodeAddress generateLinkedList(int n){
    nodeAddress head = NULL; // head of the linked list
    nodeAddress temp = NULL; // temporary node
    // special case for head
    if(n>0){
        head = malloc(sizeof(struct node)); // allocate memory for head
        head->data = rand()%100; // assign random data to head
        head->next = NULL; // assign NULL to next of head
        temp = head; // assign head to temp
    }
    // general case
    for(int i=1; i<n; i++){ // loop for n-1 times
        temp->next = malloc(sizeof(struct node)); // allocate memory for next node
        temp = temp->next; // move temp to next node
        temp->data = rand()%100; // assign random data to temp
        temp->next = NULL; // assign NULL to next of temp
    }
    return head; // return head of the linked list
}
// function for printing a linked list
void printLinkedList(nodeAddress head){ //  head of the linked list
    nodeAddress temp = head; // assign head to temp
    while(temp!=NULL){ // loop until temp is not NULL
        printf("%d ", temp->data); // print data of temp
        temp = temp->next; // move temp to next node
    }
}
// function for deleting a linked list
void deleteLinkedList(nodeAddress head){ /// head of the linked list
    nodeAddress temp = head; // assign head to temp
    while(temp!=NULL){ // loop until temp is not NULL
        head = head->next; //   move head to next node
        free(temp); // free memory of temp
        temp = head; // move temp to head
    }
}
int main(int argc, char const *argv[])
{
    int n;  // number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n); // read the number of nodes
    srand(time(0)); // seed for random number generator
    nodeAddress list; // declare a linked list
    list = generateLinkedList(n); // generate a linked list
    printLinkedList(list, n); // print the linked list
    deleteLinkedList(list); // delete the linked list
    return 0;
}
