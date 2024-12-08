# GBD

Overview
- GDB is GNU Project debugger, allows you to see what's going on inside another program while it executes.
- `gdb` is an interactive debugger of programs compiled with GNU's gcc compiler.
- 4 kinds of ways for GDB to catch bugs
  - Start program by specifying something
  - Make program with stopping at a predetermined location
  - Examine and display things, when program has stopped
  - Change things in program by setting variables.
- Compile program with gcc compiler using `-g` option to use gbd's features


- `gdb executable` allows you to use breakpoints in terminal.
- `break number` sets breakpoint at line `number`
- `run` runs a program
- `c` continuing
- `next` goes to next line
- `quite` quites `gdb`.
- `list` shows several lines of code.
- `print` prints variable
- `info locals` shows local variables
- `info break` shows all the breakpoints that have been set
- `clear function-name` removes breakpoint for function `function-name`
- `bt` (backtrace command) shows stack trace.
