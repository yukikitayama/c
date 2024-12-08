# Debugging

Overview
- Debugging checks logical errors usually
- Compiler checks syntax errors.
- Always focus on fixing the first problem detected.

Debugger
- GDB debugger
  - https://winlibs.com/#download-release
- Step into
  - Go inside a function if a function is called at the current line
- Next
  - Jump to the next line of code
- Step out
  - Try to go outside a function if currently inside function
- GDB window
  - Locals, call stack, and breakpoints are important

Setting
- Set the path of a debugger in a project to the downloaded GDB bin folder.

Call stack
- **Stack trace (call stack)** is something generated when an app crashes because of a fatal error
- Stack trace is a list of the function calls that lead to the error
- It includes filenames and line numbers of the code
- Top of the stack is the last call that caused the error
- Bottom of the stack is the first call that started the chain of calls to caused the error

Core file
- A **core dump** is generated when a program crashes or is terminated abnormally because of segmentation fault. (e.g., division by zero, illegal memory access)
- A core dump is also called a **memory dump, storage dump, or dump**.
- The core file contains a snapshot of the contents of the process's memory at the time it terminated.
- The core file is used for debugging, diagnosing and fixing errors.
- A **segmentation fault** is an error caused by accessing memory that does not belong to you.
- A core dump is `core.<process_id>`, `<name>.exe.stackdump` in current working directory.
- `ulimit -c unlimited` enables writing core files.

Static analysis
- **Static analysis** is a method of debugging by automatically examining source code before a program is run.
- Coverity by Synopsis
- Codesonar by Grammatech