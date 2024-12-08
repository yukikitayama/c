# Array

Overview
- Array is a **fixed** number of data items that are all of the **same type**.
- **Elements** are the data items in an array
- Use a number between square brackets `[]`
  - e.g., `long numbers[10];`
- **Size** of an array or **array dimension** is the number between square brackets.
- Avoid **off-by-one error** by starting 0 in the array
- Array out of bound has unpredictable result because program may crash or the array contain garbage data.
- **Compiler cannot check for out of bounds errors so your program will still compile**.
- Array out of bound is runtime error.
- Very important to ensure that array indexes are always within bounds

Initialization
- Defining initial values or array elements makes it easier to detect when things go wrong.
- If fewer initial values are specified, remaining values in the array are set to zero.
- **C does not provide any shortcut mechanisms for initializing array elements**
  - You need to initialize the array in a loop

```
#define SIZE 10

int values[SIZE];
int i

for (i = 0; i < SIZE; ++i) {
    values[i] = 0;
}
```

- The size of an array can be evaluated by `sizeof(a)` when `int a[10];` for example.

Multidimensional array
- **Designated initializer** uses subscript to initialize values like `int matrix[4][3] = { [0][0] = 1, [1][1] = 2 };`
  - Unspecified elements are set to zero by default.

```
int numbers[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
```

Variable length array (VLA)
- It's just about making array with a size using a **variable**. It sounds like you can originally do it, but it's a new feature added by C99, and before C99, it's not allowed to do like `int nums[n]`.
- Doesn't mean you can modify the length of the array after you create it. It keeps the same size after creation.
- Specify the size of an array with a variable when creating an array.
- Makes it easier to convert existing libraries of FORTRAN numerical calculation routines to C.
- It's possible in C to create a variable length array **but not necessary and it's something recommended to avoid**.
- If you need to dynamically allocate and even reallocate storage buffers, **you can always use pointers**.

Flexible array member
- Introduced in C99
- When using **structure**, we can declare an array without a dimension and whose size is flexible in nature.
- **Flexible array member** is declared by specifying **empty square brackets** `[]`.
- **There is a programming pattern to define flexible array member**.
- `malloc(sizeof(struct s) + desiredSize * sizeof(int));`
  - `sizeof()` ignores the flexible array member. 
  - `sizeof(struct)` evaluates size of all the members **except flexible array member**.
  - The extra sizeof operator `desiredSize * sizeof(int)` allocates memory for the flexible array member.
- Flexible array member can be declared only as **the last member of a struct**
- Each struct can contain **at most one** flexible array member
- Flexible array **cannot be the only member** of a struct
- Any struct containing a flexible array member cannot be a member of another struct
- A struct wiht a flexible array member **must be allocated dynamically**.
- **It's debatable on whether it's a good practice to use flexible array members**
  - Some argue it's not portable
- Using flexible array member can use less memory and effort, save storage.

```
struct s {
    int arraySize;
    int array[];
};

int desiredSize = 5;
struct s *ptr;

ptr = malloc(sizeof(struct s) + desiredSize * sizeof(int));
```


