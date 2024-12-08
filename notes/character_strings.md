# Character strings

Overview
- There is a distinction made between the single quotation and double quotation marks
  - Both are used to create two different types of constants in C.
- A string constant or string literal is a sequence of characters
- Anything between a pair of **double quotes** is interpreted by the compiler as a string
  - `"x"` is not the same as `'x'`
  - `'x'` is a basic type (`char`)
  - `"x"` is a derived type, an array of `char`. It consists of two characters, `'x'` and `\0`
- C has **no special variable type** for strings
- The standard library provides an extensive range of functions to handle strings, because a string has no special operators.
- Strings in C are stored in an array of type `char`
  - Characters in a string are **stored in adjacent memory cells, one character per cell**.

String in memory
- The end has `\0` null character.
- Special character like `\n` also has one byte assigned.

Null character
- A special character with the code value 0 is added to the end of each string to mark where it ends
- Tells compiler where it ends.
- Length of a string is always **one greater than the number of characters in the string**.
- Null character is different from `NULL`
  - Null character is a string terminator
  - `NULL` is a symbol that represents a memory address that doesn't reference anything. It's used with pointers

Creating strings
- When you specify the dimension of an array that you intend to use to store a string, it must be at least one greater than the number of characters in the string that you want to store.
- You must allow one element for the termination character (**null character**)
  - e.g., `char myString[20];` can accommodate a string that contains up to 19 characters.
- `char word[] = { 't', 'e', 's', 't' };`, in the absence of a particular array size, C compiler automatically computes the number of elements and adds the null terminator.
- Best practice is to not specify the size, let the compiler figure out.
- You can initialize part of an array of elements of type `char` with a string
  - e.g., `char str[40] = "To be";`
    - Compiler initializes the first 5 elements by `"To be"` from `str[0]` to `str[4]`
    - `str[5]` contains null character `\0`
    - But space is allocated for all 40 elements of the array

Assign a value to a string
- Use `strcpy()` to assign a value to a char array after declared or initialized.

Display a string
- Use array name
- `%s` format specifier to output in `printf()`

Input a string
- `char input[10];`, `scanf("%s", input);`, no `&` address of operator.
- `scanf` only reads up to space. Don't read the rest of the strings.
  - e.g., `Yuki Kitayama` -> `Yuki\0`

Compare strings
- Cannot use `==`

Length of strings
```
unsigned int count = 0;
char str[] = "This is test";

while (str[count] != '\0')
    ++count;

printf("The length of the string \"%s\" is %d characters.\n", str, count);
```

Constant strings
- Use `#define constant-name constant-value` preprocessor delactive to perform compile-time substitution.
- A defined name isn't a variable, so you cannot assign a value to it.
- No equal sign. No semicolon. Not statement
- `#define` statement makes programs more portable.
- `#define` statement can be used for character and string constants
  - e.g., `define BEEP '\a'`, `#define OOPS "Now you have done it!"`
- `const` keyword converts a seclaration for a variable into a declaration for a constant
  - `const` is a newer approach and is more flexible thatn using `#define`.
- `enum` also creates symbolic constant.
- Initializing a char array and declaring it as `const` is a good way of handling standard messages without modification

String functions
- **C library supplies string-handling function prototypes in the `string.h` header file**.
- Many of the string functions return pointers.
- `strlen()`
  - Get the length of a string
  - Return `size_t`
- `strcpy()` and `strncpy()`
  - Copy a string to an existing string
  - String equivalent of the assignment operator
  - `strcpy()` doesn't check to see whether the source string actually fits in the target string.
  - `strncpy()` is a safer way to copy strings by taking the 3rd argument (maximum number of characters to copy)
    - `strncpy(destination_string, source_string, sizeof(destination_string) - 1);`. -1 is for a null terminator space.
  - Always use `strncpy()`, not `strcpy()`, to avoid buffer overflow.
- `strcat()` and `strncat()`
  - Combine two character strings together (concatenation)
  - Returns the address of the first character string to which the second character string is appended.
  - Second string isn't altered, but first string is altered.
  - `strcat()` doesn't check to see whether the second string will fit in the first string.
    - If you fail to allocate enough space for the first string, you will run into problems as **excess characters overflow into adjacent memory locations**.
  - Use `strncat()` instead.
- `strcmp()` and `strncmp()`
  - Determine if two character strings are equal
  - `str1 == str2` will only check to see if the string has the same address, but don't compare string contents.
  - Returns 0 if two strings are the same
  - Return value < 0 if str1 is less than str2
  - Return value > 0 if str1 is more than str2
  - `strncmp()` is useful for **prefix comparison**
- `strcasecmp()` can compare 2 strings with case-insensitively.
- `strchr(string, char)`, `strstr(string, string)`
  - Searching a string
  - Case sensitive
  - `strchr()` returns a pointer to the first position in the string where the character is found (tyoe `char *`).
    - To store the value that's returned, you must create a variable that can store the address of a character.
    - If the character isn't found, the function returns `NULL`. `NULL` is the equivalent of 0 for a pointer and represents a pointer that doesn't point to anything.
  - `strstr()` searches one string for the **first occurrence** of a string. It returns a pointer to the position in the first string where the substring is found. If no match, returns `NULL`.
- `strtok()`
  - Tokenize characters in a string by a delimiter
  - Returns a pointer to each token one by one. So you need a while loop to access all the tokens.
- `islower()`, `isupper()`, `isalpha()`, `isdigit()`
  - Argument is character
  - Returns nonzero value of type int
  - The return value converts to true and false as Boolean values.

`strtok()`

```
char str[80] = "Hello how are you - my name is - Yuki";
const char s[2] = "-";
char *token;

token = strtok(str, s);

while (token != NULL)
{
    printf("%s\n", token);
    token = strtok(NULL, s);
}
```

Convert strings
- `tolower()`, `toupper()`
- `for (int i = 0; (buf[i] = (char) toupper(buf[i])) != '\0'; ++i);`
  - `(char)` because `toupper()` returns type int.

Convert strings to numbers
- `stdlib.h` header file declares functions that you can use to convert a string to a numerical value
- `atof()` produces `double`
- `atoi()` produces `int`
- `atol()` produces `long`
- `atoll()` produces `long long`
- `strtod()`, `strtof()`, `strtold()` are newer functions to produce numbers from string