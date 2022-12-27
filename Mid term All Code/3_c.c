//Given any two integers x and y in the Reverse BST, find the distance between the two in sorted order. That is, count how many numbers lie in between these two integers x and y. If x, y or both x and y don’t exist in the BST, return -1.

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeAddress   //defining a tree node
{
    int val;
    struct NodeAddress *left; //left child
    struct NodeAddress *right;  //right child
    struct NodeAddress *parent;  //parent
} NodeAddress;


NodeAddress *createNode(int val) //creating a tree node
{
    NodeAddress *newNode = (NodeAddress *)malloc(sizeof(NodeAddress)); //allocating memory for the new node
    newNode->val = val;  //assigning the value to the new node
    newNode->left = NULL;  //initializing the left child to NULL
    newNode->right = NULL;   // initializing the right child to NULL
    newNode->parent = NULL; //initializing the parent to NULL
    return newNode;         //returning the new node
}

NodeAddress *arrayToReverseBST(int *a, int n) //function to create a reverse BST
{
    NodeAddress *root = NULL; //initializing the root to NULL
    for (int i = 0; i < n; i++)
    {
        NodeAddress *newNode = createNode(a[i]); //creating a new node
        if (root == NULL) //if the root is NULL
        {
            root = newNode; //assigning the new node to the root
        }
        else
        {
            NodeAddress *temp = root; //creating a temporary node and assigning the root to it
            while (temp != NULL) //while the temporary node is not NULL
            {
                if (newNode->val < temp->val) //if the value of the new node is less than the value of the temporary node
                {
                    if (temp->left == NULL) //if the left child of the temporary node is NULL
                    {
                        temp->left = newNode; //assigning the new node to the left child of the temporary node
                        newNode->parent = temp; //assigning the temporary node to the parent of the new node
                        break; //breaking out of the loop
                    }
                    else
                    {
                        temp = temp->left; //assigning the left child of the temporary node to the temporary node
                    }
                }
                else //if the value of the new node is greater than the value of the temporary node
                {
                    if (temp->right == NULL) //if the right child of the temporary node is NULL
                    {
                        temp->right = newNode; //assigning the new node to the right child of the temporary node
                        newNode->parent = temp; //assigning the temporary node to the parent of the new node
                        break; //breaking out of the loop
                    }
                    else
                    {
                        temp = temp->right; //assigning the right child of the temporary node to the temporary node
                    }
                }
            }
        }
    }
    return root; //returning the root
}


void sortReverseBST(NodeAddress *root) //sorting the reverse binary tree in ascending order
{
    if (root == NULL) //if the root is NULL
    {
        return; //return
    }
    
    sortReverseBST(root->right); //calling the function recursively for the right child of the root
    sortReverseBST(root->left);  //calling the function recursively for the left child of the root
}


void printTree(NodeAddress *root)  //print values in the tree
{
    if (root == NULL) //if the root is NULL
    {
        return; //return
    }
    
    printTree(root->right); //calling the function recursively for the right child of the root
    printf("%d ", root->val); //printing the value of the root
    printTree(root->left);  //calling the function recursively for the left child of the root
}


int NumberOfElements(NodeAddress *root) //finding number of elements in the tree
{
    if (root == NULL) //if the root is NULL
    {
        return 0; //return 0
    }
    else
    {
        return NumberOfElements(root->left) + NumberOfElements(root->right) + 1; //returning the number of elements in the left subtree + number of elements in the right subtree + 1
    }
}

//converting the tree to an array
void treeToArray(NodeAddress *root, int *a, int *i) //function to convert the tres to an array
{
    if (root == NULL) // if the root is NULL
    {
        return; //return
    }
    treeToArray(root->right, a, i); //calling the function recursively for the right child of the root
    a[*i] = root->val; //assigning the value of the root to the array
    (*i)++; //incrementing the index
    treeToArray(root->left, a, i); //calling the function recursively for the left child of the root
}

//print the array
void printArray(int *a, int n) //function to print the array
{
    for (int i = 0; i < n; i++) //for loop to print the array
    {
        printf("%d ", a[i]); //printing the array
    }
    printf("\n"); //printing a new line
}

//finding the distance between two integers in the reverse binary tree
int findDistance(NodeAddress *root, int x, int y)
{   int d = 0;  //initializing the distance to 0
    int m = NumberOfElements(root); //  finding the number of elements in the tree
    int b[m]; //creating an array of size m
    int i = 0; //initializing the index to 0
    treeToArray(root, b, &i); //    converting the tree to an array
    //printArray(b, m);

    int pc = -1; //position of x intial 
    int pc1 = -1;  //position of y intial 

    
    if (x > y) //swapping x and y if x is larger than y
    {
        int temp = x;
        x = y;
        y = temp;
    }

    for(int i=0; i<m; i++) // Finding positiion of x 
    {   
        if(b[i] == x)
        {
            pc = i;
        }
        if(b[i] == y)
        {
            pc1 = i;
        }
    d =  pc1 - pc; //finding the distance between the two integers
    }

    return d; //returning the distance between x and y
}



int main()
{
    //ititializing a random array
    int a[] = {7,4,9,4,6,8,10,3};
    int n = sizeof(a) / sizeof(a[0]);//finding the size of the array
    NodeAddress *root = arrayToReverseBST(a, n);//creating a reverse binary tree
    
    sortReverseBST(root); //sorting the reverse binary tree in ascending order
    printTree(root);
    int x,y;
    printf("Enter the element 1: "); //entering the first element
    scanf("%d", &x);
    printf("Enter the element 2: "); //entering the second element
    scanf("%d", &y);
    int d= findDistance(root, x, y);  //finding the distance between the two elements
    printf("The distance between %d and %d is: %d\n", x, y, d); //printing the distance

    return 0;
}