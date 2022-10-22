//Code to make a Binary Search Treefrom Arrays 

#include <stdio.h>      //standard input output library
#include <stdlib.h>     // standard library for malloc, free, etc


//************************************************

struct nodeType{                // Defing and making nodes for the linked list
    int val;                    // value of the node
    struct nodeType *left;      //left child such that child smaller than parent
    struct nodeType *right;     //right child such that the child larger than parent
};

typedef struct nodeType NodeAddress;  //NodeAddress is a pointer to a nodeType

//************************************************

//function to make a BST from a Array by adding nodes 

//************************************************


NodeAddress * add_nodes(NodeAddress * root, int val){ //function to add_nodes a node in a BST
    if(root == NULL){                              //if the root is NULL
        root = malloc(sizeof(NodeAddress));        //allocate memory for the root
        root->val = val;                           //set the value of the root to the value of the node
        root->left = NULL;                         //set the left child of the root to NULL
        root->right = NULL;                        //set the right child of the root to NULL
        return root;                               //return the root
    }

    if(val < root->val){                           //if the value of the node is less than the value of the root
        root->left = add_nodes(root->left, val);      //add_nodes the node in the left subtree
    }

    else{                                          //if the value of the node is greater than the value of the root
        root->right = add_nodes(root->right, val);    //add_nodes the node in the right subtree
    }

    return root;                                   //return the root
}

//************************************************

//Convert an array to a BST by adding nodes from the array

//************************************************

NodeAddress * Convert_Array_to_BST(int *a, int n){ //function to make a BST from an array
    NodeAddress * root = malloc(sizeof(NodeAddress)); //allocate memory for the root
    root -> val = a[0];                    //set the value of the root to the value of the first node
    root->left = NULL;                     //set the left child of the root to NULL
    root->right = NULL;                    //set the right child of the root to NULL
    NodeAddress * temp = root;             //set the temp to the root
    int i;                                 //counter

    for(i=1;i<n;i++){                      //loop through the array
        temp = add_nodes(temp, a[i]);      //add_nodes the node to the BST
    }

    return root;                           //return the root
}
//************************************************

//Outputing nodes in prefix order to make a tree from the array

void output_tree(NodeAddress * root){ //function to output the nodes in prefix order

    if(root == NULL){                 //if the root is NULL
        return;                       //return
    }
    output_tree(root->left);          //output the left subtree
    printf("%d ", root->val);         //output the value of the root
    output_tree(root->right);         //output the right subtree
}

//************************************************

//Runing the code to check if it works and build BST from array

int main(){                      
    int a[] = {21, 65, 33, 23,11, 43, 7, 89}; //array to be converted to BST
    NodeAddress * root = Convert_Array_to_BST(a, 8); //convert the array to BST
    output_tree(root);  //output the nodes in prefix order
    return 0; 
}

//************************************************

// End Code

//************************************************