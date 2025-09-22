#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
	int data;
	Node* next;
};

int main(){
	Node* first_node = (Node*) malloc(1 * sizeof(Node));
	// NOTE: malloc returns a null pointer on failure
	if (first_node == NULL) {
		printf("Memory allocation failed\n");
		exit(0);
	}

	/******* WRITING *******/
	Node* current_node = first_node;
	current_node->data = 23;
	current_node->next = (Node*) malloc(1 * sizeof(Node));

	/* We
	 * - move the cursor
	 * - and then add values
	 * to the next node */
	current_node = current_node->next;
	current_node->data = 75;
	current_node->next = (Node*) malloc(1 * sizeof(Node));

	/* We
	 * - move the cursor
	 * - and then add values
	 * to the next node */
	current_node = current_node->next;
	current_node->data = 56;
	current_node->next = (Node*) malloc(1 * sizeof(Node));


	/******* READING *******/
	printf("%d, ", first_node->data);
	printf("%d, ", first_node->next->data);
	printf("%d, ", first_node->next->next->data);
	printf("%d, ", first_node->next->next->next->data); // This node has been defined, but no data value assigned
	printf("\n");

	/******* ERASING *******/
	free(first_node->next->next);
	printf("%d, ", first_node->data);
	printf("%d, ", first_node->next->data);
	printf("%d, ", first_node->next->next->data);
	// NOTE: dereferencing freed pointer = undefined behavior;
	// To avoid that, always set pointer to NULL after free()
	/*
	printf("%d, ", first_node->next->next->next->data);
	printf("\n");
	*/

}
