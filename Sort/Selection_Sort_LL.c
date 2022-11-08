#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* start = NULL; // first node
struct node* last = NULL; // last node
struct node* proxy; // temporary node

struct node* newNode(int x) // create new node
{
	struct node* temp = (struct node*)malloc(sizeof(struct node)); // allocate memory for new node
	temp->data = x;//  assign data to new node
	temp->link = NULL; //           assign NULL to link of new node
	return temp; //            return new node
}

void Exchanged(struct node* a, struct node* b); // exchange two nodes

void adding_nodes(int n) // add node to the end of the list
{
	struct node* temp = newNode(n); // create new node
	if (start == NULL) { // if list is empty
		start = temp; // assign new node to start
		last = temp; // assign new node to last
	}
	else {
		last->link = temp; // add node to the end of the list
		last = temp;// update last node
	}
}

void print_data(struct node *head){ //  print data of the list
    if (head == NULL){              // if list is empty
        printf("The list is empty"); // print message
    }
    struct node *pointer = NULL;   // temporary node
    pointer = head;                  // assign head to pointer
    while (pointer != NULL){          // loop until pointer is not NULL
        printf("%d ",pointer->data);  // print data of pointer
        pointer = pointer->link;       // move pointer to next node
    } 
}

void OutputLinked()                       // // print data of the list
{
    proxy = start;                    // assign start to proxy
    while(proxy->link != NULL)          
    {
        printf("%d ", proxy->data);    //   
        proxy = proxy->link;
    }
    printf("%d ", proxy->data);     // print data of last node
}


void selection()
{
    struct node* i;
    i = start;

    while(i != NULL)
    {
        proxy = i->link; //proxy is the next node
        while(proxy != NULL)
        {
            if(i->data > proxy->data) // if the first node is greater than the second node
            {
                Exchanged(i, proxy); // Exchanged the nodes
            }
            proxy = proxy->link; // move to the next node
        }
        i = i->link;
    }
}

void Exchanged(struct node *x, struct node *y)
{
    int temp = x->data;
    x->data = y->data;
    y->data = temp;
}

int main()
{

	// Create linked list
	adding_nodes(8378398);
	adding_nodes(849);
	adding_nodes(379);
	adding_nodes(8398);
	printf("\nBefore Sort \n");
	OutputLinked();

	// Function call
	selection();
	printf("\nAfter Sort \n");
	OutputLinked();
	return 0;
}
