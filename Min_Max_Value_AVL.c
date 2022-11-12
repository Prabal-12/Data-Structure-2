//Code to find the minimum and maximum value in an AVL tree

//AVL tree minimum
NodeAddress minimum (NodeAddress root) //root is the root of the AVL tree
{
    NodeAddress x = root; //x is the node address of the root
    while (x -> left) //while x has a left child
        x = x -> left; //x is the left child
    return x;          //return the node address of the minimum value
}

//AVL tree maximum
NodeAddress maximum (NodeAddress root) //root is the root of the AVL tree
{
    NodeAddress x = root; //x is the node address of the root
    while (x -> right) //while x has a right child
        x = x -> right; //x is the right child
    return x;         //return the node address of the maximum value
}

//End of code

//*****************************************************