#include <stdio.h>
#include <stdlib.h> // strtol
#include <string.h> // memcpy

int main(){
	char myOneChar = 'A'; // Single character + single quotes

	char* myCharPointer = "ABCDE"; // One or more characters + double quotes
	char myCharArray[] = "VWXYZ"; 

	/* These two are different types, but the compiler automatically converts the array into a pointer */
	printf("CHAR POINTER: %s\n", myCharPointer);
	printf("CHAR ARRAY: %s\n", myCharArray);

	/* Modify a character */
	myCharArray[2] = '-';
	//myCharPointer[2] = '-'; // Invalid: "Segmentation fault (core dumped)"
	printf("MODIFIED CHAR ARRAY: %s\n", myCharArray);
	
	int strlen1 = sizeof(myCharArray)/sizeof(myCharArray[0]);	
	printf("STRING LENGTH (CHAR ARRAY): %d\n", strlen1); // LAST CHARACTER (MARKING END OF CHAIN) IS INVISIBLE (\0), BUT IS COUNTED

	/* WARNING: not the good method for char* (see #include <string.h> below)
	 * => will always be 8 */
	int strlen2 = sizeof(myCharPointer)/sizeof(myCharPointer[0]); // 8 / 1 = 8
	printf("STRING LENGTH (CHAR POINTER): %d\n", strlen2);


	/******************************************************************************/
	/* COPYING A STRING: THE WRONG WAY! (i.e. DOES NOT WORK) */
	char* some_string = "A"; // WARNING: this string is one-character long and strings cannot be extended (as any static array in C)
	//char some_string[] = ""; // This would make "some_string" a pointer; thus it would generate an error at the next line
	
	some_string = myCharArray; // NOTE: here a char array pointer is assigned to a char pointer
	printf("\nCOPIED STRING: %s\n", some_string);
	
	some_string[2] = '@'; // Again: only valid for a char array
	printf("MODIFIED COPIED STRING: %s\n", some_string);
	printf("CHAR ARRAY (SOURCE): %s\n", myCharArray); // THE SOURCE HAS BEEN MODIFIED AS WELL
	/******************************************************************************/


	/* About initialization
	 * These 3 are equivalent: */
	//char some_other_string[11] = {0}; // Initialize with eleven \0 (invisible character)
	//char some_other_string[11] = {};
	//char some_other_string[11] = "";

	/* Below, the first two characters are 'x', followed by ten \0: */
	char some_other_string[12] = {'x', 'x'};
	/* Note/conclusion: initializing a string with one hundred 'x' would require a loop */


	/* Some functions from the library: #include <string.h>
	 * Very Useful in Bioinformatics */

	// char* some_other_string = "Guillaume"; // The strcpy() call below would fail using a char*: Segmentation fault (core dumped)
	/* NOTE: invalid operations may still be accepted by some compilers
	 * - this is a bad thing!
	 * - this can be avoided by declaring "const char*" instead of "char*"*/


	/* strcpy:
	 * if you don't know the length (and adds a trailing \0) */
	printf("\nSTRING VALUE: %s\n", some_other_string);
	int strlen3 = sizeof(some_other_string)/sizeof(some_other_string[0]);	
	printf("STRING LENGTH: %d\n", strlen3);
	printf("STRING LENGTH (with strlen()): %ld\n", strlen(some_other_string)); // NOTE: strlen() does not count the \0, NOR THE SPACES XXX
	strcpy(some_other_string, "Hello world"); // "Hello world" is exactly 12 bytes (11 char + \0), so "some_other_string" should be declared as 12
	/* With "Hello world!" (13 bytes), the strcpy() would trigger a Warning */
	printf("STRING VALUE AFTER strcpy: %s\n", some_other_string);
	printf("STRING LENGTH (with strlen()): %ld\n", strlen(some_other_string)); // %ld because long unsigned int


	/* strncpy:
	 * if you know the length (and does NOT add \0) */


	/* Many other functions in this library
	 * https://en.wikipedia.org/wiki/C_string_handling#Functions
	 * https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/tp-len-tete-string-h/
	 * https://stackoverflow.com/questions/779875/what-function-is-to-replace-a-substring-from-a-string-in-c */


	/* Convert string to int or float (and vice versa) */
	char str_number[5] = "1000"; // XXX YOU MUST COUNT THE TRAILING \0 IN THE 5 CHARACTERS
	char* char_ptr;
	long converted_int = strtol(str_number, &char_ptr, 10); // 10 for the 10 base
	printf("\nCONVERTED TO INT: %ld\n", converted_int);
	/* Alternatively, see atoi() from <stdlib.h>, but should be avoided (undefined behaviour) */


	/* There is also strtof() and strtod() for float and double */


	/*To convert into str: */
	//sprintf(str, "%d", 42); // Again itoa() should be avoided


	/* Concatenation */
	//char *strcat(char *dest, const char *src);


	//memset()
	/* The C library function
	 * void *memset(void *str, int c, size_t n)
	 * copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. */

        return 0;
}
