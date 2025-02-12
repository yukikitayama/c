# Operator

Operator is a function that uses a symbolic name

**Expression** consists of a combination of operators and operands. Every expression has a value. Math is expression. Right hand side of assingment with math operations to a variable is expression. Comparison of a variable against a number is expression.

**Statement** is basic program steps of C and most statements are constructed from expressions. Declaration is statement. Lines of code with special syntax ending with a semicolon are statements. Statement is instruction to the computer. Assigment itself is statement. Function call is statement. Return is statement.

**C considers any expression to be a statement if you append a semicolon (expression statements)**

**Compound statement** is two or more statements grouped together by enclosing them in **braces (block)**.

Logical operator
- `&&` AND
- `||` OR
- `!` NOT

Cast
- Use parentheses and type before expression
- `int days;`, `days = (int) (minutes / 60.0) / 24.0;`

**Bitwise operatoe**
- Bitwise operators look something like the logical operators but different.
- Operates on the bits in **integer value**.
- Binary number is a number that includes only ones and zeroes, can be any length
  - 0, 1, 10101, 0101010, 000111
- Every binary number has a corresponding **Decimal value**.
  - For each digit, multiply the digit by its position value
  - Add up all of the products to get the final result
  - Position values in a binary number are the **powers of two**.
  - Computing from right to left is easier.
- `~`
  - Binary ones complement operator
  - Flip 0s to 1s, and 1s to 0s. Sign will flip too because `~` flips the lestmost bit, which controls sign.
  - https://www.geeksforgeeks.org/bitwise-complement-operator-tilde/

Type conversion
- To effectively develop C programs, you must understand the rules used for the implicit conversion of floating-point and integer values in C.
- If two operands in an expression are **integers**, then any decimal portion resulting from a **division** operation is discard, even if the result is assigedn to **floating** variable
- If one operand is an **int** and the other is a **float**, then the operation is performed as a **floating** point operation.

Cast operator
- Usually should stay away from implicit conversion, and better to do an explicit conversion.
- Type cast operator has a higher precedence than all the arithmetic operators except the unary minus and unary minus.

sizeof operator
- It looks like a function, but actually operator, not a function
- Tells how many **bytes** are occupied in memory by a given type
  - Useful because it depends on each machine how much bytes a particular type occupy
- Evaluated at compile time and not at runtime (unless a variable-length array is used in its argument)
- Argument to the sizeof operator can be
  - Variable
  - Array name
  - Name of a basic data type
  - Name of a derived data type
  - Expression

Pointer
- `*a`

Ternary operator
- `<condition> ? <when-true> : <when-false>`

%zd specifier
- `%zd` formats size of type

## Operator precedence

Higher
- Addition `+`, subtraction `-`
- Bitwise shifts `<<`, `>>`
Lower