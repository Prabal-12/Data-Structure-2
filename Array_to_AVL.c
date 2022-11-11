//Code to convert Array into an AVL tree 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*************************************
// defining AVL Tree structure

struct node{ //node structure
    int data; //data
    struct node *left; //left child
    struct node *right; //right child
    int height; //height of the node
};
typedef struct nodeType *NodeAddress; //node address

//*************************************

// Adding a new node to the tree
NodeAddress add_new_node(int data){ //add a new node
    NodeAddress node = (NodeAddress)malloc(sizeof(struct node)); //allocate memory for the node
    node->data = data; //set the data
    node->left = NULL; //set the left child to NULL
    node->right = NULL; //set the right child to NULL
    node->height = 0; //set the height to 0
    return node; //return the node
}

//*************************************

// Functions that returns the height of a node
int height(NodeAddress node){ //get the height of a node
    if(node == NULL) //if the node is NULL
        return -1;   //return -1
    else
        return node->height; //else return the height of the node
}

//*************************************

// Functions that returns the maximum of two numbers
int maximum(int a, int b){  //get the maximum of two numbers
    return (a > b)? a : b;  //return the maximum of two numbers
}

//*************************************


//get the balance factor of a node
int Balance_tree(NodeAddress node){ //get the balance factor of a node
    if(node == NULL)      //if the node is NULL
        return 0;       
    else
        return height(node->left) - height(node->right); //else return the balance factor
}

//*************************************


NodeAddress Rotate_AVL_Subtree_Right(NodeAddress head){ //right rotate
    NodeAddress temp_holder = head->left; //temp_holder node
    NodeAddress temp2 = temp_holder->right; //temp2 node
    temp_holder->right = y; //rotate
    head->left = temp2; //rotate
    head->height = maximum(height(head->left), height(head->right)) + 1; //update the height
    temp_holder->height = maximum(height(temp_holder->left), height(temp_holder->right)) + 1; //update the height
    return x;
}
//*************************************

NodeAddress Rotate_AVL_Subtree_Left(NodeAddress head){ //left rotate
    NodeAddress temp_holder = head->right; //temp_holder node
    NodeAddress temp2 = temp_holder->left; //temp2 node
    temp_holder->left = head; //rotate
    head->right = temp2; //rotate
    head->height = maximum(height(head->left), height(head->right)) + 1; //update the height
    temp_holder->height = maximum(height(temp_holder->left), height(temp_holder->right)) + 1;//update the height
    return temp_holder;
}

//*************************************
NodeAddress node_insert_AVL_Tree(NodeAddress head, int data){ //insert a node in the AVL tree
    if(head == NULL) //if the head is NULL
        return add_new_node(data); //add a new node
    if(data < head->data) //if the data is less than the head data
        head->left = node_insert_AVL_Tree(head->left, data); //insert the node in the left subtree
    else if(data > head->data) //if the data is greater than the head data
        head->right = node_insert_AVL_Tree(head->right, data); //insert the node in the right subtree
    else
        return head; //else return the head


    head->height = 1 + maximum(height(head->left), height(head->right)); //update the height of the node
    int balance = Balance_tree(head); //get the balance factor of the node
    if(balance > 1 && data < head->left->data) //if the balance factor is greater than 1 and the data is less than the left child data
        return Rotate_AVL_Subtree_Right(head); //right rotate
    if(balance < -1 && data > head->right->data) //if the balance factor is less than -1 and the data is greater than the right child data
        return Rotate_AVL_Subtree_Left(head);//left rotate
    if(balance > 1 && data > head->left->data){ //if the balance factor is greater than 1 and the data is greater than the left child data
        head->left = Rotate_AVL_Subtree_Left(head->left);//left rotate
        return Rotate_AVL_Subtree_Right(head); //right rotate
    }

    if(balance < -1 && data < head->right->data){//if the balance factor is less than -1 and the data is less than the right child data
        head->right = Rotate_AVL_Subtree_Right(head->right); //right rotate
        return Rotate_AVL_Subtree_Left(head); //left rotate
    }
    return head;
}

//*************************************
NodeAddress Convert_Array_AVL(int arr[], int n){ //converting an array into an AVL tree
    NodeAddress head = NULL; //head node
    for(int i = 0; i < n; i++) //loop through the array
        head = node_insert_AVL_Tree(head, arr[i]); //insert the node in the AVL tree
    return head; 
}

//*************************************

//Output the AVL tree
void Output_tree_nodes(NodeAddress head){ //output the AVL tree
    if(head == NULL)   //if the head is NULL
        return;
    Output_tree_nodes(head->left); //output the left subtree
    printf("%d ", head->data);  //output the data
    Output_tree_nodes(head->right); //output the right subtree
}

//*************************************

//Running the program to test the AVL tree work properly

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7,8,9,10}; //array
    int n = sizeof(arr)/sizeof(arr[0]); //size of the array
    NodeAddress head = Convert_Array_AVL(arr, n); //convert the array into an AVL tree
    Output_tree_nodes(head); //output the AVL tree
    return 0;
}

//*************************************

// Code Ends

//*************************************