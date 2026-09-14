#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
	int data;
	Node* next;
};

void print_list(Node* head){
	Node* current_node = head;
	while (current_node->next != NULL){
		printf("%d, ", current_node->data);
		current_node = current_node->next;
	}
	printf("\n");
}

void erase_list(Node* head){
	Node* current_node = head;
	Node* previous_node;
	while (current_node->next != NULL){
		previous_node = current_node;
		current_node = current_node->next;
		free(previous_node);
	}
}

int main(){
	Node* first_node = (Node*) malloc(1 * sizeof(Node));

	Node* current_node = first_node;

	for (int value = 0; value < 9; value++){
		current_node->data = value;
		current_node->next = (Node*) malloc(1 * sizeof(Node));
		current_node = current_node->next;
	}
	
	print_list(first_node);
	erase_list(first_node);
	print_list(first_node);
}
