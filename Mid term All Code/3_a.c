#include <stdio.h>
#include <stdlib.h>

//defining a tree node
typedef struct NodeAddress // NodeAddress is a struct 
{
    int val;
    struct NodeAddress *left; // left is a pointer to a struct NodeAddress
    struct NodeAddress *right; // right is a pointer to a struct NodeAddress
    struct NodeAddress *parent; // parent is a pointer to a struct NodeAddress
} NodeAddress;

//creating a tree node
NodeAddress *createNode(int val) // createNode is a function that returns a pointer to a struct NodeAddress
{
    NodeAddress *newNode = (NodeAddress *)malloc(sizeof(NodeAddress)); // newNode is a pointer to a struct NodeAddress
    newNode->val = val; // newNode is a pointer to a struct NodeAddress, so newNode->val is the val field of the struct NodeAddress that newNode points to
    newNode->left = NULL; // newNode is a pointer to a struct NodeAddress, so newNode->left is the left field of the struct NodeAddress that newNode points to
    newNode->right = NULL; // newNode is a pointer to a struct NodeAddress, so newNode->right is the right field of the struct NodeAddress that newNode points to
    newNode->parent = NULL; // newNode is a pointer to a struct NodeAddress, so newNode->parent is the parent field of the struct NodeAddress that newNode points to
    return newNode; // return a pointer to a struct NodeAddress
}

//converting the array to a reverse tree (left child is always larger and right child is always smaller)
NodeAddress *arrayToReverseBST(int *a, int n) // Function to reverse an array on BST 
{
    NodeAddress *root = createNode(a[0]); // root is a pointer to a struct NodeAddress
    NodeAddress *CurrentValue = root;         // CurrentValue is a pointer to a struct NodeAddress
    for (int i = 1; i < n; i++)          // Looping when i is less than and increment i by 1 with each passing round
    {
        CurrentValue = root;                 // Current , the starting point starts with the root (top of the tree)
        while (CurrentValue != NULL)          //While CurrentValue is not equal to NULL
        {
            if (a[i] > CurrentValue->val)   //  If the value of the array is greater than the value of the CurrentValue node

            {
                if (CurrentValue->left == NULL) //   If the left child of the CurrentValue node is NULL
                {
                    //assigning the left child if it is larger than the parent 
                    CurrentValue->left = createNode(a[i]); //  Assign the left child of the CurrentValue node to the value of the array
                    CurrentValue->left->parent = CurrentValue; //  Assign the parent of the left child to the CurrentValue node
                    break; //  Break out of the loop
                }
                else
                {
                    CurrentValue = CurrentValue->left; //  Assign the CurrentValue node to the left child of the CurrentValue node
                }
            }
            else //  If the value of the array is less than the value of the CurrentValue node
            {
                //assigning the right child if it is smaller than the parent
                if (CurrentValue->right == NULL) //  If the right child of the CurrentValue node is NULL
                {
                    CurrentValue->right = createNode(a[i]); //  Assign the right child of the CurrentValue node to the value of the array
                    CurrentValue->right->parent = CurrentValue; //  Assign the parent of the right child to the CurrentValue node
                    break; //  Break out of the loop
                }
                else
                {
                    CurrentValue = CurrentValue->right; //  Assign the CurrentValue node to the right child of the CurrentValue node
                }
            }
            
        }
    }
    return root;
}

void prefixPrint(NodeAddress *root) //printing the tree in prefix order (root, left child, right child)
{
    if (root != NULL) //  If the root is not NULL
    {
        printf("%d ", root->val); //  Print the value of the root
        prefixPrint(root->left); //  Print the left child of the root
        prefixPrint(root->right); //  Print the right child of the root
    }
    
}

int main()
{
    //initiallizing a random array
    int a[] = {464, 684, 387, 265, 56, 2345, 87}; //  Array of integers
    int n = sizeof(a) / sizeof(a[0]);  //  n is the size of the array divided by the size of the first element of the array
    NodeAddress *root = arrayToReverseBST(a, n); //  root is a pointer to a struct NodeAddress, arrayToReverseBST is a function that returns a pointer to a struct NodeAddress
    prefixPrint(root);  //  Print the tree in prefix order
    return 0;           //  Return 0 , Stoping the program 
}