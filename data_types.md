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