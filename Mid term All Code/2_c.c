#include<stdio.h>
#include<stdlib.h>

typedef struct Node { //creating a structure for the linked list
    int data;
    struct Node* next; //pointer to the next node
    int k;
    struct Node* nextK; //  pointer to the next node
} Node;

//generating a random number 
int generateRandomNumber() { //generating a random number 
    return (rand() % 4) + 2;  //returning a random number 
}

//creating a linkedlist with nextK pointers
Node* arrayToLLWithNextK(int* a, int n) { //creating a linked list with nextK pointers
    Node* headValue = NULL;       //headValue of the linked list
    Node* temporyValue = NULL;        //temporary value

    //creating the linkedlist first
    for(int i=0; i<n; i++) { //looping through the array
        Node* newNode = (Node*)malloc(sizeof(Node));  //allocating memory for the new node
        newNode->data = a[i];                         //setting the data of the new node
        newNode->next = NULL;                         //setting the next of the new node to NULL
        newNode->k = generateRandomNumber();          //setting the k of the new node to a random number
        newNode->nextK = NULL;

        if (headValue == NULL) {                       //if the headValue is NULL
            headValue = newNode;                       //setting the headValue to the new node
            temporyValue = newNode;                     //setting the temporary value to the new node
        } else {
            temporyValue->next = newNode;               //  setting the next of the temporary value to the new node
            temporyValue = newNode;                     //setting the temporary value to the new node
        }
    }

    //setting the nextK pointers
    temporyValue = headValue;                           //setting the temporary value to the headValue
    while(temporyValue != NULL) {                       //looping through the linked list
        int k = temporyValue->k;                        //setting the k to the k of the temporary value
        Node* temporyValue_2 = temporyValue;                     //setting the temporary value to the temporary value
        while(k > 0 && temporyValue_2 != NULL) {
            temporyValue_2 = temporyValue_2->next;
            k--;
        }
        temporyValue->nextK = temporyValue_2;       //setting the nextK of the temporary value to the temporary value
        temporyValue = temporyValue->next;           //setting the temporary value to the next of the temporary value
    }

    //returning the headValue of the linkedlist
    return headValue;

}

void printLLNextK(Node* headValue) {                  //printing the linked list
    Node* temporyValue = headValue;                    //setting the temporary value to the headValue
    while(temporyValue != NULL) {                        //looping through the linked list
        if (temporyValue->nextK != NULL) {                //if the nextK of the temporary value is not NULL
            printf("Data: %d -> K: %d -> NextK: %d\n", temporyValue->data, temporyValue->k, temporyValue->nextK->data); //printing the data, k and nextK of the temporary value
        } else {
            printf("Data: %d -> K: %d -> NextK: NULL\n", temporyValue->data, temporyValue->k);    //printing the data and k of the temporary value
        }
        temporyValue = temporyValue->next; //setting the temporary value to the next of the temporary value
    }
}

void deleteLL(Node* headValue) { // deleting the linked list
    Node* temporyValue = headValue; //  setting the temporary value to the headValue
    while(temporyValue != NULL) { //looping through the linked list
        Node* next = temporyValue->next;  //setting the next to the next of the temporary value
        free(temporyValue);   //freeing the temporary value
        temporyValue = next;   //setting the temporary value to the next
    }
}

int main(void) {
    //change a[] to test different cases
    int a[] = { 8, 7, 10, 5, 4, 6, 12, 3, 7, 10, 16 }; //creating an array
    int n = sizeof(a)/sizeof(a[0]); //calculating the size of the array


    //original linkedlist
    printf("\nLinkedlist Structure:\n");  //printing the linked list structure
    Node* headValue = arrayToLLWithNextK(a, n);  // creating a linked list with nextK pointers
    printLLNextK(headValue);   //printing the linked list
    
    //deleting the linkedlist
    deleteLL(headValue);  //deleting the linked list

    return 0; //returning 0
}