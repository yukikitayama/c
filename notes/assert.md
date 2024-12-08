# Assert

Overview
- `assert.h`
- Insert expressions in your program as a run-time check, used for debugging.
- The program will beterminated and error message is written to `stderr`
  - `abort()` is invoked

Switching off assertions
- `#define NDEBUG` before `#include <assert.h>` can turn off assertions
- `#undef NDEBUG` before `#include <assert.h>` can switch on assertions
  - Assetions are disabled by default with some nonstandard systems. 

Compile-time assetions
- Compile-time assertion can cause a program not to compile
- `static_assert` in `assert.h`
- `static_assert()` macro outputs an error message during compilation
- Build checks