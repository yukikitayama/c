# Union

Overview
- A **union** is a derived type with members that share the same storage space.
- Used mainly in advanced programming applications where it's necessary to store different types of data in the same storage area.
- To save space.
- **Member** is each element in a union.
- Only one member can contain a value at any given time.
- Member can be of any data type
- In most cases, unions contain two or more data types.
- Unions are useful in **embedded programming where direct access to the hardware/memory is needed**.
- You could create an array of unions that store equal-sized units.
- One common storage space for all its members
- A union is created with enough space for its largest field.
- e.g., If you have a union called quantity, with fields called count, weight, and volumne, whether you set the count, weight, or volume field, the data will go into the same space in memory.

Struct vs union
- You should use a structure when your construct should be a group of other things
- You should use a union when your construct can be one of many different things but only one at a time.
- Unions are typically used in situations where space is premium but more importantly for exclusively alternate data.
- Unions ensure that mutually exclusive states remain mutually exclusive.