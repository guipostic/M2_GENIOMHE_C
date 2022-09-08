#include <stdio.h> // printf

void modifyArray(int any_array[3]);

int main(){
	int arr[3] = {11, 12, 13};

	printf("PRINT arr: %d, %p\n", arr, arr);
	/* The arr variable is actually a pointer on the first value */

	int* first_val_ptr = &arr[0]; // You can test with &arr[1] and &arr[2]
	printf("FIRST VALUE POINTER (&arr[0]): %p\n", first_val_ptr);
	printf("SAME BUT DEREFERENCED: %d\n", *first_val_ptr);

	/* Q: What's wrong with the two lines below? */
	int* entire_arr_ptr = &arr;
	printf("TEST &arr: %p\n", entire_arr_ptr);
	/* NOTE:
	 * "warning: initialization from incompatible pointer type"
	 * => try without the &
	 * XXX UNLIKE arr and &arr[0], &arr is not an int pointer (type: int*) (hence the warning):
	 * it is an array pointer (type: int(*)[3]) XXX */

	/* TWO DIFFERENT TYPES, BUT THEY HAVE THE SAME VALUE!! */
	printf("\nSUMMARY: arr: %p, &arr[0]: %p, &arr: %p\n", arr, &arr[0], &arr);


	/* NOW, THIS IS THE CORRECT WAY TO DECLARE
	 * a pointer on the entire array (not only the first value): */
	int(* arr_ptr)[] = &arr; // it works also with [3]
	printf("\nDEREFERENCED ARRAY POINTER WITH INDEX: %d\n", (*arr_ptr)[1]); // value at the index i
	printf("DEREFERENCED ARRAY POINTER (WITHOUT INDEX): %p\n", *arr_ptr); // first value pointer
	printf("DEREFERENCED x2 ARRAY: %d\n", **arr_ptr); // first value

	printf("ENTIRE ARRAY POINTER?? %p\n", arr_ptr); // NO!! ;-)
	printf("NOTE: POINTER TO POINTER: %p\n", &arr_ptr);


	/* Consequence: pass array to function
	 * => functions actually take pointers to arrays */
	printf("\nARRAY BEFORE: %d\n", arr[1]);
	modifyArray(arr);
	printf("ARRAY AFTER: %d\n", arr[1]);
	/* In Python, the list would have been copied within the function block, and only the copy would have been modified */

	/* To copy array (including string): */
	//memcpy(array2, array1, sizeof(array2)) // #include <string.h>

        return 0;
}

void modifyArray(int any_array[3]){
	any_array[1] = 999;
}

