# Library

- `stdlib.h`
  - `srand()` generates random numbers
- `time.h`
  - Seed for random

```
#include <stdlib.h>
#include <time.h>

// Create a time variable
time_t t;

// Initialize the random number generator
srand((unsigned) time(&t));

// Get the random number and store
int randomNumber = rand();
```

Overview
- A **library** is a collection (group) of header files and implementation files, exposed for use by other programs.
  - Interface expressed in a header file
  - Implementation expressed in a `.c` file.
- A library consists of one or more object files, which consist of object code.
- C functions that can be shared by more than one application should be broken out of an application's source code and compiled and bundled into a library.
- Libraries may call functions in other libraries such as the Standard C or math libraries
- A programmer has the interface file (headers) to figure out how to use a library.
- Libraries allow for fast compilation times
- **You can't run a library, it's just source code, doesn't have a `main` function, no entry point**.
- Own library needs to use `"` like `#include "mylib.h"`.
- **Driver** is a common term for a program which has a main function and does something.

Linking
- When a C program is compiled, the compiler generates object code (`.o`, `.obj`)
- The the compiler invokes the linker
- **Linking** is the process of collecting and combining multiple object files in order to create a single executable file.
- Linker makes the code of library functions available to your program
- Linking can happen either **static linking** or **dynamic linking**.

Static linking
- By copying the code of library function to your object code
- The library code is part of your application
- The primary advantage of static linking is the speed at runtime
- Creates larger binary files with more disk space and memory, because of copy
- More time consuming to fix bugs, because need to rebuild the whole program
- Also called **static library**

Dynamic linking
- By making some arrangement so that the complete code of library functions is not copied, but made available at run-time
- Linking happens when the program is run, when both the binary file and the library are in memory.
- Defers much of the linking process until a program starts running ("on the fly")
- Libraries are loaded into memory by programs when they start
- When you recompile a program that uses a library, doesn't recompile the library into the executable.
- **The main reason for using dynamic linking of libraries is to free your software from the need to recompile with each new release of a library**.
- **More modern approach**
- Smaller executable size
- Slower execution than static libraries, but not much
- May have compatibility issues.

Library type
- Static libraries
  - Uses static linking
  - Known as an archive
  - `<libname>.a`
  - `.a` library is conceptually the same as the Windows `.lib` libraries
  - Similar to `.zip` or `.tar` file. A file containing other files.
  - Convention is `lib<something>.a`, names begin with `lib` and end with `.a` extension.
  - `gcc -c main.c -o lib_mylib.o`
  - `ar rcs lib_mylib.a lib_mylib.o`
- Shared object libraries
  - Dynamically linked at run time
  - Shared object and dynamic library are terms used interchangeablly.
  - `<libname>.so`
- Dynamic linking loader system functions

Shared object (dynamic library)
- Every program linked against this library shares the same one copy
  - Contrast to static linking, in which every program given their own copy of the contents of the library
- Naming convention is `lib<something>.so`
  - Similar to Windows `.dll` and Mac `.dylib`.
- `gcc -g -fPIC main.c -shared -o lib_mylib.dll`
  - Use `-fPIC` for **position independent code** required by shared object
  - `-shared` creates shared object files.
- `#include "myLib.h"` to use the library by shared object
  - `gcc -I <directory-of-dynamic-library> -c main.c -o main.o`
  - To link, `gcc -o main.exe main.o -L <directory-of-dynamic-library> -l <name-of-library-without-dll-extension>`
- Created by the **link editor** command `ld`
- Linux `ldd <name-of-executable>` lists all the shared objects given binary/executable.

Dynamic loading
- Loading of a library is 2 types
  - Static loading
  - Dynamic loading
- Whenever we run executable, the loader will try to resolve against all the symbols at program start up.
  - Loader will store every required library into memory
  - Instead of a predefined dependency on a library, make its presence optional, load a library on demand
  - The programmer determines when/if the library is loaded.
- **Dynamic loading is a mechanism by which a computer program can, at run time, load a library (or other binary) into memory**.
- Unlike static linking and dynamic linking, dynamic loading allows a computer program to start up in the absence of libraries.
- `gcc -o main.exe main.c -l dl`
- `ldd main`

Dynamic loading API
- `<dlfcn.h>`
  - API for opening a library, looking up symbols, handling errors, closing the library.
- `dlopen()` opens a library and prepare
  - `RTLD_LAZY`
  - `RTLD_NOW`
- `dlerror()` returns a error string
- `dlsym()` looks up the value of a symbol, loads function pointer
- `dlclose()` closes a dynamic loading library
