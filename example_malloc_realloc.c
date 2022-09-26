#include<stdio.h>
#include <stdlib.h>

int main(){
	int* array = malloc(3 * sizeof(int)); // XXX No type casting;
	array[2] = 5;
	printf("FIRST PRINT: %d\n", array[2]);

	//array[3000000] = 10;
	//printf("BEFORE: %d\n", array[3000000]);
	
	array = realloc(array, 4000000 * sizeof(int));

	array[3000000] = 10;
	printf("AFTER: %d\n", array[3150002]);

	return 0;
}
