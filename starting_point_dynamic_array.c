#include <stdio.h>
#include <stdlib.h>

typedef struct dynArray DynArray;
struct dynArray{
	int* array; // Here, we implement a dynamic array of int
	size_t used; // The number of used entries
	size_t size; // The memory allocated to the array is stored here
};
