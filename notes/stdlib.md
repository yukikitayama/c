# stdlib.h

`exit()`
- Program execution is automatically terminated whenever the last statement in `main()` is executed, or when executing a return from `main()`
- `exit()` force the termination of a program earlier
- `int exit(int status)`
  - `EXIT_FAILURE` is non-zero, symbolic constant, indicates the program has failed
  - `EXIT_SUCCESS` is 0, symbolic constant, indicates it has succeeded.
- When a program terminates simply executing the last statement in the `main` without `exit` or `return`, its exit status is undefined.

`atexit()`
- A function will be called when `exit()` is executed.
- Takes as an argument a pointer to a function
  - type `void` function taking no arguments.

`abort()`
- `exit` and `atexit` are normal termination
- `abort` causes abnormal program termination
- Raises `SIGABRT` signal
- "Fail hard and fail often"
- File buffers are not flushed, streams are not closed, temporary files are not deleted.
- `void abort(void)`
- Dumps core file.

`qsort()`
- Most effective sorting algorithm, partitions arrays into smaller sizes until the element level is reached.
- `void qsort(pointer to array, size of array, size of element, pointer to function)`

- `atoi()` ascii to integer
- `atof()` ascii to float
- `atol()` ascii to long integer
- `strtod()` string to double
- `strtof()` string to float
- `strtol()` string to long integer

Random number
- `int rand(void)` creates random numbers
- `void srand(unsigned seed)` sets the starting point for producing a series of pseudo-random integers
  - Should only be seeded once at the start of the program
  - `srand(time(0))` is standard practice.
- To set range, e.g., `rand() % 10 + 1` generates random numbers from 1 to 10.

`system("command")`
- `stdlib.h`
- executes system commands

`getenv()`
- environment variables
- `char *str = NULL;`, `str = getenv("PATH")`

`memcpy()`, `memmove()`
- Copies one string to another.
- `memcpy()` is free to assume that there is no overlap between the two memory ranges
- `memmove()` copys as of all the bytes are first copied to a temporary buffer before being copied to the final destination.

`strdup`, `strndup`
- Duplicates a given string

`size_t`
- The unsigned integral type and is the result of the sizeof keyword

`NULL`
- Macro, the value of a null pointer constant
