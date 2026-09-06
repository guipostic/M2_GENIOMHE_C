#include <stdio.h>
#include <stdlib.h>

//typedef struct dynArray DynArray;
typedef struct{
	int* array; // Here, we implement a dynamic array of int
	size_t used; // The number of used entries
	size_t size; // The memory allocated to the array is stored here
} DynArray;

void initialize_arr(DynArray* da, size_t size){
/* Initialize the dynamic array with "size" elements */
	//da->array = malloc(size * sizeof(int)); // XXX No type casting
	da->used = 0;
	da->size = size;
}

void insert_arr(DynArray* da, int element) {
	if (da->used == da->size) { // check if array is full, then it is necessary to "extend" the array
		da->size *= 2; // update the size record
		da->array = realloc(da->array, da->size * sizeof(int)); // apply realloc with the updated size value
	}
	size_t index = da->used;
	da->array[index] = element; // add element at the next index
	//da->used++; // must be done only after adding element (otherwise: Error!)
	/* Note: about priority: da->array[da->used++] would update da->used only after the array has been accessed */
}

void free_arr(DynArray* da) {
	free(da->array);
	da->array = NULL;
	da->used = da->size = 0;
}

int main(){
	DynArray dynarr;
	initialize_arr(&dynarr, 7); // initialization with 7 elements
	for (int i = 0; i < 1000; i++)
		insert_arr(&dynarr, i);

	//printf("%d\n", dynarr->array[12]); // print 13th element
	//printf("%d\n", dynarr->used); // print number of elements
	//free_arr(dynarr);

	return 0;
}
