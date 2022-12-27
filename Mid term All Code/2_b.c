#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* nextValue;
    struct Node* next2;
} Node;

Node* arrayToLLWithNext2(int* a, int n) { // n is the size of the array
    Node* head = NULL;                     // head of the linked list
    Node* last_two_values = NULL;                 //   to be used for next2
    Node* temporyValue = NULL;                      //   to be used for nextValue


    for (int i = 0; i < n; i++) {          // loop through the array
        if (!head) {                        // if head is NULL
            head = (Node *)malloc(sizeof(Node)); // allocate memory for head
            head->data = a[i];                // set the data of head
            head->nextValue = NULL;                // set the nextValue of head to NULL
            head->next2 = NULL;                // set the next2 of head to NULL
            temporyValue = head;                       // set temporyValue to head
            last_two_values = temporyValue;                   // set last_two_values to temporyValue
        }
        else {
            temporyValue->nextValue = (Node *)malloc(sizeof(Node)); // allocate memory for temporyValue->nextValue
            temporyValue = temporyValue->nextValue;
            temporyValue->data = a[i];                         // set the data of temporyValue
            temporyValue->nextValue = NULL;
            temporyValue->next2 = NULL;                        // set the next2 of temporyValue to NULL

            if (i >= 2) {                             // if i is greater than or equal to 2
                last_two_values->next2 = temporyValue;
                last_two_values = last_two_values->nextValue;            //    set last_two_values->next2 to temporyValue
            }
        }
    }
    return head;
}

void printLLWithNext(Node* head) {                  // print the linked list
    Node* temporyValue = head;
    
    while(temporyValue) {
        printf("%d ", temporyValue->data);                  // print the data of temporyValue
        temporyValue = temporyValue->nextValue;
    }
    printf("\n");
}

void printLLWithNext2(Node* head) {                 // print the linked list
    Node* temporyValue = head;

    while(temporyValue != NULL) {
       printf("%d ", temporyValue->data);
        temporyValue = temporyValue->next2; 
    }
    printf("\n");
}

Node* reverseLLWithNext2(Node* head) {              // reverse the linked list
    Node* CurrentValue = head;
    Node* lastValue = NULL;
    Node* nextValue = NULL;
    Node* fastNext = head->next2;

    int count = 0;

    while(CurrentValue) {                                    // loop through the linked list
        nextValue = CurrentValue->nextValue;
        CurrentValue->nextValue = lastValue;

        if(count < 2) CurrentValue->next2 = NULL;           // if count is less than 2
        if (fastNext) {
            fastNext->next2 = CurrentValue;                 // set fastNext->next2 to CurrentValue
            fastNext = fastNext->nextValue;                  // set fastNext to fastNext->nextValue
        }

        lastValue = CurrentValue;                                   // set lastValue to CurrentValue
        CurrentValue = nextValue;                                   // set CurrentValue to nextValue
        count++;                                       // increment count

    }

    return lastValue;
}

int main() {                                        // main function
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);               // size of the array

    Node* head = arrayToLLWithNext2(a, n);       // create a linked list with next2 pointers

    head = reverseLLWithNext2(head);                //// print the linked list elements head 
    printf("Reversed Linked List: ");             // print the reversed linked list
    printLLWithNext(head);                       // print the linked list elements head 
    printf("Reversed Linked List with next2: "); // print the linked list
    printLLWithNext2(head);                      // print the linked list elements head 
}