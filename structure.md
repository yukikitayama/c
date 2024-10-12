# Structure

Overview
- Tool for grouping elements together
- Kind of like an object in OOP with data memebers but without methods
- `struct` keyword defines a collection of variables of various types called **structure** that you can treat as a single unit.
  - `struct` is followed by a **tag name**
  - **members** or **fields** are the variables inside.
- There is no memory allocation for the declaration
- Treat like defining a new type.
- To declare variable, `struct <tag-name> <variable-name>;`
  - Memory is allocated when declaring, and memory is allocated for each member.

Members in a struct
- **Structure variable is not a pointer**.
- Need a special syntax to access the members
- Use **member selection operator (dot operator)**, a period between the structure variable name and the member name, to refer to a member of a structure.
  - **There are no spaces permitted between the variable name, period, and member name**.
  - Setting the value of a member also use this dot operator.
- A function cannot be a member

Un-named structure
- You can define a structure without a tag name, but it's one time only. 
- You can no longer define further instances of the structure in another statement.

Initialize structure
- Specifying member names `.member = value` enables you to initialize the members in any order.
- `struct date date1 = { .month = 12, .day = 10 };`

Assign structure
- **Compound literal** is assignment to structure.
  - Not declaration
  - Use type cast operator
  - `today = (struct date) { 9, 25, 2015 };`
  - `today = (struct date) { .month = 9, .day = 25, .year = 2015 };`

Array of structures
- The concept of an array of structures is a very powerful and important one in C.
- `struct date myDates[10];`
- `myDates[0].month = 8;`
- `struct date myDates[5] = { {12, 10, 1975}, {12, 30, 1980}, {11, 15, 2005} };` initializes the first 3 dates.
  - The inner pairs of braces are optional but should add.
- `struct date myDates[5] = { [2] = {12, 10, 1975} };` initializes only 3rd element
- `struct date myDates[5] = { [1].month = 12, [1].day = 30 };` initializes only 2nd element's month and day.

Nested structure
- Structure that itself contains other structures as one or more of its members.
- `struct` keyword is required to define a structure inside structure.
- Defining a structure within another structure definition is possible
  - But it's impossible to declare the nested time outside the parent structure.

Pointer to structure
- C allows for pointers to structures
- Pointers to structures are easier to manipulate than structures themselves.
- Even if you can pass a structure as an argument to a function, passing a pointer is more efficient.
- **Many data representations use structures containing pointers to other structures**.
- `struct date *datePtr;`
- `datePrt = &todaysDate;`
- `(*datePtr).day = 12;` dereference first.
  - **Parentheses are required because the structure member operator `.` has higher precedence than the indirection operator `*`.
- `->` is the **structure pointer operator**. C's special operator.
  - `x->y` is equal to `(*x).y`
  - `->` is actually doing dereference for us.

Structure containing pointers
- One instance where it makes sense to use a pointer in a structure to handle a string is when you are dynamically allocating that memory.
- Use a pointer to store the address
- Advantage is to use `malloc()` to allocate the amount of space that is needed for a string.

Pass structure as an argument to functions
- When you simply pass structure as argument, it's **pass by value**. 
  - It means that **it can takes quite a bit of time to copy large structures as well as requiring whatever amount of memory to store the copy of the structure**.
- **Pointers to structures avoid the memory consumption and the copying time**.
  - Only a copy of the pointer argument is made.
  - Use `*` in argument and use `->` to access member (dereference)
- When returning a structure from a function. it's often more convenient to **return a pointer to a structure**.
  - It should be created on the heap.
- **You should always use pointers when passing structures to a function**.
  - It works on older as well as newer C implementations
  - It is quich (You just pass a single address, no copying by the pass by value)
- Advantage of passing structure as arguments
  - Safer because of copies of the original data
  - Programming style tends to be clearer
- Disadvantage of passing structure as arguments
  - Older implementations might not handle the code
  - Wastes time and space
  - Especially wasteful to pass large structures to a function that uses only one or two members of the structure.
- Passing structures by value is most often done for structures that are small.

```
struct intPtrs
{
    int *p1;
    int *p2;
};

struct intPtrs pointers;
int i2;
pointers.p2 = &i2;
*pointers.p2 = -97;
```

```
struct namect
{
    char * fname;
};

void getinfo(struct namect * pct)
{
    char temp[SLEN];
    printf("Enter your first name.\n");
    s_gets(temp, SLEN);

    // Allocate memory to hold name
    pct->fname = (char *)malloc(strlen(temp) + 1);

    // Copy name to allocated memory
    strcpy(pst->fname, temp);
}
```

```
struct Time
{
    struct Date
    {
        int day;
        int month;
        int year;
    } dob;

    int hour;
    int minutes;
    int seconds;
};
```

```
struct date
{
    int month;
    int day;
    int year;
};

struct date today;

today.year = 2024;

printf("%i", today.year);
```

An instance of the structure is declared at the same time that the structure is defined. `today` is a variable of type `date`.
```
struct date
{
    int month;
    int day;
    int year;
} today;
```

```
struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct dateAndTime {
    struct date sdate;
    struct time stime;
};

struct dateAndTime event;

event.sdate.month = 10;
++event.stime.seconds;
```