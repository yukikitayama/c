# Function

Overview
- A function in C is the same as subroutines or procedures in other programming language.

`main()` function
- A specially recognized name in the C system
- Indicates where the program is to begin execution
- All C programs **must always have** a main().
- Can pass data to it (**command line arguments**)
- Returning data is optional (error code)

Defining function
- First line of a function definition is called **function header**.
- Function header tells the compiler 3 things; type of value it returns, function name, arguments it takes.
- Often define function names that consist of more than one word
- 3 common approaches of function name
  - Separate each of the words in a function name with an underline character
  - Capitalize the first letter of each word
  - Capitalize the words after the first word (**camelCase**)
- **Scope of a function is from the point of declaration to the end of the file being compiled**.

Function prototype
- A statement that defines a function
  - Defines name, return value type, type of each argument
- Function prototype add a semicolon `;` at the end, but function definition doesn't have a semicolon.
- **Without function prototype, the compiler throws warnings** if function call appears before function implementation.
  - If function implementation appears first without function prototype before function call, the compiler doesn't throw warnings.
- **Enables the compiler to generate the appropriate instructions at each point where you call the function**.
- Checks that you are using the function correctly in each invocation.
- **When you include a standard header file (e.g., `stdio.h`) in a program, the header file adds the functions prototypes for that library to your program**.
- Generally appear at the beginning of a source file prior to the implementations of any functions, or in a header file.
- **Allows any of the functions in the file to call any function regardless of where you have placed the implementation of the functions**.
- **Parameter names do not have to be the same as those used in the function definition**.
  - Not required to include parameter names in a function prototype.

Arguments and parameters
- People use function definition and function implementation interchangeably
- **Parameter** is the placeholder for the argument and is defined within the function header.
  - Parameters is a list of parameter names and types
- **Argument** is the data you pass into functions's parameter
- Function can have no parameters. In this case, place `void` to parameter as a good practice.
- **When passing an array as an argument, you must also pass the size of the array, because the function has no means of knowing how many elements there are in the array.

Returning data
- Return type specifies the type of the value returned by the function
- Function can return any type **except an array and other functions**.
- A function that has statements in the function body but does not return a value must have the return type as `void`. Otherwise, compiler error.
- A function that does not have a `void` return type must return a value of the specified return type. Otherwise, compiler error.
- If expression results in a value that is a different type from the return type in the function header, the compiler will insert a conversion from the type of expression to the one required. If not possible, compiler error.

Local variable
- **Local variable** is a variable defined inside a function.
- Can use `auto` keyword to be more precise, but not necessary, as the compiler adds this by default.
- Local variables are applicable to any code where the variable is created in a **block** (e.g., loops, if)

Global variable
- **Global variable** can be accessed by any function in program
- Global variable has the lifetime of the program
- Global variable is declared outside of any function. It doesn't belong to any particular function.
- Any function can change the value of a global variable.
- **If there is a local variable declared in a function with the same name as a global variable, the local variable is used, and the global variable is not accessible**.
  - **Basically don't use the same name, because it's confusing**.
- Global variable typically is defined after `#define CONSTANT_NAME constant_value;` and before the first function definition.
- **In general, global variable is a bad thing, and should be avoided**.
- Most modern OOP languanges (e.g., C++, Java) do not even have the concept of global variable. They have static variable and class variable instead.
- Use parameters in functions instead. If a lot of data, use `struct`.

Variadic function
- Typically used when we don't know the total number of arguments that will be used for a function.
- `stdarg.h` provides the routines to write variadic functions
- `va_list` is an argument list, represents a data object to hold the parameters
- `va_start(va_list, last_fixed_parameter)` connects argument list with argument pointer
- `va_arg` fetches the current argument in argument list, you need to knwo the type.
- `va_end` stops using variable argument list for cleanup.
- Provide function prototype with **ellipsis (three dots)** `...`
- There must be at least one fixed parameter
- Must call `va_start()` to initialize the value of the variable argument list pointer in your function
  - This pointer must be declared as type `va_list`.
- There needs to be a mechanism to determine the type of each argument
- You must have a way to determine when the list of arguments is exhausted.
  - The last argument can work as a **sentinel value** to be detected
  - Or the first argument could specify the count of the number of arguments in total
- You must call `va_end()` before you exit a function with a variable number of arguments
- `va_copy`
  - It's possible to process a variable argument list more than once
  - `va_copy` preserves a copy of the `va_list` type variable.
  - Typically call `va_copy` early because, `va_copy()` copies the `va_list` object in whatever state it is in.

Inline function
- Normally, a function call has **overhead** when being invoked
  - It takes execution time to set up the call, pass arguments, jump to the functions code, and return
- Making a function `inline` is to **hint to the compiler** that it's worth making extra effort to call the function faster than it would otherwise.
- Compiler will **substitute the code** of the function, so that the program no longer calls that function, the compiler **replaces** every call to an inline function with the code body of that function.
- **The inline declaration is only advice to the compiler, which can decide to ignore it**.
- Common misconception that in-lining always equals faster code
  - In-lining can cause wastage of space, if many lines in inline function.
  - Inline functions can increase the file size of the program.
- **It's suggested to only declare functions as `inline` if they are short and called frequently**.
- The inline function definition has to be in the same file as the function call.
- Should always use the inline function specifier along with the `static` storage-class specifier.
- Inline functions are usually defined before their first use in a file (definition also acts as a prototype)
- **If you have a multi-file program, you need an inline definition in each file that calls the function**.
  - **The simplest way is to put the inline function definition in a header file**.
  - Include the header file in files that use the function.

```
inline static void foo()  // inline definition/prototype
{
    // do something
}
```

_Noreturn function
- C11 added it.
- Informs the user and the compiler that a function will no return control to the calling program
- Informs the user helps to prevent misuse of a function
- Informs the compiler may enable it to make some code optimizations
- `_Noreturn` function specifier is a **hint to the compiler**, so the compiler may not optimize the code.
- `exit()` function is an example of a `_Noreturn` function.
- `_Noreturn` is different from the `void` return type.
- With `<stdnoreturn.h>`, you can use the convenience macro `noreturn` instead of `_Noreturn`.

```
_Noreturn void f() {
    abort();
}
```