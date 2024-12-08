# Large program

Background
- Most common beginner mistake is to jump in directly and try to write all the necessary code into a single file and later try to debug or extend later.
- Programs that contain more than 100 statements can be considered as a large program. It must be organized around multiple files.
- **Module** refers either to a single function or to a number of related functions that you choose to group logically.
- Achieve abstraction and promote the re-usability of code

Develop
- C file contains the definition of each function
- There should be a header file for each C file
- The header files should have the same name as the C files.

Compile
- `gcc *.c -o main` compiles all the C files and creates one executable.
- Replacing the `.c` from the filename with an `.o` tells the C compiler to use the object file that was previously generated. This can skip recompiling the files which didn't have errors.
  - e.g., `gcc mod1.o mod2.c main.o -o test` doesn't delete `mod1` and `main` object code files.
- `gcc -c mod1.c` is a way to compile each module separately.
  - This tells the compiler not to link you file
  - Doesn't produce an executable
  - Retains the intermediate object file that it creates.

Makefiles
- The utility tool from the command line
- Not part of the C language
- Helpful to develop larger programs
- Speed development time
- Specify a list of files and dependencies in `Makefile`.
- `make` automatically recompiles files only when necessary.
  - If make finds `.c` source file ie newer than corresponding `.o` object file, automatically recompile

Makefile structure
```
SRC = mod1.c mod2.c main.c

OBJ = mod1.o mod2.o main.o

PROG = myProgram$(PROG):$(OBJ)
    gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)
```

- `SRC` defines the set of **source files**
- `OBJ` defines the corresponding set of **object files**
- `PROG` defines the name of the **executable**
  - `$(PROG):$(OBJ)` defines dependencies and says the executable is dependent on the object files
  - `gcc $(OBJ) -o $(PROG)` must be typed with a **leading tab**
- `$(OBJ): $(SRC)` says each object file depends on its corresponding source file

Communication between files
- In the file that calls the external functions, include a prototype declaration, so that the compiler knows the function's argument types and return type.
- **External variable** is one whose value can be accessed and changed by another module (file)
  - Functions in separate files can communicate. Extension to global variable concept.
  - Inside the module that wants to access the external variables, use `extern` keyword in declaring the variable data type to **tell the compileter that a globally defined variable from another file is to be accessed**.
  - First, declare a variable as global variable, at the beginning of your program, outside of any function.
  - Second, declare the variable with preceding `extern` keyword to reference the value of the external variable from another module.
- **Static variable** is a variable that you want to define as a global variable which is local to a partuclar module (file)
  - Not from functions contained in other files.
  - Declare the variable to be `static` is you need to define a global variable whose value doesn't have to be accessed from another file.
  - Static declaration makes it more accurately because no conflicts can be created by two modules that **unknowingly both use different external global variables of the same name**.

Heap and stack memory allocation
- There are 3 forms of memory that you can use in your program
  - **static**
    - Static memory persists throughout the entire life of the program
    - Used to store things like **global variables**, variables created with `static` clause.
  - **stack**
    - Special region of memory to store **temporary variables**.
    - Store variables that are created inside of a function, only locally available in the function.
    - No need to manage the memory yourself, variables are allocated and freed automatically.
    - **If a program tries to put too much information on the stack, stack overflow will occur**.
    - A common bug is attempting to access a variable that was created on the stack inside some function, from a place in your program outside of that function.
    - When dealing with small variables, and easier and faster access.
  - **heap**
    - Opposite of the stack, large pool of memory, not automatically managed, managed by the programmer.
    - Heap memory is accessed through **pointers**.
    - You have to explicitly allocate and free the memory.
    - **There are generally no restrictions on the size of the heap, other than the physical size of memory in the machine**.
    - **Variables created on the heap are accessible anywhere in the program essentially global in scope**.
    - Heap memory is slightly slower to be read from and written to.
    - When you need to allocate a large block of memory by large array and big structure
    - When you need to keep that variable around a long time as global variable
    - When you need variables like arrays and structs that can change size dynamically.

