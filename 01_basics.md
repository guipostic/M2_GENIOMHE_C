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
