//preprocessor directives
#include <stdio.h> // printf
#include <stdbool.h>
#include "foo_test.h"
#define SIZE 4 // SIZE is a "macro"

typedef unsigned long int ulint;
/* NOTE:
 * Maximum value for a variable of type int:                       2,147,483,647
 * Maximum value for a variable of type unsigned int:              4,294,967,295
 * Maximum value for a variable of type long long int: 9,223,372,036,854,775,807 (= 2^63-1; maximum number of positive values for a signed 64-bit integer)
*/


////////////////
// STRUCTURES //
////////////////

typedef struct enemy Enemy; // Alias to type "Enemy" instead of "struct enemy"
struct enemy{
	/* Structure "members": */
	char name[100];
	int life;
	int strength;
	/* Structures are data types so no values */
}; // XXX

typedef struct level Level;
struct level{
	int length;
	char name[100];
} Level_default = {23, "missing_name"}; // Define default value


/* Alternative syntax for aliases */
typedef struct{
	int lifeup;
} Item;


////////////////
// PROTOTYPES //
////////////////

int andOne(int inputvalue);
/* If no prototype => warning: implicit declaration of function */

void andOneMutability(int* ptr_inputvalue);


//////////
// MAIN //
//////////
int main(){
/* NOTE: the main() function is called by the operating system */
        printf("PRINT00\n");
	/* Print format */
	printf("PRINT01A: %10d\n", 12345); // will print _____12345 (5 spaces before 12345)

	float foobar = 0.9375;
	printf("PRINT01B:%.2f\n", foobar);    // prints out 0.94

	/* puts(), fputs() */
	puts("PRINT02");
	fputs("PRINT03\n", stderr); // No added newline + select stream

	int foo = 1, bar = 2, baz = foo; // Declare and define multiple variables in one line
	float qux = 2.3, fred = 4.5; // They need to be of the same type

	int sum = 22, count = 3;

	float mean1;
	mean1 = sum / count;
	printf("PRINT04: Value of mean FLOAT : %f\n", mean1 );
	int mean2;
	mean2 = sum / count;
	printf("PRINT05: Value of mean INT : %d -------- %.12f\n", mean2, mean1 ); // test with %f => Warning

	/* Conversion or "type casting" */
	double mean;
	mean = (double) sum / count;
	printf("PRINT06: Value of mean FLOAT CAST: %f\n", mean );


	/*****************************
	 * 1. ARRAYS:
	 * - static
	 * - values of the same type
	 *****************************/

	int my_arrx[] = {9, 8, 7, 6};
        my_arrx[30] = 5; // Undefined Behavior (= nothing to interpret)

        //size_t n = sizeof(my_arr)/sizeof(my_arr[0]); // site_t or (unsigned) int; %ld and %d, respectively
	/* NOTE: no typeof() equivalent */
        int lol[SIZE] = {9, 8};
        lol[3] = 10;
        
        int my_arr[] = {9, 8, 7, 6};

	printf("PRINT07: array loop:\n");
        for (int i=0; i < SIZE; i++){
                printf("\t%d\n", my_arr[i]);
        }

	/* Initializing a multidimensional array
	 * Different ways to initialize two-dimensional array */
	int c[2][3] = {{1, 3, 0}, {-1, 5, 9}}; 
	//int c[][3] = {{1, 3, 0}, {-1, 5, 9}};
	//int c[2][3] = {1, 3, 0, -1, 5, 9};


	/* Initialization of a 3D array */
	int test[2][3][4] = {
		{{3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}},
		{{13, 4, 56, 3}, {5, 9, 3, 5}, {3, 1, 4, 9}}
				};

	/*****************************
	 * 2. Conditional statements *
	 * ***************************/
	bool statement1 = true;
	bool statement2 = false;
	if (statement1 && statement2){
		printf("PRINT08: Both are true\n");
	}
	if (statement1 || statement2){
		printf("PRINT09: One or more is true\n");
	}


	/****************
	 * 3. Functions *
	 * **************/
	int test1 = 10;
	int test2 = andOne(test1);
	printf("PRINT10: %d -> %d\n", test1, test2);


	/***************
	 * 4. Pointers *
	 * *************/
	printf("PRINT11: %p ....... %p\n", &test1, &test2);

	int* ptr_test1 = &test1;
	printf("PRINT12: %p\n", ptr_test1);
	/* Note: to have behavior defined by the C standard when printing a pointer, you should convert it to (void*) */

	// DEREFERENCING
	printf("PRINT13: BEFORE = %d\n", test1);
	(*ptr_test1)++;
	// versus: *ptr_test1++; // operator precedence rules
	printf("PRINT14: AFTER = %d\n", test1);

	int test3 = 1000;
	andOneMutability(&test3);
	printf("PRINT15: %d\n", test3);

	/* Define a function pointer */
	int(*functionPointer)(int);
	functionPointer = &andOne; // Note: NULL vs 0

	int result1 = (*functionPointer)(test3);
	printf("PRINT16A: %d\n", result1);

	int abc = 999999;
	foo_function(&andOne, abc); // function from a header file: no prototype needed
	double test_math = sqrt(9); // #include <math.h> is in the header file


	/****************
	* 5. Structures *
	* ***************/
	Enemy boss1; // Instantiation
	
	printf("PRINT17: %d\n", boss1.strength); // !!!!

	boss1.strength = 9000;
	printf("PRINT18: %d\n", boss1.strength);

	Level level1 = Level_default;
	printf("PRINT19: LEVEL LENGTH = %d\n", level1.length);
	printf("PRINT20: LEVEL NAME = %s\n", level1.name);

	Item flower;

	/* Pointers to structures */
	Enemy* struct_pointer = &boss1;
	printf("PRINT21: %d\n", boss1.strength);
	printf("PRINT22: %d\n", (&boss1)->strength);
	//printf("PRINT22: %d\n", struct_pointer->strength);


	/* There is no native hash tables in C (Python dictionaries, Java maps, etc.)
	 * They have to be implemented using struct:
	 * https://benhoyt.com/writings/hash-table-in-c/
	 */

        return 0;
}


///////////////
// FUNCTIONS //
///////////////

int andOne(int inputvalue){
	int outputvalue = inputvalue + 1;
	return outputvalue;
}

void andOneMutability(int* ptr_inputvalue){
	(*ptr_inputvalue)++;
}

