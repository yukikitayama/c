# Data types

- Data type corresponds to byte sizes on the platform of a program.
- C only has primitive data types to store all sorts of data
- C doesn't have objects.
- C requires that all program variables be declared before they are used in a program
- **The difference between the data types is in the amount of memory they occupy and the range of values they can hold**
  - Data type specifies the amount of storage that is allocated to store a particular type of data
  - This is machine-dependent.


int
- Integer can be positive, negative, or zero
- You can assign a hexadecimal notation (base 16) to int

float
- 1.7e4 is a scientific notation, which is also a floating-point and it can be assigned to float
- Appending `f` or `F` to the end of the number explicitly express a float constant, not double.

double
- Similar to float but more precision
- Most computer represent double values using 64 bits (8 bytes)
- All floating-point constants are taken as double values by C compiler

_Bool
- Boolean
- 1 is true
- 0 is false.
- When you print _Bool data, you will see 0 or 1, not false or true.

Adjective keyword
- Modify basic integer type
- This is to make program more precise and efficient
- `short`, `long` and `unsigned`
- `short int` (equal to `short`) uses less storage than `int` to save space
- `unisigned` for variables that have only nonnegative values (positive).
- `signed` is an explicit intent.

Enum
- Specify the valid values
- Define type `enum primaryColor { red, yellow, blue };`
- Declare variable `enum primaryColor myColor;`
- Store value `myColor = red;`.
- Compiler treats enumeration identifiers as **integer constants**.
  - First name in the list is 0.
  - `enum direction { up, down, left = 10, right };`
    - up is 0
    - down is 1
    - left is 10
    - right is 11

Char
- Represents a **single character** with **single quotes**
- A **character string** is different from a single character.
- Double quotes is string in C.
- You can also use the numerical code in ASCII table to assign values, but don't do it.

Escape characters
- **Escape sequence**
- `char x = '\n';`. `\n` is a single character.
 
Format specifier
- Specify the data type and used to display variables as output
- `%i` int, _Bool, bool
- `%f` float
  - `%.2f` limits 2 decimal points.
- `%e` double
- `%g` double
- `%c` char
- A number after `%` specifies the minimum field width to be printed if the characters are less than the size of the width. The remaining space is filled with space.
  - e.g., when `i = 1` and `printf("%2u", i);`, ` 1` is printed. 
- https://www.geeksforgeeks.org/format-specifiers-in-c/

Command line argument
- Ask user to enter a small amount of information at the terminal
- When `main()` is called by the runtime system, 2 arguments are passed to the function
- `argc` (argument count), integer of the number of arguments typed on the command line
- `argv` (argument vector), array of character pointers (strings)

#define statement (constants)
- Defines symbolic or manifest constants
- Preprocessor directives run until the first newline following the #
  - Directive is limited to one line in length
- By convention, `#define` statements appear first in the program, and use only **uppercase letters and underscores**.
- No equal sign. No semicolon.
- A defined name isn't a variable. You cannot assign a value.
- Definition for a name can include an expression like `#define TWO_PI 2.0 * 3.14`
- `NULL` is defined name by `<stddef.h>`, `#define NULL 0`.
- `#define` vs. constant
  - `const` allows you to define a variable with a specified type
  - With `#define`, defined name will be replaced by a sequence of characters.

typedef
- Allows you to create your own name for an existing data type
- It doesn't actually define a new type, only create a new type name.
- For readability and maintainability.
- `typedef int Counter;` defines the name `Counter` to be equivalent to the C data type `int`
  - `Counter j, n;` is possible
- In many instances, `typedef` statement can be equivalently substituted by the appropritate `#define` statement
  - `#define Counter int` = `typedef int Counter;`
  - `#define` is handled by preprocessor
  - `typedef` is handled by C compiler
- Use typedefs for types that combine arrays, structs, pointers, or functions
- Use typedefs for casting. It can provide a simple name for a complicated type cast.

Complex number type
- Real numbers and imaginary numbers
- Introduced in C99
- Optional in C11
- Use `__STDC_NO_COMPLEX__` to test if it's available
- `float _Complex` for real and imaginary parts, `float _Imaginary`, `double _Complex`, etc.
- Include `complex.h`
- `1*I` makes 1 be imaginary part. `I` is defined in `complex.h`.
- `creal()` returns real part of `complex` type
- `cimag()` returns imaginary part
- `conj()`
- `cpow()`

```
#ifdef __STDC_NO_COMPLEX__
  printf("Complex arithmetic is not supported.\n");
#else
  printf("Complex arithmetic is supported.\n");
#endif
```

Designated initializer
- **Designated initilizers** allow you to specify which elements of an array, structure or union are to be initialized by the values with an array index or a field by name
- C90 required fixed order, but C99 allows you to initialize the elements in random order by specifying array index or structure field name
- `int a[6] = {[4] = 29, [2] = 15};` is equivalent to `int a[6] = {0, 0, 15, 0, 29, 0};`
- `[first_index ... last_index] = value` can initialize a range of elements to the same value.
- Length of an array is the highest index + 1.
- Designated initializer for struct use `.` or `:`.

```
int numbers2[] = {1, 2, 3, [10] = 80, 15, [70] = 50, [42] = 400};
int size = sizeof(numbers2) / sizeof(numbers2[0]);
printf("\nSize: %d\n", size);
```

```
struct point { int x, y; };

struct point p = { .y = 2, .x = 3};
struct point q = { y: 3, x: 3};
struct point s = { 2, 3};
```
