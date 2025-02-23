# Exam

`void (*f)(int);` means that `f` is a pointer to function `(int)` returning `void`.

Operator precedence of addition `+`, subtraction `-` is higher than bitwise shifts `<<`, `>>`.

`(*array)[i]` and `*array[i]`, https://stackoverflow.com/questions/64866353/what-is-the-influence-of-parentheses-on-array-pointers

`*(array[N]) = *array[N]`.

- [The difference in File access mode "w" and "wb](https://stackoverflow.com/questions/43777913/the-difference-in-file-access-mode-w-and-wb)

- `fseek(f, 0, SEEK_END)`
  - [C Library - fseek() function](https://www.tutorialspoint.com/c_standard_library/c_function_fseek.htm)
- [C Library - ftell() function](https://www.tutorialspoint.com/c_standard_library/c_function_ftell.htm)
- `fscanf(stream, format, &variable)`
  - [C Library - fscanf() function](https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm)
  - `fscanf(stream, %f, $var)` doesn't work if stream doesn't contain a decimal point, optionally with +/- or e/E.


- `#` is **Stringize operator** to convert a token into string
  - [# and ## Operators in C ?](https://www.tutorialspoint.com/hash-and-hashhash-operators-in-c)

