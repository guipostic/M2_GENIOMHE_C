
# Compiled programming language

C is a compiled programming language. This means that C source code must be processed by a compiler to generate machine code or intermediate code that can be executed directly by a computer's CPU.
In interpreted languages, the source code is executed directly by an interpreter, making the code more portable but potentially less efficient.

Developing programs in C requires the following steps:

1. **Writing code**: The C program is written in a text editor or integrated development environment (IDE).

2. **Compilation**: The C compiler (such as GCC, Clang, or Microsoft Visual C++) translates the C source code into machine code or an intermediate form, depending on the target platform and compiler options. This process is known as compilation.

3. **Linking**: In addition to compiling individual source files, the compiler may also link together various object files and libraries to produce a single executable file. Linking resolves references to functions and symbols used across multiple source files.

4. **Execution**: The resulting executable file can be executed directly by the computer's CPU. It doesn't require an interpreter to execute the code.

C's status as a compiled language offers several advantages, including high performance, direct hardware access, and the ability to create standalone executables that can be run independently on a target system. However, it also means that you need to recompile your code whenever you make changes, and the executable may be platform-dependent, requiring recompilation for different platforms.


# Data types
C provides several basic data types that can be used to define variables and perform operations on data.  
Some of the fundamental data types in C are:

1. **int**: Represents integers, which are whole numbers. The size of an `int` can vary depending on the system, but it is usually 4 bytes on most modern systems.

2. **float**: Represents single-precision floating-point numbers, which are used for real numbers with a fractional part. Typically, a `float` is a 32-bit data type.

3. **double**: Represents double-precision floating-point numbers, which provide greater precision than `float`. A `double` is usually a 64-bit data type.

4. **char**: Represents individual characters. It's typically 1 byte in size.

5. **_Bool**: Represents boolean values, which can have one of two possible values: `0` for false or `1` for true. This data type is introduced in C99 and is often used in conditional expressions.

6. **typedef**: Allows you to create aliases or custom names for existing data types. For example, you can use `typedef` to create a new name for an `int` or `struct` type.

    Example:
    ```C
    typedef unsigned long int ulint;
    ```

## Strongly 🆚 weakly typed languages

C is often described as a "weakly typed" or "loosely typed" language. This means that C allows for more implicit type conversions and flexibility in working with different data types compared to languages that are considered "strongly typed" (e.g. Ada, or Haskell).

In a strongly typed language, strict type checking is enforced, and type conversions typically require explicit casting or conversion functions. C, on the other hand, allows you to perform operations on different types of data more liberally, and it will often perform implicit type conversions when necessary.

Example:

```C
int a = 5;
float b = 3.14;
float result = a + b; // Implicit conversion of 'a' to float
```

Here, the integer `a` is implicitly converted to a float when added to the float `b`. Many strongly typed languages would require you to explicitly cast `a` to a float in this case.

However, this flexibility in C can also lead to potential issues and bugs if not used carefully, as implicit type conversions can sometimes produce unexpected results.

### Conversion or "type casting"

Example:
```C
int sum = 22, count = 3;
float mean1;
mean1 = sum / count;
printf("PRINT04: Value of mean FLOAT : %f\n", mean1 );
```
Output:
```
PRINT04: Value of mean FLOAT : 7.000000
```


Example:
```C
int sum = 22, count = 3;
double mean;
mean = (double) sum / count;
printf("PRINT06: Value of mean FLOAT CAST: %f\n", mean );
```
Output:
```
PRINT06: Value of mean FLOAT CAST: 7.333333
```

# Code overview
### Main function
In C programming, it is necessary to have a `main` function.
The `main` function serves as the entry point for a C program.
When you run a C program, the operating system starts executing code from the `main` function.
Without a `main` function, the program would not have a starting point, and it would not be able to execute.

```C
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```

### Preprocessor directives
`#include` is a preprocessor directive in C.
It is used to include the contents of a standard or user-defined header file in your C program.
In this case, `<stdio.h>` is a standard header file that stands for "standard input-output header."
It provides functions and definitions for input and output operations.
By including `<stdio.h>`, you gain access to the `printf` function and other I/O related features.  

The `#define` preprocessor directive is used to create macros or symbolic constants.
It allows you to define a name (the macro name) that represents a value, an expression, or a block of code.
When the preprocessor encounters the macro name in your code, it replaces it with the defined value or code before the actual compilation of your program begins.

Example:
```C
#define SIZE 4 // SIZE is a "macro"
```


### Output display
`printf` (print format) is a standard C library function used for formatted output.
It is responsible for displaying text or data on the console or other output devices.
In this line, `printf` is used to print the string "Hello, world!" followed by a newline character (`\n`) to the standard output (usually the console).  
Example:
```C
printf("PRINT01A: %10d\n", 12345);
```
Output:
```
PRINT01A:      12345
```
Example:
```C
float foobar = 0.9375;
printf("PRINT01B:%.2f\n", foobar);
```
Output:
```
PRINT01B:0.94
```

