#include <stdio.h>
#include <stdlib.h>

typedef struct dynArray DynArray;
struct dynArray{
	int* array; // Here, we implement a dynamic array of int
	size_t used; // The number of used entries
	size_t size; // The memory allocated to the array is stored here
};

void initialize_arr(DynArray* da, size_t size){
/* Initialize the dynamic array with "size" elements */
}

void insert_arr(DynArray* da, int element) {
	// check if array is full, then it is necessary to "extend" the array
        // update the size record
	// apply realloc with the updated size value
	// add element at the next index
}

void free_arr(DynArray* da) {
}

int main(){
	DynArray* dynarr;
	initialize_arr(dynarr, 7); // initialization with 7 elements
	for (int i = 0; i < 1000; i++)
		insert_arr(dynarr, i);

	printf("%d\n", dynarr->array[12]); // print 13th element
	printf("%d\n", dynarr->used); // print number of elements
	free_arr(dynarr);

	return 0;
}
