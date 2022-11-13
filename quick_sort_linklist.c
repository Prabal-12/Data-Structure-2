#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* link;
};

void add_nodes(struct node** head, int new_data)
{
	struct node* new
		= (struct node*)malloc(sizeof(struct node));
	new->data = new_data;
	new->link = (*head);
	(*head) = new;
}

struct node* end(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL && temp->link != NULL) {
        temp = temp->link;
    }
    return temp;
}


struct node* parition(struct node* start, struct node* end)
{
	struct node* pivot = start; //pivot is the first node
	struct node* head = start; 
	int temp = 0; //temp variable to swap data
	
	while (head != NULL && head != end) {
		if (head->data < end->data) {
			pivot = start;

			// Swapping node values
			temp = start->data;
			start->data = head->data;
			head->data = temp;

			// Moving to next node
			start = start->link;
		}

		//	// Moving to next node
		head = head->link;
	}

	// Swapping node values
	temp = start->data;
	start->data = end->data;
	end->data = temp;
	return pivot;
}

void quick(struct node* start, struct node* end)
{
	if (start == end) {
		return;
	}
	struct node* pivot = parition(start, end);

	if (pivot != NULL && pivot->link != NULL) {
		quick(pivot->link, end);
	}

	if (pivot != NULL && start != pivot) {
		quick(start, pivot);
	}
}

/* Function to print linked list */
void print_data(struct node *head){
    if (head == NULL){
        printf("The list is empty");
    }
    struct node *pointer = NULL;
    pointer = head;
    while (pointer != NULL){
        printf("%d ",pointer->data);
        pointer = pointer->link;
    }
}

int main()
{
	struct node* unsorted = NULL;

	// Create linked list
	add_nodes(&unsorted, 78748);
	add_nodes(&unsorted, 842);
	add_nodes(&unsorted, 4984);
	add_nodes(&unsorted, 47);
	printf("\nBefore Sort ");
	print_data(unsorted);

	// Function call
	quick(unsorted, end(unsorted));
	printf("\nAfter Sort ");
	print_data(unsorted);
	return 0;
}
