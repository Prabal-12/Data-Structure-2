//Code for queue data structure long with enqueue and dequeue

#include <stdio.h>
#include <stdlib.h>

//****************************************************
struct queue //queue data structure
{
    int size; //size of the queue
    int front; //front of the queue
    int rear; //rear of the queue
    int *arr;  //array to store the elements of the queue
};

//****************************************************

int check_Full(struct queue *ptr) //function to check if the queue is full
{
    if (ptr->rear == ptr->size - 1) //if the rear of the queue is equal to the size of the queue - 1, then the queue is full
    {
        return 1; //return 1 if the queue is full
    }
    return 0; //return 0 if the queue is not full
}

//****************************************************

int check_Empty(struct queue *ptr) //function to check if the queue is empty
{
    if (ptr->front == ptr->rear) //if the front of the queue is equal to the rear of the queue, then the queue is empty
    {
        return 1; //return 1 if the queue is empty
    }
    return 0; //return 0 if the queue is not empty
}

//****************************************************

void enqueue(struct queue *ptr, int val) //function to enqueue an element to the queue
{
    if (check_Full(ptr)) //if the queue is full, then we cannot enqueue an element to the queue
    {
        printf("ueue is full, can't enqueue ", val); //printing a message to the user to show that the queue is full
    }

    else //if the queue is not full, then we can enqueue an element to the queue
    {
        ptr->rear++; //incrementing the rear of the queue
        ptr->arr[ptr->rear] = val; //adding the value to the rear of the queue
    }
}

//****************************************************

int dequeue(struct queue *ptr)
{
    if (check_Empty(ptr)) //if the queue is empty, then we cannot dequeue an element from the queue
    {
        printf("Queue is empty, Can;t dequeue  ");//printing a message to the user to show that the queue is empty
        return -1; //returning -1 to show that the queue is empty and exit
    }

    else //if the queue is not empty, then we can dequeue an element from the queue
    {
        ptr->front++; //incrementing the front of the queue
        int val = ptr->arr[ptr->front]; //storing the value of the front of the queue in a variable
        return val;  //returning the value of the front of the queue
    }
}

//****************************************************

int queueFront(struct queue *ptr) //function to return the value of the front of the queue
{
    return ptr->arr[ptr->front + 1]; //returning the value of the front of the queue
}
//****************************************************

int queueRear(struct queue *ptr) //function to return the value of the rear of the queue
{
    return ptr->arr[ptr->rear]; //returning the value of the rear of the queue
}

//****************************************************

// Runing the program to test the queue data structure is working properly along with it's functions
int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); //creating a queue
    q->size = 5; //setting the size of the queue
    q->front = q->rear = -1; //setting the front and rear of the queue to -1
    q->arr = (int *)malloc(q->size * sizeof(int)); //allocating memory to the queue

    enqueue(q, 10);//enqueueing 10 to the queue
    enqueue(q, 11);//enqueueing 11 to the queue
    enqueue(q, 12);//enqueueing 12 to the queue


    return 0;

}

//****************************************************

// Code ends 

//****************************************************
