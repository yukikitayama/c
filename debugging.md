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