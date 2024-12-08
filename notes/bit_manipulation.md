# Big manipulation


Overview
- A hardware device is often controlled by sending it a byte or two in which each bit has a particular meaning.
- Operating system information about files often is stored by using particular bits to indicate particular items.
- Many compression and encryption operations manipulate individual bits.
- This allows C to write device drivers and embedded code.

Binary number
- A **binary number** is a number that includes only ones and zeroes.
- Every binary number has a corresponding **Decimal value**.
- Each position for a binary number has a value
  - For each digit, multiply the digit by its position value
    - In general, **position value is power of two**.
  - Add up all of the products to get the final result
  - First position value is `2^0`
  - Second position value is `2^1`

Bit
- A **byte** consists of eight smaller units (bit)
- Each 1 and 0 in a binary number represents 1 bit
  - If 1, the bit is **turned on**
  - If 0, the bit is **turned off**
- **The least significant bit (low-order bit)** is the rightmost bit of a byte
- **The most significant bit (high-order bit)** is the leftmost bit.
- **Word** is to group bits into bytes.
- **Setting the bit** means changing a bit's value to 1
- **Resetting the bit** means changing a bit's value to 0.

Bit for C data type
- `_Bool` is Bit, having 1 bit, having 0 to 1 value.
- `char` is Byte, having 8 bits, having -128 to 127 value.
- `short int` is Word, having 16 bits, having -32,768 to 32,767 value.
- `long int` is Long, having 32 bits, having -2,147,483,648 to 2,147,483,647 value.

Negative number
- Negative number is called **signed number**. Positive number is unsigned number.
- Computers represent negative numbers using **twos complement notation**.
  - If leftmost bit represents the sign bit
  - If leftmost bit is 1, negative
  - If rightmost bit is 2, positive
- Converting a negative decimal number to binary representation
  - Add 1 to the negative decimal number
  - Express the absolution value in binary
  - Change 1s to 0s and 0s to 1s (This process is called **complementing the bits**)
  - e.g., To get binary representation of -5, -5 + 1 = -4, 4's binary is 00000100, complementing 00000100 is 11111011. 11111011 is -5.
- Conver binary representation of negative decimal number to negative decimal number
  - Change 1s to 0s and 0s to 1s
  - Convert the binary representation to decimal number
  - Change sign
  - Subtract 1
  - e.g., 11111111, complementing it to 00000000, this decimal number is 0, change the sing of 0 is -0, -0 -1 = -1.
    - So binary of -1 is all 1s. 

Bitwise operator
- **Bit manipulation** is the act of algorithmically manipulating bits or other pieces of data shorter than a word (2 bytes)
- **Bitwise operation** operates on one or more binary numbers at the level of their individual bits.
- Faster than arithmetic operations
- Logical operators and shift operators oeperate on the bits in **integer values** in C.
  - Any type of integer value is okay; `int`, `short`, `long`, `long long`, `signed`, `unsigned`.
  - It can work on `characters` too.
- `~` is binary ones complement operator. It's unary. It has the effect of **flipping bits**.
- Shifting
  - If you shift a value by a **negative amount**, the result is **undefined**.
- **Bit mask** is data that is used for bitwise operations.
  - Check if particular bit values are present or not
  - **Multiple bits** in a Byte can be set on, off or inverted from on to off in a **single bitwise operation**.
  - Efficient way to store data.
  - Bitwise **AND** operator is used as "using a mask", because the zeros in the mask hide the corresponding bits in flags.
  - Bitwise **OR** operator is "turning bits on (setting bits)". Leaves all the other bits unchanged.
  - Bitwise **AND** operator is also used as "turning bits off (clearing bits)".
    - `flags = flags & ~MASK;`, `MASK` has 1 in the bits to turn off. `~MASK` is all 1s except for the bits to turn off. Leaves all the bits other than bit 1 unchanged, and turning off bits are set to 0 regardless of its original value.
  - Bitwise **XOR** operator is used as "toggling bits" where mask's bit is 1, turning off if it's on, turning on if it's off
    - `0 ^ b = b` regardless of its value.
  - Bitwise **AND** operator is also used as checking the value of a bit, by first masking the other bits in flags so that you compare only particular bit of flags with MASK
    - `if ((flags & MASK) == MASK)`

Using bit operators to pack data
- 2 methods are available in C; Bit fields, bitwise operators
  - You could use an `unsigned int/long` variable to hold the same information
  - You could use a `structure` the same size as unsigned int to hold state information.

Bit fields
- A **bit field** allows you to specify the number of bits in which an int member of a structure is stored.
- Uses a **special syntax in the structure definition** that allows you to define a field of bits and assign a name to that field.
- Format enables you to **allocatate a specified number of bits for a data itme**.
- Setting and retrieving its value is easy without using mask or shift.
- A bit field is declared by following an `unsigned int` member name with a **colon** `:`.
- An integer constant is placed after the color which **represetns the width (number of bits) of the field**.
- **It's possible to specify an unnamed bit field to be used as padding in the structure**.

Swap
```
int w1 = 147;
int w2 = 61;

w1 ^= w2;
w2 ^= w1;
w1 ^= w2;

// w1: 61, w2: 147
```

Bit field
```
struct packed_struct {
    unsigned int :3;  // Unnamed for padding
    unsigned int f1:1;
    unsigned int f2:1;
    unsigned int f3:1;
    unsigned int type:8;
    unsigned int index:18;
};
```
