// Code to delete_node an element from a BST 

#include <stdio.h> // standard input/output library
#include <stdlib.h> // standard library

//****************************************

struct nodeType{                // Defing and making nodes for the linked list
    int val;                    // value of the node
    struct nodeType *left;      //left child such that the child is smaller than parent
    struct nodeType *right;     //right child such that the child is larger than parent
};

typedef struct nodeType NodeAddress;

//****************************************

// add a node to the tree

NodeAddress * add_node_tree(NodeAddress * root, int val){ //function to add a node in a BST
    if(root == NULL){    //if the root is NULL
        root = malloc(sizeof(NodeAddress)); //allocate memory for the root
        root->val = val;                    //set the value of the root to the value of the node
        root->left = NULL;                  //set the left child of the root to NULL
        root->right = NULL;                 //set the right child of the root to NULL
        return root;                        //return the root
    }
    
    if(val < root->val){                    //if the value of the node is less than the value of the root
        root->left = add_node_tree(root->left, val); //add the node in the left subtree
    }

    else{                                   //if the value of the node is greater than the value of the root
        root->right = add_node_tree(root->right, val); //add the node in the right subtree
    }

    return root;                            //return the root
}

//****************************************

//Convert array into a tree 

NodeAddress * Convert_array_BST(int *a, int n){ //function to convert an array into a BST
    NodeAddress * root = malloc(sizeof(NodeAddress)); //allocate memory for the root
    root -> val = a[0];                   //    set the value of the root to the value of the first element of the array
    root->left = NULL;                    //    set the left child of the root to NULL
    root->right = NULL;                   //    set the right child of the root to NULL
    NodeAddress * temp = root;            //    set the temp to the root
    int i;                                //    declare a variable i

    for(i=1;i<n;i++){                     //    for loop to add the rest of the elements of the array to the BST
        temp = add_node_tree(temp, a[i]); //    add the node to the BST
    }
    return root;                           //return the root
}

//****************************************

// output the tree in order from the linked list defined above
void output_node_tree(NodeAddress * root){ //function to output the tree in order
    if(root == NULL){                      //if the root is NULL
        return;                            //return
    }

    output_node_tree(root->left);          //output the left subtree
    printf("%d ", root->val);              //output the value of the root
    output_node_tree(root->right);         //output the right subtree
}

//****************************************

//delete_node a node from the tree

//****************************************

NodeAddress * delete_node(NodeAddress * root, int val){ //function to delete_node a node from the BST
    if(root == NULL){                         //if the root is NULL
        return NULL;                          //return NULL
    }

    if(val < root->val){                      //if the value of the node is less than the value of the root
        root->left = delete_node(root->left, val); //delete the node from the left subtree
    }

    else if(val > root->val){                      //if the value of the node is greater than the value of the root
        root->right = delete_node(root->right, val);//delete the node from the right subtree
    }

    else{
        if(root->left == NULL){                  //if the left child of the root is NULL
            NodeAddress * temp = root->right;    //set the temp to the right child of the root
            free(root);                          //free the root
            return temp;                         //return the temp
        }

        else if(root->right == NULL){            //if the right child of the root is NULL
            NodeAddress * temp = root->left;     //set the temp to the left child of the root
            free(root);                          //free the root
            return temp;                          //return the temp
        }

        else{                                   //if the left and right child of the root is not NULL
            NodeAddress * temp = root->right;   //set the temp to the right child of the root

            while(temp->left != NULL){          //while the left child of the temp is not NULL
                temp = temp->left;              //set the temp to the left child of the temp
            }
            root->val = temp->val;              //set the value of the root to the value of the temp
            root->right = delete_node(root->right, temp->val); //delete the node from the right subtree
        }
    } 
    return root;                                  //return the root
}


//****************************************

// Runing the code to test the functions of remove_node from the tree (BST)
//****************************************

int main(){
    int a[] = {6, 3, 2, 7, 1, 9, 8,5}; //array to be converted into a BST
    NodeAddress * root = Convert_array_BST(a, 8); //convert the array into a BST

    output_node_tree(root);          //output the tree in order
    delete_node(root, 3);            //delete the node with value 3 from the BST

    printf("\n BST after delete_node:\n");   //print after delete_node
    output_node_tree(root);                  //output the tree in order
    
    return 0;
}


//****************************************

// Code END

//****************************************