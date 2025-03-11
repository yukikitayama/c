# Exam

`void (*f)(int);` means that `f` is a pointer to function `(int)` returning `void`.

Operator precedence of addition `+`, subtraction `-` is higher than bitwise shifts `<<`, `>>`.

`(*array)[i]` and `*array[i]`, https://stackoverflow.com/questions/64866353/what-is-the-influence-of-parentheses-on-array-pointers

`*(array[N]) = *array[N]`.

- [The difference in File access mode "w" and "wb](https://stackoverflow.com/questions/43777913/the-difference-in-file-access-mode-w-and-wb)

- `fgets(*str, n, *stream)`
  - Read `n - 1` character because of null character at the end.
  - [C Library - fgets() function](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)
- `fseek(FILE *stream, long int offset, int whence)`
  - sets the file position of the stream to the given offset.
  - `offset` is the number of bytes to move the file pointer.
  - `whence` is the position from which the offset is added.
  - Returns 0 on success, and non-zero on failure
  - [C Library - fseek() function](https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm)
- `ftell(FILE *stream)`
  - Returns the current file position as a long integer, and returns -1L on failure.
  - [C Library - ftell() function](https://www.tutorialspoint.com/c_standard_library/c_function_ftell.htm)
- `fscanf(stream, format, &variable)`
  - [C Library - fscanf() function](https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm)
  - `fscanf(stream, %f, $var)` doesn't work if stream doesn't contain a decimal point, optionally with +/- or e/E.


- `#` is **Stringize operator** to convert a token into string
  - [# and ## Operators in C ?](https://www.tutorialspoint.com/hash-and-hashhash-operators-in-c)

- Operator precedence of `++` `--` is higher than `*` dereference, 

- When a function definition says it returns some data type but when the function body doesn't a return statement, it actually compiles. But the program outputs an unpredictable value.

```
int f(void) {
}

int i;
i = f();  // This can compile.
```

- `fprintf(stdin, string)` and `EOF`
  - fprintf does not return EOF because its purpose is to write data, not read it. If fprintf encounters an error during writing, it will return -1, which is the same value as EOF.

- `fprintf()` returns the number of characters written if successful.

- `fputs(*str, *stream)` returns a non-negative value if success, or returns EOF (-1) if error.