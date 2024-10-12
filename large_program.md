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