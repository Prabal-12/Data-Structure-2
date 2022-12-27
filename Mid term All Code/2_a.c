#include<stdio.h>
#include<stdlib.h>

typedef struct Node { // Node structure
    int data;
    struct Node* next;
    struct Node* next2;
} Node;

Node* arrayToLLWithNext2(int* a, int n) { // n is the size of the array
    Node* head = NULL;                     // head of the linked list
    Node* last_two_values = NULL;                 //   to be used for next2
    Node* temporaryValue = NULL;                      //   to be used for next


    for (int i = 0; i < n; i++) {          // loop through the array
        if (!head) {                        // if head is NULL
            head = (Node *)malloc(sizeof(Node)); // allocate memory for head
            head->data = a[i];                // set the data of head
            head->next = NULL;                // set the next of head to NULL
            head->next2 = NULL;                // set the next2 of head to NULL
            temporaryValue = head;                       // set temporaryValue to head
            last_two_values = temporaryValue;                   // set last_two_values to temporaryValue
        }
        else {
            temporaryValue->next = (Node *)malloc(sizeof(Node)); // allocate memory for temporaryValue->next
            temporaryValue = temporaryValue->next;
            temporaryValue->data = a[i];                         // set the data of temporaryValue
            temporaryValue->next = NULL;
            temporaryValue->next2 = NULL;                        // set the next2 of temporaryValue to NULL

            if (i >= 2) {                             // if i is greater than or equal to 2
                last_two_values->next2 = temporaryValue;
                last_two_values = last_two_values->next;            //    set last_two_values->next2 to temporaryValue
            }
        }
    }
    return head;
}

void printLLWithNext(Node* head) {                  // print the linked list
    Node* temporaryValue = head;
    
    while(temporaryValue) {
        printf("%d ", temporaryValue->data);                  // print the data of temporaryValue
        temporaryValue = temporaryValue->next;                          // set temporaryValue to temporaryValue->next
    }
    printf("\n");
}

void printLLWithNext2(Node* head) {                 // print the linked list
    Node* temporaryValue = head;

    while(temporaryValue != NULL) {                           // Run the program till temporaryValue is not NULL and print the data of temporaryValue
       printf("%d ", temporaryValue->data);                    // print the data of temporaryValue
        temporaryValue = temporaryValue->next2;                           // set temporaryValue to temporaryValue->next2
    }
    printf("\n");
}

Node* reverseLLWithNext2(Node* head) {              // reverse the linked list
    Node* currentElement = head;
    Node* beforeElement = NULL;
    Node* next = NULL;
    Node* fastNext = head->next2;    // fastNext is the next2 of head

    int count = 0; // count is the number of nodes in the linked list

    while(currentElement) {                                    // loop through the linked list
        next = currentElement->next;
        currentElement->next = beforeElement;

        if(count < 2) currentElement->next2 = NULL;           // if count is less than 2
        if (fastNext) {
            fastNext->next2 = currentElement;
            fastNext = fastNext->next;
        }

        beforeElement = currentElement;                                   // set beforeElement to currentElement
        currentElement = next;                                   // set currentElement to next
        count++;                                       // increment count

    }

    return beforeElement;
}

int main() {                                        
    int a[] = {1,2,3,4,5}; // array value assignment 
    int n = sizeof(a)/sizeof(a[0]);  // size of the array

    Node* head = arrayToLLWithNext2(a, n); // create a linked list

    printf("starting  Linked List: "); // print the starting linked list
    printLLWithNext(head); // print the linked list element 
    printLLWithNext2(head); // print the linked list
    printLLWithNext2(head->next); // print the linked list element next to head

}


/* 
Original Linked List: 1 2 3 4 5 
1 3 5 
2 4 */