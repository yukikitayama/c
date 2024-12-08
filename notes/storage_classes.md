# Storage classes

Overview
- Describes the features of variables and functions about scope, visibility and life-time.
- **Variable's visibility (linkage)** determines for a multiple-source-file program whether the identifier is known only in the current source file or in any source file with proper declarations.
- Storage durations
  - **Automatic storage duration**
  - **Static storage duration**
- `storage_class var_data_type var_name;`
- C doesn't allow multiple storage classes. Register cannot be used with static.

Local variable
- Has **automatic storage duration** by default.
- Value of a local variable can only be accessed by the function in which the variable is defined
- Value cannot be accessed by any other function

Auto variables
- `auto` is used to declare variables of **automatic storage duration**.
- Created when the block in which they are defined is entered, exists while the block is active, and destroyed when the block is exited.
- Closely related to local variable.
- Keyword `auto` is seldom used, because C compiler assumes it by default.
- **C++ has repurposed the auto keyword for a different use, so simply not using auto as a storage-class specifier is better for C/C++ compatibility**.

External variable
- **Extern storage class** tells us that a variable is defined elsewhere.
  - Extern variable is a global variable initialized with a legal value where it is declared to be used elsewhere.
- **Main purpose of using extern variables is that they can be accessed between two different files which are part of a large program**.
- The external variable has to be defined in some place among the source files.
- When `extern char name[]` character array, no need to specify the size.

External function
- Instead of using head file, you can pass a function to another file
- Extern function can be called from a file where it's not defined, but the definition of the function effectively becomes global to any file  in the program.

Static
- **If you need to define a global variable whose value doesn't have to be accessed from another file, declare the variable to be statis, and it's a cleaner approach to programming**.
  - Static declaration more accurately reflects the variables' usage.
- Static makes sure it won't be used externally
- Used on local variable, global variable, and functions
- When applied to local variable, instructs the compiler to keep the variable in existence during the life-time of the program.
  - Static variable preserves its value even after it's out of the scope.
  - No new memory is allocated
  - The scope is local to the function to which the static variable is defined.
  - Making local variables static allows them to maintain their values between the same function calls
- When applied to global variable, variable's scope is restricted tot eh file in which it's declared (opposite to extern variable).
- When applied to function, the static function can be called only from within the same file.
- A static local variale is initialized only once at the start of overall program execution.
  - Cannot be initialized with an output value of a function, need to pass constant.
- Static variables have default initial value of zero, unlike automatic variable
- Static variables are allocated memory on the heap.
- **When a function is defined, it's declared as extern by default**.
- Structure
  - **Static variable should not be declared inside a structure**.
  - It's possible to have an entire structure as static.

Register
- **Processor register (CPU register)** is one of a small set of data holding places that are part of the computer processor.
- A register may hold an instruction, a storage address, or any kind of data.
- Register storage class is used to define local variables that should be stored in a register instead of RAM (memory)
- During runtime, variables in register is faster than variables in memory.
- Register storage class should only be used for variables that require quick access.
- Keyword `register` hints to the compiler that a given variable can be put in a register, but it's the compiler's choice to put it in a register or not.
- **You cannot obtain the address of a register variable using pointers**.
  - Cannot use `&` addressof operator.
- **Register can be used only with local blocks, cannot be used in global scope, outside of main()**.