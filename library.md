# Library

- `stdlib.h`
  - `srand()` generates random numbers
- `time.h`
  - Seed for random

```
#include <stdlib.h>
#include <time.h>

// Create a time variable
time_t t;

// Initialize the random number generator
srand((unsigned) time(&t));

// Get the random number and store
int randomNumber = rand();
```