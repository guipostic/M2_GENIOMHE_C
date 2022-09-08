#include <stdio.h>
#include <stdlib.h> // for exit

void main(){
	FILE *f = fopen("file.txt", "w");
	if (f == NULL){
	    printf("Error opening file!\n");
	    exit(1);
	}
	
	/* print some text */
	const char *text = "Write this to the file";
	fprintf(f, "Some text: %s\n", text);
	
	/* print integers and floats */
	int i = 1;
	float pi= 3.1415927;
	fprintf(f, "Integer: %d, float: %f\n", i, pi);
	
	/* printing single characters */
	char c = 'A';
	fprintf(f, "A character: %c\n", c);
	
	fclose(f);
}
