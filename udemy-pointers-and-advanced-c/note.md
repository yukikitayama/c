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

# Srection 3: Pointer arithmetic

Introduction
- Addition/subtraction is done in chunks of the size of the data type the pointer is pointing to.
- Rules
  - Addition of address and integer
    - new_address = previous_address + integer
    - new_address = previous_address + integer * sizeof(type)
  - Subtraction of address and integer
  - Address +/- Address = Integer

