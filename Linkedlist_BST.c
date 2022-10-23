//Code to make Linked List inary Search Tree from  Binary Search Tree
#include <stdio.h> //standard input output library
#include <stdlib.h> // standard library for malloc, free, etc


//************************************************
struct nodeType{      // Defing and making nodes for the linked list
    int val;          // value of the node
    struct nodeType *left;      //left child such that it is  smaller than parent
    struct nodeType *right;     //right child such that it is larger than parent
};

typedef struct nodeType *NodeAddress; //NodeAddress is a pointer to a nodeType

//************************************************

//function to make a BST from a linked list

//************************************************

NodeAddress linkedlist_to_BST(NodeAddress head, int n){ 
    if(n <= 0){ //if the number of nodes is less than or equal to 0, return NULL
        return NULL; //return NULL
    }

    NodeAddress left = linkedlist_to_BST(head, n/2); //make the left child of the root
    NodeAddress root = head;                         //make the root
    root->left = left;                               //make the left child of the root
    head = head->right;                              //move the head to the next node
    root->right = linkedlist_to_BST(head, n-n/2-1);  //make the right child of the root
    return root;                                     //return the root
}

//************************************************

//Convert an array to a linked list
NodeAddress * Convert_array_linklist(int * a, int n){ //function to make a linked list from an array
    NodeAddress * head = NULL;             //head of the linked list
    NodeAddress * current = NULL;          //current node of the linked list

    for(int i=0;i<n;i++){                  //loop through the array

        NodeAddress * temp = malloc(sizeof(NodeAddress)); //Take the addteress of a new node of node size Nodeaddress
        temp->val = a[i];               //set the value of the node to the value of the array
        temp->next = NULL;              //set the next node to NULL

        if (i==0){                      //if it is the first node
            head = temp;                //set the head to the first node
            current = temp;             //set the current node to the first node
        }

        else{                           //if it is not the first node
            current->next = temp;       //set the next node of the current node to the new node
            current = temp;             //set the current node to the new node
        }
    }
    return head;                        //return the head of the linked list
}

//************************************************

//Making a tree from the linked list

void prefixPrint(NodeAddress root){ // function to print the tree in prefix order

    if(root == NULL){               //if the root is NULL, return
        return;                     //return

    }
    prefixPrint(root->left);        //print the left child
    printf("%d ", root->val);       //print the value of the root
    prefixPrint(root->right);       //print the right child
}

//************************************************

// Runing the code to check if it works and implementing the functions to make a tree from a linked list
int main(){
    int a[] = {11,23,45,56,64,68,74,82,94,110}; //array to be converted to a linked list
    int n = sizeof(a)/sizeof(a[0]);             //number of nodes in the linked list

    NodeAddress * head = Convert_array_linklist(a, n);//head of the linked list
    NodeAddress root = linkedlist_to_BST(head, n);    //root of the tree

    prefixPrint(root);                                //print the tree in prefix order
    return 0;                                         //return 0
}

//************************************************

// End of the code

//************************************************