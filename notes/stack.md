# Stack

Overview
- A **stack** is a constrained version of a linked list
- All insertions and deletions are only made at the top of the stack
- A stack is referenced via a **pointer** to the top element of the stack.
  - The link member in the last node of the stack is set to NULL to indicate the bottom of the stack, otherwise runtime error
- Stacks and linked lists are represented identically, but stack allows only at the top to insert and delete.
- Operations
  - Push
  - Pop
  - Peek
    - Look at the top but don't pop
  - isEmpty

Applications
- Stacks support recursive function calls
- Stacks are used to store data in memory
- Call stack is useful when debugging
- Stacks are used by compiler
- Page visited history in a web browser
- Undo operation in a text editor
- Post-fix notation in a computer language
- Used in algorithms