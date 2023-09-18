#include<stdio.h>
#include <stdlib.h>

int main(){
	/* malloc: dynamic memory allocation (note: the memory blocks allocated are contiguous) */
	int* array = malloc(3 * sizeof(int)); // XXX No type casting;
	array[2] = 5;
	printf("FIRST PRINT: %d\n", array[2]);

	/* About the bound checking... */
	array[30] = 10;
	printf("BEFORE1: %d\n", array[30]);
	//array[3000000] = 10;
	//printf("BEFORE1: %d\n", array[3000000]);
	
	/* realloc: dynamic vs static memory allocation */
	int array2[] = {11, 12, 13};
	array2[30] = 10;
	printf("BEFORE2: %d\n", array2[29]);

	array = realloc(array, 4000000 * sizeof(int));
	//array2 = realloc(array2, 4000000 * sizeof(int));

	array[3000000] = 10;
	printf("AFTER1: %d\n", array[3000000]);
	printf("AFTER2: %d\n", array[3150002]);

	return 0;
}

/* Note: https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/ */
