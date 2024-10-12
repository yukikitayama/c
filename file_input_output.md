# File input and output

Overview
- `stdio.h`
- C views a file as a continuous sequence of bytes
- Each byte can be read individually
- `EOF` means end of file.
- Once a file has been written, it just consists of a series of bytes.

2 types of file
- Text file
  - A sequence of characters organized as lines (each line ends with a newline)
- Binary file
  - A series of bytes as they appear in memory. Not readable.
  - Image data, music encoding.

Streams
- **Stream** is an abstract representation of any external source or destination for data.
- Keyboard, command line, files are all you can work with as streams.
- **C programs automatically open 3 files on your behalf
- **Standard input** is the normal input device for your system, usually your keyboard
  - `getchar()`, `scanf()`
- **Standard output** is usually your display screen
  - `putchar()`, `puts()`, `printf()`
- **Standard error** is usually your display screen
  - Purpose of standard error output file is to provide a logically distinct place to send error messages.

Accessing files
- Files on disk have a name and rules for naming files depends on operating system.
  - Need to adjust file names depending on OS
- **File pointer (stream pointer)** is what a program references a file through
  - The pointer points to **struct of type `FILE`** that represents a stream
  - Contains the address of the buffer in memory to be used for data
  - Contains a pointer to the **current position in the file** for the next operation.
- There is a limit to the number of files you can have open at one time
  - `FOPEN_MAX` in `stdio.h`.
- `fopen(<file-name>, <mode>)` opens a file by associating an external file name with an internal file pointer `FILE`.
  - Returns a pointer of type `FILE*` if success. If fail, returns `NULL`.
- File mode
  - `w` creates a file if not exist, but doesn't truncate.
  - IF `w+` and `a+`, it creates the file if it doesn't exist and truncate the file to zero. 
  - `r+` doesn't create and is for read and write.
  - `w` is only write, cannot read.
  - `w+` creates text file for update, discard previous contents if any.
- Write mode
  - **On opening a file for writing, the file length is truncated to zero and the position will be at the beginning of any existing data for the first operation**.
  - **Any date that was previously written to the file will be lost and overwritten**.
- Read mode
  - Positions the file to the beginning of the data.
- `rename(<old-name>, <new-name>)` renames a file. Returns 0 if success, nonzero if fail.
  - The file must not be open when call.
- Closing file
  - It's a good programming practice to close a file as soon as you have finished with it
  - **You must close a file before renaming or removing**.
  - `fclose()` closes a file, returns `EOF` (equivalent to -1) if error, returns 0 if success.
  - `fclose(pfile);` and `pfile = NULL;`.
  - **Closing a file releases the memory used in opening a file, clears buffer contents from RAM or memory, and unclosed files occupy memory that is wasted**.
- Delete file
  - `remove()` with file name, not pointer.

Reading from a file
- `fgetc(<file-pointer>)` reads a character from a text file that has been opened for reading
  - Returns the character read as type `int`.
  - `rewind(<file-pointer>)` positions at the beginning, so you can read the contents again.
- `fgets(char *str, int nchars, FILE *stream)` reads from **any file or stream**.
  - Reads a string into the memory area pointed to by `str` from the file specified by `stream`
  - Characters are read until either a `\n` is read or `nchars - 1` characters are read, whichever occurs first.
  - If a newline character is read, `\0` is appended.
  - Reading `EOF` causes `NULL` to be returned
- `fgets` is more efficient than `fgetc`
- `fscanf(FILE *stream, const char *format, ...)` gets formatted input from a file

Writing to a file
- `fputc()` is the simplest write operation, writes a single character to a text file
  - Inefficient
- `fputs()` writes a string to any file or stream
  - Writes characters from a string until it reaches a `\0` character
  - Doesn't write the null terminator character to the file
  - **Expects to write a line of text that has a newline character at the end**.
- `fprintf()` writes formatted output to a stream
  - If successful, the total number of characters written is returned, otherwise a negative number is returned.

File positioning
- Finding out where you are in a file
  - `ftell()` accepts a file pointer and returns a `long int` value that specifies the current position in the file
    - Makes a variable hold the current position in the file and you can use this to return to this position at subsequent time.
    - Offset in bytes from the beginning.
  - `fgetpos()` is a little more complicated than `ftell()`
    - Designed to be used with the positioning function `fsetpos()`
    - Must declare a variable of type `fpos_t`
    - Cannot declare a pointer of type `fpos_t*` because there will not be any memory allocated to store the position data.
- Moving to a given point in a file
  - `fseek(FILE *pfile, long offset, int origin)`
    - `offset` is an offset from a reference point by `origin`
    - `origin` can be one of 3 values
      - `SEEK_SET` is beginning of the file
      - `SEEK_END` is end of the file
      - `SEEK_CUR` is current position in the file
    - For text files, second argument must be a value returned by `ftell()`. All operations are reference to the beginning of the file. 3rd argument must be `SEEK_SET`.
    - For binary files, offset argument is a relative byte count. Supply positive or negative values for the offset when `SEEK_CUR`.
  - `fsetpos()`

```
fseek(fp, 0, SEEK_END);  // Move the pointer to the end by SEEK_END
len = ftell(fp);  // Tells you the total size of file in bytes
```

```
fpos_t here;
fgetpos(pfile, &here);  // Current file position in the variable here.
```
