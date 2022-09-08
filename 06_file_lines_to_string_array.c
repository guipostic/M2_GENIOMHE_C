#include <stdio.h>
#define MAX_LINES 100
#define MAX_LEN 1000

int main(void){
	char data[MAX_LINES][MAX_LEN];
  
	FILE *file;
	file = fopen("some_text.txt", "r");
  
	if (file == NULL){
		printf("Error opening file.\n");
		return 1;
	}
  
	int line = 0;
  
	while (!feof(file) && !ferror(file))
		if (fgets(data[line], MAX_LEN, file) != NULL)
			line++;
  
	fclose(file);
   
	for (int i = 0; i < line; i++)
		printf("%s", data[i]);

	return 0;
}
