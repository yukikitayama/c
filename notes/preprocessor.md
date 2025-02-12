# Preprocessor

Overview
- Process of creating a C program
  1. Preprocessor
  2. Compilation
  3. Assembler
  4. Linker
  5. Loader
- **Preprocessor** is invoked before any code gets compiled in the C programming language.
- Not part of the compiler.
- C preprocessor is a text substitution tool
- 3 main tasks of preprocessor
  - Removes all the comments
  - Includes all of the files that the program needs to compile (`#include` directive)
  - Expansion of macro definitions

Preprocessor directive
- Commands begin with `#`

Conditional compilation
- **Conditional compilation** enables you to control the execution of preprocessor directives and the compilation of program code.
- To create one program that can be compiled to run on **different computer systems**.
- Used to switch on or off statements
- Useful for debugging
- Every `#if` construct ends with `#endif`
- `#ifdef` is shorthand for `#if defined(name)`
  - Checks whether an identifier is currently defined by `#define`
- `#ifndef` (if not defined) is shorthand for `#if !defined(name)`
  - Checks whether an identifier is not defined by `#define`
  - Common use case is `#ifndef SIZE`, `#define SIZE 100`, `#endif`.
- `#if` tests the value of a constant expression used with `#endif`.
- `#elif` and `#else` are multiple-part conditional preprocessor constructs.
- **You are allowed to one or more spaces after the `#` that begins a preprocessor statement**.

```
#ifdef UNIX
#  define DATADIR "/uxn1/data"
#else
#  define DATADIR "\usr\data"
#endif
```

Include guards `#ifndef`
- `#ifndef` prevents multiple inclusions of a file.
- It prevents multiple definitions of the same variable/function/macro
- Make sure the identifier has not been defined elsewhere
- **The definition in the first header file included becomes the active definition and subsequent definitions in other header files are ignored**.
- Ensures that the contents of a header file cannot be included more than once into a source file.
- **You should always protect code in your own header files in this way**.

```
#ifndef _STDIO_H
#define _STDIO_H
// contents of file
#endif
```

`#undef`
- Undefines an identifier you have previously defined.
- Cancels an earlier `#define` definition.

`#pragma`
- **pragma** means pragmatic information.
- Lets you place compiler instructions in your source code.
- Lets you request special behavior from the compiler.
- Useful for programs that are unusually large or that need to take advantage of the capabilities of a particular compiler.
- Controls the amount of memory set aside for automatic variables
- Sets the strictness of error checking
- Enables nonstandard language features
- `#pragma token_name`, `#pragma` usually followed by a single token representing a command for the compiler to obey.
  - Command is compiler specific.
- Major pragmas
  - `#pragma GCC dependency`
  - `#pragma GCC poison`
  - `#pragma GCC system_header`
  - `#pragma once`
  - `#pragma GCC warning`
  - `#pragma GCC error`
  - `#pragma message`
- `#pragma GCC dependency` allows you to check the relative dates of the current file and another file.
  - If the other file is more recent than the current file, a warning is issued.
- `#pragma GCC poison` removes an identifier completely from the program.
  - If any of the identifiers by poison appear anywhere in the source after the directive, an error will be displayed by the compiler.
- `#pragma GCC system_header` tells the compiler to consider the rest of the current include file as a system header.
  - System headers are header files that come with the OS or compiler.
- `#pragma once` specifies that the header file containing this directive is included only once even if the programmer includes it multiple times during a compilation.
  - Works similar to using **include guards**.
- `#pragma GCC warning "message"` causes the preprocessor to issue a warning diagnostic with the text `"message"`. 
- `#pragma GCC error "message"` issues error
- `#pragma GCC message "message"` issues informational message (not a warning or an error).

`#error` directive
- Causes the preprocessor to issue an error message that includes any text in the directive.
- Useful because it actually doesn't cause the code to not compile.

`#warning` directive
- The compiler emits a diagnostic containing the remaining tokens in the directive.

`#line`
- Useful for debugging regarding file name and the line number.

Debugging
- C preprocessor can be used to insert debugging code into your program
- BY using `#ifdef` statements, the debugging code can be enabled or disabled
  - When a preprocessor identifier `DEBUG` is defined, the debugging code is compiled
  - When `DEBUG` isn't defined, the debugging code is left out
- Defining macro with body for debugging, and macro without body for non-debugging.

Preprocessor operator
- `##` is for concatenation, **token pasting operator**.

```
#define ALPHA(x, y) x##2-y

int i = -1;
int i2 = -2;

ALPHA(i, i2) -> i##2-i2 -> i2-i2 -> -2--2 -> -2 + 2 -> 0
```

- `#` is **stringize operator** which converts a token into string, not value of a variable, but variable name itself.