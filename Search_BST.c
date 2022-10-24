// Code to search_BST a node in a BST 

#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library for malloc, free, etc.

//****************************************

struct nodeType{ // Defing and making nodes for the linked list
    int val;                    // value of the node
    struct nodeType *left;      //left child such that the child is smaller than parent
    struct nodeType *right;     //right child such that the child is larger than parent

};


typedef struct nodeType NodeAddress; //defining a new data type

//****************************************
//search in the BST for a element
//****************************************

NodeAddress *search_BST(NodeAddress *root, int val){ //function to search_BST a node in a BST
    if(root == NULL){                  //if the root is NULL
        return NULL;             //return NULL
    }

    if(root->val == val){          //if the value of the root is equal to the value of the node
        return root;               //return the root
    }

    if(val < root->val){           //if the value of the node is less than the value of the root
        return search_BST(root->left, val); //search_BST the node in the left subtree
    }

    else{  //if the value of the node is greater than the value of the root                        
        return search_BST(root->right, val); //search_BST the node in the right subtree
    }
}

//****************************************
NodeAddress *search_BST(NodeAddress *root, int val){ //function to search_BST a node in a BST
         return root?(val==root->val)?root:(val<root->val)?search_BST_2(root->left,val):search_BST_2(root->right,val):NULL; //ternary operator
}

//****************************************

//Add a node into the BST tree
NodeAddress * Add_node(NodeAddress * root, int val){ //function to add a node into the tree
    if(root == NULL){                                //if the root is NULL
        root = malloc(sizeof(NodeAddress));          //allocate memory for the root
        root->val = val;                              //assign the value to the root
        root->left = NULL;                            //assign the left child to NULL
        root->right = NULL;                            //assign the right child to NULL
        return root;                                   //return the root
    }

    if(val < root->val){                               //if the value of the node is less than the value of the root
        root->left = Add_node(root->left, val);        //add the node to the left subtree
    }

    else{                                               //if the value of the node is greater than the value of the root
        root->right = Add_node(root->right, val);       //add the node to the right subtree
    }
    return root;                                        //return the root
}

//****************************************

//Convert Array to BST
NodeAddress * Convert_array_BST(int *a, int n){ //function to convert an array to BST
    NodeAddress * root = malloc(sizeof(NodeAddress));  //allocate memory for the root
    root -> val = a[0];  //assign the value to the root
    root->left = NULL;   //assign the left child to NULL
    root->right = NULL;  //assign the right child to NULL
    NodeAddress * temp = root; //assign the root to the temp
    int i;                     //counter

    for(i=1;i<n;i++){          //loop to add the nodes to the tree
        temp = Add_node(temp, a[i]); //add the node to the tree
    }
    return root;             //return the root

    //****************************************
}

//****************************************

// Check if the tree is BST search is working or not

int main(){   //main function //
    int a[] = {6, 7, 2, 4, 3, 1, 5,9,10,8,};//array to be converted to BST
    NodeAddress * root = Convert_array_BST(a, 10); //convert the array to BST
    NodeAddress * temp = search_BST(root, 4);  //search for a node in the BST
    printf("%d ", temp->val);  //print the value of the node
    return 0;    //return 0
}

//****************************************

// Code Ends

//****************************************