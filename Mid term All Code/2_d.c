#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    int k;
    struct Node* nextK;
} Node;

Node* reverseLLWithNextK ( Node* head )
{
    // Your code goes here
    Node* temp = head;
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}
//generating a random number between 2 and 5 inclusively
int generateRandomNumber() {
    return (rand() % 4) + 2;
}

//creating a linkedlist with nextK pointers
Node* arrayToLLWithNextK(int* a, int n) {
    Node* head = NULL;
    Node* temp = NULL;

    //creating the linkedlist first
    for(int i=0; i<n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = a[i];
        newNode->next = NULL;
        newNode->k = generateRandomNumber();
        newNode->nextK = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    //setting the nextK pointers
    temp = head;
    while(temp != NULL) {
        int k = temp->k;
        Node* temp2 = temp;
        while(k > 0 && temp2 != NULL) {
            temp2 = temp2->next;
            k--;
        }
        temp->nextK = temp2;
        temp = temp->next;
    }

    //returning the head of the linkedlist
    return head;

}

void printLLNextK(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        if (temp->nextK != NULL) {
            printf("Data: %d -> K: %d -> NextK: %d\n", temp->data, temp->k, temp->nextK->data);
        } else {
            printf("Data: %d -> K: %d -> NextK: NULL\n", temp->data, temp->k);
        }
        temp = temp->next;
    }
}

void deleteLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main(void) {
    //change a[] to test different cases
    int a[] = { 5, 3, 7, 2, 4, 6, 8, 1, 9, 10, 11 };
    int n = sizeof(a)/sizeof(a[0]);


    //original linkedlist
    printf("\nLinkedlist Structure:\n");
    Node* head = arrayToLLWithNextK(a, n);
    printLLNextK(head);
    
    //deleting the linkedlist
    deleteLL(head);

    reverseLLWithNextK (head);

    return 0;
}