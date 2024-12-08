# Macro

Overview
- Two ways of defining macros
  - **Symbolic contants** (constants represented as symbols)
  - **Function macros** (operations defined as symbols)
- A **macro** is a piece of code based on the `#define` directive.
- Macros are a **text processing feature** and are expanded and replaced by macro definitions.
- Today, macros in C are considered **outdated** in terms of modern programming practices.
- `#define PX printf("x is %d.\n", x)` is `preprocessor-directive macro body`.
- You should use capital letters for macro function names
- Macros are not terminated by a semicolon
- Macros run until the first newline following the `#`.
  - Use the backslash operator `\` for multi-line coding.

```
// Symbolic constant
#define PI 3.14

// Macro
#define PRNT(a, b) \
    printf("value 1 = %d\n", a); \
    printf("value 2 = %d\n", b);
```

Macro vs function
- All the macros would be processed before your program compiles.
- Functions are not preprocessed, they are compiled.
- Time and space tradeoff
- A macro is fater than a function, which shift to where the function is and then return to the calling program.
- A macro that is used once in a program probably will not have any noticeable improvement in running time.
- A macro inside a nested loop is a candidate for speed improvements.
- When you call a function, it has to allocate some data (a newly allocated stack frame)
  - Macros do not have this overhead
- A macro produces inline code
  - If you use the same macro 20 times, you get 20 lines of code inserted into your program.
  - In you use a function 20 times, you have just one copy of the function statements in your program (less space is used)
- Functions are preferred over macros when writing large chunks of code.

Macro alternative
- Inline functions are the best alternative to macros
- Inline functions can be debugged and can have type checking.

Function macro
- `#define macro_name(list_of_identifiers) substitution_string`

Preprocessor operators
- `\`
  - The backslash operator allows for the continuation of a macro to the next line when the macro is too long for a single line
- `defined()`
  - Determine if an identifier is defined using `#define`

```
#if defined(DEBUG)
    ...
#endif

#ifdef DEBUG

#endif
```

- `#`
  - Used within a macro definition, causes a replacement text token to be converted to a string surrounded by quotes.
  - String expansion
  - Creates a constant string out of the macro argument, literally inserts double quotation marks around the actual macro argument.

```
#define str(x) #x

printf(str(Hello));

// The above is equivalent to
printf("Hello")
```

- `##`
  - Concatenates two tokens (token pasting)
  - When a macro is expanded, the two tokens on either side of each `##` operator are combined into a single token.
  - `#define CONCAT(x, y) x##y`, `CONCAT(O, K)` is replaced by `OK`.

Predefined macro
- Standard C provides predefined symbolic constans **begin and end with two underscores**.
- `__FILE__` current file name (string)
- `__LINE__` current line number of source code
- `__func__` name of any function when placed inside a function of the current file
- `__DATE__` date the source file was compiled
- `__TIME__` time the source file was compiled
- `__STDC__` indicates if the compiler supports standard C by returning the value 1