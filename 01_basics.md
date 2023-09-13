# Data types
C provides several basic data types that you can use to define variables and perform operations on data.  
Here are some of the fundamental data types in C:

1. **int**: Represents integers, which are whole numbers. The size of an `int` can vary depending on the system, but it is usually 4 bytes on most modern systems.

2. **float**: Represents single-precision floating-point numbers, which are used for real numbers with a fractional part. Typically, a `float` is a 32-bit data type.

3. **double**: Represents double-precision floating-point numbers, which provide greater precision than `float`. A `double` is usually a 64-bit data type.

4. **char**: Represents individual characters. It's typically 1 byte in size.

5. **_Bool**: Represents boolean values, which can have one of two possible values: `0` for false or `1` for true. This data type is introduced in C99 and is often used in conditional expressions.

6. **void**: Represents an empty data type. It is commonly used as the return type for functions that do not return any value. It is also used with pointers to indicate that the pointer does not have a specific data type associated with it.

7. **enum**: Represents user-defined enumerated types, which consist of a set of named integer constants.

8. **typedef**: Allows you to create aliases or custom names for existing data types. For example, you can use `typedef` to create a new name for an `int` or `struct` type.

9. **Arrays**: You can create arrays of any of the above data types to store multiple values of the same type in a contiguous block of memory.

10. **Pointers**: Pointers are a fundamental concept in C. They allow you to store addresses of variables or data structures in memory.

11. **Structures (struct)**: Allows you to create custom data types by combining multiple variables of different data types into a single unit.

12. **Unions (union)**: Similar to structures, unions allow you to group different data types together, but they only occupy as much memory as the largest member.



# Main function
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

# Preprocessor directive
`#include` is a preprocessor directive in C.
It is used to include the contents of a standard or user-defined header file in your C program.
In this case, `<stdio.h>` is a standard header file that stands for "standard input-output header."
It provides functions and definitions for input and output operations.
By including `<stdio.h>`, you gain access to the `printf` function and other I/O related features.

# Output display
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

## puts and fputs
Other functions can be used for outputting strings to a file or to the standard output (usually the console).

1. **puts**:
   - `puts` is primarily used for writing strings to the standard output (stdout).
   - It takes a single argument, which is a null-terminated string (a C-style string).
   - After writing the string to the standard output, it automatically appends a newline character (`\n`) to the end of the string, so it effectively adds a line break after the output.

   ```c
   #include <stdio.h>

   int main() {
       puts("Hello, world!"); // Output: Hello, world!
       return 0;
   }
   ```

2. **fputs**:
   - `fputs` is used for writing strings to a specified file stream.
   - It takes two arguments: the string you want to write and the file stream to which you want to write the string.
   - Unlike `puts`, `fputs` does not automatically add a newline character to the end of the string, so you need to include it in the string if you want a line break.

   ```c
   #include <stdio.h>

   int main() {
       FILE *file = fopen("output.txt", "w"); // Open a file for writing
       if (file != NULL) {
           fputs("Hello, world!", file); // Write to the file without a newline
           fclose(file); // Close the file
       }
       return 0;
   }
   ```
`fputs` also allows redirection to the [standard error](https://en.wikipedia.org/wiki/Standard_streams#Standard_error_(stderr)):
```C
fputs("PRINT03\n", stderr);
```

# Strongly vs weakly typed languages

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

## Conversion or "type casting"



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
# Return statement
`return` is a keyword in C used to specify the return value of a function.
In this case, it's used in the `main` function to indicate that the program has executed without any errors and is returning an exit status of 0.
In C and many other programming languages, a return value of 0 typically indicates success, while a non-zero value can be used to indicate different error conditions.


# Arrays
Arrays are an essential data structure in the C programming language. They allow to store multiple values of the same data type in a contiguous block of memory.

### Fixed size (static memory allocation)
The memory for the array is allocated at compile-time, and its size is determined when the array is declared. Once allocated, the size of the array remains constant throughout the program's execution.

### Same data type
All elements in a C array must be of the same data type. You cannot mix different data types within a single array.


### Declaration and Initialization
Arrays can be declared and initialized in various ways:
   ```c
   int numbers[5]; // Declaration of an integer array of size 5
   int primes[] = {2, 3, 5, 7, 11}; // Declaration and initialization of an integer array
   ```


### Bounds Checking
C does not perform bounds checking by default, which means you can access elements outside the bounds of an array. This can lead to [undefined behavior](https://en.wikipedia.org/wiki/Undefined_behavior) or memory corruption if not done carefully.

```C
int my_arr1[] = {9, 8, 7, 6};
my_arr1[30] = 5; // Undefined Behavior (= nothing to interpret)
```


### Sizeof Operator
You can use the `sizeof` operator to determine the size (in bytes) of an array or its elements. For example:
   ```c
   int size = sizeof(numbers); // Size of the 'numbers' array in bytes
   ```

### Multidimensional Arrays
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

## Iteration through a C array

1. **For Loop**: A `for` loop is a commonly used construct for iterating over arrays. You can use a `for` loop to specify the start and end index of the array and step through each element.

   ```c
   int numbers[] = {1, 2, 3, 4, 5};
   unsigned int length = sizeof(numbers) / sizeof(numbers[0]); // site_t or (unsigned) int; %ld and %d, respectively

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

1. **Function Prototype**:
   - A function prototype is a declaration of a function that provides information about its name, return type, and parameters. It serves as a blueprint for the function.
   - The function prototype typically appears before the `main` function in your C program, or you can place it in a header file (.h) and include that file in your source code.

   ```c
   // Function prototype
   return_type function_name(parameter_type parameter_name);
   ```

   Example:
   ```c
   int add(int a, int b); // Function prototype for an "add" function
   ```

2. **Function Definition**:
   - The function definition is the actual implementation of the function. It contains the code that gets executed when the function is called.
   - The function definition includes the return type, function name, parameters, and the function body enclosed in curly braces `{ }`.

   ```c
   return_type function_name(parameter_type parameter_name) {
       // Function body
       // Code to perform the function's task
       return result; // Return statement (if applicable)
   }
   ```

   Example:
   ```c
   int add(int a, int b) {
       int sum = a + b;
       return sum;
   }
   ```

3. **Function Call**:
   - To execute a function, you call it by its name and provide the necessary arguments (values) that match the function's parameters.
   - The result of the function call can be stored in a variable or used in an expression.

   ```c
   int result = add(5, 3); // Calling the "add" function
   ```

4. **Return Statement**:
   - A function can optionally include a `return` statement to return a value to the caller. The return type in the function prototype must match the type of the value being returned.
   - If a function doesn't return a value, its return type is specified as `void`.

   ```c
   return_type function_name(parameter_type parameter_name) {
       // Function body
       // Code to perform the function's task
       return result; // Return statement (if applicable)
   }
   ```

   Example:
   ```c
   void printMessage() {
       printf("Hello, world!\n");
       // No return statement in this void function
   }
   ```