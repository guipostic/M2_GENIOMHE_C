#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
struct node{
	int data;
	Node* next;
};

/* In C, you don't need to cast the return value of malloc. The pointer to void returned by malloc is automagically converted to the correct type. However, if you want your code to compile with a C++ compiler, a cast is needed. A preferred alternative among the community is to use the following: int *sieve = malloc(sizeof *sieve * length); */


int main(){
	Node* first_node = (Node*) malloc(1 * sizeof(Node));
	Node* second_node = (Node*) malloc(1 * sizeof(Node));
	Node* third_node = (Node*) malloc(1 * sizeof(Node));
	first_node->data = 12;
	first_node->next = second_node;
	second_node->data = 1234;
	second_node->next = third_node;

	Node some_node;
	Node* some_node_ptr = &some_node;
	some_node.data = 78578678;
	some_node.next = (some_address)
}