### Return statement
`return` is a keyword in C used to specify the return value of a function.
In this case, it's used in the `main` function to indicate that the program has executed without any errors and is returning an exit status of 0.
In C and many other programming languages, a return value of 0 typically indicates success, while a non-zero value can be used to indicate different error conditions.


# Arrays
Arrays are an essential data structure in the C programming language. They allow to store multiple values of the same data type in a contiguous block of memory.

* **Fixed size (static memory allocation)**:  
The memory for the array is allocated at compile-time, and its size is determined when the array is declared. Once allocated, the size of the array remains constant throughout the program's execution.

* **Same data type**:  
All elements in a C array must be of the same data type. You cannot mix different data types within a single array.


### Declaration and initialization
Arrays can be declared and initialized in various ways:
   ```c
   int numbers[5]; // Declaration of an integer array of size 5
   int primes[] = {2, 3, 5, 7, 11}; // Declaration and initialization of an integer array
   ```


### Bounds checking
C does not perform bounds checking by default, which means you can access elements outside the bounds of an array. This can lead to [undefined behavior](https://en.wikipedia.org/wiki/Undefined_behavior) or memory corruption if not done carefully.

```C
int my_arr1[] = {9, 8, 7, 6};
my_arr1[30] = 5; // Undefined Behavior (= nothing to interpret)
```


### Sizeof operator
You can use the `sizeof` operator to determine the size (in bytes) of an array or its elements. For example:
   ```c
   int size = sizeof(numbers); // Size of the 'numbers' array in bytes
   ```

### Multidimensional arrays
C supports multidimensional arrays, which are essentially arrays of arrays. Common examples include 2D arrays and matrices.

Different ways to initialize a two-dimensional array:
```
int c[2][3] = {{1, 3, 0}, {-1, 5, 9}};
int c[][3] = {{1, 3, 0}, {-1, 5, 9}};
int c[2][3] = {1, 3, 0, -1, 5, 9};
```

Initialization of a 3D array:
```C
int test[2][3][4] = {
{{3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}},
{{13, 4, 56, 3}, {5, 9, 3, 5}, {3, 1, 4, 9}}
};
````

### Iteration through an array

1. **For Loop**: A `for` loop is a commonly used construct for iterating over arrays. You can use a `for` loop to specify the start and end index of the array and step through each element.

   ```c
   int numbers[] = {1, 2, 3, 4, 5};
   unsigned int length = sizeof(numbers) / sizeof(numbers[0]); // ⚠️ site_t or (unsigned) int; %ld and %d, respectively

   for (int i = 0; i < length; i++) {
       printf("%d ", numbers[i]);
   }
   ```

2. **While Loop**: You can also use a `while` loop when you need more control over the iteration process. You manually manage the loop counter and exit condition.

   ```c
   int numbers[] = {1, 2, 3, 4, 5};
   size_t length = sizeof(numbers) / sizeof(numbers[0]);
   int i = 0;

   while (i < length) {
       printf("%d ", numbers[i]);
       i++;
   }
   ```
   
# Conditional statements
```C
bool statement1 = true;
bool statement2 = false;
if (statement1 && statement2){
    printf("PRINT08: Both are true\n");
}
        if (statement1 || statement2){
                printf("PRINT09: One or more is true\n");
        }
```



# Functions
Below are the key components of functions in C:

### Function definition
   - The function definition is the actual implementation of the function. It contains the code that gets executed when the function is called.
   - The function definition includes the return type, function name, parameters, and the function body enclosed in curly braces `{ }`.

```C
return_type function_name(parameter_type parameter_name) {
    // Function body
    // Code to perform the function's task
    return result; // Return statement (if applicable)
}
```



Example:

```c
int andOne(int inputvalue){
    int outputvalue = inputvalue + 1;
    return outputvalue;
}
```

### Function call
   - To execute a function, you call it by its name and provide the necessary arguments (values) that match the function's parameters.
   - The result of the function call can be stored in a variable or used in an expression.

Example:

   ```c
    int test1 = 10;
    int test2 = andOne(test1);
    printf("PRINT10: %d -> %d\n", test1, test2);
   ```

Output:

    ```
    PRINT10: 10 -> 11
    ```

### Return statement
   - A function can optionally include a `return` statement to return a value to the caller. The return type in the function prototype must match the type of the value being returned.
   - If a function doesn't return a value, its return type is specified as `void`.

### Function prototype
   - A function prototype is a declaration of a function that provides information about its name, return type, and parameters. It serves as a blueprint for the function.
   - The function prototype typically appears before the `main` function in your C program, or you can place it in a header file (.h) and include that file in your source code.

   ```c
   // Function prototype
   return_type function_name(parameter_type parameter_name);
   ```

   Example:
   ```c
   int andOne(int inputvalue);
   ```


# Pointers
Pointers allow to work memory addresses directly, enabling low-level memory manipulation and advanced data structures.
A pointer is a variable that stores the memory address of another variable.

Example:

```C
printf("PRINT11: %p ....... %p\n", &test1, &test2);
```
Output:
```
PRINT11: 0x7ffe48f19fc8 ....... 0x7ffe48f19fcc
```

### Declaration and initialization
   - Pointers are declared using an asterisk (*) symbol followed by the data type they point to.
   - Pointers must be initialized with the address of a valid variable before they can be used. Uninitialized pointers may lead to undefined behavior.

Example:
    
   ```c
   int* ptr_test1 = &test1;
   printf("PRINT12: %p\n", ptr_test1);
   ```
   💡 To have behavior defined by the C standard when printing a pointer, you should convert it to `(void*)`

Output:

   ```
   PRINT12: 0x7ffe48f19fc8
   ```

### Dereferencing
   - To access the value pointed to by a pointer, you use the dereference operator (`*`).

Example:

   ```c
   printf("PRINT13: BEFORE = %d\n", test1);
   (*ptr_test1)++;
   printf("PRINT14: AFTER = %d\n", test1);
   ```
   🆚 `*ptr_test1++;`: operator precedence rules

Output:

   ```
   PRINT13: BEFORE = 10
   PRINT14: AFTER = 11
   ```


### Passing pointers to functions
   - Pointers are frequently used to pass data by reference to functions, allowing functions to modify the original data.

Example:
    
   ```c
   void andOneMutability(int* ptr_inputvalue){
        //  The concept of mutability determines whether an object's state can be modified after creation.
       (*ptr_inputvalue)++;
   }

   int main() {
       int test3 = 1000;
       andOneMutability(&test3);
       printf("PRINT15: %d\n", test3);
   }
   ```


Output:

   ```
   PRINT15: 1001
   ```

### Function pointer
A function pointer can be defined by specifying its return type, parameter types, and the pointer variable's name. The basic syntax for defining a function pointer is:

```c
return_type (*pointer_name)(parameter_types);
```

- `return_type`: This is the return type of the function that the pointer can point to.
- `(*pointer_name)`: This is the pointer variable's name enclosed in parentheses. The asterisk `*` indicates that it's a pointer.
- `(parameter_types)`: These are the parameter types of the function that the pointer can point to.



Example:

Header file `foo_test.h`:

```c
#include <math.h>

/* This example function does nothing more than reusing another function */
int foo_function( int(*funcPtr)(int), int myvalue ){
        int resulting_value = (*funcPtr)(myvalue);
        printf("PRINT16B: %d\n", resulting_value);
        return resulting_value;
}
```

File `01_basics.c`:
```c
#include "foo_test.h"

int main(){
    int(*functionPointer)(int);
    functionPointer = &andOne; // Note: NULL vs 0

    int result1 = (*functionPointer)(test3);
    printf("PRINT16A: %d\n", result1);
    int abc = 999999;
    foo_function(&andOne, abc); // function from a header file: no prototype needed
    double test_math = sqrt(9); // #include <math.h> is in the header file

    return 0;
}
```

Output:
```
PRINT16A: 1002
PRINT16B: 1000000
```


# Structures
A structure is a composite data type that allows to group together variables of different data types under a single name. Structures enable to create custom data types to represent complex data structures or objects in your programs.

### Declaration
   - You declare a structure using the `struct` keyword, followed by the structure's name.
   - Inside the structure, you define the member variables or fields, each with its own data type.

   ```c
   struct Student {
       char name[50];
       int age;
       float gpa;
   };
   ```

### Initialization
   - You can create instances (variables) of a structure by specifying the structure's name followed by the variable name.
   - You can also initialize structure variables during declaration.

   ```c
   struct Student student1; // Declaration of a structure variable
   struct Student student2 = {"Alice", 20, 3.5}; // Declaration and initialization
   ```

### Accessing members
   - You access the members (fields) of a structure variable using the dot (`.`) operator.

   ```c
   student1.age = 21;
   ```
   ```c
   printf("Name: %s, Age: %d, GPA: %.2f\n", student1.name, student1.age, student1.gpa);
   ```

### Nested structures
   - Structures can contain other structures as members, allowing you to create complex data structures.

   ```c
   struct Address {
       char street[50];
       char city[30];
       char state[20];
   };

   struct Person {
       char name[50];
       int age;
       struct Address address;
   };
   ```


### Typedef
   - You can use `typedef` to create an alias for a structure, making it easier to declare variables of that type.

   ```c
   typedef struct {
       char title[50];
       int year;
   } Book;

   Book myBook;
   ```

#### Alternative syntax for aliases
```c
typedef struct level Level; // Alias to type "Level" instead of "struct level"
struct level{
        int length;
        char name[100];
} Level_default = {23, "missing_name"}; // Define default value
```

#### Default value
```c
Level level1 = Level_default;
```

### Pointers to structures
Example:
```c
typedef struct enemy Enemy; // Alias to type "Enemy" instead of "struct enemy"
struct enemy{
        /* Structure "members": */
        char name[100];
        int life;
        int strength;
        /* Structures are data types so no values */
}; // XXX


int main() {
        Enemy boss1; // Instantiation
        boss1.strength = 9000;
        Enemy* struct_pointer = &boss1;
        printf("PRINT21: %d\n", boss1.strength);
        printf("PRINT22: %d\n", (&boss1)->strength);
        printf("PRINT23: %d\n", struct_pointer->strength);
    return 0;
}
```
Output:
```
PRINT21: 9000
PRINT22: 9000
PRINT23: 9000
```

### Hash tables
In C, there is no native hash tables (e.g. dictionaries in Python, maps in Java).
They have to be [implemented using struct](https://benhoyt.com/writings/hash-table-in-c/).


# Array pointers
```c
int arr[3] = {11, 12, 13};
printf("PRINT arr: %d, %p\n", arr, arr);
```
```
PRINT arr: -1305537268, 0x7ffeb22f150c
```
The `arr` variable is actually a pointer on the first value.

```c
int* first_val_ptr = &arr[0]; // You can test with &arr[1] and &arr[2]
printf("FIRST VALUE POINTER (&arr[0]): %p\n", first_val_ptr);
printf("SAME BUT DEREFERENCED: %d\n", *first_val_ptr);
```
```
FIRST VALUE POINTER (&arr[0]): 0x7ffeb22f150c
SAME BUT DEREFERENCED: 11
```

### What's wrong with the two lines below?
```c
int* entire_arr_ptr = &arr;
printf("TEST &arr: %p\n", entire_arr_ptr);
```
```
warning: initialization from incompatible pointer type
TEST &arr: 0x7ffeb22f150c
```
Try also without the `&`...  
Unlike `arr` and `&arr[0]`, `&arr` is not an `int` pointer (type: `int*`) (hence the warning): it is a "length-3-array pointer" (type: `int(*)[3]`)


⚠️ Two different types but they have the same value!
```c
printf("\nSUMMARY: arr: %p, &arr[0]: %p, &arr: %p\n", arr, &arr[0], &arr);
```
```
SUMMARY: arr: 0x7ffeb22f150c, &arr[0]: 0x7ffeb22f150c, &arr: 0x7ffeb22f150c
```

### The correct way to declare a pointer on the entire array
```c
int(* arr_ptr)[] = &arr; // it works also with [3]
printf("\nDEREFERENCED ARRAY POINTER WITH INDEX: %d\n", (*arr_ptr)[1]); // value at the index i
printf("DEREFERENCED ARRAY POINTER (WITHOUT INDEX): %p\n", *arr_ptr); // first value pointer (type: int*)
printf("DEREFERENCED x2 ARRAY: %d\n", **arr_ptr); // first value
```
```
DEREFERENCED ARRAY POINTER WITH INDEX: 12
DEREFERENCED ARRAY POINTER (WITHOUT INDEX): 0x7ffeb22f150c
DEREFERENCED x2 ARRAY: 11

```
```c
printf("ENTIRE ARRAY POINTER?? %p\n", arr_ptr); // NO!! ;-) first value pointer (type: int(*)[3])
```
```
ENTIRE ARRAY POINTER?? 0x7ffeb22f150c
```

No equivalent of Python `typeof()`, but you can test the type this way:
```c
int(* tab)[] = *arr_ptr;
```
as this will generate an "incompatible pointer type" warning.

```c
printf("NOTE: POINTER TO POINTER: %p\n", &arr_ptr);
```
```
NOTE: POINTER TO POINTER: 0x7ffeb22f14f0
```

Consequence: pass array to function.
Functions actually take pointers to arrays:
```c
printf("\nARRAY BEFORE: %d\n", arr[1]);
modifyArray(arr);
printf("ARRAY AFTER: %d\n", arr[1]);
```
```
ARRAY BEFORE: 12
ARRAY AFTER: 999
```
In Python, the list would have been copied within the function block, and only the copy would have been modified.

To copy array (including string):
```c
memcpy(array2, array1, sizeof(array2)) // #include <string.h>
```
