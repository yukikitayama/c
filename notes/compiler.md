# Compiler

GCC compiler options
- The order of the options doesn't matter
- When you use several options of the same kind, order does matter
  - `-L` more than once
- Many options have long names starting with `-f` or with `-W--`.
- `gcc -c` only compiles, no linking, gives `.o`.
- `gcc -o` is linking, gives `.exe`.
- `gcc -Wall` enables all warnings.`
- `gcc -E` redirects outputs.
- `gcc -save-temps` produces all the intermediary files and final executable.
- `gcc -l` links external libraries.
- `gcc -fPIC` creates shared library.
- `gcc -g` generates debugging information
- `gcc -v` prints all the commands in each step.
- `gcc -D` defines macro
- `gcc -Werror` converts warning to error.

Optimization flags
- Without optimization option, the compiler's goal is to reduce the cost of compilation and to make debugging produce the expected results
- Makes the compiler attempt to improve the performance and/or code size at the expense of compilation time and possibly the ability to debug the program.
- `gcc -Q --help=optimizers` finds out the exact set of optimizations that are enabled at each level.

GCC environment variables
- `PATH` searches the executables and run-time shared libraries
- `CPATH` searches the include-path for headers.
- `LIBRARY_PATH` searches library-paths for link libraries.
