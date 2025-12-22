# Pointers and Advanced C

Introduction
- To become an expert in C, you need to master pointers
- Pointer is one of the most important and influencing topics in programming career
- Address is a unique place in the memory of your computer where a variable resides

# Section 2

Pointer motivation
- Passing by pointer
  - Pass by pointer vs pass by reference
- Returning more than just one thing from a function
  - In C, you can't return more than one thing from function
- Passing arrays and strings to functions
- Allocating unknown memory at run time

Declaration and usage
- Standard variable stores standard value
- Pointer variable stores an address of standard variable
- `int *p;` means point to int
  - `*` means not a standard variable
  - `p` is just a name
- `<data-type> *<variable-name>` 
- `&` - address operator
- **Dereferencing** is using pointer variable to show the value of original standard variable with `*`

Pointer initialization
- `int *p = NULL;`
- `int a = 1;`
- `p = &a;`

Pointers dereferencing
- User the pointer variable to change the value of standard variable
- Indirect way to change
- **Pointers indirection**

# Section 3: Pointer arithmetic

Introduction
- Addition/subtraction is done in chunks of the size of the data type the pointer is pointing to.
- Rules
  - Addition of address and integer
    - new_address = previous_address + integer
    - new_address = previous_address + integer * sizeof(type)
  - Subtraction of address and integer
  - Address +/- Address = Integer

Address
- In 64-bit Environment, an address is represented by 8 bytes.
- That's why pointer size will be 8 bytes
- 4-bit is 1 byte.

# Section 4: Pointers concept and beyond

Multiple indirection
- `int **ptr2 = &ptr1;` is pointer to pointer to int.
- `int *...*ptrN = &ptr<N - 1>;`  is a pointer to pointer (n - 1 times) to int.

`void *` Universal Pointer Void
- `void *` is **Void universal approach** which points to an address of any type of data
- Useful in developing general purpose functions which receive unknown types
- Universal void pointer is used in returned pointer type
- Used in dynamic memory allocation
- "Void star"
- Every variable has to have own adress in memory
- Require an explicit type casting to use it
- `printf("%d", *(int*)ptr);`, `(int*)` is an explicit casting to universal void pointer
  - From that address, instruct how many bytes they should read.

# Section 5: Arrays and pointers

Array
- Array variable is an address of the first element
- Function can receive array as array and pointer
- `func(int arr[])` and `func(int *ptr)` both are okay

# Section 7: Dynamic memory allocation

Pointers motivation
- Passing by pointer
- "Returning" more than just one thing from a function
- Passing arrays and strings to functions
- Allocating unknown memory at run time

Dynamic memory allocation
- Functions to allocate memory
  - `malloc`, `calloc`
- `malloc` function
  - Allocates a sequence of bytes
  - Returns the address of the sequence (the address of the first byte)
  - Can work with allocated sequence.
  - Definition is `void * malloc(unsigned size)`, so we need to cast.
    - Casting allows us to tell how to treat the sequence of bytes. 
- **To use `malloc` / `calloc` functions, include `malloc.h` or `stdlib.h`**.

calloc
- Allocates a sequence of bytes
- Returns the address of the first byte of the sequence
- Can work with allocated sequence after allocation
- **All elements are set to 0**
- `void * calloc(unsigned num, unsigned size)`
  - The first is number of elements
  - The second is size of each element. (Not sizeof * number of elements)
- e.g., `(int *)calloc(5, sizeof(int))`

free function
- Whenever you are making a dynamic memory allocation inside some function for some object, it will ramain in memory even after finishing with the function
- That memory will be consumed until the program ends, even if it will take very long time for that to happen
  - It's opposed to how static arrays free their memory once a given function is over.
- There is no infinite memory in computer, so there is no need for holding memory which has no usage.
- Free functions free the memory that was dynamically allocated.
- Considerations for using the free function
  - Dynamic allocation inside a function
  - Repeatable memory allocation inside a loop
    - e.g., when every iteration does dynamic memory allocation
- 5 common errors with using free function
  1 Use free function to statis array (e.g., int a[10])
  2 Use it to a uninitialized pointer to some data type
  3 Free twice to the the same thing
  4 Try to free a part of the sequence
  5 Understand the previous 4 things

Dangling pointer
- `free` function frees the real memory that a pointer points to, but the pointer still contains the address.
- The program is no longer allowed to access the memory, but the pointer still contains the address.
- The pointer in this situation is called **dangling pointer**
- So it's a good practice to manually set `a = NULL;` after using `free` function. 

Valgrind
- Finds memory leakages

realloc function
- Resize the block of memory that was previously allocated
  - e.g., we need to have a longer array than the previous
- `void * realloc(void *ptr, size_t size)`
  - The first argument is the address of the already allocated memory
  - The second argument is the new size
- Allocates a new sequence of elements in your computer's memory
- Gives us a copy of previous elements
- Issues with realloc
  - Overwriting the actual pointer
    - When copy fails, we lose the address to the previous memory.
  - Different implementations