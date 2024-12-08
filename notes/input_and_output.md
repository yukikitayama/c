# Input and Output

Overview
- `<stdio.>` contains all the I/O operations
- The Unix implementation of C has served as a model for I/O functions. 
  - These functions work in a wide variety of computer environments
- When a C program is executed, 3 files are automatically opened by the system for the use by the program. All are defined in `stdio.h`
  - `stdin`
    - Standard input of the program
    - Associated with terminal window
    - All the standard I/O functions which perform input and do not take a `FILE` pointer get their input from `stdin`.
  - `stdout`
    - Standard output of the program
    - Associated with terminal window
  - `stderr`
    - Standard error file
    - Most of the error messages produced by the system are written
    - Associated with terminal window

Char functions
- `getc()` takes `FILE` pointer, but `stdin` is also a file, so `getc()` can take `stdin` as well.
  - Returns ASCII value
- `getchar()` is only `stdin`
- `fgetc()`
- `ungetc(int ch, FILE* stream)`
- Output
  - `putc()` writes a single character to a file (or to stdout)
  - `putchar()` writes to stdout.
  - `fputc()`

String functions
- Input
  - `gets()` reads a line from standard input into a buffer, but should never use it, removed from C11, deprecated.
  - `char *fgets(char *buffer, int n, FILE *stream)` reads entire lines of data from a file/stream, accepts the number of characters to read
    - But `fgets` is also deprecated, should not use
  - `size_t getline(char **buffer, size_t *size, FILE *stream)` is **the latest function for reading a string of text**, preferred method.
    - First parameter is a pointer to a block allocated with `malloc` or `calloc` (type `char **`).
    - Automatically enlarge the block of memory as needed, never shortage of space, safe
    - Returns -1 if error, otherwise returns the number of characters read, not including the final null character.
    - `%zu` is the format for `size_t`
- Output
  - `int puts(const char *string)` only to `stdout`, automatically appends a new line, cannot contain any control characters (`%` format string)
  - `int fputs(const char *buffer, FILE *filePtr)` can output to any file or stream.

Formatting functions
- `sprintf(char *string, const char *format, multiple variables)` is string print formatted function, used to write formatted output to string
  - Store the output data to a char buffer
  - Make sure the size of the buffer to be written to is large enough to avoid buffer overruns.
  - Unsafe, because doesn't check the length of the destination buffer
- `fprintf()` takes `FILE` pointer
  - The reason `stderr` exists is so that error messages can be logged to a device or file other than where the normal output is written
  - `fprintf(stderr, string)`
- `fscanf()` reads formatted input from a file
  - `fscanf(file, "%i", &i)` reads in the next integer value from the file, and stores it in the variable i. 
- `sscanf()` reads formatted data from a string.
- You can use `fscanf()` by itself, however, you may be able to avoid some headaches by using `fgets()` + `sscanf()`.
- `fflush()` cleans the buffer (making empty);
