//Code for finding the minimum and successor in an AVL tree

//AVL tree minimum
NodeAddress minimum (NodeAddress root) //root is the root of the tree
{
    NodeAddress x = root; //x is the node to be returned
    while (x -> left) //while x has a left child
        x = x -> left; //x is the left child
    return x;  //return x
}

//*********************************************

//AVL tree successor
NodeAddress successor (NodeAddress x) //x is the node to find the successor of
{
    if (x -> right) //if x has a right child
        return minimum (x -> right); //return the minimum of the right subtree
    NodeAddress y = x -> parent; //y is the parent of x
    while (y && x == y -> right) //while y exists and x is the right child of y
    {
        x = y; //x is y
        y = y -> parent; //y is the parent of y
    }
    return y;
}

//*********************************************
//End of code

//*********************************************