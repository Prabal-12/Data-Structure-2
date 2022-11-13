//Code for deleting a node from AVL tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//**************************************************
//transplant function
void transplant (NodeAddress delete_element, NodeAddress replace_element) //delete_element is the node to be deleted and replace_element is the node to be replaced
{
    if (!delete_element -> parent) //if delete_element is the root
        root = replace_element; //replace_element is the new root
    else if (delete_element == delete_element -> parent -> left) //if delete_element is the left child of its parent
        delete_element -> parent -> left = replace_element; // replace_element is the new left child of delete_element's parent
    else //if delete_element is the right child of its parent
        delete_element -> parent -> right = replace_element; // replace_element is the new right child of delete_element's parent
    if (replace_element) //if replace_element is not null
        replace_element -> parent = delete_element -> parent; //replace_element's parent is delete_element's parent
}

//**************************************************

//Element from AVL to be deleted is passed as argument

//**************************************************
NodeAddress delete (NodeAddress root, int val) //root is the root of the AVL tree and val is the value of the node to be deleted
{
    NodeAddress element_to_delete = root; //element_to_delete is the node to be deleted
    while (element_to_delete && element_to_delete -> val != val) //searching for the node to be deleted
    {
        if (val < element_to_delete -> val) //if val is less than the value of the current node
            element_to_delete = element_to_delete -> left; //go to the left child
        else
            element_to_delete = element_to_delete -> right; //go to the right child
    }
    if (!element_to_delete) //if the node to be deleted is not found
        return root;

    if (!element_to_delete -> left) //if the left child of the node to be deleted is null
        transplant (element_to_delete, element_to_delete -> right); //replace the node to be deleted with its right child
    else if (!element_to_delete -> right) //if the right child of the node to be deleted is null
        transplant (element_to_delete, element_to_delete -> left); //replace the node to be deleted with its left child
    else

    {
        NodeAddress y = minimum (element_to_delete -> right); //y is the minimum element in the right subtree of the node to be deleted
        if (y -> parent != element_to_delete) //if y is not the right child of the node to be deleted
        {
            transplant (y, y -> right); //replace y with its right child
            y -> right = element_to_delete -> right; //y's right child is the right child of the node to be deleted
            y -> right -> parent = y; //y's right child's parent is y
        }
        transplant (element_to_delete, y); //replace the node to be deleted with y
        y -> left = element_to_delete -> left; //y's left child is the left child of the node to be deleted
        y -> left -> parent = y; //y's left child's parent is y

    }
    return root;
}


//**************************************************

//Code ends

//**************************************************