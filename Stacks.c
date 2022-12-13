//Code to create a stacks data structure in C

#include <stdio.h>
#include <stdlib.h>

//*****************************************

struct stack //stack data structure
{
    int size;  //size of the stack
    int top;   //top of the stack
    int *arr;  //array to store the elements of the stack
};


//*****************************************

int check_full(struct stack *ptr) //function to check if the stack is full
{
    if (ptr->top == ptr->size - 1) //if the top of the stack is equal to the size of the stack - 1, then the stack is full
    {
        return 1; //return 1 if the stack is full
    }
    return 0; //return 0 if the stack is not full
}

//*****************************************

int check_Empty(struct stack *ptr) //function to check if the stack is empty
{
    if (ptr->top == -1) //if the top of the stack is equal to -1, then the stack is empty
    {
        return 1; //return 1 if the stack is empty
    }
    return 0; //return 0 if the stack is not empty
}

//*****************************************

void push(struct stack *ptr, int val) //function to push an element into the stack
{
    if (check_full(ptr)) //if the stack is full, then print a message to the user
    {
        printf("Stack is full, Cannot push %d to the stack ", val); //printing a message to the user to show that the stack is full
    }
    else //if the stack is not full, then push the element into the stack
    {
        ptr->top++; //incrementing the top of the stack
        ptr->arr[ptr->top] = val; //adding the value to the top of the stack
    }
}

//*****************************************

int pop(struct stack *ptr) //function to pop an element from the stack
{
    if (check_Empty(ptr)) //if the stack is empty, then print a message to the user
    {
        printf(" stack is empty,therefore, Can't push"); //printing a message to the user to show that the stack is empty
        return -1; //return -1 if the stack is empty
    }
    else //if the stack is not empty, then pop the element from the stack
    {
        int val = ptr->arr[ptr->top]; //storing the value of the top of the stack in a variable
        ptr->top--; //decrementing the top of the stack
        return val; //returning the value of the top of the stack
    }
}

//*****************************************

int stackTop(struct stack *ptr) //function to return the top of the stack element
{
    return ptr->arr[ptr->top]; //returning the top of the stack element
}

//*****************************************

int stackBottom(struct stack *ptr) //function to return the bottom of the stack element
{
    return ptr->arr[0]; //returning the bottom of the stack element
}

//*****************************************

// running the program to test the stack functions
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack)); //creating a stack
    s->size = 12; //setting the size of the stack
    s->top = -1;  //setting the top of the stack to -1
    s->arr = (int *)malloc(s->size * sizeof(int)); //allocating memory to the stack
    printf("Stack has been created successfully "); //printing a message to the user to show that the stack has been created successfully
    printf(" Before pushing, Full: %d  ", check_full(s)); //printing a message to the user to show that the stack is not full
    printf(" Before pushing, Empty: %d  ", check_Empty(s)); //printing a message to the user to show that the stack is empty
    push(s, 1); //pushing an element into the stack
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6); //pushing an element into the stack
    push(s, 7);
    push(s, 8);
    push(s, 9);
    push(s, 10);
    push(s, 11); //pushing an element into the stack


    return 0;
}


//*****************************************

//End of program

//*****************************************
