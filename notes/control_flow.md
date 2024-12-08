# Control flow

- Decision-making statements
  - if-then
  - if-then-else
  - switch
  - goto (maybe you not gonna use. Only exist)
- Looping statements
  - for
  - while
  - do-while
- Branching statements
  - break
  - continue
  - return

Loop
- When execution leaves a scope, all automatic objects that were created in that scope are destroyed.
- **For loop** is traditionally used for a purpose of creating infinite loop by a condition never becoming false.

The curly brackets are required for compound statements inside the if block, and not required for single line statement, but usually provide curly brackets even for single statment for consistency.

Nested if statement should use indentation or curly brackets for readability.

**Tenary statement** is a conditional operator for shorthand notation of if else statement. It's easy to assign. An expression for the maximum or minimum of **two variables** can be written very simply using the conditional operator.

Switch statement
- A program chooses one of several alternatives
- When the value of a variable is successively compared against different values use the switch statement.
- `switch`, `case`, `break;`, `default`
- Use curly brackets for the block that `switch` has, but the block that `case` has doesn't need curly brackets.
- `case` must be simple constants or constant expressions
- Curly brackets are not required for the block of `case`.
- `break` causes execution of the switch statement to be terminated.
- If a block doesn't have a `break` statement, another case evaluation executes.
- Should include the break statement at the end of every case.
- `default` is executed if the value of expression does not match any of the case values.

goto statement
- In C, it's available, but no need to use it.
- It's not readable because of jump
- Should not use `goto` statement.

Loop
- Counter controlled loop
- Quit by condition loop (sentinel loop)

For loop
- `for (starting_condition; continuation_condition; action_per_iteration)`
- **continuation_condition is tested at the beginning of the loop rather than at the end**
- loop_statement will not be executed at all if the continuation_condition starts out as false.
- action_per_iteration is executed at the end of each loop iteration
- One line for loop is possible like `for (int i = 1; i <= count; sum += i++);`. Don't forget `;`.
- Infinity loop can be made if you omit the last action_per_iteration like `for (int i = 1; i <= count ;)`
- `for( ;; )` is another statement for infinite loop
  - You have no obligation to put any parameters in the for loop statement.
  - Useful for monitoring data or listening for connections.

While loop
- **Pre-test loop**, meaning the condition for continuation of the while loop is tested at the start.
- Should use this pre-test loop, and stay away from post-test loop.
- Easier to read if the condition is at the beginning of the loop.
- `whilte (test)` is equal to `for( ; test ;)`

Do while loop
- Always guaranteed to execute at least once unconditionally
- Condition is at the bottom (**Post-test loop**)
- `do {} while ();` should end with `;`.
- Better to avoid using do while loop

Continue statement
- When you don't wanna end a loop but you want to skip the current iteration
- Use `continue;` in the body of the loop
- Can enhance readability

Break statement
- Immediately exit from the loop
- Use `break;`
- If the break statement is inside nested loops, it affects only the innermost loop.

Goto statement
- Bad reputation, hard to maintain
- Causes the program to branch immediately to the statement that is preceded by the label
- Label can be located anywhere in the function, before or after the goto
- goto statements are not considered part of good programming style.
- With deeply nested for loops, goto statement to exit from the entire nested for loops is useful.

```
goto someLabel;

someLabel: printf("Hello");
```

Null statement
- Null statement has the effect of doing nothing but exists for syntactical reasons
- Without the null statement, whatever statement that follows for loop or while loop in the program is treated as the body of the program loop by the compiler.

```
for (count = 0; getchar() != EOF; ++count)
    ;
```

Comma operator
- Comma is a binary operator that evaluates its first operand and discards the results, then evaluates the second operand and returns this value.
- The value of the comma operator is that of the rightmost expression
- Often used with variable declaration and for loop variables. 
```
int i(5, 10);  // 10 is assigned to i
int j = (f1(), f2());  // f2 output is assigned to j
x = (y = 3, (z = ++y + 2) + 5);  // x will have 11 by 4 + 2 + 5
```

Setjmp and longjmp
- `setjmp()` and `longjmp()` are functions that let you perform complex flow-of-control in C.
- Mainly used to implement **exception handling** in C (**error recovery situations**).
  - setjmp is like **try**
  - longjmp is like **throw**.
- Error handling makes sense only in the top level function if there is an error deep down in a function nested in many other functions
- Use setjmp and longjmp for error handling so that you can jump out of deeply nested call chain without needing to deal with handling errors in every function in the chain.
- `<setjmp.h>`
- setjmp() is called first.
- longjmp() goes back to setjmp place
- Difference from goto
  - jmp can jump from function to another function. longjmp only goes back to somewhere you have already been.
  - goto only jump within the same function. goto can't jump out of the current function.
