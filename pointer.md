# Pointer

Overview
- Pointer is a variable that stores an address.
- Its value is the address of another location in memory that can contain a value
- `*` asterisk is used in declaring a pointer
- `*` asterisk is also used to dereference the pointer. Its effect is to access the data stored at the address specified by a pointer.

Indirection
- In programming language, indirection is the ability to reference something using a name, reference, or container, instead of the value itself.
- The act of manipulating a value through its memory address.
- A pointer provides an indirect means of accessing the value of a particular data item
- A pointer is a variable whose value is a memory address (The address of another location in memory that can contain a value)

WHy pointers?
- With pointers, you can access any location in memory and perform arithmetic with pointers (accessing data by variables is limiting)
- Pointers make it easier to use arrays and strings
- You can update the same space in memory from one location and the change can be seen from another location in program
- Save space by sharing components
- Pointers allow functions to modify data passed to them as variables
- Run program faster and use less memory
- Can get multiple values from the function
- Allow you to allocate memory in run time, not in compile time (dynamic memory allocation)
- Allow us to create stack, queue, linked list.

Declare pointer
- Needs data type because different types take up different amounts of storage
- `int *pnumber;`, `pnumber` is a pointer to an integer variable
- **Space between * and variable name is optional**.
- Use space in declaration and don't use space in deference, by convention
- `%p` is format specifier for pointers
- **You should always initialize a pointer when you declare it**
- When no idea about initial value, use `NULL`
- `NULL` is a value that is guaranteed not to point to any location in memory.
- Need to add `#include <stddef.h>` to use `NULL`
- `int * p, q;` p is pointer to int, q is int variable
- **It's a good idea to use names beginning with `p` as pointer names**.

Address of operator
- If you want to initialize a pointer with the address of a vairable you already declared, use the **address of operator** `&`.

Access value that a pointer points at
- Use **indirection operator** `*` to access the value of the variable pointed to by a pointer.
- This operator also is called as **dereference operator**.
- It's confusing because indirection operator is also the symbol for multiplication and specification of pointer types
- The compiler will understand it depending on where the asterisk appears.

```
int number = 15;
int *pnumber = &number;
int result = 0;

result = *pnumber + 5;  // 15 + 5
```

```
int number = 0;
int *pnumber = NULL;

number = 10;
pnumber = &number;

printf("pnumber's value: %p\n", pnumber);  // Output the value (an address)
printf("number's address: %p\n", &number);  // Output the address
printf("pnumber's address: %p\n", (void*)&pnumber);  // Output the address
```

- The cast to `void*` is to **prevent a possible warning from the compiler**.
- The `%p` specification expects the value to be some kind of pointer type, but the type of `&pnumber` is pointer to pointer to int.
- To prevent warning of `sizeof`, casting to int is required
  - `(int)sizeof(pnumber)`

Testing for NULL
- Do not dereference an uninitialized pointer

```
int * pt;  // An uninitialized pointer
*pt = 5;  // A terrible error
```

- Second line means store the value 5 in the location to which pt points
- pt has a random value, so there is no knowing where the 5 will be placed.
- **It might go somewhere harmless, it might overwrite data or code, or it might cause the program to crash.**
- **When declaring a pointer that doesn't point to anything, we should initialize it to NULL**.
- You can also initialize a pointer to null by using `0`.

Const with pointer
- With pointers, we have to consider two things when using the const modifier
  - Whether the pointer will be changed
  - Whether the value that the pointer points to will be changed
- `const int * ...` means value cannot be changed
- `int *const ...` means pointer address cannot be changed.
- When you use const keyword when declaring a pointer, it indicates that the value pointed to must not be changed
- Pointer itself is not constant, so you can still change what it points to.
```
long value = 9999L;
const long *pvalue = &value;  // Defines a pointer to a constant
long number = 7777L;

*pvalue = 8888L;  // Not okay
value = 8888L;  // This is okay
pvalue = &number;  // This is okay
```
- If you ensure that the address stored in a pointer cannot be changed, put const keyword after the asterisk
```
int count = 43;
int *const pcount = &count;
```
- You can create a constant pointer that points to a value that is also constant
  - Cannot change the address stored in `pitem`
  - Cannot use `pitem` to modify what it points to
```
int item = 25;
const int *const pitem = &item;
```

Void pointer
- A pointer of type `void*` can contain the address of a data item of any type.
- `void*` is often used as a parameter type or return value type with functions that deal with data in a type-independent way.
- But the void pointer must first be explicityly cast to another pointer type before it is dereferenced.
```
int i = 10;
float f = 2.34;
char ch = 'k';

void *vptr;

vptr = &i;
printf("Value of i = %d\n", *(int *)vptr);  // (int *) is cast to int pointer type, and the first * is dereference.

vptr = &f;
printf("Value of f = %.2f\n", *(float *)vptr);  // (float *) is cast to float pointer type, and the first * is dereference.

vptr = &ch;
printf("Value of ch = %c\n", *(char *)vptr);  // (char *) is cast to char pointer type, and the first * is dereference.
```

Array with pointer
- Arrays and pointers seem different, but they are closely related and **can sometimes be used interchangeably**.
- One of the most common uses of pointers in C is as pointers to arrays
- The main reasons for using pointers to arrays are ones of **notational convenience** and of program efficiency.
- **Pointers to arrays generally result in code that uses less memory and executes faster**.
- Set pointer to point to **the first element in the array**
- No need `&`, because array is also pointer.
  - **C compiler treats the apprearance of an array name without a subscript as a pointer to the array**.
  - Specifying array name without a subscript has the effect of producing a pointer to the first element of values.
```
int values[100];  // Array of 100 integers
int *pvalues;
pvalues = values;  // Point to the first element in the array

pvalues = &values[0];  // This is the same and valid
```
- `ar[i]` and `*(ar + i)` are equivalent

Pass by reference
- **Pass by value (call by value)** is when a function copies the **actual value** of an argument into the formal parameter of the function.
  - Changes made to the parameter inside the function have no effect on the argument.
- You can pass a pointer as an argument to a function and you can also have a function return a pointer as its result.
- **Pass by reference** copies the **address** of an argument into the formal parameter.
  - Address is used to access the actual argument used in the call
  - **Changes made to the parameter affect the passed argument**
  - Changes inside the function are reflected outside the function.
- Syntax
  - `int function1(int num)` and `function1(x);`
  - `int function2(int * ptr)` and `function2(&x);`

Return pointer from a function
- It provides a way to return a whole set of values, not just a single value
- `int * function();`

Pointer arithmetic
- When `valuesPtr` is a pointer to int array `values`, using indirection operator `*(valuesPtr + 3)` is the same as `values[3]`.
- To change a value in array via pointer, `*(valuesPtr + 3) = 27`. This is the same as `values[3] = 27`.
- You cannot do pointer arithmetic to array itself
- Functions that process arrays actually use pointers as arguments
- You have a choice between array notation and pointer notation for writing array processing functions.
  - Using pointer notation is less code and more efficient
  - Using array notation makes it more obvious that the function is working with arrays

Pointer and string
- One of the most common applications of using a pointer to an array is as a pointer to a character string.
