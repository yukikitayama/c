# Dynamic memory allocation

Overview
- Whenever you define a variable in C, the compiler automatically allocates the correct amount of storage for you based on the data type
- Desirable to be able to dynamically allocate storage while a program is running
- Using **dynamic memory allocation** functions, you can get storage and allocate memory as the program is executing
- Dynamic memory allocation depends on **pointers**. Dynamic memory allocation is possible only because you have pointers available.
- **Majority of production programs will use dynamic memory allocation**.
- `sizeof()` operator is very important when using dynamic memory allocation.
- `#include <stdlib.h>`

Guideline
- Avoid allocating lots of small amounts of memory, because allocating memory on the heap carries some overhead with it
- Only hang on to the memory as long as you need it. Release the memory as soon as you are finished
- Decide where in your code you will release the memory when you write the code that allocates it.

Heao vs. stack
- **Heap** is a memory area that dynamic memory allocation uses to reserve space.
  - Persist while program is running
  - Memory in heap is controlled by you.
  - When you allocate memory on the heap, **it's up to you to keep track of when the memory you have allocated is no longer required**.
  - **You must free the space you have allocated to allow it to be reused**.
- **Stack** is another place where memory is allocated, but stack is different from heap.
  - When the execution of a function ends, the space allocated to store arguments and local variables is freed.

malloc
- `malloc()` is the **simplest standard library function** to allocate memory at runtime
- `#include <stdlib.h>`
- Specify the number of bytes of memory to allocate
- Returns the address of the first byte of memory allocated
  - **Returns a pointer of type pointer to void, so you have to cast**.
- **Pointer** is the only place to put what `malloc()` returns.
- Returns `NULL` when it couldn't allocate for any reason.
  - **It's always a good idea to check any dynamic memory request immediately using an if statement to make sure the memory is actually there before you try to use it**.

`int *pNumber = (int *)malloc(100);`
- Request 100 bytes of memory
- Assign the address of this memory to `pNumber`
- `pNumber` points to the first `int` location at the beginning of the 100 bytes allocated
- When type `int` requires 4 bytes, this memory can hold 25 `int` values on computer.
- `int *pNumber = (int *)malloc(25 * sizeof(int));` is better


Release memory
- Memory that you allocated on the heap will be automatically released when your program ends
- **Better to explicitly release the memory when you are done with it, even if it's just before you exit from the program**.
- **Memory leak** occurs when you allocated memory dynamically and you didn't retain the reference to it, so **you are unable to release the memory**.
  - Often occurs within a loop. Your program consumes more and more of the available memory on each loop iteration.
- To free memory, **you must still have access to the address that references the block of memory**.
- `free()` is a function to release the memory. Pass the pointer. **Usually after releasing the memory with the pointer, set the pointer to NULL**.
  - `free()` has a formal parameter of type `void*`, so no need to cast. You can pass a pointer of any type.
- **You should always set the pointer to NULL after the memory that it points to has been freed**.

calloc
- `#include <stdlib.h>`
- Allocates memory and initialize memory so that all bytes are zero.
- Requires the number of data items, and size of each data item
- e.g., `int *pNumber = (int *)calloc(10, sizeof(int));`

realloc
- Reuse or extend memory that you previously allocated using `malloc()` or `calloc()`
- Requires 2 arguments
  - Pointer containing an address that was previously returned by `malloc()` or `calloc()`
  - Size in bytes of the new memory you want to allocate
- Transfers the contents of the previously allocated memory
- Returns a `void*` pointer to the new memory
- Preserves the contents of the original memory area.
