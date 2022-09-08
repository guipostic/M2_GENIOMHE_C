#include <math.h>

int foo_function( int(*funcPtr)(int), int myvalue ){
	/* This example function does nothing more than reusing another function */
	int resulting_value = (*funcPtr)(myvalue);
	printf("PRINT16B: %d\n", resulting_value);
	return resulting_value;
}

