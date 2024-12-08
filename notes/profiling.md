# Profiling

Overview
- **Profiling** is a program analysis to measure space, time, usage of instructions, and the frequency and duration of function calls.
- Profiling applies a specific profiling tool to the program source code or its binary executable.

gprof
- GNU profiling tool
- A hybrid approach of compiler assisted instrumentation and sampling.
- `gcc -pg` run gprof
- `gmon.out` is output of gprof
- `gprof <executable-name> gmon.out`

Valgrind
- `valgrind --leak-check=yes <executable-name>`
- **Detect memory leak**
- Delivers the most accurate results
- For multi-threaded applications

gperftools
- From Google
- CPU profiler
- Google performance tool