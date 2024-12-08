# Type Qualifier

Overview
- **Type qualifiers** can be used in front of variables to **give the compiler more information about the intended use of the variable to help with optimization**.
- `const`, `volatile`, `restrict`

Const
- Tells the compiler that the specified variables have a constant value throughout the program's execution.
- The compiler might issue an error message if you try to assign a value to a `const` variable **after initializing it**.
- **Allows the compiler to place const variables into read-only memory for compiler optimization**.
- pointer
  - `const float *pf;` means that value of `*pf` cannot change, but value of `pf` can change (pointer  address can change).
  - `float * const pt;` means pt is a const pointer, value of `pt` cannot change, pointer address cannot change, always pointing to the same thing.
  - `const float * const ptr;` means that address of pointer cannot change, and the value that pointer points to also cannot change, `*ptr` cannot change, `ptr` cannot change.
  - `float const *pfc;` is the same as `const float *pfc;`. **Order of type and const before asterisk doesn't matter**.
  - const right of `*` make pointer constant. const left of `*` makes value that pointer points to constant.
- Parameter declaration in function with `const` is common to avoid changing given data.
- Global variable should use with `const`
- **Constant variable has to be declared and defined (initialize value) at the same time**.

volatile
- `volatile` type qualifier tells the compiler explicitly that the value will change
- Tell the complier to suppress optimization, prevent from caching variable
- Programs that have a lot of threading and resources are scarce use `volatile`.
- A variable should be declared `volatile` whenever its value could change unexpectedly
- When optimizer need to reload the variable every time, instead of holding a copy in a register
- Use cases
  - Memory-mapped peripheral registers
  - Global variables modified by an interrupt service routine
  - Global variables accessed by multiple tasks within a multi-threaded application
- `volatile int loc1` means `loc1` is a volatile location and value
- `volatile int * ploc` means `ploc` points to a volatile location or value
- `volatile const` allows a value to be **both const and volatile**. Appears in threading.
  - Something that should not be changed by the program but can be changed by agency (another process or another thread) other than program.

restrict
- `restrict` type qualifier is an optimization hint for the compliler
  - Compiler can choose to ignore it
- Used in **pointer declaration**
- Tells the compiler that **a particular pointer is the only reference to the value it points to throughout its scope**.
  - Same value is not referenced by other pointer
- Without `restrict` keyword, the compiler assumes the worst case where some other identifier might have changed the data in between two uses of a pointer.
- Not supported by C++
- `int * restrict intPtrA;`, `int * restrict intPtrB;`, means they will never access the same value.

This assumes that a1 array and a2 array are disjoint
```
void f1(int n, float * restrict a1, const float * restrict a2)
{
    int i;
    for (i = 0; i < n; i++)
    {
        a1[i] += a2[i];
    }
}
```